DROP SCHEMA public CASCADE;
CREATE SCHEMA public;

create TABLE DISCIPLINA(
  NUMDISP INT PRIMARY KEY,
  NOME VARCHAR(40),
  QUANTCREDITOS INT
);

CREATE TABLE PROFESSOR(
  NUMFUNC INT PRIMARY KEY,
  NOME VARCHAR(40),
  ADMISSAO DATE,
  AREAPESQUISA VARCHAR(40)
);

CREATE TABLE CURSO(
  NUMCURSO INT PRIMARY KEY,
  NOME VARCHAR(40),
  TOTALCREDITOS INT
);

create table ALUNO(
  NUMALUNO INT PRIMARY KEY,
  NOME VARCHAR(40),
  ENDERECO VARCHAR(40),
  CIDADE VARCHAR(40),
  TELEFONE CHAR(9),
  NUM_CURSO INT,
  constraint cursoAluno foreign key (num_curso)
  	references curso (numcurso)
);

CREATE TABLE AULA(
  NUMALUNO INT,
  NUMDISP INT,
  NUMFUNC INT,
  SEMESTRE INT,
  NOTA FLOAT,
  constraint Aaluno foreign key  (numaluno)
  	references aluno (numaluno),
  constraint Adisciplina foreign key (numdisp)
  	references disciplina (numdisp),
  constraint Aprofessor foreign key (numfunc)
  	references professor (numfunc),
  primary key (numaluno, numfunc, numdisp, semestre)
 );
 
 CREATE TABLE DISCIPLINACURSO(
   NUMDISP INT,
   NUMCURSO INT,
   primary key (numdisp, numcurso),
   constraint Ddisc foreign key (numdisp)
   	references disciplina (numdisp),
   constraint Dcurso foreign key (numcurso)
   	references curso (numcurso)
 );
