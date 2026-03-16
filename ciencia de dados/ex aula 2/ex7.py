from collections import Counter

cont = Counter()

for i in range (1, 10):
    texto = input()
    palavra = texto.split()
    cont.update(palavra)

print(cont.most_common(3))  

