#include <iostream>
#include <fstream> //Fornece classes e funções para trabalhar com arquivos de entrada e saída
#include <string>
#include <vector> //vetor dinamico
#include <unistd.h> //sleep
#include <cstdlib> //alocacao de memoria dinamica
#include <ctime> 
#include <random>
#include <chrono> //f. medicao de tempo
#include <thread>
#include <stdio.h> //f com e/s
#include <algorithm> 
#include <limits> //limite numerico de um dado
#include <cassert> 
#include <cctype> //manipular caracter
#include "iniciarJogo.hpp" // inclui o cabeçalho para iniciarJogo

using namespace std;

#define L 10
#define C 7
#define R 5


struct Jogo;


void imprimirArtePrincipal();
void bemVindo();
void menuPrincipal(vector<Jogo>& jogos);
void fraseMenu();
void adicionarJogo(vector<Jogo>& jogos); 
void listarJogos(vector<Jogo>& jogos);
void salvarJogos(const vector<Jogo>& jogos);
void carregarJogos(vector<Jogo>& jogos, int& ultimoNumeroChegada);
int iniciarJogo(); // Protótipo da função iniciarJogo()
void excluirJogo(vector<Jogo>& jogos);
void fraseTeimoso();
void ordenarPorChegada(vector<Jogo>& jogos);
void ordenarPorNota(vector<Jogo>& jogos);
void editarJogoPorNome(vector<Jogo>* jogos);
void adicionarJogo(vector<Jogo>& jogos, int& ultimoNumeroChegada);
void num (vector<Jogo>& jogos);
bool ehAlfanumericoComTamanho(const string& str, size_t maxTam);
bool ehApenasLetrasComTamanho(const string& str, size_t maxTam);
bool ehNumeroEntre(int num, int min, int max);
bool ehFloatEntre(float num, float min, float max);
void lerIntValidado(int& input, int min, int max);
void lerFloatValidado(float& input, float min, float max);
int contador = 0;
int ultimoNumeroChegada;


struct Jogo {
    int numeroChegada;
    string nome;
    int anoLancamento;
    string genero;
    string plataforma;
    string modosDeJogo;
    string desenvolvedora;
    float nota;
};

//nao rolou prototipo ??

void lerStringValidada(string& input, size_t maxTam, bool apenasLetras = true, bool alfanumerico = false) {
    getline(cin, input);
    while (((apenasLetras && !ehApenasLetrasComTamanho(input, maxTam)) ||
            (alfanumerico && !ehAlfanumericoComTamanho(input, maxTam))) ||
            (!apenasLetras && !alfanumerico && input.length() > maxTam)) {
        cout << "Entrada invalida. Por favor, insira novamente (max. " << maxTam << " caracteres): ";
        getline(cin, input);
    }
}


