#ifndef iniciarJogo_HPP
#define iniciarJogo_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <conio.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string>
#include <stdio.h>
	
using namespace std;

#define L 10
#define C 7
#define R 5

extern int pontuacao;
extern int ranke[R];
extern std::string nick[]; // Corrigido aqui
extern std::string rankn[R];

void leaderboards();
void imprimirmorte();
void imprimirarte();
void inicializarBordas(char matriz[L][C]);
void criarObstaculos(char matriz[L][C]);
void moverObstaculos(char matriz[L][C]);
void exibirMatriz(char matriz[L][C]);
char obterTeclaPressionada();
char inicializarMatriz(int velocidade);
void jogar(int velocidade);
void exibirleaderboards();
void mododejogo();
void menu();
void advinha();
int iniciarJogo();

#endif // JOGO_HPP
