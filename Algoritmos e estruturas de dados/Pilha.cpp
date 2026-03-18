#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unistd.h>
#include <windows.h>

using namespace std;

void imprimir ();
int cartas();
void preencheBaralho(stack<int>& baralho, int numCartas); 
int carta(stack<int>& baralho); 
void partida (int rodadas, const string& p1, const string& p2, stack<int>& baralho);



int main() {

    imprimir ();

    srand(time(NULL));

    stack<int> baralho;
    
    preencheBaralho(baralho, 40);

    int rodadas;
    
    string p1, p2;

    cout << "Digite o nome do primeiro jogador" << endl;
    cin >> p1;

    cout << "Digite o nome do segundo jogador" << endl;
    cin >> p2;

    cout << "Escolha o numero de rodadas que deseja jogar" << endl;
    cin >> rodadas;
    system("cls");
    partida (rodadas, p1, p2, baralho);
    return 0;
}

void imprimir() {
    cout << "  _____  " << endl;
    cout << " |2    | " << endl;
    cout << " | / \\ | " << endl;
    cout << " | \\ / | " << endl;
    cout << " |  .  | " << endl;
    cout << " |____2| " << endl;

    string bemvindo = "Seja bem vindo ao CODIGO SECRETO: o game onde a intuicao define o ganhador! \n";
    int x = bemvindo.length();
    usleep(200000);
    for (int i = 0; i < x; i++) {
        cout << bemvindo[i];
        usleep (30000);
    }
    sleep(2);
    system("cls");


}


int cartas() {
    return rand() % 8 + 1;
}

void preencheBaralho(stack<int>& baralho, int numCartas) { 
    for (int i = 0; i < numCartas; i++) {
        baralho.push(cartas());
    }
}

int carta(stack<int>& baralho) {
    if (!baralho.empty()) {
        int n = baralho.top();
        baralho.pop();
        return n;   
    } 
    return -1;   
}

void partida (int rodadas, const string& p1, const string& p2, stack<int>& baralho){
    int num1, num2;
    int pontos1 = 0, pontos2 = 0;
    int dif1, dif2;
    int nSort;
    for(int i = 0; i < rodadas; i++){
        sleep(1); 
        cout << "Rodada " << i + 1 << endl;
        cout << p1 << " Adivinhe o numero" << endl;
        cin >> num1;
        cout << p2 << " Adivinhe o numero" << endl;
        cin >> num2;
        nSort = carta(baralho);
        cout << "\n Carta sorteada:" << endl;
        cout << "  _____  " << endl;
        cout << " |" << nSort << "    | " << endl;
        cout << " | / \\ | " << endl;
        cout << " | \\ / | " << endl;
        cout << " |  .  | " << endl;
        cout << " |____" << nSort << "| " << endl;

            if(nSort > num1){
                dif1 = nSort - num1;
            }else{
                if(nSort < num1){
                    dif1 = num1 - nSort;
                }
            }

            if(nSort > num2){
                dif2 = nSort - num2;
            }else{
                if(nSort < num2){
                    dif2 = num2 - nSort;
                }
            }

            if (num1 == num2 && num1 == nSort){
                pontos1 += 3;
                pontos2 += 3;
                cout << " Ambos acertaram \n";
            }
            else if(num1 == nSort ){
                pontos1 += 3;
                cout << p1 << " acertou! \n";
            }
            else if(num2 == nSort ){
                pontos2 += 3;
                cout << p2 << " acertou! \n";
            }
            else if(dif1 < dif2){
                pontos1++;
                cout << p1 << " marcou! \n";
            }else{
                if(dif1 > dif2){
                    pontos2++;
                    cout << p2 << " marcou! \n";
                }else{
                    if(dif1 == dif2){
                        pontos1++;
                        pontos2++;
                        cout << "Ambos marcaram! \n";
                    }
                }
            }
            sleep(2); 
            system("cls");
    }
    sleep(1); 
    cout << "Pontuacao de " << p1 << ": " << pontos1 << endl;
    cout << "Pontuacao de " << p2 << ": " << pontos2 << endl;
    if(pontos1 > pontos2){
        cout << p1 << " Venceu!" << endl;
    }else{
        if(pontos1 < pontos2){
            cout << p2 << " Venceu!" << endl;
        }else{
            if(pontos1 == pontos2){
                cout << "Empate!" << endl;
            }
        }
    }

    char SN;
    string novamente = "Deseja jogar novamente s/n";
    cout << endl;
    int x = novamente.length();
    usleep(200000);
    for (int i = 0; i < x; i++) {
        cout << novamente[i];
        usleep (30000);
    }
    cin >> SN;
    if (SN == 's'){
        main();

    } 
    system("cls"); 

}