void testeAdicaoOrdenacaoEdicaoExclusao(vector<Jogo>& jogos) {
	if (!jogos.empty()) {
        return;
    }
    
    size_t tamanhoInicial = jogos.size();
    
    Jogo jogo1;
    jogo1.numeroChegada = jogos.size() + 1;
    jogo1.nome = "Teste Jogo 1";
    jogo1.anoLancamento = 2022;
    jogo1.genero = "Acao";
    jogo1.plataforma = "PC";
    jogo1.modosDeJogo = "Singleplayer";
    jogo1.desenvolvedora = "DevTeste";
    jogo1.nota = 9.0;
    jogos.push_back(jogo1);

    Jogo jogo2;
    jogo2.numeroChegada = jogos.size() + 1;
    jogo2.nome = "Teste Jogo 2";
    jogo2.anoLancamento = 2021;
    jogo2.genero = "Aventura";
    jogo2.plataforma = "Console";
    jogo2.modosDeJogo = "Multiplayer";
    jogo2.desenvolvedora = "DevTeste";
    jogo2.nota = 8.5;
    jogos.push_back(jogo2);

    assert(jogos.size() == tamanhoInicial + 2);

    // Teste ordenação por chegada
    bool ordenadoPorChegada = true;
    for (size_t i = 1; i < jogos.size(); i++) {
        if (jogos[i - 1].numeroChegada > jogos[i].numeroChegada) {
            ordenadoPorChegada = false;
            break;
        }
    }
    assert(ordenadoPorChegada);

    // Teste ordenação por nota
    bool ordenadoPorNota = true;
    for (size_t i = 1; i < jogos.size(); i++) {
        if (jogos[i - 1].nota < jogos[i].nota) {
            ordenadoPorNota = false;
            break;
        }
    }
    assert(ordenadoPorNota);

    // Teste editar jogo por nome
    string nomeJogoEditar = "Teste Jogo 1"; // Editando o primeiro jogo adicionado
    int novoAnoLancamento = 2023;
    string novoGenero = "Acao";
    string novaPlataforma = "Console";
    string novosModosDeJogo = "Multiplayer";
    string novaDesenvolvedora = "DevTesteNova";
    float novaNota = 9.5;

    bool editadoCorretamente = false;
    for (auto& jogo : jogos) {
        if (jogo.nome == nomeJogoEditar) {
            jogo.anoLancamento = novoAnoLancamento;
            jogo.genero = novoGenero;
            jogo.plataforma = novaPlataforma;
            jogo.modosDeJogo = novosModosDeJogo;
            jogo.desenvolvedora = novaDesenvolvedora;
            jogo.nota = novaNota;
            editadoCorretamente = true;
            break;
        }
    }
    assert(editadoCorretamente);

    // Teste exclusão de ambos os jogos
    string nomeJogoExcluir1 = "Teste Jogo 1";
	string nomeJogoExcluir2 = "Teste Jogo 1 Editado";
	string nomeJogoExcluir3 = "Teste Jogo 2";

	jogos.erase(std::remove_if(jogos.begin(), jogos.end(), [nomeJogoExcluir1, nomeJogoExcluir2, nomeJogoExcluir3](const Jogo& jogo) {
    	return jogo.nome == nomeJogoExcluir1 || jogo.nome == nomeJogoExcluir2 || jogo.nome == nomeJogoExcluir3;
	}), jogos.end());

	assert(std::none_of(jogos.begin(), jogos.end(), [nomeJogoExcluir1, nomeJogoExcluir2, nomeJogoExcluir3](const Jogo& jogo) {
    	return jogo.nome == nomeJogoExcluir1 || jogo.nome == nomeJogoExcluir2 || jogo.nome == nomeJogoExcluir3;
	}));

    cout << "Teste de adicao, ordenacao, edicao e exclusao de jogos passou." << endl;
}


int main() {
    vector<Jogo> jogos;
    testeAdicaoOrdenacaoEdicaoExclusao(jogos);
    num (jogos);
    imprimirArtePrincipal();
    bemVindo ();
    menuPrincipal(jogos);
}


void num (vector<Jogo>& jogos){
	ultimoNumeroChegada = 0;

    ifstream arquivo("jogos.txt");
    if (arquivo) {
        carregarJogos(jogos, ultimoNumeroChegada);

        // Encontrar o maior número de chegada entre os jogos carregados
        int maiorNumeroChegada = 0;
        for (const auto& jogo : jogos) {
            if (jogo.numeroChegada > maiorNumeroChegada) {
                maiorNumeroChegada = jogo.numeroChegada;
            }
        }
        ultimoNumeroChegada = maiorNumeroChegada;
    }
}


