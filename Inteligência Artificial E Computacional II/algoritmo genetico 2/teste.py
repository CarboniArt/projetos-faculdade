import numpy as np
from PIL import Image, ImageDraw
import random, os, glob

# --- Parâmetros de Configuração do Algoritmo Genético ---
TARGET_PATH = "target.jpg" # Caminho para a imagem alvo
IMG_SIZE = (128, 128)      # Tamanho para redimensionar a imagem (para processamento mais rápido)
POP_SIZE = 20              # Número de indivíduos (conjuntos de triângulos) na população
NUM_TRIANGLES = 40         # Número de triângulos que compõem cada indivíduo
GENERATIONS = 100000       # Número máximo de iterações do algoritmo
MUTATION_RATE = 0.1        # Taxa de mutação (probabilidade de um gene/atributo ser alterado)
ELITISM = 0.2              # Proporção da população mais apta (elite) copiada diretamente para a próxima geração

# --- Inicialização ---
# Carrega a imagem alvo, redimensiona e converte para um array NumPy de 8 bits
try:
    target = np.array(Image.open(TARGET_PATH).resize(IMG_SIZE), dtype=np.uint8)
except FileNotFoundError:
    print(f"Erro: Imagem alvo '{TARGET_PATH}' não encontrada. Crie um arquivo ou altere TARGET_PATH.")
    exit()

# Extrai as dimensões da imagem (Altura, Largura, Canais de cor)
H, W, C = target.shape

# ----------------------------------------------------------------------
# --- Funções de Renderização e Representação do Indivíduo (Genótipo) ---
# ----------------------------------------------------------------------

def render(triangles):
    """
    Desenha os triângulos em uma imagem e retorna como um array NumPy.
    A imagem resultante é o fenótipo do indivíduo.
    """
    # Cria uma nova imagem RGB com fundo branco. Usa RGBA para suportar transparência.
    img = Image.new("RGB", (W, H), (255, 255, 255))
    draw = ImageDraw.Draw(img, "RGBA")
    
    for tri in triangles:
        # Um triângulo é definido por 10 parâmetros: 3 vértices (x, y) e RGBA
        (x1, y1, x2, y2, x3, y3, r, g, b, a) = tri
        
        # Desenha o polígono (triângulo) com a cor e transparência especificadas
        draw.polygon([(x1, y1), (x2, y2), (x3, y3)], fill=(r, g, b, a))
        
    return np.array(img) # Converte para array para cálculo de fitness

def random_triangle():
    """Cria um único triângulo com atributos aleatórios (o 'gene')."""
    return [
        random.randint(0, W), random.randint(0, H),   # x1, y1 (Vértice 1)
        random.randint(0, W), random.randint(0, H),   # x2, y2 (Vértice 2)
        random.randint(0, W), random.randint(0, H),   # x3, y3 (Vértice 3)
        random.randint(0, 255), random.randint(0, 255), # R, G
        random.randint(0, 255),                        # B
        random.randint(30, 150)                        # A (Alpha/Transparência, limitada para visibilidade)
    ]

def random_individual():
    """Cria um indivíduo (o 'cromossomo'), que é uma lista de NUM_TRIANGLES."""
    return [random_triangle() for _ in range(NUM_TRIANGLES)]

# ----------------------------------------------------------------------
# --- Função de Aptidão (Fitness) ---
# ----------------------------------------------------------------------

def fitness(ind):
    """
    Avalia o quão semelhante a imagem renderizada é à imagem alvo.
    O fitness é o negativo do Erro Absoluto Médio (Mean Absolute Error - MAE).
    Maximizar este valor significa minimizar o erro.
    """
    img = render(ind)
    
    # Calcula a diferença absoluta pixel a pixel. 
    # Usar int16 evita overflow/underflow ao subtrair arrays de uint8.
    error = np.abs(img.astype(np.int16) - target.astype(np.int16))
    
    # Retorna o MAE negado.
    return -np.mean(error)

# ----------------------------------------------------------------------
# --- Operadores Genéticos ---
# ----------------------------------------------------------------------

def crossover(p1, p2):
    """
    Realiza a recombinação (crossover) de ponto único.
    O filho herda a primeira parte dos triângulos de p1 e a segunda parte de p2.
    """
    # Escolhe um ponto de corte aleatório (não pode ser o primeiro nem o último)
    cut = random.randint(1, NUM_TRIANGLES - 1)
    return p1[:cut] + p2[cut:]

def mutate(ind):
    """
    Realiza a mutação, alterando aleatoriamente alguns atributos dos triângulos.
    """
    # Cria uma cópia profunda para não alterar o pai
    new = [t.copy() for t in ind]
    
    for t in new: # Itera sobre cada triângulo
        # Se um triângulo for selecionado para mutação (10% de chance para cada atributo)
        if random.random() < MUTATION_RATE: 
            i = random.randint(0, len(t) - 1) # Escolhe um atributo (gene) aleatório do triângulo
            
            # Aplica a mutação de acordo com o tipo de atributo (coordenada, cor RGB, ou Alpha)
            if i < 6: # Coordenadas (x, y)
                # Altera a coordenada para um novo valor aleatório dentro dos limites da imagem (W ou H)
                t[i] = random.randint(0, W if i % 2 == 0 else H)
            elif i < 9: # Cores (R, G, B)
                t[i] = random.randint(0, 255)
            else: # Alpha (A)
                t[i] = random.randint(30, 150) # Mantém-se dentro do limite de transparência
    return new

# ----------------------------------------------------------------------
# --- Loop Principal da Evolução ---
# ----------------------------------------------------------------------

# 1. Inicializa a população com indivíduos aleatórios
population = [random_individual() for _ in range(POP_SIZE)]

# Cria o diretório para salvar as imagens de evolução
os.makedirs("evolucao", exist_ok=True)

for gen in range(GENERATIONS):
    # 2. Avaliação: Calcula o fitness para cada indivíduo
    fits = [fitness(ind) for ind in population]
    
    # 3. Seleção: Classifica a população do melhor (maior fitness) para o pior
    ranked = sorted(zip(fits, population), key=lambda x: x[0], reverse=True)
    best_fit, best = ranked[0] # O melhor indivíduo e seu fitness

    # Imprime e salva o progresso a cada 5 gerações
    if gen % 5 == 0:
        print(f"Geração {gen} | Fitness: {best_fit:.2f}")
        Image.fromarray(render(best)).save(f"evolucao/gen_{gen:04d}.png")

    # 4. Elitismo: Seleciona a elite para cópia direta
    num_elite = int(POP_SIZE * ELITISM)
    elite = [ind for _, ind in ranked[:num_elite]]
    next_gen = elite.copy()

    # 5. Reprodução: Cria novos indivíduos (crossover e mutação) até encher a população
    while len(next_gen) < POP_SIZE:
        # Seleção dos pais: Amostragem aleatória da elite
        p1, p2 = random.sample(elite, 2)
        
        # Criação do filho: Crossover seguido de Mutação
        child = mutate(crossover(p1, p2))
        
        next_gen.append(child)

    # 6. Substituição: A nova geração substitui a antiga
    population = next_gen

# Salva o resultado final após todas as gerações
Image.fromarray(render(best)).save("evolucao/final.png")
print("Resultado salvo em evolucao/final.png")