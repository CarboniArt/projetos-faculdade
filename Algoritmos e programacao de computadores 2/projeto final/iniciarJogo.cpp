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
	#define L 10
	#define C 7
	#define R 5
	
	using namespace std;
	
	int pontuacao = 0;
	int ranke[R] = {0};
	string nick[R] = {" "};
	string rankn[R] = {" "};
	
	void leaderboards(){
		int ranking[3], pontuacao, aux;
		for (int i = 0; i < 3; i++){
			if (ranking[i + 1] < pontuacao){
				aux = ranking [i + 1];
				ranking[i + 1] = pontuacao;
				pontuacao = aux;
			}
		}
	};
	
	void imprimirmorte(){
		string finalcav = "  .='`\"=.";
		cout <<"    .-. \n";
		usleep(200000);
		cout <<"   (0.0) \n";
		usleep(200000);
		cout <<" '=.|m|.='\n";
		usleep(200000);
		cout <<finalcav << endl;
		usleep(200000);
		cout << "                \n";
	};
	void imprimirarte(){
		
		cout << "                  .   ,- Continue a voar!\n";
		usleep(200000);
		cout << "                 .'.\n";
		usleep(200000);
		cout << "                 |o|\n";
		usleep(200000);
		cout << "                .'o'.\n";
		usleep(200000);
		cout << "                |.-.|\n";
		usleep(200000);
		cout << "                '   '\n";
		usleep(200000);
		cout << "                 ( )\n";
		usleep(200000);
		cout << "                  )\n";
		usleep(200000);
		cout << "                 ( )\n";
		cout << "                 \n";
	
	};
	
	void inicializarBordas(char matriz[L][C]) {
	    for (int i = 0; i < L; i++) {
	        for (int j = 0; j < C; j++) {
	            matriz[i][j] = ' ';
	            matriz[0][j] = '_';
	            matriz[i][0] = '#';
	            matriz[i][C - 1] = '#';
	        }
	    }
	    for (int j = 0; j < C - 2; j++) {
	        matriz[9][j + 1] = '|';
	    }
	
	};
	
	void criarObstaculos(char matriz[L][C]) {
	    for (int j = 0; j < C - 2; j++) {
	        if (rand() % 8 == 1) {
	            matriz[1][j + 1] = 'O';
	        }
	    }
	};
	
	void moverObstaculos(char matriz[L][C]) {
	    for (int i = L - 1; i >= 0; i--) {
	        for (int j = 0; j < C; j++) {
	            if (matriz[i][j] == 'O' && i < L - 1) {
	                matriz[i][j] = ' ';
	                matriz[i + 1][j] = 'O';
	            }
	        }
	    }
	    for (int j = 0; j < C; j++) {
	            if (matriz[L - 2][j + 1] == 'O') {
	                matriz[L - 2][j + 1] = ' ';
	            }
	    }
	};
	
	void exibirMatriz(char matriz[L][C]) {
	    system("clear||cls");
	    for (int i = 0; i < L; i++) {
	        for (int j = 0; j < C; j++) {
	            cout << matriz[i][j] << " ";
	        }
	        cout << endl;
	    }
	};
	
	char obterTeclaPressionada() {
    if (_kbhit()) {
        return _getch();
    }
    return ' ';
}
	
	char inicializarMatriz(int velocidade) {
	    char matriz[L][C];
	    int limite[2] = {1,5};
	    int V = 7, H = 3;
	    bool vivo = true;
	    char direcao = ' ';
	    char teclaPressionada = ' ';
	    int pontuacao = 0;
	
	    inicializarBordas(matriz);
	    criarObstaculos(matriz);
	    matriz[V][H] = '^';
	    while (vivo) {
	    	
	        moverObstaculos(matriz);
	        criarObstaculos(matriz);
	
	        matriz[V][H] = '^';
	        exibirMatriz(matriz);
	
	        teclaPressionada = obterTeclaPressionada();
	        switch (teclaPressionada) {
	            case 'a':
	                matriz[V][H] = ' ';
	                H--;
	                if(H < limite[0]){
	                	H++;
					}
	                if(matriz[V][H] == 'O'){
	                	vivo = false;
					}
	                break;
	                
	            case 75:
	            	matriz[V][H] = ' ';
	                H--;
	                if(H < limite[0]){
	                	H++;
					}
	                if(matriz[V][H] == 'O'){
	                	vivo = false;
					}
	                break;
	                
	            case 'd':
	                matriz[V][H] = ' ';
	                H++;
	                if(H > limite[1]){
	                	H--;
					}
	                if(matriz[V][H] == 'O'){
	                	vivo = false;
					}
	                matriz[V][H] = '^';
	                break;
	            case 77:
	        		matriz[V][H] = ' ';
	                H++;
	                if(H > limite[1]){
	                	H--;
					}
	                if(matriz[V][H] == 'O'){
	                	vivo = false;
					}
	                matriz[V][H] = '^';
	                break;
	        }
	        if(matriz[V-1][H] == 'O' && matriz[V][H] == '^'){
	    		vivo = false;
			}
	    
	        usleep(velocidade);
		pontuacao++;
		usleep (20000);
	    }
		return pontuacao;
	};
	
	void jogar(int velocidade) {
		string nick;
		
		cout << "Digite seu nick: ";
		cin >> nick;
		cout << endl << "Boa Partida " << nick << endl;
	    int pontuacao = inicializarMatriz(velocidade);
		cout << "voce morreu"<< endl;
		imprimirmorte();
		cout << "Sua Pontuacao foi de " << pontuacao << endl;
		for(int i = 0; i < 5; i++){
			if(pontuacao > ranke[i]){
				cout << "voce entrou no rank" << endl;
				int aux = ranke[i];
				string auxN = rankn[i];
				ranke[i] = pontuacao;
				rankn[i] = nick;
				rankn [i + 1] = auxN; 
				ranke[i + 1] = aux;
				int j = i + 2;		
				while(j < 5){
					aux = ranke[j + 1];
					ranke[j+1] = ranke[j];
					ranke[j + 2] = aux;	
					j +=2;
				}
				
				break;
			}
	}
	usleep(2000000);
	};
	
	void exibirleaderboards(){
		for(int i = 0; i < 5; i++){
		cout << "Top " << i + 1 << " = " << rankn[i] << " com " << ranke [i] << " pontos. \n";
		}
	};
	void mododejogo(){
		char escolha = 0;
			cout << "Escolha uma dificuldade" << endl;
	        cout << "1 - Facil" << endl;
	        cout << "2 - Medio" << endl;
	        cout << "3 - Dificil" << endl;
	        cin >> escolha;
	        switch(escolha){
	            case '1': 
	                jogar(400000);
	                break;
	            case '2':
	            	jogar(200000);
	                break;
	            case '3':
	            	jogar(100000);
	                break;
	            default:
	                cout << "Escolha invalida" << endl;
	        };
	};
	void menu(){
	    char opcao = 0, escolhida;
	    string bemvindo = "Bem vindo a bordo, prepare-se para uma viagem espacial :)";
	    int x = bemvindo.length();
	    imprimirarte();
	    usleep(200000);
	  	for (int i = 0; i < x; i++){
	  		cout << bemvindo[i];
	  		usleep (30000);
		  }
		cout << endl;
		usleep(2000000);
		
	    do{
	        cout << "Escolha uma opcao" << endl;
	        cout << "1 - Jogar" << endl;
	        cout << "2 - Leaderboards" << endl;
	        cout << "3 - sair" << endl;
	        cin >> escolhida;
	
	        switch(escolhida){
	            case '1': 
	                mododejogo();
	                break;
	            case '2':
	            	exibirleaderboards();
	                break;
	            case '3':
	            	system("clear||cls");
	            	cout << "Obrigado pela diversao!" << endl; 
	            	exit(0);
	            	break;
	            default:
	            	system("clear||cls");
	                cout << "Escolha invalida" << endl;
	                sleep(3);
	                system("clear||cls");
	        };
	
	    }while(opcao != 4);
	};
	void advinha() {
	   int pergunta;
	    int numero;
	    string boas_vindas = "Ola, viajante! Fico contente em te ter aqui!!!";
	    int x1 = boas_vindas.length();
	    for (int i = 0; i < x1; i++) {
	        cout << boas_vindas[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string introducao = "Antes de partimos para a aventura, temos de fazer um teste neurologico para ver se voce esta apto a jogar";
	    int x2 = introducao.length();
	    for (int i = 0; i < x2; i++) {
	        cout << introducao[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string aceitarcondicoes = "Voce aceita nossas condicoes?";
	    int x3 = aceitarcondicoes.length();
	    for (int i = 0; i < x3; i++) {
	        cout << aceitarcondicoes[i];
	        usleep(45000);
	    }
	    cout << endl;
	    cout << endl;
	    cout << "1 - sim     2 - nao" << endl;
	    cin >> pergunta;
	    if (pergunta != 1) {
	        cout << "Obrigado pela diversao!" << endl;
	        usleep(450000);
	        exit(0);
	    }
	    usleep(600000);
	    system("clear||cls");
	    string instrucao_adivinhacao = "Muito bem! Antes de mais nada, faremos um teste de advinhacao";
	    int x4 = instrucao_adivinhacao.length();
	    for (int i = 0; i < x4; i++) {
	        cout << instrucao_adivinhacao[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string resumo_adivinhacao = "Em resumo, voce deve pensar e insira um numero para que o algoritmo tente advinhar";
	    int x5 = resumo_adivinhacao.length();
	    for (int i = 0; i < x5; i++) {
	        cout << resumo_adivinhacao[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string acesso_jogo = "caso ele acerte, lhe darei acesso a este incrivel jogo.";
	    int x6 = acesso_jogo.length();
	    for (int i = 0; i < x6; i++) {
	        cout << acesso_jogo[i];
	        usleep(70000);
	    }
	    system("clear||cls");
	    string pensar_numero = "Pense e insira em um numero de 1 a 1000 para o algoritmo advinhar";
	    int x7 = pensar_numero.length();
	    for (int i = 0; i < x7; i++) {
	        cout << pensar_numero[i];
	        usleep(45000);
	    }
	    cout << endl;
	    cin >> numero;
	    cout << endl;
	    string analisando_ondas = "analisando ondas cerebrais...";
	    int x8 = analisando_ondas.length();
	    for (int i = 0; i < x8; i++) {
	        cout << analisando_ondas[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string escaneando_memorias = "Escaneando memorias...";
	    int x9 = escaneando_memorias.length();
	    for (int i = 0; i < x9; i++) {
	        cout << escaneando_memorias[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string calculando_probabilidades = "calculando probabilidades...";
	    int x10 = calculando_probabilidades.length();
	    for (int i = 0; i < x10; i++) {
	        cout << calculando_probabilidades[i];
	        usleep(45000);
	    }
	    cout << endl;
	    string numero_adivinhado = "VOCE ESTA PENSANDO NO NUMERO ";
	    int x11 = numero_adivinhado.length();
	    for (int i = 0; i < x11; i++) {
	        cout << numero_adivinhado[i];
	        usleep(45000);
	    }
	    cout << numero << "." << endl;
	    usleep(3000000);
	    system("clear||cls");
	};
		
		
		
	
	int iniciarJogo(){
	    srand(time(NULL));
	    advinha();
	    menu();
	    return 0;
	};
