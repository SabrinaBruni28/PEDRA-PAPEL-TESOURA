#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PEDRA '0'
#define PAPEL '/'
#define TESOURA '<'
#define MAX 10
typedef struct{
    char sorteia;
    char joga;
    int jogador;
    int computador;
    int empate;
}Jogo;

void Inicializa_Pontuacao(Jogo* jog);
void Copia_Caractere(char* a, char b);
int Jogada(Jogo* jog);
int Sorteia(Jogo* jog);
int Resultado(Jogo* jog);
int Contador_Pontos(Jogo* jog, int n);
void Fim_Jogo(Jogo* jog, int n);
void Print_Jogada(Jogo* jog);