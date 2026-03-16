import numpy as np

# 1
vendas = np.random.randint(100, 501, size=12)
print(vendas)

# 2
vendas_matriz = vendas.reshape(3, 4)
print(vendas.reshape(3, 4))

# 3
total_por_semana = vendas_matriz.sum(axis=1)
for i, total in enumerate(total_por_semana, 1):
    print(f"   Semana {i}: {total}")

# 4
media_por_dia = vendas_matriz.mean(axis=0)
print("\n4. Média de vendas por dia da semana:")
dias = ["Segunda", "Terça", "Quarta", "Quinta"]
for dia, media in zip(dias, media_por_dia):
    print(f"   {dia}: {media:.2f}")

# 5
dias_acima_400 = np.sum(vendas_matriz > 400)
print(f"\n5. Dias com vendas superiores a 400: {dias_acima_400}")


# add

# 1
arr = np.arange(10)
print(arr)

# 2
bool_mat = np.full((3, 3), True, dtype=bool)
print(bool_mat)

# 3
arr_base = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
impares = arr_base[arr_base % 2 != 0]
print(impares)

# 4
arr_sub = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
arr_sub[arr_sub % 2 != 0] = -1
print(arr_sub)

# 5
mat_aleatoria = np.random.randint(1, 101, size=(5, 5))
print(mat_aleatoria)

# 6
print(mat_aleatoria.sum(axis=0))

# 7
print(mat_aleatoria.max(axis=1))

# 8
a = np.array([1, 2, 3, 4, 5])
print(a + 2)

# 9
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])
print(np.concatenate([a, b]))

# 10
arr_inv = np.array([10, 20, 30, 40])
print(arr_inv[::-1])


#add pt 2

# 1
temps = np.array([22, 24, 21, 23, 25, 20, 22])
print(f"   Média: {temps.mean():.2f}°C")
dias_semana = ["Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sáb"]
print(f"   Dia mais quente: {dias_semana[np.argmax(temps)]} ({temps.max()}°C)")

# 2
vendas_mensais = np.random.randint(50, 201, size=(3, 4))
print(vendas_mensais)
print("   Total por produto:", vendas_mensais.sum(axis=1))

# 3
pontos = np.array([75, 88, 92, 65, 70, 80, 95, 60, 85, 78])
print(f"   Mínima: {pontos.min()} | Máxima: {pontos.max()}")

# 4
sensores = np.random.rand(20)
print("   Leituras acima de 0.7:", sensores[sensores > 0.7])

# 5
precos = np.array([120.50, 121.00, 119.80, 122.30, 120.00])
variacao = np.diff(precos) / precos[:-1] * 100
print(np.round(variacao, 2))

# 6
print(np.eye(4))

# 7
print(np.zeros((3, 3)))
print(np.ones((2, 5)))

# 8
img = np.random.randint(0, 256, size=25).reshape(5, 5)
print(img)

# 9
arr_range = np.arange(10)
print(arr_range[arr_range % 2 == 0])

# 10
print(np.cumsum([1, 2, 3, 4, 5]))

# 11
print(np.unique([1, 2, 2, 3, 4, 4, 4, 5]))

# 12
print(np.linspace(0, 10, 5))

# 13
notas = np.array([80, 90, 70])
pesos = np.array([0.3, 0.5, 0.2])
print(f"   {np.average(notas, weights=pesos):.2f}")

# 14
dados = np.array([[1, 2, 3], [4, 5, 6]])
print(dados.T)

# 15
mat_3x4 = np.arange(1, 13).reshape(3, 4)
print(mat_3x4[::-1])

# 16
a = np.array([1, 2, 3])
b = np.array([3, 2, 1])
print(a == b)

# 17
arr_rand = np.random.randint(0, 101, size=10)
print("   Array:", arr_rand)
print("   Maiores que 50:", arr_rand[arr_rand > 50])

# 18
arr_count = np.array([1, 7, 3, 7, 5, 7])
print(np.sum(arr_count == 7))

# 19
print(np.round([1.23, 2.78, 3.50, 4.11]))

# 20
print(np.vstack(([1, 2, 3], [4, 5, 6])))
