<img align="right" width="260" height="260" src="https://upload.wikimedia.org/wikipedia/commons/3/35/Tux.svg">

# Sistemas Operacionais (3º Ano)

[![Python Repo](https://img.shields.io/badge/python%20repo-up%20to%20date-brightgreen.svg)](https://github.com/eduschadesoares/pythonCodes) [![C++ Repo](https://img.shields.io/badge/c++%20repo-up%20to%20date-blue.svg)](https://github.com/eduschadesoares/cCodes) [![Read the Docs](https://img.shields.io/badge/docs-check%20out-red.svg)](http://deinfo.uepg.br/~arion/MaterialDeApoio.html)

#

### Conteúdo refente à matéria de Sistemas Operacionais
Curso de [Engenharia de Software](http://www.uepg.br/catalogo/cursos/2016/bachareleminformatica.pdf) da *[Universidade Estadual de Ponta Grossa](https://portal.uepg.br/)*

#

#### Conteúdo 
- [x] [1º Bimestre](#1º-bimestre) (Processos)
- [x] [2º Bimestre](#2º-bimestre) (Memórias)
- [x] [3º Bimestre](#3º-bimestre) (Arquivos)
- [x] [4º Bimestre](#4º-bimestre) (I/O)
 
# 

### [1º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/1%C2%BA%20Bimestre)
1) Guiação de um [FrontEnd em shell script](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/1%C2%BA%20Bimestre/Trabalho%20Script/Trabalho_Script) para alguns comandos do linux


2) Criação de [Forks](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/1%C2%BA%20Bimestre/Trabalho%20Fork/Trabalho_Fork.cpp) e cálculo de tempo de chaveamento de processos
   * [(CÁLCULO DE APROXIMAÇÃO DA RAIZ DE 2 E DE TEMPO DE CHAVEAMENTO DE PROCESSOS)](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/1%C2%BA%20Bimestre/Trabalho%20Fork/Trabalho%20SO%20-%201%C2%BA%20Bimestre%20-%20Processos.pdf)

# 

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
  
# 

### [3º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/3%C2%BA%20Bimestre)
1) [Avaliação](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/3%C2%BA%20Bimestre/Cria%C3%A7%C3%A3o%20e%20C%C3%B3pias%20de%20Arquivos/Trabalho%20SO%20-%203%C2%BA%20Bimestre%20-%20Arquivos.pdf) de tempo em [sistemas de arquivos](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/3%C2%BA%20Bimestre/Cria%C3%A7%C3%A3o%20e%20C%C3%B3pias%20de%20Arquivos/copiar.cpp)

   - **Métodos:** Função ou syscall
   - Copiar 1B por vez
   - Criar um arquivo **"file.in"** por *função* e *syscall* de tamanho *1B*, *1KB*, *1MB* e *1GB*
   - Tirar a média do tempo decorrido na criação dos arquivos
   - Copiar cada um dos 4 arquivos **"file.in"** por *função* e *syscall* para o arquivo **"file.out"**
   - Tirar a média do tempo decorrido na cópia dos arquivos
   - [(AVALIAÇÃO DE TEMPO DE CRIAÇÃO E CÓPIA DE ARQUIVOS)](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/3%C2%BA%20Bimestre/Cria%C3%A7%C3%A3o%20e%20C%C3%B3pias%20de%20Arquivos/Trabalho%20SO%20-%203%C2%BA%20Bimestre%20-%20Arquivos.pdf)


2) [Filtro](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/3%C2%BA%20Bimestre/Tipos%20de%20Arquivos%20Linux/FilesType.cpp) de [arquivos de acordo com o seu tipo](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/3%C2%BA%20Bimestre/Tipos%20de%20Arquivos%20Linux) (Linux)

    - Criar um filtro para mostrar os tipos de arquivos desejados em dado diretório.
    - Utilização do [cabeçalho](https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html) ```<dirent.h>```
    - Localização do cabeçalho ```/usr/include/dirent.h```
    
    - [**TIPOS DE ARQUIVOS**](https://www.systutorials.com/docs/linux/man/2-getdents/)
    
      | VALUES  | TYPE | NUMBER |
      | :---: | :---: | :---: |
      | DT_BLK | This is a block device. | 6 |
      | DT_CHR | This is a character device. | 2 |
      | DT_DIR | This is a directory. | 4 |
      | DT_FIFO | This is a named pipe (FIFO). | 1 |
      | DT_LNK | This is a symbolic link. | 10 |
      | DT_REG | This is a regular file. | 8 |
      | DT_SOCK | This is a UNIX domain socket. | 12 |
      | DT_UNKNOWN | The file type is unknown. | 0 |
    
# 

### [4º Bimestre](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/4%C2%BA%20Bimestre)
1) Comunicação [Serial](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/IO%20-%20Serial/serial.c)

    - Criar uma comunicação serial entre duas máquinas através da conexão serial ```DB9```.
    - Utilização do [programa base](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/IO%20-%20Serial/io-serial(base).c) que cria a conexão entre as duas máquinas com auxílio do [material tutorial](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/IO%20-%20Serial/serial.pdf).
    - **Enviar** *(máquina 1)* comandandos do terminal do linux de uma máquina para outra *(máquina 2)*. Executar o manual do comando na máquina **receptora** *(máquina 2)* e printar os resultados na tela da máquina que **enviou** *(máquina 1)* os comandos.
    - Páginação dos resultados é opcional

2) Seminário sobre [Segurança Digital](https://github.com/eduschadesoares/sistemasOperacionais/tree/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital)
    - [Engenharia Social](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital/Engenharia%20Social%20-%20Eduardo%20Soares%20e%20Matheus%20Gomes.pdf) ([Me](https://github.com/eduschadesoares), [Matheus Gomes](https://github.com/gomesmat))
    - [Backup](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital/Backup%20-%20Guilherme%20L%C3%BAdio%20e%20Chrystian%20Freitas.pdf) (Guilherme Lúdio, Chrystian Freitas)
    - [Certificação Digital](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital/Certifica%C3%A7%C3%A3o%20Digital%20-%20Lucas%20Kluber%20e%20Silvia%20Lopes.pdf) ([Lucas Kluber](https://github.com/klubas), Silvia Lopes)
    - [Firewall](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital/Firewall%20-%20Leandro%20Souza%20e%20Matheus%20Krol.pdf) (Leandro Souza, Matheus Krol)
    - [Segurança Web](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital/Seguran%C3%A7a%20Web%20-%20F%C3%A1bio%20Castro%20e%20Natali%20Lisboa.pdf) (Fábio Castro, Natali Lisboa)
    - [Sistemas Anti-Fraude](https://github.com/eduschadesoares/sistemasOperacionais/blob/master/4%C2%BA%20Bimestre/Semin%C3%A1rio%20Seguran%C3%A7a%20Digital/Sistemas%20Anti-Fraude%20-%20Gustavo%20Turra%20e%20Mateus%20Loman.pdf) ([Gustavo Turra](https://github.com/gustavo-tp), Mateus Loman)