void imprimirArtePrincipal() {
    cout << "                          .----." << endl;
    usleep(200000);             
    cout << "              .---------. | == |" << endl;
    usleep(200000);  
    cout << "              |.-------.| |----|" << endl;
    usleep(200000);  
    cout << "              ||       || | == |" << endl;
    usleep(200000); 
    cout << "              ||       || |----|" << endl;
    usleep(200000);  
    cout << "              |'-.....-'| |::::|" << endl;
    usleep(200000);  
    cout << "               --)---(--|_.|" << endl;
    usleep(200000); 
    cout << "             /:::::::::::\\-\\_  \\ " << endl;
    usleep(200000);
    cout << "            /:::=======:::\\ \\" << endl;
    usleep(200000);
    cout << "            -------------- '-'" << endl;
}


void bemVindo() {
    string bemvindo = "Seja bem vindo ao Noxys, o maior (ou nao) acervo de jogos do mundo :)\n";
    int x = bemvindo.length();
    usleep(200000);
    for (int i = 0; i < x; i++) {
        cout << bemvindo[i];
        usleep (30000);
    }
    sleep (1);
}


void menuPrincipal(vector<Jogo>& jogos) {
    fraseMenu();
    char tecla;
    cin >> tecla;
    switch (tecla) {
        case '1':
        	contador++;
        	if (contador == 2){
        	fraseTeimoso();
        	
			}
			else {
				cout << "funcao bloqueada...";
            	sleep (2);
			}
			system("clear||cls");
            menuPrincipal(jogos);
        case '2':
    		adicionarJogo(jogos, ultimoNumeroChegada); // Chama a função adicionarJogo() quando a opção 2 for selecionada
            break;
        case '3':
            listarJogos(jogos);
            break;
        case '4':
        	excluirJogo(jogos);
            break;
        case '5':
        	editarJogoPorNome(&jogos);
        case '6':
        	system("clear||cls");
        	cout << "Ate breve :)";
        	sleep (2);
        	exit (0);
        case 'g':  
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	system("clear||cls");
            iniciarJogo();
            break;
        case 'G':  
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	cin.ignore();
        	system("clear||cls");
            iniciarJogo();
            break;
        default:
            cout << "Opcao invalida";
            sleep (2);
            system("clear||cls");
            menuPrincipal(jogos);
    }
}


void fraseTeimoso(){
	string teimoso = "Voce e teimoso mesmo hein? \n";
	string teimoso1 = "Para desbloquear a funcao, volte para o menu e insira a opcao secreta (nome do melhor professor)";
	int x = teimoso.length();
    usleep(200000);
    for (int i = 0; i < x; i++) {
        cout << teimoso[i];
        usleep (30000);
    	}
   	sleep (1);
   	x = teimoso1.length();
    usleep(200000);
    for (int i = 0; i < x; i++) {
        cout << teimoso1[i];
        usleep (30000);
    }
    sleep (3);
	
}


void fraseMenu() {
    string fraseMenu = "Por favor, selecione uma opcao:\n";
    int x = fraseMenu.length();
    usleep(200000);
    for (int i = 0; i < x; i++) {
        cout << fraseMenu[i];
        usleep (30000);
    }
    sleep (1);
    cout << endl;
    cout << "1- Jogar \n";
    usleep (30000);
    cout << "2- Adicionar jogo \n";
    usleep (3000);
    cout << "3- Listar jogos \n";
    usleep (3000);
    cout << "4- Excluir jogo \n";
    usleep (3000);
    cout << "5- Editar jogo \n";
    usleep (3000);
    cout << "6- Sair (sentiremos saudades) \n";
    usleep (3000);
}


