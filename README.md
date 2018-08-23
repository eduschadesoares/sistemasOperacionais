# Sistemas Operacionais (3º Ano)

### [1º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/1%C2%BA%20Bimestre)
1) Guiação de um [FrontEnd em shell script](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/1%C2%BA%20Bimestre/Trabalho%20Script/Trabalho_Script) para alguns comandos do linux

2) Criação de [Forks](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/1%C2%BA%20Bimestre/Trabalho%20Fork/Trabalho_Fork.cpp) e cálculo de tempo de chaveamento de processos
   * [(CÁLCULO DE APROXIMAÇÃO DA RAIZ DE 2 E DE TEMPO DE CHAVEAMENTO DE PROCESSOS)](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/1%C2%BA%20Bimestre/Trabalho%20Fork/Trabalho%20SO%20-%201%C2%BA%20Bimestre%20-%20Processos.pdf)

-----

### [2º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/2%C2%BA%20Bimestre)
1) Desenvolver uma aplicação que simule os métodos básicos de [alocação de processos](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/2%C2%BA%20Bimestre/Dynamic%20process%20allocator%20simulator) em lacunas de memória com particionamento dinâmico
   * Best Fit, First Fit, Worst Fit e Circular Fit  
   * Opção 1 - Inserir Processo em memória
   * Opção 2 - Remover processo em memória
   * Opção 3 - Listar estado das memórias
   * Opção 4 - Finalizar aplicação
   
2) Desenvolver uma estrutura de dados que represente um sistema de [paginação de memória](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/2%C2%BA%20Bimestre/Pagina%C3%A7%C3%A3o)
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

### [3º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/3%C2%BA%20Bimestre)
1) [Avaliação](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/3%C2%BA%20Bimestre/Cria%C3%A7%C3%A3o%20e%20C%C3%B3pias%20de%20Arquivos/Trabalho%20SO%20-%203%C2%BA%20Bimestre%20-%20Arquivos.pdf) de tempo em [sistemas de arquivos](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/3%C2%BA%20Bimestre/Cria%C3%A7%C3%A3o%20e%20C%C3%B3pias%20de%20Arquivos/copiar.cpp)

   - **Métodos:** Função ou syscall
   - Copiar 1B por vez
   - Criar um arquivo **"file.in"** por *função* e *syscall* de tamanho *1B*, *1KB*, *1MB* e *1GB*
   - Tirar a média do tempo decorrido na criação dos arquivos
   - Copiar cada um dos 4 arquivos **file.in** poŕ *função* e *syscall* para o arquivo **"file.out"**
-----

### 4º Bimestre:

