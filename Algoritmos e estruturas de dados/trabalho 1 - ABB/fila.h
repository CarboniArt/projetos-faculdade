#ifndef FILA_H
#define FILA_H

struct FilaNo {
    int info;
    FilaNo *link;
};

FilaNo *inicializaFila(FilaNo *L) {
    return NULL;
}

void imprimeFila(FilaNo *L) {
    FilaNo *P = L;    
    printf("\n Imprime Fila: \n");    
    while (P != NULL) {
        cout << P->info << " ";    
        P = P->link;
    }    
}

FilaNo *insereFila(FilaNo *L, int x) {
    FilaNo *N = new FilaNo;
    N->info = x;
    N->link = NULL;
     
    if (L == NULL) {
        L = N;
    } else {
        FilaNo *P = L;    
        while (P->link != NULL) {
            P = P->link;
        }
        P->link = N;    
    }
    return L;
}

FilaNo *removeFila(FilaNo *L, int *n) {
    if (L != NULL) {
        *n = L->info;
        FilaNo *AUX = L;
        L = L->link;
        delete AUX;
    } else {
        *n = 0;
    }
    return L;
}

#endif