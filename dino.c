#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// Limpar a tela.
#define LIMPA_TELA system("cls");

// Limite da Tela em colunas de caracteres.
int limiteInferiorY = 32;
int limiteSuperiorY = 2;
int limiteInferiorX = 2;
int limiteSuperiorX = 72;

char caractereBorda = '*';

// Teclas.
int ENTER = 13;
int CIMA = 72;

// Posiciona cursor para escrita subsequente.
void setCursor(int x, int y)
{
    COORD coord; // Struct para definir as coordenadas de um caractere no buffer do console.
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), // Buffer da tela do console.
                             coord);                          // Nova coordenada.
}

// Struct para guardar informações dos obstáculos.
typedef struct Bloco
{
    int x;
    int y;
    int tamanho;
    // Utilizando abstração de pseudométodo.
    void (*moverBloco)(struct Bloco *, int novoX, int novoY);
} Bloco;

// Função para mudar a posição do bloco no terminal.
void moverBloco(Bloco *bloco, int novoX, int novoY);

// Função para desenhar a borda.
void desenharBorda();

Bloco *criarBloco(int x, int y, int tamanho)
{
    Bloco *bloco = (Bloco *)malloc(sizeof(Bloco));
    bloco->x = x;
    bloco->y = y;
    bloco->tamanho = tamanho;
    bloco->moverBloco = &moverBloco; // Definindo o pseudométodo.
    return bloco;
}

// Funções utilizadas.
void

main()
{
    LIMPA_TELA;
    desenharBorda();
    // Criar tela inicial.

    // Capturar evento para iniciar a partida.

    // Criar os blocos.
    Bloco blocos[3] = {*criarBloco(0, 0, 1),
                       *criarBloco(0, 10, 2),
                       *criarBloco(0, 20, 3)};
    for (int i = 0; i < 3; i++)
    {
        Bloco bloco = blocos[i];
        // bloco.moverBloco(&bloco, bloco.x, bloco.y);
    }

    // Mover os blocos.

    // fim
    while (1)
    {
    }
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
    int nColunas = 1 + limiteSuperiorX - limiteInferiorX;

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
    for (int i = limiteSuperiorY - 1; i <= limiteInferiorY+1; i++)
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