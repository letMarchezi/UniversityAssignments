#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// --------------------------------------- UTILS ---------------------------------------

unsigned convert(char *s)
{
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++)
        h = h * 256 + s[i];

    return h;
}

unsigned hashFunc(unsigned x, unsigned B)
{
    return x % B;
}

void printScores(int *scores, int M)
{
    for (int i = 0; i < M; i++)
    {

        printf("%d\n", scores[i]);
    }
}

// --------------------------------------- END UTILS ---------------------------------------


// --------------------------------------- HASH ---------------------------------------

#define MAX_STRING_LEN 50

typedef struct node
{
    char data[MAX_STRING_LEN];
    int val;
    struct node *next;
}node;

typedef struct node *List;
typedef struct node no;

typedef struct hash
{
    unsigned TAM;
    List *val;
} hash;

typedef struct hash Hash;


List *createList(unsigned TAM)
{
    List *li = (List *)malloc(TAM * sizeof(List));
    if (li != NULL)
    {
        for(int i=0; i< TAM; i++)
        {
            li[i] = NULL;
        }
    }

    return li;
}

void deleteList(List *li, int TAM)
{
    if (li != NULL)
    {
        for (int i = 0; i < TAM; i++)
            free(li[i]);

        free(li);
    }
}

int insereLista(List *li, char* data, int valData)
{
    int houveColisao = 0;
    no *newNode = (no *)malloc(sizeof(no));
    strcpy(newNode->data, data);
    newNode->val = valData;

    if ((*li) != NULL) //Se a lista nao apontar pra NULL eh pq teve colisao.
        houveColisao = 1;

    newNode->next = (*li);
    (*li) = newNode;

    return houveColisao;
}

int buscaLista(node *ptr, char* data)
{
    while (ptr != NULL)
    {
        if (strcmp(ptr->data, data) == 0)
            return ptr->val;

        ptr = ptr->next;
    }

    return -1;
}


//Cria a tabela Hash
Hash *createHash(unsigned TAM)
{
    Hash *h = (Hash *)malloc(sizeof(Hash));
    if (h != NULL)
    {
        h->TAM = TAM;
        h->val = createList(TAM);
        if (h->val == NULL)
            exit(1);
    }
    return h;
}

void deleteHash(Hash *h)
{
    if (h == NULL)
        return;
    for (int i = 0; i < h->TAM; i++)
    {
        if (h->val[i] != NULL)
            free(h->val[i]);
    }
    free(h->val);
    free(h);
}

int buscaHash(Hash *h, char* data)
{
    if (h == NULL)
        return -1;
    

    int pos = hashFunc(convert(data), h->TAM);

    //Busca na lista da posicao da tabela
    int valueRetrived = buscaLista(h->val[pos], data);

    if (valueRetrived != -1)
        return valueRetrived;
    
    return -1;
}


int insereHash(Hash *h, char* data, int valData)
{
    if (h == NULL)
        return -1;

    int pos = hashFunc(convert(data), h->TAM);

    // Verificar se o dado ja existe no Hash para nao inserir duas vezes
    int valFound = buscaLista(h->val[pos], data);
    if (valFound == valData)
        return 0;

    // Inserir na Lista, se retornar 0 nao houve colisao.    
    if(!insereLista(&h->val[pos], data, valData) )
        return 0;

    return 1;
}

void printList(node *ptr)
{
    while(ptr != NULL)
    {
        printf("[Data: %s - valData: %d]; ->  ", ptr->data, ptr->val);
        ptr = ptr->next;
    }
}

void printHash(Hash *h)
{
    for(int i=0; i<h->TAM; i++)
    {
        printf("h[%d]-> ", i);
        printList(h->val[i]);
        printf("\n");
    }
}


// --------------------------------------- END HASH ---------------------------------------


// --------------------------------------- READER ---------------------------------------

void ReadNWords(Hash *h, int N)
{
    int ammtToRead = N;
    char *wordRead;
    wordRead = (char *)malloc(256 * sizeof(char));
    int pontuation = 0;

    while (ammtToRead > 0)
    {
        scanf("%s", wordRead);
        scanf("%d", &pontuation);

        insereHash(h, wordRead, pontuation);

        ammtToRead--;
    }

    free(wordRead);
}

void ReadAndParseText(Hash *h, int M, int *scores)
{
    // Read text and search words in hash table
    int amtToRead = M;
    char *wordRead;
    wordRead = (char *)malloc(256 * sizeof(char));

    int scorePos = 0;

    while (amtToRead > 0)
    {
        scanf("%s", wordRead);
        while (strcmp(wordRead, ".") != 0)
        {
            int scorePontuation = buscaHash(h, wordRead);

            if (scorePontuation != -1)
                scores[scorePos] += scorePontuation;

            else
                scores[scorePos] -= 10;

            scanf("%s", wordRead);
        }

        amtToRead--;
        scorePos++;
    }
    free(wordRead);
}

// --------------------------------------- END READER ---------------------------------------




int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int *scores;
    scores = (int*)malloc(M*sizeof(int));
    for(int i=0; i<M; i++)
        scores[i] = 0;

    Hash *h = createHash(N);

    // Ler as N palavras e suas pontuacoes e inserir na tabela hash
    ReadNWords(h, N);
   
    ReadAndParseText(h,M,scores);

    printScores(scores, M);

    deleteHash(h);

    free(scores);
    
    return 0;
}