class Veiculo:
    def __init__(self, modelo):
        self.modelo = modelo
        
    def tipo_habilitacao(self):
        return "habilitacao geral"
        
class Carro(Veiculo):
    def tipo_habilitacao(self):
        return "categoria b"
    
    
class Moto(Veiculo):
    def tipo_habilitacao(self):
        return "categoria a"
    
carro = Carro("Civic")
moto = Moto("hornet")



print(f"{carro.modelo} requer habilitação {carro.tipo_habilitacao()}")

print(f"{moto.modelo} requer habilitação {moto.tipo_habilitacao()}")    