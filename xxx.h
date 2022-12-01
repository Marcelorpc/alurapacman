#define ESQUERDA 'a'
#define DIREITA 'd'
#define CIMA 'w'
#define BAIXO 's'

void move(char direcao);
int entradavalida(char direcao);
int direcaovalida(int x, int y);
void andanomapa(int origemx, int origemy, int destinox, int destinoy);
void fantasmas();