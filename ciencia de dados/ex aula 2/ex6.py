import math 
print("insira o x1")
x1 = float(input())
print("insira o y1")
y1 = float(input())

coordenadas1 = (x1, y1)

print("insira o x2")
x2 = float(input())
print("insira o y2")
y2 = float(input())

coordenadas2 = (x2, y2)


distancia = math.sqrt((coordenadas2[0] - coordenadas1[0])**2 + (coordenadas2[1] - coordenadas1[1])**2)

print("Distância:", distancia)