void adicionarJogo(vector<Jogo>& jogos, int& ultimoNumeroChegada) {
    char adicionarMais;

    do {
        Jogo jogo;
        jogo.numeroChegada = ++ultimoNumeroChegada;

        cout << "Digite o nome do jogo (apenas letras, max. 60 caracteres): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer antes de ler
        lerStringValidada(jogo.nome, 60);

        cout << "Digite o ano de lancamento do jogo (1900 ate 2024): ";
        lerIntValidado(jogo.anoLancamento, 1900, 2024);

        cout << "Digite o genero do jogo (apenas letras, max. 60 caracteres): ";
        lerStringValidada(jogo.genero, 60);

        cout << "Digite a plataforma do jogo (max. 60 caracteres, letras e numeros permitidos): ";
		lerStringValidada(jogo.plataforma, 60, false, true);

        cout << "Digite os modos de jogo (apenas letras, max. 60 caracteres): ";
        lerStringValidada(jogo.modosDeJogo, 60);

        cout << "Digite a desenvolvedora do jogo (apenas letras, max. 60 caracteres): ";
        lerStringValidada(jogo.desenvolvedora, 60);

        cout << "Digite a nota do jogo (0 a 10): ";
        lerFloatValidado(jogo.nota, 0.0f, 10.0f);

        jogos.push_back(jogo);
        cout << "Jogo adicionado com sucesso!\n";

        cout << "Deseja adicionar outro jogo? (s/n): ";
        cin >> adicionarMais;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
    } while (adicionarMais == 's' || adicionarMais == 'S');

    salvarJogos(jogos);
    ordenarPorChegada(jogos);
    system("clear||cls");
    menuPrincipal (jogos);
}


void salvarJogos(const vector<Jogo>& jogos) {
    ofstream arquivo("jogos.txt"); // Abra o arquivo sem o modo append

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo.is_open()) {
        arquivo.clear(); // Limpe o conteúdo do arquivo

        // Agora, escreva os jogos no arquivo
        for (const auto& jogo : jogos) {
            arquivo << jogo.numeroChegada << endl
                    << jogo.nome << endl
                    << jogo.anoLancamento << endl
                    << jogo.genero << endl
                    << jogo.plataforma << endl
                    << jogo.modosDeJogo << endl
                    << jogo.desenvolvedora << endl
                    << jogo.nota << endl << endl;
        }

        arquivo.close(); // Feche o arquivo após escrever os jogos
    } else {
        cerr << "Erro ao abrir o arquivo para salvar os jogos." << endl;
    }
}


void carregarJogos(vector<Jogo>& jogos, int& ultimoNumeroChegada) {
    ifstream arquivo("jogos.txt");
    if (arquivo.is_open()) {
        while (true) {
            Jogo jogo;
            arquivo >> jogo.numeroChegada;
            if (arquivo.fail()) break; // Se a leitura falhar, sair do loop
            arquivo.ignore(); // Ignorar o espaço em branco após o número de chegada
            getline(arquivo, jogo.nome);
            arquivo >> jogo.anoLancamento >> jogo.genero >> jogo.plataforma >> jogo.modosDeJogo >> jogo.desenvolvedora >> jogo.nota;
            jogos.push_back(jogo);
            // Atualizar o último número de chegada conforme necessário
            if (jogo.numeroChegada > ultimoNumeroChegada) {
                ultimoNumeroChegada = jogo.numeroChegada;
            }
        }
        arquivo.close();
    } else {
        cerr << "Arquivo de jogos nao encontrado. Iniciando com nova lista de jogos." << endl;
    }
    ultimoNumeroChegada++; // Incrementa o último número de chegada para o próximo jogo
}


