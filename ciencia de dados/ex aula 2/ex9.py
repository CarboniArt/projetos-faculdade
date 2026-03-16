class produto:
    def __init__(self, nome, preco, estoque):
        self.nome = nome
        self.preco = preco
        self.estoque = estoque

    def vender(self, quantidade):
        if quantidade <= self.estoque:
            self.estoque -= quantidade
            print ("venda realizada")
        else:
            print ("estoque insuficiente")

    def repor(self, quantidade):
        self.estoque += quantidade
        print("estoque atualizado")

    
    def exibir(self):
        return f"o produto {self.nome}, custa {self.preco} e tem {self.estoque} unidades"


mouse = produto("Mouse", 50, 10)

print(mouse.exibir())

mouse.vender(3)

print(mouse.exibir())