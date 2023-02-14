#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Definicao de cada caractere do jogo.*/
#define PEDRA '0'
#define PAPEL '/'
#define TESOURA '<'

/*Numero maximo de pontos.*/
#define MAX 10

/*TAD que armazena os caracteres do computador e do jogador, alem dos pontos de cada um e do empate.*/
typedef struct{
    char sorteia;
    char joga;
    int jogador;
    int computador;
    int empate;
}Jogo;

/*Funcao que inicializa os pontos com zero.*/
void Inicializa_Pontuacao(Jogo* jog);
/*Funcao que iguala um caractere a outro.*/
void Copia_Caractere(char* a, char b);
/*Funcao que sorteia o caractere do computador e recebe o do jogador.
  Contando os pontos e quem ganhou essa jogada.
  Retorna 1 caso alguem ganhou a partida e 0 caso contrario.*/
int Jogada(Jogo* jog);
/*Funcao que sorteia qual sera o caractere do computador.
  Atravez da funcao que gera numeros aleatorios.
  Se sortear 0 e pedra, 1 e papel e 2 tesoura.*/
void Sorteia(Jogo* jog);
/*Funcao que confere quem ganhou determinada jogada.
  Retorna 1 se o jogador ganhar, 0 se o computador e -1 se empatar.*/
int Resultado(Jogo* jog);
/*Funcao que incrementa os pontos de acordo com a numero que entrar.
  1 incrementa ponto para o jogador, 0 para o computador e qualquer outra coisa empate.
  Alem de Printa e conferir quem ganhou a jogada.*/
int Contador_Pontos(Jogo* jog, int n);
/*Funcao que confere se alguem ganhou e deternima o fim do jogo.
  Retorna 1 se fim de jogo, ou seja, alguem completou o maximo de pontos.
  E retorna 0 caso contrario.*/
int Fim_Jogo(Jogo* jog);
/*Funcao que printa quem ganhou a partida no final de acordo com o numero que entra.
  1 jogador ganhou, 2 jodagor perdeu e 3  empatou*/
void Quem_Ganhou(Jogo* jog, int n);
/*Funcao que printa o andar do jogo.
  O que o computador e o jogador jogaram, alem da pontuacao atual de cada um e do empate.*/
void Print_Jogada(Jogo* jog);