%%%% Base de conhecimento:
maior(X, Y) :- X > Y.
problema(preparador_fisico) :- preparo_fisico(ruim).
problema(equipe_tecnica) :- atritos(constantes), situação_psicológica(ruim).
problema(time) :- preparo_fisico(bom), situação_de_gols(ruim).
problema(insatisfação_financeira) :- atritos(constantes), salarios(atrasado).
atritos(constantes) :- jogador(X), tecnico(Y), discute(X, Y).
atritos(constantes) :- jogador(X), jogador(Y), discute(X, Y).
situação_psicológica(ruim) :- jogador(X), suspenso(X).
situação_psicológica(ruim) :- jogador(X), cortado(X).
situação_de_gols(ruim) :- gols_sofridos(X), gols_feitos(Y), maior(X,Y).
suspenso(X) :- cartão_vermelho(X).
preparo_fisico(ruim) :- jogador(X), lento(X).
preparo_fisico(ruim) :- jogador(X), lesão(X).

:- dynamic jogador/1, tecnico/1, discute/2, atritos/1, salarios/1, suspenso/1, cortado/1, gols_sofridos/1, gols_feitos/1, lento/1, lesão/1, cartão_vermelho/1.

%%%% Situação 1:
jogador(jorge).
lesão(jorge).
gols_sofridos(2).
gols_feitos(1).
preparo_fisico(bom).

%% Resultado:
% X = preparador_fisico ;
% X = time ;
% false.

%%%% Situação 2:
jogador(joaquim).
suspenso(joaquim).
tecnico(zico).
jogador(nilson).
discute(nilson, zico).
preparo_fisico(bom).
salarios(atrasado).

%% Resultado:
% X = equipe_tecnica ;
% X = 'insatisfação_financeira' ;
% false.

%%%% Situação 3:
gols_feitos(7).
gols_sofridos(2).
jogador(romario).
jogador(ronaldo).
tecnico(felipao).
cartão_vermelho(romario).

%% Resultado:
% false.

%%%% Situação 4:
jogador(carlos).
cartão_vermelho(carlos).
tecnico(eduardo).
discute(carlos, eduardo).
gols_feitos(7).
gols_sofridos(2).
preparo_fisico(bom).

%% Resultado:
% X = equipe_tecnica ;
% false.
