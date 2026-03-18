package JogoDaVelha;
public class Tabuleiro {
    private char simbolo;

    
    public Tabuleiro() {
        simbolo = ' ';
    }

    public char getSimbolo() {
        return simbolo;
    }

    public void setSimbolo(char simbolo) {
        this.simbolo = simbolo;
    }

    public static void desenhoTabuleiro(Tabuleiro[][] velha) {
        System.out.println("       0     1     2  ");
        System.out.println("    ╔═════╦═════╦═════╗");
        for (int i = 0; i < 3; i++) {
            System.out.print(" " + i + "  ");
            for (int j = 0; j < 3; j++) {
                System.out.print("║  " + velha[i][j].getSimbolo() + "  ");
            }
            System.out.println("║");
            if (i < 2) {
                System.out.println("    ╠═════╬═════╬═════╣");
            } else {
                System.out.println("    ╚═════╩═════╩═════╝");
            }
        }
    }
}