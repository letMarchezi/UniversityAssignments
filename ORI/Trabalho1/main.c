/*
Trabalho Prático 1 - Tipo 1
Nome: Júlia Aparecida Sousa de Oliveira RA:769707
Nome: Leticia Bossatto Marchezi         RA:791003
Nome: Mateus Grota Nishimura Ferro      RA:771043
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAM_KEY 8                                                                                         // tamanho do campo key
#define TAM_LAST 11                                                                                       // tamanho do campo last name
#define TAM_FIRST 11                                                                                      // tamanho do campo 1 nome
#define TAM_ADDRESS 16                                                                                    // tamanho do campo endereco
#define TAM_CITY 16                                                                                       // tamanho do campo cidade
#define TAM_STATE 3                                                                                       // tamanho do campo estado
#define TAM_ZIP 10                                                                                        // tamanho do campo zip
#define TAM_PHONE 14                                                                                      // tamanho do campo telefone
#define TAM_REG TAM_LAST + TAM_FIRST + TAM_ADDRESS + TAM_CITY + TAM_STATE + TAM_ZIP + TAM_PHONE + TAM_KEY // tamanho registro

typedef struct
{
    char key[TAM_KEY];          // chave que identifica a pessoa
    char last_name[TAM_LAST];   // sobrenome da pessoa
    char first_name[TAM_FIRST]; // nome da pessoa
    char address[TAM_ADDRESS];  // endereco da pessoa
    char city[TAM_CITY];        // cidade onde a pessoa mora
    char state[TAM_STATE];      // estado onde a pessoa mora
    char zip[TAM_ZIP];          // cep
    char phone[TAM_PHONE];      // telefone
} pessoa;


char *limpar_string(char *str);                    // função que limpa os espaços em branco de uma string, usada para comparação
FILE *obterArquivo(char *modoAbertura, int abrir); // função que abre o arquivo e testa se deu certo
void ler();
void obterCampo(char *buffer, int tamanho);
void escrever();
void obterRegistro(char *buffer);
void mostrarRegistro(pessoa umaPessoa);
void lerRegistroAux(char *campo, char *buffer, int *inicioCampo, int tamanho);
void lerRegistro(pessoa *umaPessoa, char *buffer);
void busca(char *nome, int op);
void buscaRRN(int num);
int recuperarRegistro(char *buffer, FILE *arquivo);
int remover(char *str);
int removerRegistro(int RRN);
int buscaRemovido(FILE *arquivo);


int main(void)
{
    char key[TAM_KEY];
    int op = 1;
    int RRN;
    while (op != 0) // loop que roda enquanto o usuário não digitar 0
    {
        printf("--------------- MENU ---------------\n");
        printf("1 - ESCREVER \n");
        printf("2 - LER \n");
        printf("3 - BUSCA PELO PRIMEIRO NOME\n");
        printf("4 - BUSCA PELA KEY\n");
        printf("5 - BUSCA PELO NUMERO DO REGISTRO\n");
        printf("6 - REMOÇÃO PELO RRN\n");
        printf("0 - SAIR \n");
        printf("------------------------------------\n");
        printf("Opção: ");
        scanf("%d", &op);
        switch (op)
        {
        // escreve o registro de uma pessoa no arquivo
        case 1: 
            escrever();
            break;

        // le todos os registros do arquivo
        case 2: 
            ler();
            break;

        // procura pelo nome de uma pessoa no arquivo
        case 3: 
            printf("Digite o nome para procurar pelo registro:");
            char name[TAM_FIRST];
            scanf("%s", name);
            busca(name, 1);
            break;

        // procura por uma key no arquivo
        case 4: 
            printf("Digite a key para procurar pelo registro:");
            scanf("%s", key);
            busca(key, 2);
            break;

        // procura pelo RRN do registro no arquivo
        case 5: 
            printf("Digite o número do registro para procurar:");
            scanf("%d", &RRN);
            RRN--;
            buscaRRN(RRN);
            break;

        // dado um RRN apaga o registro correspondente no arquivo
        case 6: 
            printf("Digite o RRN para procurar para apagar:");
            fflush(stdin);
            scanf("%d", &RRN);
            removerRegistro(RRN);
            break;

        // finaliza o programa
        case 0: 
            printf("Finalizando o programa\n");
            break;

        // opcoes invalidas
        default:
            printf("Opcao invalida! Digite uma opcao existente.\n\n");
            break;
        }
    }
}

FILE *obterArquivo(char *modoAbertura, int criar)
{
    char pathname[50]; //caminho para o arquivo
    FILE *arquivo; //ponteiro para o arquivo que sera aberto

    printf("Digite o PathName do Arquivo: ");
    scanf("%s", pathname);

    //tentativa de abrir o arquivo
    arquivo = fopen(pathname, modoAbertura);

    // verifica se conseguiu abrir e se o arquivo não existe deve ser criado
    if (arquivo == NULL && criar)
    {
        arquivo = fopen(pathname, "ab");
    }

    // se não conseguiu abrir, faz com que o usuário digite novamente outro caminho
    while (NULL == arquivo) //arquivo especificado nao existe
    {
        printf("Impossível Abrir o Arquivo Especificado. Digite Novamente.\n");
        printf("Digite o PathName do Arquivo: ");
        scanf("%s", pathname);                   //obter pathname do teclado
        arquivo = fopen(pathname, modoAbertura); //abrindo arquivo especificado por pathname
    }
    return arquivo; //retorna o ponteiro para o arquivo aberto
}

//funcao que verifica se a key ja foi inserida em registros anteriores
int validarKey(FILE *arquivo, char *chave)
{
    int valido = 1;
    char buffer[TAM_REG] = "\0";
    pessoa umaPessoa;
    char aux = *chave;
    //le todos os registros do arquivo especificado
    while (recuperarRegistro(buffer, arquivo))
    {
        fflush(stdin);
        lerRegistro(&umaPessoa, buffer); //buffer que ira armazenar os registros do arquivo

        //caso encontre uma key presente no arquivo, mostra registro com key igual e impede inserçao
        if (!strcmp(limpar_string(umaPessoa.key), limpar_string(&aux)))
        {
            printf("Essa key já existe!\n\n");
            valido = 0;
            mostrarRegistro(umaPessoa);
        }
        buffer[0] = '\0';
    }

    return valido;
}
//o que faz?
int buscaRemovido(FILE *arquivo)
{
    int contador = 0;
    char buffer[TAM_REG] = "\0";
    fflush(stdin);
    fseek(arquivo, 0, SEEK_SET);
    while (recuperarRegistro(buffer, arquivo))
    {
        
        if (buffer[0] == '*')
        {
            break;
        }
        contador++;
        
    }
    return contador;
}

void escrever(void)
{
    FILE *arquivo;
    int op = 1;                  //variavel que indica se o usuario quer escrever mais que um registro
    int posicao = 0;            //contador da posicao do registro
    char buffer[TAM_REG] = "\0"; //buffer que armazena os registros que serao armazenados no arquivo

    arquivo = obterArquivo("r+b", 1); //abrindo arquivo para escrita e leitura

    if (arquivo == NULL) //se nao abriu o arquivo encerra o método
    {
        return;
    }

    while (op == 1) //loop para receber os campos do registro
    {
        printf("Digite o código KEY: ");
        obterCampo(buffer, TAM_KEY);
        printf("\n");

        //testa se a key ja existe no arquivo
        if (validarKey(arquivo, buffer)){
            //busca se ha registro removido
            posicao = buscaRemovido(arquivo);
            obterRegistro(buffer); //obtem registro
            //se ha registro removido insere no seu lugar, senao insere no final
            fseek(arquivo, (89 * posicao), SEEK_SET);
            fwrite(buffer, TAM_REG, 1, arquivo);
        }
        buffer[0] = '\0';
        printf("\n----------------------------------------\n");
        
        //verifica se o usuario quer inserir mais registros
        printf("1 - Escrever Registro\tOutra - Sair\n");
        scanf("%d", &op);
        putchar('\n');
    }
    fclose(arquivo); //fecha arquivo
}
//funcao que obtem um registro
void obterRegistro(char *buffer)
{

    printf("Digite o Último Nome: ");
    obterCampo(buffer, TAM_LAST);
    printf("\n");

    printf("Digite o Primeiro Nome: ");
    obterCampo(buffer, TAM_FIRST);
    printf("\n");

    printf("Digite o Endereço: ");
    obterCampo(buffer, TAM_ADDRESS);
    printf("\n");

    printf("Digite a Cidade: ");
    obterCampo(buffer, TAM_CITY);
    printf("\n");

    printf("Digite o Estado: ");
    obterCampo(buffer, TAM_STATE);
    printf("\n");

    printf("Digite o CEP: ");
    obterCampo(buffer, TAM_ZIP);
    printf("\n");

    printf("Digite o telefone: ");
    obterCampo(buffer, TAM_PHONE);
    putchar('\n');
}

//obtem cada campo individualmente
void obterCampo(char *buffer, int tamanho)
{
    char bufferAux[tamanho]; //buffer do campo que sera recebido
    char *espacoAdic;        //espaco restante que nao foi utilizado pelo usuário
    int i;

    fflush(stdin);
    scanf("%s", bufferAux); //recebe o campo
    // REALMENTE NECESSÁRIO?
    strcat(buffer, bufferAux); //concatena o campo recebido com o espaco restante

    //aloca dinamicamente o tamanho do campo
    espacoAdic = (char *)malloc(tamanho - strlen(bufferAux) + 1);
    for (i = 0; i < tamanho - strlen(bufferAux); i++)
    {
        espacoAdic[i] = ' '; //adiciona espaco em branco no array de espaco restante
    }

    espacoAdic[i] = '\0';
    strcat(buffer, espacoAdic); //concatena o campo recebido com o espaco restante
}

void ler(void)
{
    pessoa umaPessoa; //variavel para o registro de uma pessoa
    FILE *arquivo; //ponteiro para o arquivo que sera usado
    char buffer[TAM_REG]; //buffer utilizado para armazenar os registros do arq

    //tenta abrir o arquivo em modo de leitura
    arquivo = obterArquivo("rb", 0);

    //le todos os registros no arquivo, enquanto nao encontrar o final
    while (recuperarRegistro(buffer, arquivo))
    {
        fflush(stdin);
        lerRegistro(&umaPessoa, buffer); //armazena os registros lidos na struct umaPessoa
        mostrarRegistro(umaPessoa);      //mostra o registro
    }
    putchar('\n');
    fclose(arquivo); //fecha o arquivo
}

//funcao invocada na funcao ler, obtem registro de uma pessoa
void lerRegistro(pessoa *umaPessoa, char *buffer)
{
    int inicioCampo = 0; //armazena a posicao em que parou a leitura de um campo

    // campo key
    lerRegistroAux(umaPessoa->key, buffer, &inicioCampo, TAM_KEY);

    // campo ultimo nome
    lerRegistroAux(umaPessoa->last_name, buffer, &inicioCampo, TAM_LAST);

    // campo primeiro nome
    lerRegistroAux(umaPessoa->first_name, buffer, &inicioCampo, TAM_FIRST);

    // campo endereço
    lerRegistroAux(umaPessoa->address, buffer, &inicioCampo, TAM_ADDRESS);

    // campo cidade
    lerRegistroAux(umaPessoa->city, buffer, &inicioCampo, TAM_CITY);

    // campo estado
    lerRegistroAux(umaPessoa->state, buffer, &inicioCampo, TAM_STATE);

    // campo cep
    lerRegistroAux(umaPessoa->zip, buffer, &inicioCampo, TAM_ZIP);

    // campo telefone
    lerRegistroAux(umaPessoa->phone, buffer, &inicioCampo, TAM_PHONE);
}

void lerRegistroAux(char *campo, char *buffer, int *inicioCampo, int tamanho)
{
    strncpy(campo, &buffer[*inicioCampo], tamanho); //lendo campo
    campo[tamanho - 1] = '\0';                      //colocando caractere de fim de string
    *inicioCampo += tamanho;                        //preparando para pegar proximo campo
}

//funcao para receber os registros do arquivo
int recuperarRegistro(char *buffer, FILE *arquivo)
{
    return fread(buffer, TAM_REG, 1, arquivo); //le 1 registro do arquivo para o buffer
}

//imprime registro na tela
void mostrarRegistro(pessoa umaPessoa)
{
    printf("Registro:\n");
    printf("\t%s %s\n", "Key: ", umaPessoa.key);
    printf("\t%s %s\n", "Último Nome: ", umaPessoa.last_name);
    printf("\t%s %s\n", "Primeiro Nome: ", umaPessoa.first_name);
    printf("\t%s %s\n", "Endereço: ", umaPessoa.address);
    printf("\t%s %s\n", "Cidade: ", umaPessoa.city);
    printf("\t%s %s\n", "Estado: ", umaPessoa.state);
    printf("\t%s %s\n", "CEP: ", umaPessoa.zip);
    printf("\t%s %s\n\n", "Telefone: ", umaPessoa.phone);
}

//funcao auxiliar que remove os espacos em branco de uma string
char *limpar_string(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

//funcao de busca pelo nome ou key
void busca(char *entrada, int op)
{
    pessoa umaPessoa; //struct que armazenara o registro encontrado
    FILE *arquivo; //ponteiro para o arquivo que sera usado
    char buffer[TAM_REG]; //buffer que armazenara o registro do arquivo
    int achou = 0; //flag indicando que encontrou o registro procurado
    
    //abre o arquivo em modo de leitura
    arquivo = obterArquivo("rb", 0);

    //loop que ira percorrer todos os registros do arquivo
    while (recuperarRegistro(buffer, arquivo))
    {
        fflush(stdin);
        lerRegistro(&umaPessoa, buffer); //le o registro

        //se a busca for pelo nome
        //compara os nomes dos registros com o nome procurado
        if (op == 1 && !strcmp(limpar_string(umaPessoa.first_name), entrada))
        {
            achou = 1;
            mostrarRegistro(umaPessoa);
        }
        //se a busca for pela key
        //compara as keys dos registros com a key procurada
        else if (op == 2 && !strcmp(limpar_string(umaPessoa.key), entrada))
        {
            achou = 1;
            mostrarRegistro(umaPessoa);
        }
    }
    //caso o registro procurado nao tenha sido encontrado pelo loop de busca
    if (achou != 1)
    {
        printf("Não foi encontrado nenhum registro com este nome");
    }

    putchar('\n');
    fclose(arquivo); //fecha o arquivo
}

//funcao de busca pelo RRN do registro no arquivo
void buscaRRN(int RRN)
{
    FILE *arquivo; //ponteiro para o arquivo que sera usado
    pessoa umaPessoa; //struct que armazenara o registro encontrado
    char buffer[TAM_REG]; //buffer que armazenara o registro do arquivo


    arquivo = obterArquivo("rb", 0); //abre o arquivo em modo de leitura
    int byte = (RRN+1) * 89; //multiplica o RRN pelo tamanho total de cada registro
    fseek(arquivo, byte, SEEK_SET); //desloca para o byte obtido pela multiplicacao
    fread(buffer, TAM_REG, 1, arquivo); //le o registro do RRN especificado para o buffer

    fflush(stdin);
    lerRegistro(&umaPessoa, buffer); //le o registro do buffer dentro da struct
    mostrarRegistro(umaPessoa); //mostra o registro

    fclose(arquivo); //fecha o arquivo
}
//remove registro dado seu RRN
int removerRegistro(int RRN)
{
    FILE *arquivo; //ponteiro para o arquivo que sera usado
    char buffer[TAM_REG]; //buffer que armazenara o registro do arquivo
    arquivo = obterArquivo("r+b", 0); // abre o arquivo para leitura e gravação

    // move o ponteiro do inicio ate o RRN desejado para ler o registro
    fseek(arquivo, RRN * 89, SEEK_SET); //desloca até encontrar o RRN especificado
  
    //salva o registro no buffer
    fread(buffer, TAM_REG, 1, arquivo);
    //insere o caractere * identificando registro removido logicamente
    buffer[0] = '*';

    //volta uma posição e substitui o registro
    fseek(arquivo, -(89), SEEK_CUR);
    fwrite(buffer, 1, TAM_REG, arquivo);

    //fecha o arquivo
    fclose(arquivo);
    return 0;
}
