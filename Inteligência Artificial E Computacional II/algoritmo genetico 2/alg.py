import numpy as np
from PIL import Image, ImageDraw
import random, os, glob

TARGET_PATH = "target.jpg"
IMG_SIZE = (128, 128)
POP_SIZE = 20
NUM_TRIANGLES = 40
GENERATIONS = 100000
MUTATION_RATE = 0.1
ELITISM = 0.2

target = np.array(Image.open(TARGET_PATH).resize(IMG_SIZE), dtype=np.uint8)
H, W, C = target.shape

def render(triangles):
    img = Image.new("RGB", (W, H), (255, 255, 255))
    draw = ImageDraw.Draw(img, "RGBA")
    for tri in triangles:
        (x1, y1, x2, y2, x3, y3, r, g, b, a) = tri
        draw.polygon([(x1, y1), (x2, y2), (x3, y3)], fill=(r, g, b, a))
    return np.array(img)

def random_triangle():
    return [
        random.randint(0, W), random.randint(0, H),
        random.randint(0, W), random.randint(0, H),
        random.randint(0, W), random.randint(0, H),
        random.randint(0, 255), random.randint(0, 255),
        random.randint(0, 255), random.randint(30, 150)
    ]

def random_individual():
    return [random_triangle() for _ in range(NUM_TRIANGLES)]

def fitness(ind):
    img = render(ind)
    return -np.mean(np.abs(img.astype(np.int16) - target.astype(np.int16)))

def crossover(p1, p2):
    cut = random.randint(1, NUM_TRIANGLES - 1)
    return p1[:cut] + p2[cut:]

def mutate(ind):
    new = [t.copy() for t in ind]
    for t in new:
        if random.random() < MUTATION_RATE:
            i = random.randint(0, len(t) - 1)
            if i < 6:
                t[i] = random.randint(0, W if i % 2 == 0 else H)
            elif i < 9:
                t[i] = random.randint(0, 255)
            else:
                t[i] = random.randint(30, 150)
    return new

population = [random_individual() for _ in range(POP_SIZE)]
os.makedirs("evolucao", exist_ok=True)

for gen in range(GENERATIONS):
    fits = [fitness(ind) for ind in population]
    ranked = sorted(zip(fits, population), key=lambda x: x[0], reverse=True)
    best_fit, best = ranked[0]

    if gen % 5 == 0:
        print(f"Geração {gen} | Fitness: {best_fit:.2f}")
        Image.fromarray(render(best)).save(f"evolucao/gen_{gen:04d}.png")

    elite = [ind for _, ind in ranked[:int(POP_SIZE * ELITISM)]]
    next_gen = elite.copy()

    while len(next_gen) < POP_SIZE:
        p1, p2 = random.sample(elite, 2)
        child = mutate(crossover(p1, p2))
        next_gen.append(child)

    population = next_gen

Image.fromarray(render(best)).save("evolucao/final.png")
print("Resultado salvo em evolucao/final.png")