void listarJogos(vector<Jogo>& jogos) {
    char opcaoOrdenacao;

    cout << "Deseja ordenar os jogos por chegada (1) ou por nota (2)? ";
    cin >> opcaoOrdenacao;

    if (opcaoOrdenacao == '1') {
        ordenarPorChegada(jogos);
    } else if (opcaoOrdenacao == '2') {
        ordenarPorNota(jogos);
    } else {
        cout << "Opcao invalida. Listando os jogos sem ordenacao." << endl;
    }
    system("clear||cls");
    cout << "Lista de Jogos:" << endl;

    // Utilizando aritmética de ponteiros para iterar através do vetor
    if (!jogos.empty()) { // Verificar se o vetor não está vazio
        Jogo* ptr = &jogos[0]; // Ponteiro para o primeiro elemento do vetor
        for (size_t i = 0; i < jogos.size(); ++i) {
            cout <<"--------------------------------------------- \n";
            cout << "Numero de Chegada: " << ptr->numeroChegada << endl;  //aritmética de ponteiros
            cout << "Nome: " << ptr->nome << endl;
            cout << "Ano de lancamento: " << ptr->anoLancamento << endl;
            cout << "Genero: " << ptr->genero << endl;
            cout << "Plataforma: " << ptr->plataforma << endl;
            cout << "Modos de jogo: " << ptr->modosDeJogo << endl;
            cout << "Desenvolvedora: " << ptr->desenvolvedora << endl;
            cout << "Nota: " << ptr->nota << endl;
            cout <<"---------------------------------------------";
            cout << endl;

            ptr++; // Avança o ponteiro para o próximo elemento
        }
    } else {
        cout << "Nao ha jogos cadastrados para listar." << endl;
    }

    cout << "\n";
    cout << "Deseja voltar para o menu? (s/n) ";
    char voltarMenu;
    cin >> voltarMenu;
    if (voltarMenu == 's' || voltarMenu == 'S') {
        system("clear||cls");
        menuPrincipal(jogos);
    } else if (voltarMenu == 'n' || voltarMenu == 'N') {
        cout << "Saindo..." << endl;
        exit(0);
    }
}
		

void excluirJogo(vector<Jogo>& jogos) {
    system("clear||cls"); // Limpa a tela
    char excluir;
    bool mudanca = false; // Para verificar se houve alguma exclusão

    if (jogos.empty()) {
        cout << "Nenhum jogo cadastrado para excluir." << endl;
        return;
    }

    do {
        int opcao;
        cout << "Escolha o metodo de exclusao: " << endl;
        cout << "1 - Por Numero de Chegada" << endl;
        cout << "2 - Por Nome" << endl;
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o numero de chegada do jogo que deseja excluir: ";
            int numeroChegada;
            cin >> numeroChegada;

            auto it = remove_if(jogos.begin(), jogos.end(), [numeroChegada](const Jogo& jogo) {
                return jogo.numeroChegada == numeroChegada;
            });

            if (it != jogos.end()) {
                jogos.erase(it, jogos.end());
                cout << "Jogo excluido com sucesso." << endl;
                mudanca = true;
            } else {
                cout << "Jogo nao encontrado." << endl;
            }
        } else if (opcao == 2) {
            cout << "Digite o nome do jogo que deseja excluir: ";
            cin.ignore();
            string nome;
            getline(cin, nome);

            auto it = remove_if(jogos.begin(), jogos.end(), [&nome](const Jogo& jogo) {
                return jogo.nome == nome;
            });

            if (it != jogos.end()) {
                jogos.erase(it, jogos.end());
                cout << "Jogo excluido com sucesso." << endl;
                mudanca = true;
            } else {
                cout << "Jogo nao encontrado." << endl;
            }
        } else {
            cout << "Opcao invalida." << endl;
        }

        cout << "Deseja excluir outro jogo? (s/n): ";
        cin >> excluir;
    } while (excluir == 's' || excluir == 'S');

    if (mudanca) {
        salvarJogos(jogos); // Salva as mudanças no arquivo apenas uma vez após todas as exclusões
    }

    system("clear||cls"); // Limpa a tela novamente
    menuPrincipal(jogos);
}


