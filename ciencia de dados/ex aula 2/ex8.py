def estatisticas(*numeros):
    return{
        "maximo": max(numeros),
        "minimo": min(numeros),
        "media": sum(numeros)/len(numeros)
    }
    
resultado = estatisticas(10, 20, 50, 30)

print (resultado)