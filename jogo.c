#include "jogo.h"

void Inicializa_Pontuacao(Jogo* jog){
    jog->computador = 0;
    jog->empate = 0;
    jog->jogador = 0;
}

void Copia_Caractere(char* a, char b){
    *a = b;
}

int Jogada(Jogo* jog){
    char c;
    Sorteia(jog);
    printf("\n\033[1;34mPEDRA: 0  PAPEL: /  TESOURA: < \n\033[m");
    printf("\n\033[1;33mPEDRA, PAPEL, TESOOOURA...\n\033[m");
    scanf(" %c",&c);
    Copia_Caractere(&jog->joga, c);
    return Contador_Pontos(jog, Resultado(jog));
}

void Sorteia(Jogo* jog){
    int numero;
    srand( (unsigned)time(NULL) );
    numero = rand()%3;
    switch (numero){
    case 0:
        Copia_Caractere(&jog->sorteia,PEDRA);
        break;
    case 1:
        Copia_Caractere(&jog->sorteia, PAPEL);
        break;
    case 2:
        Copia_Caractere(&jog->sorteia, TESOURA);
        break;
    default:
        printf("e ate o numero entao ein\n");
        break;
    }
}

int Resultado(Jogo* jog){
    if(jog->sorteia == jog->joga){
        printf("\n\033[1;35m##### EMPATE!!!! #####\n\033[m");
        return -1;
    }
    else if(jog->joga==PEDRA && jog->sorteia==PAPEL){
        printf("\n\033[1;31m##### PONTO PARA O COMPUTADOR!!!!! #####\n\033[m");
        return 0;
    }
    else if(jog->joga==PAPEL && jog->sorteia==PEDRA){
        printf("\n\033[1;32m ##### PONTO PARA VOCE!!!!! #####\n\033[m");
        return 1;
    }
    else if(jog->joga==TESOURA && jog->sorteia==PAPEL){
        printf("\n\033[1;32m ##### PONTO PARA VOCE!!!!! #####\n\033[m");
        return 1;
    }
    else if(jog->joga==PEDRA && jog->sorteia==TESOURA){
        printf("\n\033[1;32m ##### PONTO PARA VOCE!!!!! #####\n\033[m");
        return 1;
    }
    else if(jog->joga==PAPEL && jog->sorteia==TESOURA){
        printf("\n\033[1;31m##### PONTO PARA O COMPUTADOR!!!!! #####\n\033[m");
        return 0;
    }
    else if(jog->joga==TESOURA && jog->sorteia==PEDRA){
        printf("\n\033[1;31m##### PONTO PARA O COMPUTADOR!!!!! #####\n\033[m");
        return 0;
    }
}

int Contador_Pontos(Jogo* jog, int n){
    switch (n){
    case 1:
        jog->jogador++;
        break;
    case 0:
        jog->computador++;
        break;
    default:
        jog->empate++;
        break;
    }
    Print_Jogada(jog);
    return Fim_Jogo(jog);
}

int Fim_Jogo(Jogo* jog){
    if(jog->computador == MAX){
        Quem_Ganhou(jog, 2);
        return 1;
    }
    else if(jog->jogador == MAX){ 
        Quem_Ganhou(jog, 1);
        return 1;
    }
    else if(jog->empate == MAX){
        Quem_Ganhou(jog, 3);
        return 1;
    }
    return 0;
}

void Quem_Ganhou(Jogo* jog, int n){
    switch (n){
    case 1:
        printf("\n\033[1;32m********** VOCE GANHOU!!!!!! **********\n\n\033[m");
        break;
    case 2:
        printf("\n\033[1;31m********** VOCE PERDEU!!!!!! **********\n\n\033[m");
        break;
    case 3:
        printf("\n\033[1;34m********** EMPATOU!!!!!! **********\n\n\033[m");
        break;
    }
}

void Print_Jogada(Jogo* jog){
    printf("\n\033[1mVoce: %c\t\t\t Pontuacao:\n\033[m", jog->joga);
    printf("\033[1mComputador: %c\t\t voce: %d  computador: %d  empatado: %d\n\n\033[m", jog->sorteia, jog->jogador, jog->computador, jog->empate);
}
