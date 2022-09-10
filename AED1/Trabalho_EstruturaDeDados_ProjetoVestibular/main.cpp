#include "filaMatricula.h"
#include <string>

typedef struct pscurso{
  ListaCandidato * inscricao;
  ClassificacaoCandidato * classificacao;
  FilaMatricula * matricula;
  Curso curso;
} psCurso;

void caseCandidatos();
void caseClassificados();
void mostrarCursos(Curso cursos[], int numCursos);
void cadastrarCursos(Curso cursos[], int numCursos, psCurso listas[]);
int existeCurso(int codCurso, int qtdeCursos);


int main() {
  
  bool erro;
  int contador, codCurso, qtdVagas, opcaoMenu, codInsc;
  int contadorCandidatos = 0;
  Candidato cand1, *cand2;

  int qtdeCursos;
  cout << "Quantos cursos voce deseja cadastrar?" << endl;
  cin >> qtdeCursos;
  while(qtdeCursos <= 0){
    cout << "Digite um número maior que 0!" << endl;
    cin >> qtdeCursos;
  }

  Curso * cursos = new Curso[qtdeCursos];
  psCurso * listas = new psCurso[qtdeCursos];

  cadastrarCursos(cursos, qtdeCursos, listas);
  mostrarCursos(cursos, qtdeCursos);

  while(opcaoMenu != 0){
    cout << endl << endl;
    cout << "----------- SISTEMA VESTIBULAR ------------"<< endl;
    cout << "Entre com a acao desejada:" << endl;
    cout << "1 - Cursos" << endl;
    cout << "2 - Inscritos" << endl;
    cout << "3 - Classificacao" << endl;
    cout << "4 - Matricula" << endl;
    cout << "0 - Encerrar sistema" << endl;
    cout << "Opcao escolhida: "; 
    cin >> opcaoMenu;
    cout << "-------------------------------------------"<< endl<<endl;
    
    switch(opcaoMenu) {

      case 0:
        cout<<"Obrigado pela preferencia, volte sempre!"<<endl;
        cout<<"Saindo do sistema..."<<endl;
        break;

      case 1: // mostrar cursos cadastrados
        mostrarCursos(cursos, qtdeCursos);
        break;
        
      case 2: { // opcoes da listaCandidato
        int op = 1;
      
        while (op)
        {
          cout << "------------ MENU DE CANDIDATOS -----------" << endl;
          cout << "Escolha entre as opcoes:" << endl;
          cout << "1 - Inserir candidatos." << endl;
          cout << "2 - Remover candidato." << endl;
          cout << "3 - Remover todos candidatos." << endl;
          cout << "4 - Mostrar candidatos." << endl;
          cout << "5 - Mais detalhes das funcionalidades." << endl;
          cout << "0 - Sair desse Menu" << endl;
          cout << "Opcao escolhida: "; 
          cin >> op;
          cout << "-------------------------------------------" << endl<<endl;
          switch (op){
          case 0:
            break;
          
          case 1: // inserir candidatos
            int numCandidatos;
            cout << "Digite o codigo do curso para inserir os candidatos:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
              
            cout << "Número de candidatos que serao cadastrados:";
            cin >> numCandidatos;
            
            for (contador = 0; contador < numCandidatos; contador++){
              cout << endl;
              cout << "Nome do candidato: ";
              cin >> cand1.nome;
              cout << "Nota do candidato: ";
              cin >> cand1.nota;
              contadorCandidatos++;
              cand1.numInscricao = contadorCandidatos;
              cand1.cursoCandidato= listas[codCurso-1].curso;
              insereCandidato(listas[codCurso-1].inscricao, cand1);
              cout << "Codigo de inscricao: " << cand1.numInscricao << endl; 
            }
            cout << endl << endl;
          break;

          case 2:
            int codInsc;
            cout << endl;
            cout << "Codigo do curso do candidato: ";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            cout << "Numero de inscricao do candidato a ser removido: ";
            cin >> codInsc;
            removeUm(listas[codCurso-1].inscricao, codInsc, erro);
            if(erro){
              cout << endl;
              cout << "Nao foi possível encontrar este candidato." << endl << endl << endl;
            }else{
              cout << "Candidato removido com sucesso." << endl << endl << endl;
            }
          break;

          case 3:
            cout << "Codigo do curso que voce deseja excluir a lista: " << endl;
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            removeTodos(listas[codCurso-1].inscricao, erro);
            cout << endl << endl << endl;
          break;

          case 4:
            cout << "Codigo do curso que voce deseja imprimir:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
              break;
            imprimeCandidatos(listas[codCurso-1].inscricao);
          break;
          default:
            break;
          } // switch menu candidato
        } // while(op)
      break;
    }
    case 3: { 
      int op = 1;
        while (op)
        {
          cout << "---------- MENU DE CLASSIFICACAO ----------" << endl;
          cout << "Escolha entre as opcoes:" << endl;
          cout << "1 - Criar a lista de classificados." << endl;
          cout << "2 - Remover classificado." << endl;
          cout << "3 - Remover todos classificados." << endl;
          cout << "4 - Mostrar lista de classificacao." << endl;
          cout << "5 - Mais detalhes das funcionalidades." << endl;
          cout << "0 - Sair desse Menu" << endl;
          cout << "Opcao escolhida: "; 
          cin >> op;
          cout << "-------------------------------------------" << endl<<endl;
          switch (op){
          case 0:
            break;
          
          case 1: // criar lista classificados 
            cout << "Digite o codigo do curso para criar a lista de classificacao:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            insereClassificacao(listas[codCurso-1].inscricao, listas[codCurso-1].classificacao);
            cout<<"Lista de classificados criada."<<endl;
            cout << endl << endl;
          break;

          case 2:
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro" << endl<<endl<<endl;
              break;
            }
            int codInsc;
            cout << endl;
            cout << "Codigo do curso do candidato:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
              
            cout << "Numero de inscricao do candidato a ser removido:" << endl;
            cin >> codInsc;
            cout << endl;
            removeUm(listas[codCurso-1].classificacao, codInsc, erro);
            if(erro){
              cout << endl;
              cout << "Nao foi possível encontrar este candidato." << endl << endl;
            }
            
          break;

          case 3:
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro" << endl<<endl<<endl;
              break;
            }
            cout << "Codigo do curso que voce deseja excluir a lista:" << endl;
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
              
            removeTodos(listas[codCurso-1].classificacao, erro);
            cout << endl << endl;
          break;

          case 4: // imprimir
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro." << endl << endl << endl;
              break;
            }
            cout << "Codigo do curso que voce deseja imprimir: ";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            imprimeClassificados(listas[codCurso-1].classificacao);
            cout << endl << endl;
            break;

          default:
            break;
          } // switch menu candidato
      } // while(op)
      break;
    } // case 3
    case 4: { // opcoes de matricula
      int op = 1;
        while (op)
        {
          cout << "---------- MENU DE MATRICULADOS ----------" << endl;
          cout << "Escolha entre as opcoes:" << endl;
          cout << "1 - Matricular aluno." << endl;
          cout << "2 - Remover matriculado." << endl;
          cout << "3 - Remover todas as matriculas." << endl;
          cout << "4 - Mostrar lista de matriculados." << endl;
          cout << "5 - Mostrar nota de corte do curso." << endl;
          cout << "6 - Mais detalhes das funcionalidades." << endl;
          cout << "0 - Sair desse Menu" << endl;
          cout << "Opcao escolhida: "; 
          cin >> op;
          cout << "-------------------------------------------" << endl<<endl;
          switch (op){
          case 0:
            break;
          
          case 1: // matricular aluno
            cout << "Digite o codigo do curso para criar a lista de matricula: ";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro." << endl<<endl<<endl;
              break;
            }
            int codIns;  
            cout << "Codigo de inscricao do aluno: ";
            cin >> codIns;
            cand2=buscaCandidato(listas[codCurso-1].classificacao, codIns);
            if(cand2==NULL){
              cout << "Numero de inscricao invalido." << endl;
              cout << "Voltando ao menu..." << endl <<endl;
              break;
            }
            insereMatriculado(listas[codCurso-1].matricula, listas[codCurso-1].classificacao, codIns, erro);
            if(erro){
              cout<<"Nao foi possivel matricular o candidato, tente novamente mais tarde."<<endl;
              cout << "Voltando ao menu...";
            }else{
              cout<<"A matricula foi realizada com sucesso.";
            }
            cout << endl << endl;
          break;

          case 2: // remove um matriculado
            cout << "Codigo do curso do candidato:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro" << endl<<endl<<endl;
              break;
            }
            cout << "Numero de inscricao do candidato a ser removido:";
            cin >> codInsc;
            removeUm(listas[codCurso-1].matricula, codInsc, erro);
            if(erro){
              cout << endl << "Nao foi possível encontrar este candidato." << endl;
            }else{
              cout<<"A matricula foi removida com sucesso"<<endl;
            }
            cout<<endl;
            
          break;

          case 3: // excluir lista
            cout << "Codigo do curso que voce deseja excluir a lista:" << endl;
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            
            if(listaVazia(listas[codCurso-1].matricula)){
              cout << "Voce deve criar a lista de classificacao primeiro" << endl<<endl<<endl;
              break;
            }
            removeTodos(listas[codCurso-1].matricula, erro);
            cout << endl << endl;
          break;

          case 4: // imprimir
            cout << "Codigo do curso que voce deseja imprimir:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro" << endl<<endl<<endl;
              break;
            }
            cout <<endl<< "LISTA DE CANDIDATOS MATRICULADOS: "<< endl;
            mostrarMatriculados(listas[codCurso-1].matricula);
            break;

          case 5: // nota de corte
            cout << "Codigo do curso para mostrar nota de corte:";
            cin >> codCurso;
            if(!existeCurso(codCurso,qtdeCursos)){
              break;
            }
            if(listaVazia(listas[codCurso-1].classificacao)){
              cout << "Voce deve criar a lista de classificacao primeiro" << endl<<endl<<endl;
              break;
            }
            cout<<"Nota de corte do curso "<<listas[codCurso-1].curso.nomeCurso<<" é: "<<calcularNotaCorte(listas[codCurso-1].matricula, listas[codCurso-1].classificacao)<<endl<<endl;

            break;
          case 6:
            
            break;
          default:
            break;
          } // switch menu candidato
      } // while(op)
      break;
      }

        
    } // switch menu
  }  // while(opcaoMenu)

  for(contador=0; contador<qtdeCursos; contador++){
    destroi(listas[codCurso].matricula, erro);
    destroi(listas[codCurso].classificacao, erro);
    destroi(listas[codCurso].inscricao, erro);
  }
  
  //system("Pause");
} 


