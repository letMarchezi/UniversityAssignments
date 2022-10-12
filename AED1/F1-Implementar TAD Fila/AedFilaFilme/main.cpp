/*
Nome: Leticia Bossatto Marchezi
RA: 791003
Turma: Bacharelado em Ciência da Computacao 020
Prof. Dr. Roberto Ferrari Junior
Materia: Algoritmo e Estrutura de Dados
Objetivo: arquivo principal de testes da classe Fila

*/

#include "Fila.h"
#include <iostream>
#include <cstdio>

// Metodo para impressao da fila
void imprimeFila(Fila filmes){
    // Criação de variáveis auxiliares
    string temp;
    bool resultado;
    int cont=0;
    // Se a fila esta vazia imprime um erro
    if(filmes.Vazia()){
        cout<<"A fila esta vazia. Nao existem elementos a serem mostrados."<<endl<<endl;
    }
    else{
        cout<<"Imprimindo a fila: "<<endl;
        // Enquanto a fila não estiver vazia, retira os elementos e imprime na tela
        while(!filmes.Vazia()){
            filmes.Retira(temp, resultado);
            if(resultado){
                // Se a operacao retira foi bem sucesidade, imprime a fila 
                cout<<"Posicao: "<<cont<<"      Nome: "<<temp<<endl;
                cont++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    
    int caso=1;
    bool resultado;
    Fila filaFilmes=Fila();
    string registroFilme;
    // Menu de testes
    while((caso>=1)&&(caso<=5)){
        cout<<"----------------------------------------------"<<endl;
        cout<<"1- Adicionar um filme a fila"<<endl;
        cout<<"2- Retirar um elemento da fila"<<endl;
        cout<<"3- Mostrar se a fila esta cheia"<<endl;
        cout<<"4- Mostrar se a fila esta vazia"<<endl;
        cout<<"5- Imprimir a fila"<<endl;
        cout<<"0- Para sair"<<endl;
        cout<<"Digite a operacao que deseja realizar: "<<endl;
        cin>>caso;
        cout<<"----------------------------------------------"<<endl;

        switch(caso){
            // Insercao de elemento na fila
            case 1:
                cout<<"Salvando:"<<endl;
                if(!filaFilmes.Cheia()){
                    cout<<"Digite o nome do filme a ser salvo: "<<endl;
                    cin.ignore();
                    getline(cin, registroFilme);
                    filaFilmes.Insere(registroFilme, resultado);
                    if(resultado){
                        cout<<"Salvo!"<<endl<<endl;
                    }else{
                        cout<<"Erro."<<endl;
                    }
                }else{
                    cout<<"A fila esta cheia. Nao foi possivel inserir o elemento."<<endl<<endl;
                }
                
                break;
            // Retirada de elemento da fila
            case 2:
                cout<<"Retirando..."<<endl;
                filaFilmes.Retira(registroFilme, resultado);
                if(resultado){
                    cout<<"Nome do filme retirado: "<<registroFilme<<endl<<endl;
                }else{
                    cout<<"Erro ao retirar, a fila esta vazia"<<endl<<endl;
                }
                break;
            // Imprime se a fila esta cheia
            case 3:
                if(filaFilmes.Cheia()){
                    cout<<"A fila esta cheia!"<<endl<<endl;
                }else{
                    cout<<"Nao esta cheia"<<endl<<endl;
                }
                break;
            // Imprime se a fila esta vazia 
            case 4:
                if(filaFilmes.Vazia()){
                    cout<<"Vazia!"<<endl<<endl;
                }else{
                    cout<<"Nao esta vazia"<<endl<<endl;
                }
                break;

            case 5:
                imprimeFila(filaFilmes);
                break;

            default:
                cout<<"Saindo do programa..."<<endl<<endl;

        }
        // COMANDO OPCIONAL, ATIVAR APENAS AO COMPILAR NO WINDOWS
        // system("pause");
        
    }

    return 0;
    
}


