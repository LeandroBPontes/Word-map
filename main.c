#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Mapa.h"

//NAO ESQUECER DA FUNCAO FREEEEEEEE



int main(void)
{
    setlocale(LC_ALL, "");
    int escolha, c, v, i, x, cont = 0, qtd_max, qtd_min, *aux, ordenador =1, escolha_inicio, total;
    Mapa *mp;
    char *fp, *aux_termo, arq, *palavra, *arq2, *fp2;

    escolha_inicio =  menu();

    if(escolha_inicio == 1)
    {
        mp = malloc(sizeof(Mapa));
        inicia_mapa (mp);
        fp = malloc(sizeof(char));
        printf("\nEntre com o caminho do arquivo: ");
        scanf("%s",fp);
        fp2 = fp;
        leitura_arquivo(mp,fp);
    }
    else
    {
        printf("\n É necessario ler o arquivo primeiro\n");
        escolha_inicio =  menu();
        if(escolha_inicio == 1)
        {
            mp = malloc(sizeof(Mapa));
            inicia_mapa (mp);
            fp = malloc(sizeof(char));
            fp2 = malloc(sizeof(char));
            printf("\nEntre com o caminho do arquivo: \n");
            scanf("%s",fp);
            fp2 = fp;
            leitura_arquivo(mp,fp);
        }
        else
        {
            exit(0);
        }
    }
    for(;;)
    {
        escolha = menu();
        libera_mapa (mp);
        mp = malloc(sizeof(Mapa));
        inicia_mapa (mp);
        fp = fp2;
        leitura_arquivo(mp,fp);
        switch(escolha)
        {
        case 1:

            libera_mapa(mp);
            mp = malloc(sizeof(Mapa));
            inicia_mapa (mp);
            fp = malloc(sizeof(char));
            printf("\nEntre com o caminho do novo arquivo: ");
            scanf("%s",fp2);
            fp = fp2;
            leitura_arquivo(mp,fp);
            printf("\nArquivo lido com sucesso: ");
            system("pause");

            break;

        case 2:

            tamanho_mapa(mp);
            ordena_mapa(mp,fp);

            break;
        case 3:


            //mp = malloc(sizeof(Mapa));
            //fp = malloc(sizeof(char));
            aux = malloc(sizeof(int));
            aux_termo = malloc(sizeof(char));
            //inicia_mapa (mp);
            //printf("\nEntre com o caminho do arquivo: ");
            //scanf("%s",fp);
            //leitura_arquivo(mp,fp);
            printf("\nDigite a quantidade máxima: \n");
            scanf("%d", &qtd_max);
            printf("\nDigite a quantidade minima: \n");
            scanf("%d", &qtd_min);

            printf("\nPalavra ----------------Qtd\n");

            for(i=0; i < mp->total; i++)
            {

                if(mp->lista[i]->conta >= qtd_min && mp->lista[i]->conta <= qtd_max)
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
                        if(mp->lista[i]->conta >= qtd_min && mp->lista[i]->conta <= qtd_max)
                        {
                            cont++;
                        }
                    }
                    if(i ==mp->total){
                       printf("\nNumero de Palavras: %d\n", cont);
                    }

                      for(i=0; i < mp->total; i++)
                    {
                        if(mp->lista[i]->conta >= qtd_min && mp->lista[i]->conta <= qtd_max)
                        {
                            printf("\n%s----------------%d\n", mp->lista[i]->termo, mp->lista[i]->conta);
                        }
                    }
                }
            }
            for(i=mp->total; i > mp->total; i--)
            {
            free(aux);
            free(aux_termo);
            }
            break;
        case 4:
            aux = malloc(sizeof(int));
            palavra = malloc(sizeof(char));
            arq2 = malloc(sizeof(char));
            aux_termo = malloc(sizeof(char));
            printf("\nDigite a palavra-> ");
            scanf("%s", palavra);
            for(i=0; i < mp->total; i++)
            {
                if(strcasecmp(mp->lista[i]->termo, palavra)==0)
                {
                    cont = mp->lista[i]->conta;
                    arq2 = mp->lista[i]->termo;

                }

            }
            if(cont>=1)
            {
                printf("\nPalavra ------- qtd daqui");
                printf("\n%s-------------- %d\n", arq2, cont);

            }
            else
            {
                cont = 0;
                printf("\nPalavra ------- qtd");
                printf("\n%s-------------- %d\n", palavra, cont);

            }
            cont = 0;
            free(arq2);
            free(palavra);

            break;
        //ESCOLHA 5
        case 5:

            printf("\nDigite o mínimo de palavras a considerar\n");
            scanf("%i", &v);
            for(i=0; i < mp->total; i++)
            {
                x = strlen(mp->lista[i]->termo);
                if(v == x)
                {
                    cont++;
                }
            }
            if(cont == 0)
            {
                printf("\nNão há palavras com esse tamanho\n");
            }
            else
            {
                printf("\nTotal de Palavras -> %i\n", cont);
            }


            break;
        case 6:
            libera_mapa(mp);
            exit(0);
            break;

        }
    }
}
