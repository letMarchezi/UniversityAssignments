/* IMPLEMENTANDO REGISTROS DE TAMANHO FIXO COM CAMPOS DE TAMANHO FIXO */

/*

Autor  :  Emerson Junior Firmino
Revisor:  Diego Pereira Gimenez
Data   :  24/11/2003

OBJETIVO: Implementar rotinas de leitura, escrita e pesquisa em arquivos
          contendo registros de tamanho fixo com campos de tamanho fixo. */

   /* O tamanho de cada campo sera representado por uma constante. */
# define TAM_LAST 11    //tamanho do campo last name
# define TAM_FIRST 11   //tamanho do campo first name
# define TAM_ADDRESS 16 //tamanho do campo address
# define TAM_CITY 16    //tamanho do campo city
# define TAM_STATE 3    //tamanho do campo state
# define TAM_ZIP 10     //tamanho do campo zip
# define TAM_REG TAM_LAST+TAM_FIRST+TAM_ADDRESS+TAM_CITY+TAM_STATE+TAM_ZIP //tamanho de um registro

# include <stdio.h>  /* FUNCOES: fread, printf, putchar, gets, fwrite(),
                        DEFINICOES: FILE, */
# include <string.h> /* FUNCOES: strlen() */
# include <stdlib.h> /* FUNCOES: malloc(), */

/*    DEFINICAO DE UM REGISTRO DE TAMANHO FIXO COM CAMPOS DE TAMANHO FIXO */
   /* Registro que define os dados de uma pessoa */
typedef struct
{
   char last[TAM_LAST];        //sobrenome da pessoa
   char first[TAM_FIRST];      //nome da pessoa
   char address[TAM_ADDRESS];  //endereco da pessoa
   char city[TAM_CITY];        //cidade onde a pessoa mora
   char state[TAM_STATE];      //estado onde a pessoa mora
   char zip[TAM_ZIP];          //cep
} pessoa;

void ler(void);  /*Procedimento que le registros de tamanho fixo com campos de
                   tamanho fixo em um arquivo. */

void lerRegistro(pessoa *, char *);  /* Procedimento que transfere para a
estrutura pessoa um registro armazenado no buffer. */

void lerRegistroAux(char *, char *, int *, int);   //pega um campo do buffer e coloca na estrutura pessoa

void mostrarRegistro(pessoa);   // Mostra o registro na tela.

FILE *obterArquivo(char *);  /*Funcao que abre o arquivo aonde sera feita a
leitura de registros. */

void escrever(void); /*Procedimento que escreve registros de tamanho fixo com
                       campos de tamanho fixo em um arquivo. */

int recuperarRegistro(char *, FILE *); //recupera um registro do arquivo

void obterRegistro(char *); //obtem dados do teclado e os armazena no buffer de escrita

void obterCampo(char *, int);  //obtem um campo da estrutura pessoa e o coloca no buffer

void escreverRegistro(char *, FILE *);  //escreve o buffer no arquivo especificado

void pesquisar(void);    //visualiza um determinado campo de todos os registro no arquivo

int posicaoCampo(int, int[]); //calcula a posicao aonde um determinado campo comeca dentro do registro

int main(void)
{
   int opcao;  //ler, escrever ou pesquisar

   //clrscr();
   printf("IMPLEMENTAÇÃO USANDO REGISTROS DE TAMANHO FIXO COM CAMPOS DE"
          " TAMANHO FIXO:\n\n");

   printf("1 - Ler   2-Escrever   3-Pesquisar\n");
   printf("Digite a Opção (4 para terminar): ");
   scanf("%d",&opcao); //obter caractere do teclado
   putchar('\n');     //pula uma linha
   while(opcao != 4)  //enquanto a entrada for diferente de ESC...
   {
      switch(opcao)
      {
         case 1:  ler();
                    break;
         case 2:  escrever();
                    break;
         case 3:  pesquisar();
                    break;
         default:   printf("Opção Inválida! Digite Novamente.\n");
                    break;
      }//switch

      printf("1 - Ler\t2-Escrever\t3-Pesquisar\n");
      printf("Digite a Opção (4 para terminar): ");
      fflush(stdin);   //limpar o buffer de entrada e saida
      scanf("%d",&opcao); //obter caractere do teclado
      putchar('\n');     //pula uma linha
   }//while

   return 0;
}//main

