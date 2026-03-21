import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
import itertools
from rich.console import Console
from rich.table import Table


# Configuração do Rich

console = Console()

def log_epoch(epoch, acc_train, acc_test):
    table = Table(title=f"📊 Época {epoch+1}", expand=True)
    table.add_column("Métrica", justify="left", style="cyan", no_wrap=True)
    table.add_column("Valor", justify="right", style="magenta")

    table.add_row("Acurácia Treino", f"{acc_train:.4f}")
    table.add_row("Acurácia Teste", f"{acc_test:.4f}")

    console.print(table)


# 1. Importação do Dataset
df = pd.read_csv("dataset1.csv")

X = df.drop(columns=["Result"])
y = df["Result"]

y = (y == 1).astype(int).values.reshape(-1, 1)

scaler = StandardScaler()
X = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42
)


# 2. Funções da Rede Neural
def sigmoid(z):
    return 1 / (1 + np.exp(-z))  #ideal para classificacao binaria

def sigmoid_deriv(z):
    return sigmoid(z) * (1 - sigmoid(z)) #derivada. importante para backpropagatin

def initialize_network(n_input, hidden_layers, n_output):
    layers = [n_input] + hidden_layers + [n_output]     #neuronios por camadas
    weights = [  #aleatorios pequenos de inicio
        np.random.randn(layers[i], layers[i+1]) * 0.1   
        for i in range(len(layers) - 1)
    ]
    biases = [ #inicia com zero
        np.zeros((1, layers[i+1]))
        for i in range(len(layers) - 1)
    ]
    return weights, biases, layers

def forward(X, weights, biases):
    #Multiplica entradas pelos pesos, soma bias, aplica sigmoid.
    #Guarda ativações e os valores intermediários (z) para usar no backprop
    
    activations = [X]
    zs = []
    for W, b in zip(weights, biases):
        z = activations[-1] @ W + b
        zs.append(z)
        activations.append(sigmoid(z))
    return activations, zs

def backward(activations, zs, y_true, weights, biases, learning_rate):
    #Calcula gradientes do erro em relação aos pesos/biases.
    #Ajusta pesos na direção que reduz o erro
    grads_w = [np.zeros_like(W) for W in weights]
    grads_b = [np.zeros_like(b) for b in biases]

    delta = (activations[-1] - y_true) * sigmoid_deriv(zs[-1])
    grads_w[-1] = activations[-2].T @ delta
    grads_b[-1] = np.sum(delta, axis=0, keepdims=True)

    for l in range(2, len(weights)+1): #retropropragacao
        z = zs[-l]
        sp = sigmoid_deriv(z)
        delta = delta @ weights[-l+1].T * sp
        grads_w[-l] = activations[-l-1].T @ delta
        grads_b[-l] = np.sum(delta, axis=0, keepdims=True)

    for i in range(len(weights)): #aplicacao dos pesos e biases
        weights[i] -= learning_rate * grads_w[i]
        biases[i] -= learning_rate * grads_b[i]

    return weights, biases

def predict(X, weights, biases):
    activations, _ = forward(X, weights, biases)
    return (activations[-1] > 0.5).astype(int)
    #var>0.5 vira resposta 1

def train(X, y, X_test, y_test, weights, biases, epochs, learning_rate):
    for epoch in range(epochs):
        activations, zs = forward(X, weights, biases)
        weights, biases = backward(activations, zs, y, weights, biases, learning_rate)

        # Log a cada 50 épocas
        if (epoch+1) % 50 == 0:
            y_pred_train = predict(X, weights, biases)
            y_pred_test = predict(X_test, weights, biases)
            acc_train = accuracy_score(y, y_pred_train)
            acc_test = accuracy_score(y_test, y_pred_test)
            log_epoch(epoch, acc_train, acc_test)

    return weights, biases


# 3. Experimentos Automáticos

neurons_options = [8, 16, 32]          # N° de neurônios por camada
layers_options = [1, 2, 3]             # N° de camadas intermediárias
learning_rates = [0.001, 0.01, 0.1]    # Taxa de aprendizado

epochs = 200
n_input = X.shape[1]
n_output = 1

results = []

for n_layers, n_neurons, lr in itertools.product(layers_options, neurons_options, learning_rates):
    console.rule(f"[bold yellow]Treinando -> Camadas={n_layers}, Neurônios={n_neurons}, LR={lr}")

    hidden_layers = [n_neurons] * n_layers
    weights, biases, layers = initialize_network(n_input, hidden_layers, n_output)
    weights, biases = train(X_train, y_train, X_test, y_test, weights, biases, epochs, lr)

    y_pred_train = predict(X_train, weights, biases)
    y_pred_test = predict(X_test, weights, biases)

    acc_train = accuracy_score(y_train, y_pred_train)
    acc_test = accuracy_score(y_test, y_pred_test)

    results.append({
        "Camadas Intermediárias": n_layers,
        "Neurônios por Camada": n_neurons,
        "Learning Rate": lr,
        "Acurácia Treino": round(acc_train, 4),
        "Acurácia Teste": round(acc_test, 4)
    })


# 4. Resultado Final com Rich
df_results = pd.DataFrame(results)

table = Table(title="📊 Resultados Finais dos Experimentos", expand=True)
for col in df_results.columns:
    table.add_column(col, justify="center", style="cyan")

for _, row in df_results.iterrows():
    table.add_row(*[str(x) for x in row.values])

console.print(table)
