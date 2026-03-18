#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#include "ABB.h"
#include "Fila.h"

int main(void) {
    no *T;
    int x, c;

    T = ini_AB(T);
   
    do {
        printf("\n");
        printf("1 - Insere Item na ARVORE DE BUSCA BINARIA\n");
        printf("5 - PERCURSO EM LARGURA - TA1\n");
        printf("8 - Zerar a ARVORE DE BUSCA BINARIA\n");
        printf("9 - SAIR\n");
        printf("\n Escolha: ");

        cin >> c;

        switch(c) {
            case 1: 
                while (true) { 
                cout << " \nEntre com o item a ser inserido (digite -1 para parar): ";
                cin >> x;
                if (x == -1) {
                break; 
                }
                T = insere_AB(T, x);
            }
            break;
            case 5:
                percursoLargura(T);
                printf("\n");
                break;
            case 8: 
                libera_AB(T);
                T = ini_AB(T);
                cout << "Arvore zerada!\n";
                break;
            case 9:
             exit(0);
               
        }
    } while (c != 9);
    
    return 0;
}