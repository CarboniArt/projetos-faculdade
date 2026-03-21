import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score

# -----------------------------
# 1. Importação do Dataset
# -----------------------------
df = pd.read_csv("dataset1.csv")

print("Dimensão do dataset:", df.shape)
print("Primeiras colunas:", df.columns[:10])
print(df.head())

# -----------------------------
# 2. Separação de Features e Alvo
# -----------------------------
X = df.drop(columns=["Result"])
y = df["Result"]

# Transformar y em binário (0 = legítimo, 1 = phishing)
y = (y == 1).astype(int).values.reshape(-1, 1)

# -----------------------------
# 3. Normalização dos dados
# -----------------------------
scaler = StandardScaler()
X = scaler.fit_transform(X)

# -----------------------------
# 4. Divisão em treino e teste
# -----------------------------
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42
)

# -----------------------------
# 5. Implementação da Rede Neural com funções
# -----------------------------

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def sigmoid_deriv(z):
    return sigmoid(z) * (1 - sigmoid(z))

# Inicialização da rede
def initialize_network(n_input, hidden_layers, n_output):
    layers = [n_input] + hidden_layers + [n_output]
    weights = [
        np.random.randn(layers[i], layers[i+1]) * 0.1
        for i in range(len(layers) - 1)
    ]
    biases = [
        np.zeros((1, layers[i+1]))
        for i in range(len(layers) - 1)
    ]
    return weights, biases, layers

def forward(X, weights, biases):
    activations = [X]
    zs = []
    for W, b in zip(weights, biases):
        z = activations[-1] @ W + b
        zs.append(z)
        activations.append(sigmoid(z))
    return activations, zs

def backward(activations, zs, y_true, weights, biases, learning_rate):
    grads_w = [np.zeros_like(W) for W in weights]
    grads_b = [np.zeros_like(b) for b in biases]

    # Erro da saída
    delta = (activations[-1] - y_true) * sigmoid_deriv(zs[-1])
    grads_w[-1] = activations[-2].T @ delta
    grads_b[-1] = np.sum(delta, axis=0, keepdims=True)

    # Retropropaga para camadas ocultas
    for l in range(2, len(weights)+1):
        z = zs[-l]
        sp = sigmoid_deriv(z)
        delta = delta @ weights[-l+1].T * sp
        grads_w[-l] = activations[-l-1].T @ delta
        grads_b[-l] = np.sum(delta, axis=0, keepdims=True)

    # Atualização dos parâmetros
    for i in range(len(weights)):
        weights[i] -= learning_rate * grads_w[i]
        biases[i] -= learning_rate * grads_b[i]

    return weights, biases

def predict(X, weights, biases):
    activations, _ = forward(X, weights, biases)
    return (activations[-1] > 0.5).astype(int)

def train(X, y, weights, biases, epochs, learning_rate):
    history = []
    for epoch in range(epochs):
        activations, zs = forward(X, weights, biases)
        weights, biases = backward(activations, zs, y, weights, biases, learning_rate)

        if (epoch+1) % 50 == 0:
            y_pred = predict(X, weights, biases)
            acc = accuracy_score(y, y_pred)
            history.append(acc)
            print(f"Época {epoch+1}/{epochs} - Acurácia treino: {acc:.4f}")

    return weights, biases, history

# -----------------------------
# 6. Treinamento
# -----------------------------
n_input = X.shape[1]
hidden_layers = [16, 8]
n_output = 1
learning_rate = 0.01
epochs = 200

weights, biases, layers = initialize_network(n_input, hidden_layers, n_output)
weights, biases, history = train(X_train, y_train, weights, biases, epochs, learning_rate)

# -----------------------------
# 7. Avaliação no teste
# -----------------------------
y_pred = predict(X_test, weights, biases)
acc_test = accuracy_score(y_test, y_pred)

# -----------------------------
# 8. Resumo final
# -----------------------------
print("\n===== RESUMO FINAL =====")
print(f"Número de camadas intermediárias: {len(hidden_layers)}")
print(f"Neurônios por camada intermediária: {hidden_layers}")
print(f"Taxa de aprendizado: {learning_rate}")
print(f"Épocas de treinamento: {epochs}")
print(f"Acurácia final no treino: {history[-1]:.4f}")
print(f"Acurácia no teste: {acc_test:.4f}")
print("=========================")