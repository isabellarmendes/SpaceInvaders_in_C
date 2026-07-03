#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tJogador{
    int isAlive;
    int posicao; //somente x

} tJogador;

typedef struct tAlien{
    int isAlive;
    int linha; //posicao do meio do alien no grid
    int coluna; //posicao do meio do alien no grid
    int tipo; //qual desenho
    int vidas = 2;
} tAlien;

typedef struct tTiro{
    //posicao
    int linha;
    int coluna;
    //liga e desliga o tiro
    int ativo;
} tTiro;

typedef struct tEstadoJogo{
    int contaIteracao = 0;
    int pontuacao;
    int direcaoFileira; //para alien. comeca indo para a direita(+1) e dps para a esquerda(-1)
    int funcionalidade;
    int num_aliens;
    int mapa[11][21];
    int aliens[2][num_aliens];


} tEstadoJogo;

typedef struct tPersonagens{
    char tiroAlien;
    char tiroJogador;
    char skinJogador[2][3];
    char skinAlien1[2][3];
    char skinAlien2[2][3];
} tPersonagens;



int main(int argc, char** argv) {


    return (EXIT_SUCCESS);
}

