#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string.h>

#define STR_MAX_SIZE 50

// Comunication Status
const char AVAILABLE = 'a', SENDER = 's', RECIEVER = 'r';

const char man_file[] = "/tmp/man_file";

// Global Variables
char command[STR_MAX_SIZE];

// Status
char status = 'a';


void man_maker(){
  char man_word[STR_MAX_SIZE] = "man ";
  char end_word[STR_MAX_SIZE] = "\n";
  strcat(man_word, command);
	strcat(man_word, end_word);
  strcpy(command, man_word);
  printf("\n%s\n", command);
int z=0;
for(z=0; z<strlen(man_word);z++)
              {
                  man_word[z] = 0;
              }

}

void do_command() {
    FILE *command_resul, *man_resul;
    command_resul = popen(command, "r");
	
    man_resul = fopen(man_file, "w");

    do fprintf(man_resul, "%c", fgetc(command_resul)); while(!feof(command_resul));


    pclose(command_resul);
    fclose(man_resul);
}

int main(int argc, char **argv) {
  int fd, kbd, aux, remover;
  int i = 0;
  char letra, *portname;
  char check_status = 0;
  char msg[80];
  struct termios mytty, kbdios;
  fd_set descritores;     /* Set of i/o handles */
  struct timeval timeout;
  /* Open serial port */
  portname="/dev/ttyS0";  /* Use /dev/ttyS0 by default */
  /* or get the name of the serial port device from the command line */
  if(argc>1 && *argv[1]=='/') portname=argv[1];
  /* Open the serial port */
  fd=open(portname, O_RDWR | O_NDELAY);
  if(fd==-1) {
    sprintf(msg, "\nUnable to open \"%s\"", portname);
    perror(msg);
    return -1;
  }
  /* Set attributes of the serial interface to raw mode */
  if(tcgetattr(fd, &mytty)==-1) {
    perror(NULL);
    close(fd);
    return -1;
  }
  mytty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP
                |INLCR|IGNCR|ICRNL|IXON);
  mytty.c_oflag &= ~OPOST;
  mytty.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
  mytty.c_cflag &= ~(CSIZE|PARENB);
  mytty.c_cflag |= CS8;           /* 8 bit data bytes */
  /* Set Baud Rate to 9600 baud */
  cfsetispeed(&mytty, B9600);
  cfsetospeed(&mytty, B9600);

  if(tcsetattr(fd, TCSANOW, &mytty)==-1) {
    perror(NULL);
    close(fd);
    return -1;
  }
  /* Get keyboard handle (assuming that stdin is the keyboard and video) */
  kbd=fileno(stdin);
  /* Set keyboard to raw mode */
  tcgetattr(kbd, &kbdios);
  memcpy(&mytty, &kbdios, sizeof(struct termios));
  mytty.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
  tcsetattr(kbd, TCSANOW, &mytty);
  /* These calls make read to return imedately even when there is
    no data in the input stream */
  fcntl(fd, F_SETFL, FNDELAY);
  fcntl(kbd, F_SETFL, FNDELAY);
  /* Now we may use the serial interface and keyboard for sending
    just one character at a time */
  printf("\nSerial tty terminal on port \"%s\"\n", portname);
  printf("Type ctrl-X (meta-X) to exit.\n");
  do {
  /* Wait for any activitiy in the serial port (fd) or keyboard (kbd) */
    FD_ZERO(&descritores);  /* Inicializa a lista de handles */
    FD_SET(fd,  &descritores);
    FD_SET(kbd, &descritores);
    timeout.tv_sec=5;
    timeout.tv_usec=0;
    select(FD_SETSIZE, &descritores, NULL, NULL, &timeout);

    // Custom Stuff

    
      // Verify first input
      while(read(fd, &letra, 1) >= 0) {      /* Get a char from serial port "fd"*/
        if(status == AVAILABLE) { //change to 2
					if(letra == RECIEVER) {
         	  status = letra;
	 					letra = ' ';
          	printf("Receiver\n");
        	}
				} else 
					 if(status == RECIEVER) {
	           //Receiver logic
	           command[i] = letra;
         	   if(command[i] == '\n') {
               do_command();
							 aux = open(man_file, O_RDONLY);
							
							 while(read(aux, &letra, 1)){
	//								write(fd, &letra, 1);
                  printf("%c", letra);
                  status = AVAILABLE;
                  remover = remove(man_file);
                              int g=0;
              for(g=0; g<strlen(command);g++)
              {
                  command[g] = ' ';
              }
							 }
							 close(aux);
							 i = 0;
          	}
				 		i++;
       	 }
      }
      while(read(kbd, &letra, 1) >= 0) {       /* Get a char from "kbd" (keyboard)*/
        if(status == AVAILABLE) {
					if(letra == '\n') {
		        status = SENDER;
		        printf("Sender\n");  
		        write(fd, &RECIEVER, 1);                 /* send it to the serial port "fd"*/
		        printf("Press enter to send a command\n");
					}
        }
        else {
          if(letra == '\n') {
            //write to serial port
            man_maker();
            int count = 0;
            while(command[count] != '\n') {
              write(fd, &command[count], 1);
							count++;
            }				
            write(fd, "\n", 1);
					  i = 0;
						status = AVAILABLE;

            int z=0;
              for(z=0; z<strlen(command);z++)
              {
                  command[z] = ' ';
              }

          } else {
	          	command[i] = letra;
		          write(kbd, &letra, 1);
         	    i++;
					}
        }
				fflush(stdin);
      }
    
    } while(letra!='X'-64);               /* if the key was Ctrl-X exit*/
  close(fd);
  /* Set console back to normal */
  fcntl(kbd, 0, FNDELAY);
  tcsetattr(kbd, TCSANOW, &kbdios);
  putchar('\n');
  return 0;
}

//Command
//socat -d -d pty,raw,echo=0 pty,raw,echo=0