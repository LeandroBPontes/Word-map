#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"
#define TAM 10

//chamadas das funcoes para inicializar e executar as opções
int menu(void)
{
    int c;
    printf("Menu:\n");
    printf("1. Ler arquivo txt\n");
    printf("2. Exibir ranking completo\n");
    printf("3. Exibir intervalo de Ranking\n");
    printf("4. Buscar palavra\n");
    printf("5. Opções\n");
    printf("6. Sair\n");
    do
    {
        printf("\nEntre com sua escolha: ");
        scanf("%i", &c);
        c;
    }
    while(c<0 || c>6);

    return c;
}
//inicia um mapa vazio

void inicia_mapa (Mapa *mp)
{
    int i;
    mp -> total = 0;
    mp -> blocos = 1;

    mp -> lista = malloc(TAM * sizeof(Item*));
    if (mp -> lista == NULL)
    {
        printf("nao foi possivel alocar");
    }

    for (i = 0; i < TAM; i++)
    {
        mp -> lista[i] = calloc(1, sizeof(Item));
       //mp -> lista[i] = malloc(sizeof(Item));
        //mp->lista[i]->termo = 0;
        //mp->lista[i]->conta = 0;
       // printf("iTEM -> %i", mp->lista[i]->termo);
    }
    if (mp -> lista[i-1] == NULL)
    {
        printf("nao foi possivel alocar 1");
    }   else{printf("Alocado com sucesso");}

}

//inserida na funcao leitura_arquivo
// recebe uma palavra por vez e faz um malloc do tamanho da palavra
// busca o tamanho da palavra em x e realloca caso ultrapasse o espaco reservado

void insere_termo (Mapa *mp, char *s)
{

    int i, x;

    //x = strlen(s);
    //printf("\nTAMNHO ->  %d", x);
     mp -> total++;
     x = strlen(s);

    for (i = 0; i <= mp->total; i++)
    {
        mp->lista[i]->termo = malloc(x * sizeof(char));

        if( mp->lista[i]->termo == NULL)
        {
            printf("\nIMPOSSIVEL MALOCAR");
        }
        strcpy(mp->lista[i]->termo, s);
        printf("\n %s [%i] -> %i \n", mp->lista[i]->termo, i, mp->total);


        if(mp -> total >= TAM * mp->blocos)
        {
            mp->blocos++;
            mp -> lista = realloc(mp->lista, mp->blocos * TAM * sizeof(Item*));
            for(i = 0; i<= mp->blocos * TAM; i++){
            mp -> lista[i] = realloc(mp->lista[i], sizeof(Item));
            }

        }

    }

}

// incrementa contador do termo s, retorna 1 se não encontrou o termo
int incrementa (Mapa *mp, char *s)
{
    int i;

    //printf("valor -> %i", mp->blocos*TAM);
    for(i=0; i < mp->total; i++)
    {

        if(strcasecmp(mp->lista[i]->termo, s)==0)
        {
            //
            mp -> lista[i]->conta++;


        }


    }
   // printf("\nA palavra -> %s possui contador igual a -> %i\n",mp->lista[i]->termo,  mp -> lista[i]->conta);
    return 1;
    //printf("\nA PALAVRA -> %s e o valor de i ->%i\n", s,i);

}

//retorna o contador do termo s
int le_contador (Mapa *mp, char *s)
{

    int i, c;
    c = mp->lista[i]->conta;
    for(i = 0; i < mp->total; i++)
    {
        if (mp->lista[i]->termo == NULL )
        {

        return 1;
        }

  }
  return c;
}

int escreve_cont (Mapa *mp, char *s, int c)
{

    int i;

    mp->total;
    for(i = 0; i < mp->total; i++)
    {
        c = mp->lista[i]->conta;



        if (mp->lista[i]->termo == NULL )
        {

        return 1;
        }

    }
  // printf("\nO contador de %s vale -> %i\n",s, c);


       //printf("\nO total vale -> %i\n", x);
}



 //Retorna a quantidade de palavras inseridas no mapa

int tamanhoMapa(Mapa *mp)
{
    return mp->total;
    //printf("O tamanho do mapa é -> %i", mp->total);
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
// reorganiza os termos com um auxiliar realizando a troca

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

// usuario entra com o nome do arquivo
// sao chamadas duas funcoes
// problemas com o contador da funcao incrementa
void leitura_arquivo(Mapa *mp, char *fp)
{

    // preencher com os termos do arquivo
    char vetorPercorre[1000];
    int i;

    // ponteiro que recebera o endereco dos termos do arquivo
    char *sub;


    char  c;
     printf("\nEntre com o caminho do arquivo: ");
            sub = malloc(sizeof(char));
            scanf("%s",sub);

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
        //ptr = strtok(vetorPercorre, corre);
        //printf("\nRetorno = %s", vetorPercorre);
        while(fp != NULL)
        {
         //printf("\nRetorno = %s", sub);

        if(fp){
            insere_termo (mp,fp);
            incrementa (mp,fp);
            c = le_contador (mp, fp);
            escreve_cont (mp,fp,c);
            tamanhoMapa(mp);

       // printf("\n %s = %i", sub);
        }
        fp = strtok(NULL, " ,[]{}+\")(:%_/*;= ? !.\n\0");
        }
    }
    printf("\nTamanho do mapa = %i\n", mp->total);
    printf("\n FIM");
    return 0;
    fclose(arq);
}






