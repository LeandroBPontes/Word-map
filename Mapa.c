#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Mapa.h"
#define TAM 10

//chamadas das funcoes para inicializar e executar as opções
int menu(void)
{
    int c;
    printf("Menu:\n");
    printf("1. Read file txt\n");
    printf("2. Show complete ranking\n");
    printf("3. Show ranking range \n");
    printf("4. Search word\n");
    printf("5. Options\n");
    printf("6. Quit \n");
    do
    {
        printf("\nInsert your choice: ");
        scanf("%i", &c);
    }
    while(c<0 || c>6);

    return c;
}
//inicia um mapa vazio

void inicia_mapa (Mapa *mp)
{
    int i;

    mp -> lista = malloc(TAM * sizeof(Item*));
    if (mp -> lista == NULL)
    {
        printf("could not allocate");
    }

    for (i = 0; i < TAM; i++)
    {
        mp -> lista[i] = calloc(1, sizeof(Item));

    }
    if (mp -> lista[i-1] == NULL)
    {
        printf("could not allocate");
    }
    mp -> total = 0;
    mp -> blocos = 1;
}

//inserida na funcao leitura_arquivo
// recebe uma palavra por vez e faz um malloc do tamanho da palavra
// busca o tamanho da palavra em x e realloca caso ultrapasse o espaco reservado

void insere_termo (Mapa *mp, char *s)
{

    int i, x;
    mp -> total++;
    x = strlen(s);
    mp->lista[mp->total - 1]->termo = malloc(x * sizeof(char));
    if( mp->lista[mp->total-1]->termo == NULL)
    {
        printf("\nIMPOSSIVEL MALOCAR");
    }
    strcpy(mp->lista[mp->total - 1]->termo, s);
    mp->lista[mp->total - 1]->conta = 1;

    if(mp -> total >= TAM * mp->blocos)
    {
        mp->blocos++;
        mp -> lista = realloc(mp->lista, mp->blocos * TAM * sizeof(Item*));
        for(i = TAM * (mp->blocos - 1); i< TAM * mp->blocos; i++)
        {
            mp -> lista[i] = calloc(1, sizeof(Item));
        }

    }
}
// incrementa contador do termo s, utilizada na funcao de leitura do arquivo
int incrementa (Mapa *mp, char *s)
{
    int i;

    for(i=0; i < mp->total; i++)
    {
        if(strcasecmp(mp->lista[i]->termo, s)==0)
        {
            mp -> lista[i]->conta++;
            return;
        }
    }
}

//Retorna a quantidade de palavras inseridas no mapa

int tamanho_mapa(Mapa *mp)
{
    printf("\nTotal de Palavras -> %i\n", mp->total);
}

void libera_mapa (Mapa *mp)
{
    int i;

    free(mp->lista);

    for (i=mp->total; i > mp->total ; i--)
    {

        free(mp->lista[i]);

    }
    free(mp);

}
int ordena_mapa(Mapa *mp, char *s)
{
    int i, ordenador =1, *aux;
    char *aux_termo;
    aux = malloc(sizeof(int));
    aux_termo = malloc(sizeof(char));

    printf("\nPalavra ----------------Qtd\n");

    for(i=0; i < mp->total; i++)
    {


        while(ordenador <= mp->total)
        {
            for(i=0; i < mp->total; i++)
            {
                if(mp->lista[i]->conta <= mp->lista[i+1]->conta)
                {
                    aux = mp->lista[i]->conta;
                    aux_termo = mp->lista[i]->termo;
                    mp->lista[i]->conta = mp->lista[i+1]->conta;
                    mp->lista[i]->termo = mp->lista[i+1]->termo;
                    mp->lista[i+1]->conta = aux;
                    mp->lista[i+1]->termo = aux_termo;

                }
            }
            ordenador++;
        }
        for(i=0; i < mp->total; i++)
        {

            printf("\n%s----------------%d\n", mp->lista[i]->termo, mp->lista[i]->conta);

        }

    }

}
int verifica_lista (Mapa *mp, char *s)
{


    int i;
    for(i = 0; i < mp->total; i++)
    {
        if(strcasecmp(mp->lista[i]->termo, s)==0)
        {
            return 1;
        }
    }
    return 0;
}

// leitura e inserção com possível troca de arquivos

void leitura_arquivo(Mapa *mp, char *fp)
{

    // preencher com os termos do arquivo
    char vetorPercorre[1000];
    char vetor[1000];
    int i, *cont_aux;

    // ponteiro que recebera o endereco dos termos do arquivo
    char *sub;
    cont_aux = malloc(sizeof(int));
    cont_aux = 0;

    char  c;

    sub = malloc(sizeof(char));
    sub = fp;

    FILE* arq = fopen(sub, "r");

    if(arq == NULL)
    {
        printf("ARQUIVO INEXISTENTE - TENTE NOVAMENTE");
        return 1;
    }
    fseek(arq, 0, SEEK_SET);

    while(fgets(vetorPercorre,1000, arq) !=NULL )
    {

        fp = strtok(vetorPercorre," ,[]{}+\")(:%_/*;=?!.\n\0");

        while(fp != NULL)
        {

            if(fp)
            {

                if(verifica_lista (mp,fp))
                {
                    incrementa (mp,fp);
                }
                else
                {
                    insere_termo (mp,fp);

                }
            }

            fp = strtok(NULL, " ,[]{}+\")(:%_/*;= ? !.\n\0");
        }
    }
    return 0;
    fclose(arq);
}

// --------------------- FUNCOES DE POSSÍVEIS UTILIDADES FUTURAS ------------------------------------------------------- //

//retorna o contador do termo s
int le_contador (char *fp)
{

}

int escreve_cont (Mapa *mp, char *s, int c)
{
    int i;

    for(i = 0; i < mp->total; i++)
    {
        c = mp->lista[i]->conta;
        if (mp->lista[i]->termo == NULL )
        {

            return 1;
        }

        return c;

    }
    return 1;
    printf("\nA PALAVRA -> %s e o valor de i ->%i\n",mp->lista[i]->termo,i);

    //printf("\nA palavra -> %s possui contador igual a -> %i\n",mp->lista[i]->termo, c);
}

// copia o termo em t e retorna t
// c recebe o contador de termos e retorna

void le_termo (Mapa * mp, int i, char *t, int *c)  //retorna em "t" o termo no índice  "i"
{
//e em  "c" o seu contador
    for (i = 0; i < mp->total ; i++)
    {
        strcpy(t, mp->lista[i] -> termo);
    }
    c = mp -> lista[i] -> conta;
    return t,i;
}

// o usuario entra com a palavra que deseja remover
// a funcao faz uma varredura no mapa
// se encontrar libera o ponteiro que aponta para o termo na posicao i;
// decrementa o total de palavras

void remove_termo (Mapa *mp, char *s)// remove o item com termo s
{
    int i;
    printf("Entre com o termo que deseja remover");
    scanf("%s", s);
    for(i = 0; i< mp-> total; i++)
    {
        if(strcmp(mp->lista[i]->termo, s) ==0)
        {

            free(mp->lista[i]->termo);
            mp -> total -= 1;
        }
    }
}


void reorganiza_mapa(Mapa *mp, int i)
{
    Item *auxiliar;
    for (; i < mp->total ; i++)
    {

        auxiliar = mp->lista[i];
        mp->lista[i] = mp->lista[i+1];
        mp->lista[i+1] = auxiliar;
    }
}