void ler(void)
{
   pessoa umaPessoa;   /*cada registro lido sera armazenado
                        nessa estrutura para apresentacao na tela */
   FILE *arquivo;        //arquivo de onde sera lido os registros
   char buffer[TAM_REG]; //buffer utilizado para ler registros do arquivo

   arquivo = obterArquivo("rb");  //obtem arquivo para a leitura de registros

   /* enquanto nao for o fim do arquivo... */
   while(recuperarRegistro(buffer, arquivo))   //lendo registro inteiro do arquivo
   {
   	  fflush(stdin);
      lerRegistro(&umaPessoa, buffer);    //transfere os dados do buffer para a estrutura pessoa
      mostrarRegistro(umaPessoa);          //mostrar Registro na Tela
      getchar(); //getch();   //pressionar qualquer tecla para ver o proximo registro
   }//while

   putchar('\n');    //pula uma linha
   fclose(arquivo);  //fecha arquivo depois da leitura
}//le1

int recuperarRegistro(char *buffer, FILE *arquivo)
{
   return fread(buffer, TAM_REG, 1, arquivo);  //lendo registro do arquivo para buffer
}//recuperarRegistro

void lerRegistro(pessoa *umaPessoa, char *buffer)
{
   int inicioCampo = 0;  //armazena a posicao de inicio de um campo no buffer

       /* colocando campo last na estrutura pessoa */
   lerRegistroAux(umaPessoa->last, buffer, &inicioCampo, TAM_LAST);

       /* colocando campo first na estrutura pessoa */
   lerRegistroAux(umaPessoa->first, buffer, &inicioCampo, TAM_FIRST);

          /* colocando campo address na estrutura pessoa */
   lerRegistroAux(umaPessoa->address, buffer, &inicioCampo, TAM_ADDRESS);

       /* colocando campo city na estrutura pessoa */
   lerRegistroAux(umaPessoa->city, buffer, &inicioCampo, TAM_CITY);

          /* colocando campo city na estrutura pessoa */
   lerRegistroAux(umaPessoa->state, buffer, &inicioCampo, TAM_STATE);

          /* colocando campo city na estrutura pessoa */
   lerRegistroAux(umaPessoa->zip, buffer, &inicioCampo, TAM_ZIP);
}//obterRegistro

void lerRegistroAux(char *campo, char *buffer, int *inicioCampo, int tamanho)
{
   strncpy(campo, &buffer[*inicioCampo], tamanho);  //lendo campo
   campo[tamanho - 1] = '\0';  //colocando caractere de fim de string
   *inicioCampo += tamanho; //preparando para pegar proximo campo
}//lerRegistroAux

void mostrarRegistro(pessoa umaPessoa)
{
   printf("Registro:\n");
   printf("\t%s %s\n", "Último Nome:", umaPessoa.last);       //imprimindo last
   printf("\t%s %s\n", "Primeiro Nome:", umaPessoa.first);     //impriminndo first
   printf("\t%s %s\n", "Endereço:", umaPessoa.address); //imprimindo address
   printf("\t%s %s\n", "Cidade:", umaPessoa.city);       //imprimindo city
   printf("\t%s %s\n", "Estado:", umaPessoa.state);     //imprimindo state
   printf("\t%s %s\n\n", "CEP:", umaPessoa.zip);      //imprimindo zip
}//imprimirRegistro

FILE *obterArquivo(char *modoAbertura)
{
   char pathname[50]; //guarda o endereco do arquivo
   FILE * arquivo;    //arquivo de onde sera lido os registros

   printf("Digite o PathName do Arquivo: ");
   scanf("%s",pathname);  //obter pathname do teclado

   arquivo = fopen(pathname, modoAbertura);  //abrindo arquivo especificado por pathname

   while(NULL == arquivo)  //arquivo especificado nao existe
   {
      printf("Impossível Abrir o Arquivo Especificado. Digite Novamente.\n");
      printf("Digite o PathName do Arquivo: ");
      scanf("%s",pathname);  //obter pathname do teclado
      arquivo = fopen(pathname, modoAbertura);  //abrindo arquivo especificado por pathname
   }//while

   return arquivo;    //retornando o arquivo aberto
}//obterArquivo

void escrever(void)
{
   FILE * arquivo;    //arquivo onde serao escritos os registros
   int continua;     // indica se continua ou nao a escrever registros
   char buffer[TAM_REG] = "\0";  //buffer utilizado para escrevermos registros no arquivo

   arquivo = obterArquivo("ab");   //abrindo arquivo para escrita no fim do arquivo (append)

   if(NULL == arquivo)   //usuario deseja sair
   {
      return;
   }//if

   printf("1 - Escrever Registro\tOutra - Sair\n");
   scanf("%d",&continua);    //obter resposta do teclado
   putchar('\n');         //pula uma linha
   while (1 == continua)  //enquanto tiver registro a escrever...
   {
      obterRegistro(buffer);    //obter registro para escrever no arquivo
      escreverRegistro(buffer, arquivo);  //escrever registro no arquivo
      printf("1 - Escrever Registro\tOutra - Sair\n");
      scanf("%d",&continua);    //obter resposta do teclado
      putchar('\n');         //pula uma linha
   }//while

   fclose(arquivo);   //fecha arquivo depois de escrever registros
}//escrever

