class Livro:
    def __init__(self, titulo, autor, isbn):
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn
        self.disponivel = True

    def exibir(self):
        status = "Disponível" if self.disponivel else "Emprestado"
        return f"{self.titulo} - {self.autor} | ISBN: {self.isbn} | {status}"
   
   
    
class Usuario:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf
        self.livros_emprestados = []

    def pegar_livro(self, livro):
        self.livros_emprestados.append(livro)

    def devolver_livro(self, livro):
        self.livros_emprestados.remove(livro)
 
 
        
class Biblioteca:
    def __init__(self):
        self.livros = []
        self.usuarios = {}

    def adicionar_livro(self, livro):
        self.livros.append(livro)

    def cadastrar_usuario(self, usuario):
        self.usuarios[usuario.cpf] = usuario

    def buscar_livro(self, titulo):
        for livro in self.livros:
            if livro.titulo.lower() == titulo.lower():
                return livro
        return None
    

    def emprestar_livro(self, titulo, cpf):
        try:
            livro = self.buscar_livro(titulo)

            if livro is None:
                print("Livro não encontrado.")
                return

            if not livro.disponivel:
                print("Livro já emprestado.")
                return

            usuario = self.usuarios.get(cpf)

            if usuario is None:
                print("Usuário não encontrado.")
                return

            livro.disponivel = False
            usuario.pegar_livro(livro)

            print("Livro emprestado com sucesso!")

        except Exception as erro:
            print("Erro ao emprestar livro:", erro)
            

    def devolver_livro(self, titulo, cpf):
        try:
            usuario = self.usuarios.get(cpf)

            if usuario is None:
                print("Usuário não encontrado.")
                return

            livro = self.buscar_livro(titulo)

            if livro in usuario.livros_emprestados:
                usuario.devolver_livro(livro)
                livro.disponivel = True
                print("Livro devolvido com sucesso!")

        except Exception as erro:
            print("Erro ao devolver livro:", erro)
            
            
biblioteca = Biblioteca()

livro1 = Livro("1984", "George Orwell", "123")
livro2 = Livro("Dom Casmurro", "Machado de Assis", "456")

biblioteca.adicionar_livro(livro1)
biblioteca.adicionar_livro(livro2)

usuario1 = Usuario("Arthur", "11122233344")

biblioteca.cadastrar_usuario(usuario1)

biblioteca.emprestar_livro("1984", "11122233344")

print(livro1.exibir())

biblioteca.devolver_livro("1984", "11122233344")

print(livro1.exibir())