contatos = []

num = int(input())

for i in range (num):
    contato = {
        "nome": input(),
        "telefone": int(input())
    }
    
    contatos.append(contato)
    
print("escreva o nome desejado: ")

nome = input()

for contato in contatos:
    if contato["nome"] == nome:
        print(f"telefone de {nome}: {contato['telefone']}")

    
