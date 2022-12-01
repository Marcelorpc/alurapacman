#define PAREDEHORIZONTAL '-'
#define PAREDEVERTICAL '|'
#define VAZIO '.'
#define HEROI '@'
#define FANTASMA 'F'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;
struct posicao {
    int x;
    int y;
};
typedef struct posicao POSICAO;

void encontraheroi(MAPA* m, POSICAO* p, char c);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
void copiamapa(MAPA* origem, MAPA* destino);
void liberamapa(MAPA* m);