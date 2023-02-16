CREATE TABLE autor(
  cod_autor VARCHAR(5) PRIMARY KEY,
  nome varchar(50),
  nascimento DATE,
  UNIQUE(nome, nascimento)
);
CREATE TABLE editora(
  cod_editora VARCHAR(5) PRIMARY KEY,
  razao VARCHAR(50),
  endereco VARCHAR(50),
  cidade VARCHAR(50)
);
CREATE TABLE livro(
  cod_livro VARCHAR(5) PRIMARY KEY,
  titulo varchar(50),
  valor DECIMAL (7,2),
  volume DECIMAL(3),
  cod_editora VARCHAR(5) REFERENCES editora
);
CREATE TABLE escreve(
  cod_autor VARCHAR(5) REFERENCES autor,
  cod_livro VARCHAR(5) REFERENCES livro,
  PRIMARY KEY (cod_autor, cod_livro)
  
);
--DROP TABLE autor
