#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

//Variáveis Globais

double tempo;
int pid;
int numForks;

void menu() {
  int opcao;

  printf( "╔═════════════════════════════╗\n");
  printf( "╠ 1 - Execução de Referência  ║\n");
  printf( "╠ 2 - Criar forks             ║\n");
  printf( "╠ 3 - Sair                    ║\n");
  printf( "╠═════════════════════════════╝\n");
  printf( "╠ ");
	scanf("%i", &opcao);

  switch (opcao) {
    case 1:
      numForks = 1;
      break;

    case 2:
      printf( "║\n");
      printf( "╠ Quantos forks deseja criar?\n");
      printf( "║\n");
      printf( "╠ ");
    	scanf("%i", &numForks);
      numForks++;
      break;

    case 3:
      exit(0);
      break;

    default:
      printf("Número incorreto, tente novamente...\n");
      menu();
      break;
  }

}

double raiz_2(){
  struct timeval tempo1, tempo2;
  struct timezone tzp;
	long double x = 1, xn;
	long double iteracoes = 0, i = 1;

  iteracoes = 999999999;

  gettimeofday(&tempo1, &tzp);

  //-------------------------------------------------------

	while (i <= iteracoes) {
		xn = x;
		x = xn/2 + 1/xn;
		i++;
	}

  //-------------------------------------------------------

  gettimeofday(&tempo2, &tzp);

	//printf("\nRaiz de 2 = %.20Lf\n", x);

  tempo = (double) (tempo2.tv_sec - tempo1.tv_sec) + (((double) (tempo2.tv_usec - tempo1.tv_usec)) / 1000000);

}

int main(){

  menu();

  char url[]="results.txt";
  FILE *arq;
  arq = fopen(url, "a+");

  if(arq == NULL) {
      printf("Erro, nao foi possivel abrir o arquivo\n");
      fclose(arq);
  }

  fprintf(arq, "--------------------------------------------\n");
  fprintf(arq, "\n--------------------------------------------\n");
  fprintf(arq, "-  Execução com %2.1i processos - %2.1i FORK     -\n", numForks, numForks - 1);

  fclose(arq);

  printf( "║\n");

//Criação dos Forks

  for(int i=0; i < numForks-1; i++) {
    if(pid == 0) {
      pid = fork();
      if(pid < 0) {
        exit(1);
      }
    }
  }

  raiz_2();


  arq = fopen(url, "a+");
  if(pid == 0)
    fprintf(arq, "-  PAI  - %.30f -\n", tempo);
  else
    fprintf(arq, "- %5.1d - %.30f -\n", pid, tempo);

  fclose(arq);


  printf( "╠ PID: %5.1d - Tempo decorrido: %.30f segundos\n", pid, tempo);

  //Fim Criação dos Forks

  return 0;
}