void obterRegistro(char *buffer)
{
   printf("Digite o Último Nome: ");
   obterCampo(buffer, TAM_LAST);

   printf("Digite o Primeiro Nome: ");
   obterCampo(buffer, TAM_FIRST);

   printf("Digite o Endereço: ");
   obterCampo(buffer, TAM_ADDRESS);

   printf("Digite a Cidade: ");
   obterCampo(buffer, TAM_CITY);

   printf("Digite o Estado: ");
   obterCampo(buffer, TAM_STATE);

   printf("Digite o CEP: ");
   obterCampo(buffer, TAM_ZIP);

   putchar('\n');    //pula uma linha
}//obterRegistro

void obterCampo(char *buffer, int tamanho)
{
   char bufferAux[TAM_REG];  //buffer utilizado para ler um campo do teclado
   char *espacoAdic;     //espaco restante de um campo que deve armazenado no buffer
   int i;   //variavel utilizada para acessar o array espacoAdic

   fflush(stdin);   //limpar o buffer de entrada e saida
   scanf("%[^\n]s",bufferAux);   //obtendo dados de um campo da estrutura pessoa
   strcat(buffer, bufferAux);  //colocando os dados do campo no fim do buffer

   espacoAdic = (char *) malloc(tamanho - strlen(bufferAux) + 1);

   for(i = 0; i < tamanho - strlen(bufferAux); i++)
   {
      espacoAdic[i] = ' ';
   }//for
   espacoAdic[i] = '\0';

   strcat(buffer, espacoAdic);
}//obterCampo

void escreverRegistro(char *buffer, FILE *arquivo)
{
    fwrite(buffer, TAM_REG, 1, arquivo);   //escrevendo o buffer no arquivo
    buffer[0] = '\0';  //preparando buffer para armazenar o proximo registro
}//escreverRegistro

void pesquisar(void)
{
   int opcao;           //determina o campo que deseja-se visualizar
   FILE * arquivo;      //arquivo onde deseja-se fazer a pesquisa
   int posicao;         //armazena a posicao do campo dentro do registro
   char campo[TAM_REG]; //armazenara o conteudo do campo lido do arquivo

    /* array que associa cada campo ao seu tamanho */
   int tamanhoCampo[6] = {TAM_LAST, TAM_FIRST, TAM_ADDRESS, TAM_CITY, TAM_STATE, TAM_ZIP};

   arquivo = obterArquivo("rb");   //obtendo arquivo para pesquisa

   //obtendo a opcao desejada
   printf("1 - Último Nome   2 - Primeiro Nome   3 - Endereço\n"
          "4 - Cidade   5 - Estado   6 - CEP\n");
   printf("Digite o Campo que Voce Deseja Visualizar: ");
   scanf( "%d", &opcao);

     /* descobrindo qual e a posicao do campo dentro do registro*/
   posicao = posicaoCampo(opcao, tamanhoCampo);

   printf("\nResultado da Pesquisa:\n");

   /* obtendo o campo escolhido */
   fseek(arquivo, posicao, SEEK_SET);
   while(fread(campo, tamanhoCampo[opcao - 1], 1, arquivo)) //lendo o campo escolhido no arquivo
   {
      campo[tamanhoCampo[opcao - 1] - 1] = '\0';  //colocando o caractere de fim de string
      printf("%s\n", campo);  //imprimindo o campo na tela

      /* obter o proximo registro*/
      fseek(arquivo, TAM_REG - tamanhoCampo[opcao - 1], SEEK_CUR);
   }//while

   putchar('\n');    //pula uma linha
   fclose(arquivo);   //fechando arquivo depois da pesquisa
}//pesquisar

int posicaoCampo(int campo, int tamanhoCampo[])
{
   int i;   //iterador
   int posicao = 0;   //armazenara a posicao onde o campo comeca dentro do registro

     /* procurar pela posicao do campo dentro do registro */
   for(i = 0; i < (campo - 1); i++)
   {
      posicao += tamanhoCampo[i];
   }//for

   return posicao;
}//posicaoCampo


