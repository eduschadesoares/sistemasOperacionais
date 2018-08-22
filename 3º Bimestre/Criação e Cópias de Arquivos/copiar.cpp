#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// Constantes
const char c = 'o';
const int b = 1;
const int Kb = 1024;
const int Mb = 1024 * 1024;
const int Gb = 1024 * 1024 * 1024;

struct timeval tempo1, tempo2;
struct timezone tzp;

// Protótipos
void copyFileFunction();
void copyFileSyscall();
void createFileFunction();
void createFileSyscall();
void fileFunctionCopier(int);
void fileSyscallCopier(int);
void fileFunctionCreator(int, int);
void fileSyscallCreator(int, int);
void fileCreator();
void menu();

// C++ stuff
using namespace std;

// The very beginning
int main() {
    menu();
}

void copyFileFunction() {
    printf("\nCopiando arquivos por função!\n\n");
    for(int i=1; i<=4; i++) {
        if(i == 1) { //b
            printf("Copiando %iº arquivo de 1b.\n", i);
            fileFunctionCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
        if (i == 2) { //Kb
            printf("Copiando %iº arquivo de 1Kb.\n", i);
            fileFunctionCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
        if (i == 3) { //Mb
            printf("Copiando %iº arquivo de 1Mb.\n", i);
            fileFunctionCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
        if (i == 4) { //Gb
            printf("Copiando %iº arquivo de 1Gb (Vai demorar um pouco!).\n", i);
            fileFunctionCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
    }
}

void copyFileSyscall() {
    printf("\nCopiando arquivos por syscall!\n\n");
    for(int i=1; i<=4; i++) { // (<=)Right
        if(i == 1) { //b
            printf("Copiando %iº arquivo de 1b.\n", i);
            fileSyscallCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
        if (i == 2) { //Kb
            printf("Copiando %iº arquivo de 1Kb.\n", i);
            fileSyscallCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
        if (i == 3) { //Mb
            printf("Copiando %iº arquivo de 1Mb.\n", i);
            fileSyscallCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
        if (i == 4) { //Gb
            printf("Copiando %iº arquivo de 1Gb (Vai demorar um pouco!).\n", i);
            fileSyscallCopier(i);
            printf("Arquivo file%i.in copiado!\n\n", i);
        }
    }
}

void createFileFunction() {
    printf("\nCriando arquivos por função!\n\n");
    for(int i=1; i<=4; i++) {
        if(i == 1) { //b
            printf("Criando %iº arquivo de 1b.\n", i);
            fileFunctionCreator(i, b);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 2) { //Kb
            printf("Criando %iº arquivo de 1Kb.\n", i);
            fileFunctionCreator(i, Kb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 3) { //Mb
            printf("Criando %iº arquivo de 1Mb.\n", i);
            fileFunctionCreator(i, Mb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 4) { //Gb
            printf("Criando %iº arquivo de 1Gb (Vai demorar um pouco!).\n", i);
            fileFunctionCreator(i, Gb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
    }
}

void createFileSyscall() {
    printf("\nCriando arquivos por syscall!\n\n");
    for(int i=1; i<=4; i++) { // (<=)Right
        if(i == 1) { //b
            printf("Criando %iº arquivo de 1b.\n", i);
            fileSyscallCreator(i, b);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 2) { //Kb
            printf("Criando %iº arquivo de 1Kb.\n", i);
            fileSyscallCreator(i, Kb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 3) { //Mb
            printf("Criando %iº arquivo de 1Mb.\n", i);
            fileSyscallCreator(i, Mb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
        if (i == 4) { //Gb
            printf("Criando %iº arquivo de 1Gb (Vai demorar um pouco!).\n", i);
            fileSyscallCreator(i, Gb);
            printf("Arquivo file%i.in criado!\n\n", i);
        }
    }
}

void fileFunctionCopier(int num) {
    FILE* file;
    FILE* fileCopied;
    double tempo;
    char ch;
    char fileName1[64];
    char fileName2[64];
    sprintf(fileName1, "file%i.in", num);
    sprintf(fileName2, "file%i.out", num);

    // Openning file
    file = fopen(fileName1, "r");
    fileCopied = fopen(fileName2, "w");

    gettimeofday(&tempo1, &tzp); // Start timing

    while((ch = fgetc(file)) != EOF) fputc(ch, fileCopied);

    gettimeofday(&tempo2, &tzp); // End timing


    //Closing files
    fclose(file);
    // fclose(fileCopied);

    tempo = (double) (tempo2.tv_sec - tempo1.tv_sec) + (((double) (tempo2.tv_usec - tempo1.tv_usec)) / 1000000);

    printf("Tempo: %.30f\n", tempo);
}

void fileSyscallCopier(int num) {
    int file, fileCopied;
    double tempo;
    char ch;
    char fileName1[64];
    char fileName2[64];
    sprintf(fileName1, "SYSfile%i.in", num);
    sprintf(fileName2, "SYSfile%i.out", num);

    // Openning file
    file = open(fileName1, O_RDONLY);
    fileCopied = open(fileName2, O_WRONLY| O_CREAT,S_IRUSR|S_IWUSR);


    gettimeofday(&tempo1, &tzp); // Start timing

    while(read(file,&ch,1) == 1) write(fileCopied,&c,1);

    gettimeofday(&tempo2, &tzp); // End timing


    //Closing file
    close(file);
    close(fileCopied);
    
    tempo = (double) (tempo2.tv_sec - tempo1.tv_sec) + (((double) (tempo2.tv_usec - tempo1.tv_usec)) / 1000000);

    printf("Tempo: %.30f\n", tempo);
}

void fileFunctionCreator(int num, int size) {
    FILE* file;
    double tempo;    
    char fileName[64];
    sprintf(fileName, "file%i.in", num);

    // Openning file
    file = fopen(fileName, "w");


    gettimeofday(&tempo1, &tzp); // Start timing

    for(int i=0; i < size; i++) fputc(c, file);

    gettimeofday(&tempo2, &tzp); // End timing


    //Closing file
    fclose(file);

    tempo = (double) (tempo2.tv_sec - tempo1.tv_sec) + (((double) (tempo2.tv_usec - tempo1.tv_usec)) / 1000000);

    printf("Tempo: %.30f\n", tempo);
}

void fileSyscallCreator(int num, int size) {
    int file;
    double tempo;    
    char fileName[64];
    sprintf(fileName, "SYSfile%i.in", num);

    // Openning file
    file = open(fileName, O_WRONLY| O_CREAT,S_IRUSR|S_IWUSR);


    gettimeofday(&tempo1, &tzp); // Start timing

    for(int i=0; i < size; i++) write(file, &c, 1);

    gettimeofday(&tempo2, &tzp); // End timing


    //Closing file
    close(file);
    
    tempo = (double) (tempo2.tv_sec - tempo1.tv_sec) + (((double) (tempo2.tv_usec - tempo1.tv_usec)) / 1000000);

    printf("Tempo: %.30f\n", tempo);
}

void menu() {
    int choice;
    printf("1 - Criar os arquivos por FUNÇÃO\n");
    printf("2 - Criar os arquivos por SYSCALL\n");
    printf("3 - Copiar os arquivos por FUNÇÃO\n");
    printf("4 - Copiar os arquivos por SYSCALL\n");
    cin >> choice;
    
    switch(choice) {
        case 1:
            createFileFunction();
            break;
        case 2:
            createFileSyscall();
            break;
        case 3:
            copyFileFunction();
            break;
        case 4:
            copyFileSyscall();
            break;
        default:
            printf("Mano, ajuda ai\n");
            menu();
            break;
    }
}   