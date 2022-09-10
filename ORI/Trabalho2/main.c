/*
Trabalho Prático 2
Disciplina: Organização e Recuperação da Informação
Professor: Ricardo Cerri
Nome: Júlia Aparecida Sousa de Oliveira RA:769707
Nome: Leticia Bossatto Marchezi         RA:791003
Nome: Mateus Grota Nishimura Ferro      RA:771043
*/
/*
O programa deve ser capaz de criar uma árvore B com grau
mínimo (valor de t) arbitrário, que deve ser passado como parâmetro para o procedimento inicial que cria a árvore.
-> busca: recebe chave a ser localizada, retorna o nó e índice i da posição. Se não, mensagem "CHAVE NÃO ENCONTRADA!"
->inserção: parâmetro chave a ser inserida. Inserir em nó folha. Retorna o nó e índice i da posição.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definindo o no
typedef struct node{
  int qtde;    // total de key
  int folha;   // 1 se é folha; 0 se não é folha
  int *key;    // key
  struct node **filho;
}Node;

// Assinatura das funções
void menu();
int buscaArvore(Node *, int);
void insere(Node *, int, int);
void divideFilho(Node *, int, int);
void testaInsere(Node **, int, int);
Node* novoNo(int);
void mostraArvore(Node*, int, int);
void liberaArvore(Node*, int);

int main(){
  int op=1, t, num;
  Node * arvore;

  // Criação da árvore com grau t
  printf("Digite o grau da arvore: ");
  scanf("%d", &t);
  arvore = novoNo(t);
  
  // Menu de operações
  while(op!=0){
    menu();
    scanf("%d", &op);
    switch(op){
      // Sai do menu
      case 0:
        printf("Saindo...\n");
        break;
      // Insere um número na árvore
      case 1:
        printf("Digite o numero inteiro para inserir: ");
        scanf("%d", &num);
        testaInsere(&arvore, num, t);
        break;
      // Busca na árvore
      case 2:
        printf("Digite o numero para buscar: ");
        scanf("%d", &num);
        int busca = buscaArvore(arvore, num);
        if(busca == -1){
          printf("CHAVE NÃO ENCONTRADA!\n");
        }
        else
          printf("Numero encontrado, indice: %d\n", busca);
        break;
      // Mostra a árvore  
      case 3:
        printf("Imprimindo a arvore...\n");
        mostraArvore(arvore, t, 0);
        break;
      // Outras opções
      default:
        printf("Opcao invalida. Tente novamente\n");
        break;
      
    }
    printf("_________________________\n");
  }
  // Libera a memoria alocada na arvore
  liberaArvore(arvore, t);
}

// Menu que mostra opções de operações
void menu(){
  printf("\n       MENU       \n");
  printf("1 - INSERIR NA ÁRVORE\n");
  printf("2 - BUSCA NA ÁRVORE\n");
  printf("3 - MOSTRAR ARVORE\n");
  printf("0 - SAIR \n");
  printf("\n");
  printf("Opcao: ");
}

// Cria um novo no alocando a memoria 
Node* novoNo(int t){
  Node* arv;
  
  // Aloca o ponteiro da arvore
  arv = (Node*)malloc(sizeof(Node));
  // Aloca a memória para as 2*t-1 keys
  arv->key = (int*)malloc((2*t-1) * sizeof(int));
  // Atribui 1 a folha
  arv->folha = 1;
  // Quantidade inicial de keys é zero
  arv->qtde = 0;
  // Aloca a memória para os 2*t filhos possiveis
  arv->filho = malloc(sizeof(Node *)*2*t);
  return arv;
}

// Usa ponteiro de ponteiro para inserir o novo número 
void testaInsere(Node** arv, int ch, int t){
  // Testa se a raiz da arvore está cheia
  if((*arv)->qtde == (2*t-1)){ 
    // Cria um novo nó para ser a raiz
    Node *r = *arv;
    Node *novo = novoNo(t);
    *arv = novo;
    novo->folha = 0;
    // A antiga raiz é agora filho do novo nó
    novo->filho[0] = r;
    // Divide filho cheio em outro filho 
    divideFilho(novo, 0, t);
    // Insere o número árvore com novo nó
    insere(novo, ch, t);
  }
  else
  // Insere o número na árvore
    insere(*arv, ch, t);
}

// Insere o número na árvore
void insere(Node *novo, int ch, int t){
  int i = novo->qtde-1;
  
  // Se o nó for folha então insere diretamente de forma ordenada
  if(novo->folha){
    while(i >= 0 && ch < novo->key[i]){
      novo->key[i+1] = novo->key[i];
      i--;
    }
    // Insere a key e aumenta o contador de quantidade
    novo->key[i+1] = ch;
    novo->qtde++;
    printf("Inserindo %d no indice: %d \n",novo->key[i+1], i+1);
  }
  // Se o no não for folha
  else{
    // Atualiza o indice i para a inserção ser ordenada
    while(i >= 0 && ch < novo->key[i]){
      i--;
    }
    i++;
    // Se o filho de indice i estiver cheio
    if(novo->filho[i]->qtde == 2*t-1){
      // divide o filho em outro nó
      divideFilho(novo, i, t);
      if(ch > novo->key[i])
        i=i+1;
    }
    // Chama recursivamente a função para inserir a chave no filho
    insere(novo->filho[i], ch, t);
    printf("Inserindo %d no indice: %d \n",novo->key[i+1], i+1);
  }
}

// Divide os filhos  
void divideFilho(Node *arv, int i, int t){
  // Cria ponteiros para novo nó
  Node *z = novoNo(t);
  // Cria ponteiro para o filho com indice i do parâmetro
  Node *y = arv->filho[i];
  int j;

  // Atribui nó z aos valores após a mediana do filho cheio 
  z->folha = y->folha;
  z->qtde = t - 1;
  for(j=0;j<t-1;j++){
    z->key[j] = y->key[j+t];
  }
  // Se o filho do nó não for uma folha atribui ao novo nó
  // o filho de indice j+t
  if(!y->folha){
    for(j=0; j<t; j++){
      z->filho[j] = y->filho[j+t];
    }
  }
  // Atualiza o valor do nó após a criação do novo nó
  y->qtde = t-1;
  
  // Se a raiz tiver keys
  for(j=arv->qtde+1; j>i+1; j--){
    // Desloca os filhos para a esquerda
    arv->filho[j+1] = arv->filho[j];
  } 
  // Atribui como filho o nó com as novas chaves
  arv->filho[i+1] = z;
  // Se a raiz tiver keys
  for(j=arv->qtde; j>i; j--) {
    // Desloca todas a chaves para a direita
    arv->key[j+1] = arv->key[j];
  } 
  // Passa a chave mediana para a raiz
  arv->key[i] = y->key[t-1];
  // Soma o contador de quantidade de chaves
  arv->qtde= arv->qtde + 1;
}

// Busca o número na árvore
int buscaArvore(Node *x, int busca){
  // Contador
  int i = 0;

  // Enquanto houverem chaves e o número for menor do que a chave
  while(i < x->qtde && busca > x->key[i]){
    // Soma o contador
    i++;
  }
  // Achou a chave
  if(busca == x->key[i])
    return i; 
  // Caso não haja filho a busca é encerrada com erro  
  else if(x->folha)
    return -1;
  // Chama recursivamente para buscar o número no filho  
  else 
    return buscaArvore(x->filho[i], busca);
}

// Mostra a árvore em sua estrutura
void mostraArvore(Node* node, int t, int l) {
  // Identação
  for (int i=0; i<l; i++)
    printf(" ");

  // Imprime as chaves
  printf("[ ");
  for (int i=0; i < 2*t-1; i++)
    // Mostra as chaves
    if (i < node->qtde)
      printf("%d ", node->key[i]);
    else // Imprime X para chaves não existentes
      printf("X ");
  printf("]\n");

  // Chama recursivamente a função para imprimir os filhos
  if (!node->folha)
    for (int i=0; i < node->qtde+1; i++)
      mostraArvore(node->filho[i], t, l+1);
}

// Libera a memória alocada na árvore
void liberaArvore(Node* arv, int t){
  // Libera a memória das chaves
  free(arv->key);
  
  // Chama recursivamente a função para os filhos
  if(!arv->folha){
    for(int j=0; j < 2*t-1; j++){
      liberaArvore(arv->filho[j], t);
    }
  }
  // Libera o nó
  free(arv);
}