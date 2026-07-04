#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//structs
typedef struct tJogador{
    int isAlive;
    int posicao; //somente x

} tJogador;

typedef struct tAlien{
    int isAlive;
    int linha; //posicao do meio do alien no grid
    int coluna; //posicao do meio do alien no grid
    int tipo; //qual desenho
    int vidas; //lembra de inicializar no inicializajogo!!!
} tAlien;

typedef struct tTiro{
    //posicao
    int linha;
    int coluna;
    //liga e desliga o tiro
    int ativo;
} tTiro;

typedef struct tEstadoJogo{
    int contaIteracao; //lembra de inicializar no inicializajogo!!!
    int pontuacao;
    int direcaoFileira; //para alien. comeca indo para a direita(+1) e dps para a esquerda(-1)
    int funcionalidade;
    int num_aliens;
    int mapa[11][21];

    tJogador jogador;
    tTiro  tiroJogador;
    tTiro tiroAlien[3];
    int aliens[2][4];


} tEstadoJogo;

typedef struct tConfigInicial{
    int funcionalidade;
    int num_aliens;
    int firstAlien;
    int secondAlien;
} tConfigInicial;

typedef struct tPersonagens{
    char tiroAlien;
    char tiroJogador;
    char skinJogador[2][3];
    char skinAlien1[2][3];
    char skinAlien2[2][3];
} tPersonagens;

//struct func
    //tpersonagens
tPersonagens lePersonagens(char * caminhoArquivo){
    tPersonagens novosPersonagens;
    char caminhoPersonagens[1200];
    strcpy(caminhoPersonagens, caminhoArquivo);
    strcat(caminhoPersonagens, "/personagens.txt");
    // le personagens.txt
    FILE * temp;
    temp = fopen(caminhoPersonagens, "r");

    if(!temp){
        printf("O arquivo %s nao existe!", caminhoPersonagens);
        exit(EXIT_FAILURE);
    }

    char linha[30];

    fgets(linha, sizeof(linha), temp);
    novosPersonagens.tiroJogador = linha[0];

    for(int i = 0; i < 2; i++){
        fgets(linha, sizeof(linha), temp);
        for(int j = 0; j < 3; j++){
            novosPersonagens.skinJogador[i][j] = linha[j];
        }
    }

    fgets(linha, sizeof(linha), temp);
    novosPersonagens.tiroAlien = linha[0];

    for(int i = 0; i < 2; i++){
        fgets(linha, sizeof(linha), temp);
        for(int j = 0; j < 3; j++){
            novosPersonagens.skinAlien1[i][j] = linha[j];
        }
    }
    for(int i = 0; i < 2; i++){
        fgets(linha, sizeof(linha), temp);
        for(int j = 0; j < 3; j++){
            novosPersonagens.skinAlien2[i][j] = linha[j];
        }
    }
    
    return novosPersonagens;
}

    //tconfiginicial
tConfigInicial leConfig(char * caminhoArquivo){
    tConfigInicial configInicial;

    // le config_inicial.txt
    char caminhoConfig[1200];
    strcpy(caminhoConfig, caminhoArquivo);
    strcat(caminhoConfig, "/config_inicial.txt");
    FILE * temp;
    temp = fopen(caminhoConfig, "r");

    if(!temp){
        printf("O arquivo %s nao existe!", caminhoConfig);
        exit(EXIT_FAILURE);
    }

    char linha[30];

    fgets(linha, sizeof(linha), temp);
    configInicial.funcionalidade = linha[0];

    fgets(linha, sizeof(linha), temp);
    configInicial.num_aliens = linha[0];
    configInicial.firstAlien = linha[2];
    configInicial.secondAlien = linha[4];

    return configInicial;
}

//imprime + cria arquivos
void geraMapa(){
    //arquivo_saida.txt

}


int main(int argc, char** argv) {
    //iniciar pedindo o caminho do arquivo
    char caminhoArquivo[1001];
    scanf("%s", caminhoArquivo);

    if(caminhoArquivo[strlen(caminhoArquivo) <= 2]){
        printf("ERRO: Informe o diretório com os arquivos de configuração.");
        exit(EXIT_FAILURE);
    }

    tPersonagens personagens = lePersonagens(caminhoArquivo);
    tConfigInicial config = leConfig(caminhoArquivo);
    
    //inicializar jogo

    //ler acoes

    return (EXIT_SUCCESS);
}