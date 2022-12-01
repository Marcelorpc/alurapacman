/*
- o malloc aloca um espaco de memoria dinamicamente, e e importante sempre liberar essa memoria apos o uso
- o char** declara um ponteiro de ponteiros, um ponteiro para arrays que por sua natureza sao ponteiros para outros dados

- ao passar endereço de memoria de um struct, &v, para acessar o valor em vez de usar *valor, usa-se (*v).valor ou o mais moderno v->valor

ao dar return em uma funcao vazia, voce encerra ela

#define heroi '@'
#define vazio '.'
é usado para definir constantes

um array de char quando lido como string, sempre termina com \0, mesmo que nao esteja declarado, pq uma string em c sempre termina com \0
*/

#include <stdio.h>
#include <stdlib.h>
#include "mapa.c"
#include "xxx.h"

MAPA m;
POSICAO heroi;
MAPA mcopy;

void fantasmas() {
    copiamapa(&m, &mcopy);
    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {
            if(mcopy.matriz[i][j] == FANTASMA) {
                if(direcaovalida(i, j+1)) {
                    andanomapa(i, j, i, j+1);
                }
            }
        }
    }
    liberamapa(&mcopy);
}

int entradavalida(char direcao) {
    if(direcao == ESQUERDA || direcao == DIREITA || direcao == CIMA || direcao == BAIXO) {
        return 1;
    } else {
        return 0;
    }
}

int direcaovalida(int x, int y) {
    if(m.matriz[x][y] == PAREDEHORIZONTAL) {
        return 0;
    } else if(m.matriz[x][y] == PAREDEVERTICAL) {
        return 0;
    } else {
        return 1;
    }
}

void andanomapa(int origemx, int origemy, int destinox, int destinoy) {
    char personagem = m.matriz[origemx][origemy];

    m.matriz[origemx][origemy] = VAZIO;
    m.matriz[destinox][destinoy] = personagem;
}

void move(char direcao) {
    int proximox = heroi.x;
    int proximoy = heroi.y;

    if(!entradavalida(direcao)) {
        return;
    }
    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
    }
    if(!direcaovalida(proximox, proximoy)){
        return;
    }
    andanomapa(heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;    
}

int main() {
    lemapa(&m);
    encontraheroi(&m, &heroi, HEROI);
    do {
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();
    } while(0 == 0);
    liberamapa(&m);
    liberamapa(&mcopy);
} 