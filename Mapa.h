#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

// Autor: Leandro Barros Pontes
// Disciplina: Estrutura de dados 1
// Trabalho: Ranking de Palavras

typedef struct _item
{
    int conta;            // contador de palavras repetidas

    char *termo;         // palavras
} Item;
typedef struct _mapa
{
    int total;                  // número de itens no mapa
    int blocos;                 // número de blocos de itens alocados
    Item **lista;               // vetor de ponteiros para itens
} Mapa;
int menu(void);

void inicia_mapa (Mapa *mp); //inicia um mapa vazio

void insere_termo (Mapa *mp, char *s); // insere um item com termo s e conta =1

int incrementa (Mapa *mp, char *s);// incrementa contador do termo s, retorna 1 se não encontrou o termo

int escreve_cont (Mapa *mp, char *s, int c); // escreve o contador do termo s

int le_contador (Mapa *mp, char *s);  // retorna o contador do termo s

void remove_termo (Mapa *mp, char *s); // remove o item com termo s

void libera_mapa (Mapa * mp); // libera o espaço ocupado pelo mapa

int tamanho_mapa (Mapa * mp); // retorna número de itens no mapa

void le_termo (Mapa * mp, int i, char *t, int *c); //retorna em t o termo em determinado índice e seu contador

void reorganiza_mapa(Mapa *mp, int i); // utiliza um auxiliar para fazer a troca dos ponteiros e reorganizar o mapa

void leitura_arquivo(Mapa *mp, char *fp); // realiza a leitura */

#endif // MAPA_H_INCLUDED
