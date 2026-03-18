#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>
#include "FilaPrioridadesLE.h"

#include <windows.h>

using namespace std;

void imprimirArte();

int geraNumeroAleatorio();

void preenche(no *&P);

void adiciona(no *&Lista, no *&P, ofstream &logFile, int t);

void instante_func(no *&P, int t, int pista, ofstream &logFile);

void limpaTela();


int main() {
    imprimirArte();
    srand(time(NULL));

    ofstream logFile("logAvioes.txt");

    int t = 1;

    no *Lista = inicializaFP(nullptr);
    no *Pista1 = inicializaFP(nullptr);
    no *Pista2 = inicializaFP(nullptr);
    no *Pista3 = inicializaFP(nullptr);

    preenche(Lista);

    for (int i = 0; i < 35; i++) {
        int j = i;
        if (i == 34) {
            cout << "Instante " << i << " : Todos os avioes alocados com sucesso!" << endl;
            logFile << "Instante " << i << " : Todos os avioes alocados com sucesso!\n";
            break;
        } else {
            if (i == 1) {
                cout << "instante " << i << ": Pistas livres, alocando avioes\n" << endl;
                logFile << "Instante " << i << ": Pistas livres, alocando avioes\n\n";
                adiciona(Lista, Pista1, logFile, i);
                adiciona(Lista, Pista2, logFile, i);
                adiciona(Lista, Pista3, logFile, i);
                cout << "\n\nLista de espera:" << endl;
                exibe(Lista);
                cout << endl;
            } else {
                if (i % 2 != 0) {
                    cout << "Instante " << i << ": pistas livres, alocando avioes\n" << endl;
                    logFile << "Instante " << i << ": pistas livres, alocando avioes\n\n";
                    adiciona(Lista, Pista1, logFile, i);
                    adiciona(Lista, Pista2, logFile, i);
                    adiciona(Lista, Pista3, logFile, i);
                    cout << endl;
                    cout << "Lista de espera:" << endl;
                    exibe(Lista);
                    cout << endl;
                } else {
                    instante_func(Pista1, j, 1, logFile);
                    instante_func(Pista2, j, 2, logFile);
                    instante_func(Pista3, j, 3, logFile);
                    cout << endl;
                }
            }
        }

        Sleep(1500);

        limpaTela();
    }

    logFile.close();
    return 0;
}


void imprimirArte() {
    cout << "                __|__\n";
    Sleep(300);
    cout << "                \\___/\n";
    Sleep(300);
    cout << "                 | | Bem vindo a maior pista de \n";
    Sleep(300);
    cout << "                 | | Controle de Trafego Aereo\n";
    Sleep(300);
    cout << "               __|_|______________\n";
    Sleep(300);
    cout << "                       /|\\ \n";
    Sleep(300);
    cout << "                     */ | \\*\n";
    Sleep(300);
    cout << "                     / -+- \\\n";
    Sleep(300);
    cout << "                 ---o--(_)--o---\n";
    Sleep(300);
    cout << "                   /  0 \" 0  \\\n";
    Sleep(300);
    cout << "                 */     |     \\*\n";
    Sleep(300);
    cout << "                 /      |      \\\n";
    Sleep(300);     
    cout << "               */       |       \\*\n";
    Sleep(300);
    cout << "\\ `/ |\n";
    cout << " \\__`!\n";
    cout << " / ,' `-.__________________\n";
    cout << "'-\'\\_____                  `-.\n";
    cout << "   <____()-=O=O=O=O=O=[]====--)\n";
    cout << "     `.___ ,-----,_______...-'\n";
    cout << "          /    .'\n";
    cout << "         /   .'\n";
    cout << "        /  .'         \n";
    cout << "        `-'\n";

    Sleep(3000);

    system("cls");
}

int geraNumeroAleatorio() {
    return rand() % 3 + 1;
}

void preenche(no *&P) {
    int numAviao;
    int numPrioridade;
    for (int i = 1; i <= 50; i++) {
        numPrioridade = geraNumeroAleatorio();
        numAviao = i;
        P = insereFP(P, numAviao, numPrioridade, 0);
    }
}

void adiciona(no *&Lista, no *&P, ofstream &logFile, int t) {
    int numAviao = Lista->info;
    int numPrioridade = Lista->prior;
    int instanteChegada = Lista->instanteChegada;
    int num, prior, chegada;

    P = insereFP(P, numAviao, numPrioridade, instanteChegada);

    int tempoEspera = t - instanteChegada;

    if (P->prior == 1 || P->prior == 2) {
        cout << "Aviao " << numAviao << " Iniciando pouso" << endl;
        logFile << "Aviao " << numAviao << "\nPrioridade: " << numPrioridade << "\nInstante de pouso: " << t << "\nTempo de espera: " << tempoEspera << " minuto(s)\n\n";
    } else if (P->prior == 3) {
        cout << "Aviao " << numAviao << " Iniciando decolagem" << endl;
        logFile << "Aviao " << numAviao << "\nPrioridade: " << numPrioridade << "\nInstante de decolagem: " << t << "\nTempo de espera: " << tempoEspera << " minuto(s)\n\n";
    }

    Lista = removeFP(Lista, &num, &prior, &chegada);

    Sleep(500);
}
 
void instante_func(no *&P, int t, int pista, ofstream &logFile) {
    if (P != NULL) {
        int numAviao = P->info;
        int numPrioridade = P->prior;
        int instanteChegada = P->instanteChegada;

        int tempoEspera = t - instanteChegada;

        if (P->prior == 1 || P->prior == 2) {
            cout << endl;
            cout << "Instante " << t << ": Pista " << pista << " ocupada, aviao pousando (Prioridade " << P->prior << ")" << endl;
            logFile << "Aviao " << numAviao << "\nPrioridade: " << numPrioridade << "\nInstante de pouso: " << t << "\nTempo de espera: " << tempoEspera << " minuto(s)\n\n";
        } else if (P->prior == 3) {
            cout << endl;
            cout << "Instante " << t << ": Pista " << pista << " ocupada, aviao decolando (Prioridade " << P->prior << ")" << endl;
            logFile << "Aviao " << numAviao << "\nPrioridade: " << numPrioridade << "\nInstante de decolagem: " << t << "\nTempo de espera: " << tempoEspera << " minuto(s)\n\n";
        }
        
        int num, prior, chegada;
        P = removeFP(P, &num, &prior, &chegada);

        Sleep(500);
    }
}

void limpaTela() {
    system("cls");
}
