package JogoDaVelha;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Jogo extends JFrame {
    private JButton[][] botoes = new JButton[3][3];
    private char jogadorAtual = 'X';
    private Tabuleiro[][] velha = new Tabuleiro[3][3];
    private JLabel statusLabel;
    private int pontosX = 0;
    private int pontosO = 0;
    private JLabel pontosXLabel;
    private JLabel pontosOLabel;

    public Jogo() {
        setTitle("Jogo da Velha");
        setSize(400, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        getContentPane().setBackground(Color.DARK_GRAY);

        JPanel painelJogo = new JPanel();
        painelJogo.setLayout(new GridLayout(3, 3));
        painelJogo.setBackground(Color.DARK_GRAY);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j] = new JButton("");
                botoes[i][j].setFont(new Font("Arial", Font.BOLD, 60));
                botoes[i][j].setFocusPainted(false);
                botoes[i][j].setBackground(Color.BLACK);
                botoes[i][j].setForeground(Color.WHITE);
                botoes[i][j].addActionListener(new OuvinteCliqueBotao(i, j));
                painelJogo.add(botoes[i][j]);
                velha[i][j] = new Tabuleiro();
            }
        }

        statusLabel = new JLabel("Jogador X começa");
        statusLabel.setHorizontalAlignment(SwingConstants.CENTER);
        statusLabel.setFont(new Font("Arial", Font.BOLD, 16));
        statusLabel.setForeground(Color.WHITE);
        statusLabel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        pontosXLabel = new JLabel("Pontos X: 0");
        pontosXLabel.setHorizontalAlignment(SwingConstants.LEFT);
        pontosXLabel.setFont(new Font("Arial", Font.BOLD, 16));
        pontosXLabel.setForeground(Color.WHITE);
        pontosXLabel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        pontosOLabel = new JLabel("Pontos O: 0");
        pontosOLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        pontosOLabel.setFont(new Font("Arial", Font.BOLD, 16));
        pontosOLabel.setForeground(Color.WHITE);
        pontosOLabel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JPanel painelInferior = new JPanel(new BorderLayout());
        painelInferior.setBackground(Color.DARK_GRAY);
        painelInferior.add(statusLabel, BorderLayout.NORTH);

        JPanel painelPontos = new JPanel(new GridLayout(1, 2));
        painelPontos.setBackground(Color.DARK_GRAY);
        painelPontos.add(pontosXLabel);
        painelPontos.add(pontosOLabel);

        painelInferior.add(painelPontos, BorderLayout.SOUTH);

        add(painelJogo, BorderLayout.CENTER);
        add(painelInferior, BorderLayout.SOUTH);

        setVisible(true);
    }

    private class OuvinteCliqueBotao implements ActionListener {
        private int x;
        private int y;

        public OuvinteCliqueBotao(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (botoes[x][y].getText().equals("") && velha[x][y].getSimbolo() == ' ') {
                botoes[x][y].setText(String.valueOf(jogadorAtual));
                velha[x][y].setSimbolo(jogadorAtual);

                if (Jogada.vitoria(velha).equals(String.valueOf(jogadorAtual))) {
                    JOptionPane.showMessageDialog(null, "Jogador " + jogadorAtual + " venceu!");
                    if (jogadorAtual == 'X') {
                        pontosX++;
                    } else {
                        pontosO++;
                    }
                    atualizarPontos();
                    if (JOptionPane.showConfirmDialog(null, "Deseja jogar novamente?", "Jogo da Velha", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION) {
                        resetarTabuleiro();
                    } else {
                        System.exit(0);
                    }
                } else if (tabuleiroCompleto()) {
                    JOptionPane.showMessageDialog(null, "Empate!");
                    if (JOptionPane.showConfirmDialog(null, "Deseja jogar novamente?", "Jogo da Velha", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION) {
                        resetarTabuleiro();
                    } else {
                        System.exit(0);
                    }
                } else {
                    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
                    statusLabel.setText("Jogador " + jogadorAtual + " é a sua vez");
                }
            }
        }
    }

    private void resetarTabuleiro() {
        jogadorAtual = 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j].setText("");
                velha[i][j] = new Tabuleiro();
            }
        }
        statusLabel.setText("Jogador X começa");
    }

    private void atualizarPontos() {
        pontosXLabel.setText("Pontos X: " + pontosX);
        pontosOLabel.setText("Pontos O: " + pontosO);
    }


    private boolean tabuleiroCompleto() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (velha[i][j].getSimbolo() == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
}