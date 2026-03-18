package JogoDaVelha;

public class Jogada {

    public static boolean jogada(Tabuleiro[][] velha, int[] vetorPonto, char simboloJogador) {
        int x = vetorPonto[0];
        int y = vetorPonto[1];
        if (x >= 0 && x < 3 && y >= 0 && y < 3 && velha[x][y].getSimbolo() == ' ') {
            velha[x][y].setSimbolo(simboloJogador);
            return true;
        } else {
            return false;
        }
    }


    public static String vitoria(Tabuleiro[][] velha) {
        for (int i = 0; i < 3; i++) {
            if (velha[i][0].getSimbolo() == velha[i][1].getSimbolo() && velha[i][1].getSimbolo() == velha[i][2].getSimbolo() && velha[i][0].getSimbolo() != ' ') {
                return String.valueOf(velha[i][0].getSimbolo());
            }
            if (velha[0][i].getSimbolo() == velha[1][i].getSimbolo() && velha[1][i].getSimbolo() == velha[2][i].getSimbolo() && velha[0][i].getSimbolo() != ' ') {
                return String.valueOf(velha[0][i].getSimbolo());
            }
        }
        if (velha[0][0].getSimbolo() == velha[1][1].getSimbolo() && velha[1][1].getSimbolo() == velha[2][2].getSimbolo() && velha[0][0].getSimbolo() != ' ') {
            return String.valueOf(velha[0][0].getSimbolo());
        }
        if (velha[0][2].getSimbolo() == velha[1][1].getSimbolo() && velha[1][1].getSimbolo() == velha[2][0].getSimbolo() && velha[0][2].getSimbolo() != ' ') {
            return String.valueOf(velha[0][2].getSimbolo());
        }
        return "";
    }
}