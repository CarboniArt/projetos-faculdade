package JogoDaVelha;

import java.util.InputMismatchException;
import java.util.Scanner;

public class JogadorHumano implements Jogador {
    private char simbolo;
    private Scanner scan;


    public JogadorHumano(char simbolo) {
        this.simbolo = simbolo;
        this.scan = new Scanner(System.in);
    }

    @Override
    public int[] fazerJogada() {
        int[] vetorPonto = new int[2];
        boolean entradaValida = false;

        while (!entradaValida) {
            try {
                System.out.printf("Quem joga: %c%n", simbolo);
                System.out.println("Informe a linha desejada (0, 1, ou 2): ");
                vetorPonto[0] = scan.nextInt();
                System.out.println("Informe a coluna desejada (0, 1, ou 2): ");
                vetorPonto[1] = scan.nextInt();

                if (vetorPonto[0] < 0 || vetorPonto[0] > 2 || vetorPonto[1] < 0 || vetorPonto[1] > 2) {
                    throw new IndexOutOfBoundsException("Posição fora dos limites da tabela.");
                }
                entradaValida = true;
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, insira números inteiros.");
                scan.next();
            } catch (IndexOutOfBoundsException e) {
                System.out.println(e.getMessage());
            }
        }

        return vetorPonto;
    }

    @Override
    public char getSimbolo() {
        return simbolo;
    }
}