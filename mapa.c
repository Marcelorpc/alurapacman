#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void copiamapa(MAPA* origem, MAPA* destino) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    alocamapa(destino);
    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void encontraheroi(MAPA* m, POSICAO* p, char c) {
    for(int i = 0; i < m->linhas; i++) {
        for(int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }

}

void lemapa(MAPA* m) {
    FILE* f;

    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("NAO ENCONTRADO");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocamapa(m);
    for(int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void alocamapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->colunas);
    for(int i = 0; i < m->colunas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->linhas+1));
    }
}

void liberamapa(MAPA* m) {
    for(int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void imprimemapa(MAPA* m) {
    for(int i = 0; i < m->linhas; i++) {
        printf("%s\n", m->matriz[i]);
    }
}