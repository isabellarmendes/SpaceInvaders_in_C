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
    tTiro tiroJogador;
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
    fclose(temp);
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
    configInicial.funcionalidade = linha[0] - '0';

    fgets(linha, sizeof(linha), temp);
    configInicial.num_aliens = linha[0] - '0';
    configInicial.firstAlien = linha[2] - '0';
    configInicial.secondAlien = linha[4] - '0';

    fclose(temp);
    return configInicial;
}

//imprime + cria arquivos
void criaHeatmap(int heatmap[11][21]){
    //arquivo_saida.txt
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 21; j++){
            heatmap[i][j] = 0;
        }
    }
}

void atualizaHeatmap(int heatmap[11][21]){
    
}

void geraHeatmap(char * caminhoArquivo, int heatmap[11][21]){

    //arquivo_saida.txt
    char caminhoSaida[1200];
    strcpy(caminhoSaida, caminhoArquivo);
    strcat(caminhoSaida, "/arquivo_saida.txt");

    FILE * temp;
    temp = fopen(caminhoSaida, "w");

    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 21; j++){
            fprintf(temp, "%02d ", heatmap[i][j]);
        }
        fprintf(temp, "\n");
    }
    fclose(temp);
}

void InicializaJogo(tConfigInicial config, tPersonagens personagens){
    tEstadoJogo estadoJogo;
    estadoJogo.contaIteracao = 0;
    estadoJogo.pontuacao = 0;
    estadoJogo.direcaoFileira = 1;
    estadoJogo.funcionalidade = config.funcionalidade;
    estadoJogo.num_aliens = config.num_aliens;

    //inicializa mapa
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 21; j++){
            estadoJogo.mapa[i][j] = 0;
        }
    }

    //inicializa jogador
    estadoJogo.jogador.isAlive = 1;
    estadoJogo.jogador.posicao = 10;

    //inicializa tiro do jogador
    estadoJogo.tiroJogador.ativo = 0;
}


int main(int argc, char** argv) {


    //iniciar pedindo o caminho do arquivo
    if(argc < 2){
        printf("ERRO: Informe o diretorio com os arquivos de configuracao.");
        return EXIT_FAILURE;
    }
    tPersonagens personagens = lePersonagens(argv[1]);
    tConfigInicial config = leConfig(argv[1]);
    
    //inicializar jogo

    //ler acoes
 

    //finaliza jogo

    return (EXIT_SUCCESS);
}

