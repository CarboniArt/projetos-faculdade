/*Ex1
#include <iostream>
using namespace std;
//função como eu faria semestre passado
int main()
{
    int n, total;
    cin >> n;
    do{
    total += n;
    n--;
    } while (n != 0);
    cout << total << endl;
    return 0;
}


//função com protótipo e interface
int somatorio(int n);

int main(){
    int n, total;
    cin >> n;
    total = somatorio(n);
    cout << total << end;
    return 0;
}

int somatorio(int n) {
    int total = 0;
    while (n > 0){
        total += n;
        n--;
    }
    return total;
}
*/

/*Ex2
#include <iostream>
using namespace std;
bool bissexto(int ano);
int main (){
  int ano;
  cin >> ano;
  if (bissexto (ano)){
      cout << ano << " e um ano bissexto" << endl;
    }
  else{
      cout << ano << " nao e um ano bissexto" << endl;
    }
    return 0;
}

bool bissexto(int ano){
  if (ano % 4 == 0 || ano % 400 == 0){
      if (ano % 100 == 0 && ano != 0){
	  return false;
	}
      else{
	  return true;
	}
    }
  else{
      return false;
    }
}
*/

/*ex3
#include <iostream>

using namespace std;
string binario(int n);
int main()
{
  int n;
  cin >> n;
  cout << binario(n);
}

string binario(int n)
{
    string b = "";
    while (n > 0){
        if (n % 2 != 0)
        { b = '1' + b;
        } else
        { b = '0' + b;
        }
        n /= 2;
    }
    return b;
}
*/

/* Ex4
#include <iostream>
#include <cctype>
using namespace std;

bool confere(string senha);

int main()
{
    string senha;
    bool checker = false;
    cin >> senha;
    while (checker == false){
        checker = confere(senha);
        if (checker == false){
            cout << "senha invalida" << endl;
            cin >> senha;
        }
    }
    cout << "senha valida" << endl;
}

bool confere (string senha){
    int tamanho, maiscula = 0, minuscula = 0, numero = 0;
    tamanho = senha.length();
    for (char c : senha) 
    {
        if (isdigit(c)) 
        { 
            numero++;
        }
        if (isupper(c)) 
        {
            maiscula++;
        } else
        { 
            minuscula ++;
        }
    }
    if (tamanho >= 8 && maiscula > 0 && minuscula > 0 && numero > 0){
        return true;
    } else 
    {
        return false;
    }
}
*/

/*Ex5
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double juros(float c, float i, int t);

int main()
{
    float c, i, m;
    int t;
    cout << "Insira o valor: ";
    cin >> c;
    cout << "Insira a taxa de juros: ";
    cin >> i;
    i = i / 100;
    cout << "Insira o tempo: ";
    cin >> t;
    m = juros(c, i, t);
    cout << fixed << setprecision(2) << "O valor será de: R$" << m << endl;
    return 0;
}

double juros(float c, float i, int t)
{
    double conta = 1 + i;
    return c * pow(conta, t);
}
*/

/*Ex6
#include <iostream>
using namespace std;

void organizar(int v[], int tamanho);

int main()
{
    int tamanho, numero;
    cin >> tamanho;
    int v[tamanho];
    for (int i = 0; i < tamanho; i++){
        cin >> numero;
        v[i] = numero;
    }
    organizar(v, tamanho);
     for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
}

void organizar(int v[], int tamanho) 
{
    for (int i = 0; i < tamanho - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (v[j] < v[minimo]) {
                minimo = j;
            }
        }
        int temp = v[i];
        v[i] = v[minimo];
        v[minimo] = temp;
    }
}
*/
