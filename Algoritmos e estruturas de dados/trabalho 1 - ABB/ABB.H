#ifndef ABB_H
#define ABB_H

#include "Fila.h"  

struct no {
    int info;
    no *Llink;
    no *Rlink;
};

no *ini_AB(no *T) {
    return NULL;
}

no *novoNo_AB(no *T, int x) {
    T = new no;
    if (T != NULL) {
        T->info = x;
        T->Llink = NULL;
        T->Rlink = NULL;
    }
    return T;
}

no *insere_AB(no *T, int x) {
    if (T == NULL) {
        T = novoNo_AB(T, x);
        return T;
    } else {
        if (x < T->info) { 
            T->Llink = insere_AB(T->Llink, x);
        } else {     
            T->Rlink = insere_AB(T->Rlink, x);
        }
        return T;
    }
}


void percursoLargura(no *T) {
    if (T == NULL) return;

    FilaNo *fila = inicializaFila(NULL);
    fila = insereFila(fila, T->info);

    int nivelAtual = 1;
    int proximosNoNivel = 0;
    int nosNoNivel = 1;

    while (fila != NULL) {
        int info;
        fila = removeFila(fila, &info);
        

        no *current = T;
        while (current != NULL && current->info != info) {
            if (info < current->info) {
                current = current->Llink;
            } else {
                current = current->Rlink;
            }
        }

       
        if (current != NULL) {
            cout << current->info << " ";

           
            if (current->Llink != NULL) {
                fila = insereFila(fila, current->Llink->info);
                proximosNoNivel++;
            }
            if (current->Rlink != NULL) {
                fila = insereFila(fila, current->Rlink->info);
                proximosNoNivel++;
            }
        }

        nosNoNivel--;

    
        if (nosNoNivel == 0) {
            cout << endl;
            nosNoNivel = proximosNoNivel;
            proximosNoNivel = 0;
            nivelAtual++;
        }
    }
}

    void libera_AB(no *T) {
    if (T != NULL) {
        libera_AB(T->Llink);  
        libera_AB(T->Rlink); 
        delete T;             
    }
    }


#endif