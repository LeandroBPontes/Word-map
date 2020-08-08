#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"
#include <locale.h>

// Funcao teste incompleta por problemas no contador dos termos

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int escolha, c;
    Mapa *mp;
    char *s, *fp;
    for(;;)
    {
        escolha = menu();
        switch(escolha)
        {
        case 1:
            inicia_mapa (mp);
            leitura_arquivo(mp,fp);

            /*if(fp){
            insere_termo (mp,s);
            incrementa (mp,s);
            c = le_contador (mp, s);
            escreve_cont (mp, s, c);
            }*/

            break;
        case 2:

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            exit(0);
            break;
        }
    }
}

