#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
int fd, kbd;
char letra, *portname;
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
if(fd==-1)
  {
  sprintf(msg, "\nUnable to open \"%s\"", portname);
  perror(msg);
  return -1;
  }
/* Set attributes of the serial interface to raw mode */
if(tcgetattr(fd, &mytty)==-1)
  {
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

if(tcsetattr(fd, TCSANOW, &mytty)==-1)
  {
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
do
  {
/* Wait for any activitiy in the serial port (fd) or keyboard (kbd) */
  FD_ZERO(&descritores);  /* Inicializa a lista de handles */
  FD_SET(fd,  &descritores);
  FD_SET(kbd, &descritores);
  timeout.tv_sec=5;
  timeout.tv_usec=0;
  select(FD_SETSIZE, &descritores, NULL, NULL, &timeout);

  while(read(fd, &letra, 1) >= 0)       /* Get a char from serial port "fd"
*/
        write(kbd, &letra, 1);          /* Send it to the console "kbd"
*/
  while(read(kbd, &letra,1) >= 0)       /* Get a char from "kbd" (keyboard)
*/
        write(fd, &letra, 1);           /* send it to the serial port "fd"
*/
  } while(letra!='X'-64);               /* if the key was Ctrl-X exit
*/
close(fd);
/* Set console back to normal */
fcntl(kbd, 0, FNDELAY);
tcsetattr(kbd, TCSANOW, &kbdios);
putchar('\n');
return 0;
}
