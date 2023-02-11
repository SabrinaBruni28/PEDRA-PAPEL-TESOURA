#include "jogo.h"

/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(){
    printf("\033[1;33m**********************************************************************************\n\033[m");
}

/*Funcao que comeca o jogo e pergunta se quer jogar ou sair.
  Retorna 1 caso o usuario queira jogar e 0 caso contrario.*/
int Comeco(){
    int i;
    Asterisco();
    printf("\t\033[1;35m######### PEDRA, PAPEL E TESOURA ##########\n\033[m");
    printf("\n\033[1m1- Jogar\n2- Sair\n\033[m");
    scanf("%d",&i);
    if(i==1) return 1;
    Asterisco();
    return 0;
}

/*Funcao que finaliza o jogo e pergunta se quer jogar novamente ou sair.
  Retorna 1 caso o usuario queira jogar novamente e 0 caso contrario.*/
int Final(){
    int i;
    printf("\n\033[1;35m**** FIM DE JOGO ****\n\033[m");
    printf("\n\033[1m1- Jogar Novamente\n2- Sair\n\033[m");
    scanf("%d",&i);
    if(i==1) return 1;
    Asterisco();
    return 0;
}

int main(){
    Jogo jog;
    int estado;
    estado = Comeco();
    while(estado){
        switch (estado){
            case 1:
                Inicializa_Pontuacao(&jog);
                estado = 2;
                break;
            case 2:
                if(Jogada(&jog)) estado = 3;
                break;
            case 3:
                estado = Final();
                break;
        }
    }
    return 0;
}