void editarJogoPorNome(vector<Jogo>* jogos) {   //uso de ponteiro
    string nomeJogo;
    cout << "Digite o nome do jogo que deseja editar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer antes de ler
    getline(cin, nomeJogo);

    bool encontrado = false;

    for (auto& jogo : *jogos) {
        if (jogo.nome == nomeJogo) {
            encontrado = true;
            cout << "Jogo encontrado. Digite as novas informacoes:" << endl;

            cout << "Digite o nome do jogo (apenas letras, max. 60 caracteres): ";
            lerStringValidada(jogo.nome, 60);

            cout << "Digite o ano de lancamento do jogo (1900 ate 2024): ";
            lerIntValidado(jogo.anoLancamento, 1900, 2024);

            cout << "Digite o genero do jogo (apenas letras, max. 60 caracteres): ";
            lerStringValidada(jogo.genero, 60);

            cout << "Digite a plataforma do jogo (max. 60 caracteres, letras e numeros permitidos): ";
			lerStringValidada(jogo.plataforma, 60, false, true);

            cout << "Digite os modos de jogo (apenas letras, max. 60 caracteres): ";
            lerStringValidada(jogo.modosDeJogo, 60);

            cout << "Digite a desenvolvedora do jogo (apenas letras, max. 60 caracteres): ";
            lerStringValidada(jogo.desenvolvedora, 60);

            cout << "Digite a nota do jogo (0 a 10): ";
            lerFloatValidado(jogo.nota, 0.0f, 10.0f);

            cout << "Jogo editado com sucesso!\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "Jogo não encontrado." << endl;
    }

    salvarJogos(*jogos);
    menuPrincipal(*jogos);
}


void ordenarPorChegada(vector<Jogo>& jogos) {
    // Usando o algoritmo de ordenação sort com uma função lambda para comparar pelo número de chegada
    sort(jogos.begin(), jogos.end(), [](const Jogo& a, const Jogo& b) {
        return a.numeroChegada < b.numeroChegada;
    });
}

// Função para ordenar por maiores notas
void merge(vector<Jogo>& jogos, int inicio, int meio, int fim) {
    vector<Jogo> temp(fim - inicio + 1);

    int i = inicio, j = meio + 1, k = 0;

    // Intercalar as duas metades no vetor temp
    while (i <= meio && j <= fim) {
        if (jogos[i].nota > jogos[j].nota) {
            temp[k++] = jogos[i++];
        } else {
            temp[k++] = jogos[j++];
        }
    }

    // Copiar os elementos restantes da primeira metade, se houver
    while (i <= meio) {
        temp[k++] = jogos[i++];
    }

    // Copiar os elementos restantes da segunda metade, se houver
    while (j <= fim) {
        temp[k++] = jogos[j++];
    }

    // Copiar os elementos ordenados de volta para o vetor original
    for (i = inicio, k = 0; i <= fim; ++i, ++k) {
        jogos[i] = temp[k];
    }
}


void mergeSort(vector<Jogo>& jogos, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Dividir o vetor em duas metades
        mergeSort(jogos, inicio, meio);
        mergeSort(jogos, meio + 1, fim);

        // Conquistar (ordenar) e combinar as duas metades
        merge(jogos, inicio, meio, fim);
    }
}


void ordenarPorNota(vector<Jogo>& jogos) {
    if (!jogos.empty()) {
        mergeSort(jogos, 0, jogos.size() - 1);
    }
}


bool ehAlfanumericoComTamanho(const string& str, size_t maxTam) {
    return str.length() <= maxTam && !str.empty();
}


bool ehApenasLetrasComTamanho(const string& str, size_t maxTam) {
    if (str.length() > maxTam || str.empty()) return false;
    for (char const &c : str) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}


bool ehNumeroEntre(int num, int min, int max) {
    return num >= min && num <= max;
}


bool ehFloatEntre(float num, float min, float max) {
    return num >= min && num <= max;
}


void lerIntValidado(int& input, int min, int max) {
    cin >> input;
    while (cin.fail() || !ehNumeroEntre(input, min, max)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Por favor, insira um numero entre " << min << " e " << max << ": ";
        cin >> input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer após a leitura
}


void lerFloatValidado(float& input, float min, float max) {
    cin >> input;
    while (cin.fail() || !ehFloatEntre(input, min, max)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Por favor, insira um número entre " << min << " e " << max << ": ";
        cin >> input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer após a leitura
}

