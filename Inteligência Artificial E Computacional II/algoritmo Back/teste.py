# Instale as dependências se ainda não as tiver:
# pip install kagglehub scikit-learn pandas

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score
import kagglehub
from kagglehub import KaggleDatasetAdapter

# ==================== CONFIGURAÇÃO DO MODELO (AJUSTE AQUI) ====================

# Número de neurônios nas camadas ocultas.
# Ex: (100, 50) significa 2 camadas ocultas, uma com 100 e outra com 50 neurônios.
# Você pode ajustar o número de camadas e neurônios conforme desejar.
hidden_layers = (100, 50)

# Taxa de aprendizado (n)
# Ajuste este valor para controlar a velocidade do aprendizado.
learning_rate = 0.001

# ==================== IMPLEMENTAÇÃO DO MODELO ====================

# O caminho para o arquivo dentro do dataset do Kaggle
file_path_in_dataset = "Phishing_Website_Detection_Dataset.csv"

# Carregue o dataset diretamente de Kaggle usando kagglehub
print("Carregando o dataset do Kaggle. Isso pode levar alguns segundos...")
df = kagglehub.load_dataset(
    KaggleDatasetAdapter.PANDAS,
    "mdsultanulislamovi/phishing-website-detection-datasets",
    file_path_in_dataset,
)

# Separe os recursos (X) e o rótulo (y)
X = df.iloc[:, 1:-1]
y = df.iloc[:, -1]

# Divida os dados em conjuntos de treinamento e teste (80% para treino, 20% para teste)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Crie e configure o modelo MLPClassifier
mlp = MLPClassifier(
    hidden_layer_sizes=hidden_layers,
    learning_rate_init=learning_rate,
    max_iter=500,
    activation='relu',
    solver='adam',
    random_state=42
)

# Treine o modelo
print("\nIniciando o treinamento do modelo. Isso pode levar alguns segundos...")
mlp.fit(X_train, y_train)
print("Treinamento concluído.")

# Faça previsões no conjunto de teste
y_pred = mlp.predict(X_test)

# Calcule a porcentagem de acerto (acurácia)
accuracy = accuracy_score(y_test, y_pred)
accuracy_percentage = accuracy * 100

print("\n--- Resultados de Avaliação ---")
print(f"Porcentagem de acerto (acurácia) no conjunto de teste: {accuracy_percentage:.2f}%")