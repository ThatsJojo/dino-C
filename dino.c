#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// Limpar a tela.
#define LIMPA_TELA system("cls");

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

// Função para mover o bloco.

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
    // Criar tela inicial.

    // Capturar evento para iniciar a partida.

    // Criar os blocos.
    Bloco blocos[3] = {*criarBloco(0, 0, 1),
                       *criarBloco(0, 0, 2),
                       *criarBloco(0, 0, 3)};
    for (int i = 0; i < 3; i++)
    {
        Bloco bloco = blocos[i];
        bloco.moverBloco(&bloco, bloco.x, bloco.y);
    }

    // Mover os blocos.
    system("pause");

}

void moverBloco(Bloco *bloco, int novoX, int novoY)
{
    // Apagar bloco da posição atual.
    printf("OPA! %i %i %i\n", bloco->x, bloco->y, bloco->tamanho);
    setCursor(bloco->x, bloco->y);
    putchar('H');
    

    // Conferir limites da tela.

    // Desenhar bloco na nova posição.
    setCursor(bloco->x, bloco->y);

    // Atualizar coordenadas da Struct Bloco.
}