void cadastrarCursos(Curso cursos[], int numCursos, psCurso listas[]){
    string nomeCurso;
    int qtdeVagas;
    int contador;

    for(contador = 0;contador < numCursos;contador++){
      cout << "-----------Registrando o "<<contador+1<<" curso. ------------"<<endl;
      cout << "Entre com o nome do curso: ";
      cin >> nomeCurso;
      cursos[contador].nomeCurso = nomeCurso;
      cout << "Número de vagas que serao ofertadas: ";
      cin >> qtdeVagas;
      cursos[contador].qtdVagas = qtdeVagas;
      cursos[contador].codCurso = contador + 1;

      listas[contador].curso = cursos[contador];
      
      listas[contador].inscricao = new ListaCandidato;
      listas[contador].classificacao = new ClassificacaoCandidato;
      listas[contador].matricula = new FilaMatricula;

      listas[contador].inscricao = criaLista();
      listas[contador].classificacao = criaLista();
      listas[contador].matricula = criaLista();

      
      cout << "--------------Curso " << contador+1 << " registrado------------" << endl << endl;
    }
}

void mostrarCursos(Curso cursos[], int numCursos){
  int i;
  cout << "------ Imprimindo cursos registrados ------" << endl;
  for(i = 0; i < numCursos;i++){
    cout << endl;
    cout << "Codigo do curso: " << cursos[i].codCurso << endl;
    cout << "Nome do curso: " << cursos[i].nomeCurso << endl;
    cout << "Quantidade de vagas: " << cursos[i].qtdVagas << endl;
    cout << endl;
  }
  cout<<"-------------------------------------------"<<endl;
}

int existeCurso(int codCurso, int qtdeCursos){
  if(codCurso > qtdeCursos){
    cerr<<endl<<endl<<"Codigo invalido, o curso nao existe"<<endl;
    cout<<"Voltando ao menu..."<<endl<<endl;
    return 0;
  }
  return 1;

}