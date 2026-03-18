package JogoDaVelha;
import java.util.Scanner;


public class ClassePrincipal {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Escolha a forma de jogar:");
        System.out.println("1. Interface Gráfica");
        System.out.println("2. Terminal");
        System.out.print("Opção: ");
        int escolha = scanner.nextInt();

        if (escolha == 1) {
            javax.swing.SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                    new Jogo();
                }
            });
        } else if (escolha == 2) {
            iniciarJogoTerminal();
        } else {
            System.out.println("Opção inválida!");
        }
    }

    public static void iniciarJogoTerminal() {
        Scanner scanner = new Scanner(System.in);
        boolean continuar = true;

        while (continuar) {
            Tabuleiro[][] velha = new Tabuleiro[3][3];
            Jogador jogador1 = new JogadorHumano('O');
            Jogador jogador2 = new JogadorHumano('X');
            Jogador jogadorAtual = jogador1;
            boolean jogo = true;
            String win = "";

            iniciarTabuleiro(velha);

            while (jogo) {
                limparTela();
                Tabuleiro.desenhoTabuleiro(velha);
                win = Jogada.vitoria(velha);
                if (!win.equals("")) {
                    System.out.printf("Jogador %s venceu!%n", win);
                    break;
                }
                try {
                    int[] ponto = jogadorAtual.fazerJogada();
                    if (Jogada.jogada(velha, ponto, jogadorAtual.getSimbolo())) {
                        jogadorAtual = (jogadorAtual == jogador1) ? jogador2 : jogador1;
                    }
                } catch (Exception e) {
                    System.out.println("Erro: " + e.getMessage());
                }
            }
            System.out.println("O jogo acabou");

            System.out.println("Deseja jogar novamente? (s/n)");
            String resposta = scanner.next();
            if (!resposta.equalsIgnoreCase("s")) {
                continuar = false;
            }
        }
        scanner.close();
    }

    public static void limparTela() {
        for (int i = 0; i < 50; i++) {
            System.out.println("");
        }
    }


    public static void iniciarTabuleiro(Tabuleiro[][] velha) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                velha[i][j] = new Tabuleiro();
            }
        }
    }
}