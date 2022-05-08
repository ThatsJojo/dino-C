#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// Limpar a tela.
#define LIMPA_TELA system("cls");
#define ESPERA Sleep(1);

// Variáveis para controle da tela lógica.
int limiteInferiorY = 12;
int limiteSuperiorY = 2;
int limiteInferiorX = 2;
int limiteSuperiorX = 72;
int nColunas;
int alturaTerreno = 9;
float tempoAtualizacao = 6000;
float fracaoTempo = 0.001;
char caractereBorda = '*';

// Teclas.
int ENTER = 13;
int CIMA = 72;

// Struct para guardar informações dos obstáculos.
typedef struct Bloco
{
    int x;
    int y;
    int tamanho;
    // Utilizando abstração de pseudométodo.
    void (*moverBloco)(struct Bloco *, int novoX, int novoY);
} Bloco;

// Classe utilizada para desenho do chão;
typedef struct Terreno
{
    char *terreno;
    int inicioAatual;
    int tamanhoTerreno;
} Terreno;

// Funções utilizadas
void setCursor(int x, int y);
void moverBloco(Bloco *bloco, int novoX, int novoY);
void desenharBorda();
void moverTerreno(Terreno *terreno);
Bloco *criarBloco(int x, int y, int tamanho);

int main()
{
    // Iniciando variáveis dinâmicas
    nColunas = 1 + limiteSuperiorX - limiteInferiorX;
    LIMPA_TELA;
    desenharBorda();
    Terreno terreno;
    terreno.terreno = "-.^-----.--.---__------.^.---------~~--^--------...__-.--------------^~---";
    terreno.inicioAatual = 0;
    terreno.tamanhoTerreno = 74;
    float velocidade = 10; // Posteriormente variável com a dificuldade.

    // Criar tela inicial.

    // Capturar evento para iniciar a partida.

    // Criar os blocos.
    Bloco blocos[3] = {*criarBloco(nColunas / 6, alturaTerreno - 1, 1),
                       *criarBloco(nColunas / 2, alturaTerreno - 1, 2),
                       *criarBloco(nColunas / 3, alturaTerreno - 1, 3)};
    for (int i = 0; i < 3; i++)
    {
        Bloco bloco = blocos[i];
        bloco.moverBloco(&bloco, bloco.x, bloco.y);
    }

    // Mover os blocos.

    // Mover terreno.
    int nivel = 1;
    for (float i = 0; 1; i += fracaoTempo)
    {
        if (i > (velocidade/nivel) * tempoAtualizacao)
        {
            moverTerreno(&terreno);
            setCursor(limiteInferiorX, limiteInferiorY + 2);
        }
        if(i >tempoAtualizacao){
            nivel++;
        }
    }

    // fim
}

void moverBloco(Bloco *bloco, int novoX, int novoY)
{
    // Apagar bloco da posição atual.
    setCursor(bloco->x, bloco->y);
    putchar(' ');

    // Conferir limites da tela.

    // Desenhar bloco na nova posição.
    setCursor(novoX, novoY);
    printf("OPA! %i %i %i\n", bloco->x, bloco->y, bloco->tamanho);

    // Atualizar coordenadas da Struct Bloco.
}

// Desenha a borda (exterior) da tela lógica.
void desenharBorda()
{
    // Desenho das linhas horizontais.
    char *str = malloc((nColunas + 1) * sizeof(char));
    // Cria a string com o caractere de borda.
    for (int i = 0; i <= nColunas; i++)
        str[i] = caractereBorda;

    str[nColunas] = '\0'; // Finaliza a string.

    // Linha horizontal superior.
    setCursor(limiteInferiorX, limiteSuperiorY - 1);
    printf("%s", str);
    // Linha horizontal inferior.
    setCursor(limiteInferiorX, limiteInferiorY + 1);
    printf("%s", str);

    // Desenho das linhas verticais (Acompanha quinas).
    for (int i = limiteSuperiorY - 1; i <= limiteInferiorY + 1; i++)
    {
        // Borda vertical esquerda.
        setCursor(limiteInferiorX - 1, i);
        printf("%c", caractereBorda);
        // Borda vertical direita.
        setCursor(limiteSuperiorX + 1, i);
        printf("%c", caractereBorda);
    }

    printf("\n \n");
}

// Posiciona cursor para escrita subsequente.
void setCursor(int x, int y)
{
    COORD coord; // Struct para definir as coordenadas de um caractere no buffer do console.
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), // Buffer da tela do console.
                             coord);                          // Nova coordenada.
}

Bloco *criarBloco(int x, int y, int tamanho)
{
    Bloco *bloco = (Bloco *)malloc(sizeof(Bloco));
    bloco->x = x;
    bloco->y = y;
    bloco->tamanho = tamanho;
    bloco->moverBloco = &moverBloco; // Definindo o pseudométodo.
    return bloco;
}

void moverTerreno(Terreno *terreno)
{
    // Posiciona o cursos na posição do terreno.
    setCursor(limiteInferiorX, alturaTerreno);
    terreno->inicioAatual = terreno->inicioAatual < (terreno->tamanhoTerreno - 1) ? terreno->inicioAatual + 1 : 0;
    int inicio = terreno->inicioAatual;
    for (int i = 0; i < nColunas; i++)
    {
        printf("%c", terreno->terreno[inicio]);
        inicio = inicio < (terreno->tamanhoTerreno - 1) ? inicio + 1 : 0;
    }
}