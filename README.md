# Sistemas Operacionais (3º Ano)

### [1º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/1%C2%BA%20Bimestre):
1) Guiação de um FrontEnd em shell script para alguns comandos do linux
2) Criação de Forks e cálculo de tempo de processos
   * (CÁLCULO DE APROXIMAÇÃO DA RAIZ DE 2 E DE TEMPO DE CHAVEAMENTO DE PROCESSOS)

-----

### 2º Bimestre:
1) Desenvolver uma aplicação que simule os métodos básicos de alocação de processos em lacunas de memória com particionamento dinâmico.
   * Best Fit, First Fit, Worst Fit e Circular Fit  
   * Opção 1 - Inserir Processo em memória
   * Opção 2 - Remover processo em memória
   * Opção 3 - Listar estado das memórias
   * Opção 4 - Finalizar aplicação
2) Desenvolver uma estrutura de dados que represente um sistema de paginação de memória
   - 512 páginas de 8KB e 256 frames;
   - uma tabela de páginas será criada, associando (aleatoriamente) 256 páginas às 256 molduras disponíveis;
   - representação de endereços virtuais e reais na notação binária, separados na forma de tuplas número da página/descolamento e número da moldura/deslocamento, respectivamente 9+13 bits e 8+13 bits;
   - endereços deverão ser tratados na forma de Bytes;
   - ex.: página 1 mapeada na moldura 0
     - EV [9000] (pág. nr. 1, deslocamento de 808B = 000000001 0001100101000)
     - ER [808] (moldura nr. 0, deslocamento de 808B = 00000000 0001100101000)
   - os processos podem "acessar" 4MB e o sistema disponibiliza 2MB de memória física.
Após:
   - uma entrada será fornecida definindo a quantidade de endereços (N);
   - em seguida, serão criados N endereços aleatórios (EV) entre 0 e 4194303;
   - como saída, fornecerá a localização na tabela de páginas na forma nr. da página/deslocamento em decimal e binário e o respectivo endereço físico (ER) na forma nr.da moldura/deslocamento em decimal e binário, quando houver. Caso contrário, informar que houve PF.
   - sumarizar a taxa de acertos (hit ratio) e a taxa de page faults (miss ratio).
  
-----

### 3º Bimestre:

-----

### 4º Bimestre:
