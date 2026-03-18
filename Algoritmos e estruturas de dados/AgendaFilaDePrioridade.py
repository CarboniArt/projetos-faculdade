import heapq
import tkinter as tk
from tkinter import messagebox, ttk

filaDePrioridade = []
contador = 0

def adicionarTarefa():
    global contador
    tarefa = entradaTarefa.get()
    try:
        prioridade = int(entradaPrioridade.get())
        if prioridade < 1 or prioridade > 10:
            raise ValueError("A prioridade deve estar entre 1 e 10.")
    except ValueError as e:
        messagebox.showerror("Erro", str(e))
        return

    if tarefa:
        heapq.heappush(filaDePrioridade, (prioridade, contador, tarefa))
        contador += 1
        atualizarListaDeTarefas()
        entradaTarefa.delete(0, tk.END)
        entradaPrioridade.delete(0, tk.END)
        entradaTarefa.focus()
    else:
        messagebox.showerror("Erro", "A tarefa não pode estar vazia.")

def removerTarefa():
    if filaDePrioridade:
        removida = heapq.heappop(filaDePrioridade)
        atualizarListaDeTarefas()
        messagebox.showinfo("Tarefa Removida", f"Tarefa '{removida[2]}' removida com sucesso!")
    else:
        messagebox.showerror("Erro", "Não há tarefas para remover.")

def concluirTarefa(index):
    filaDePrioridade.pop(index)
    atualizarListaDeTarefas()

def atualizarListaDeTarefas():
    for widget in frameTarefas.winfo_children():
        widget.destroy()
    
    for i, (prioridade, _, tarefa) in enumerate(sorted(filaDePrioridade)):
        cb = ttk.Checkbutton(frameTarefas, text=f"{tarefa} (Prioridade: {prioridade})", command=lambda i=i: concluirTarefa(i))
        cb.pack(anchor='w')

root = tk.Tk()
root.title("Lista de Tarefas com Prioridade")

label_tarefa = tk.Label(root, text="Tarefa:")
label_tarefa.grid(row=0, column=0, padx=10, pady=10)

entradaTarefa = tk.Entry(root, width=40)
entradaTarefa.grid(row=0, column=1, padx=10, pady=10)
entradaTarefa.bind("<Return>", lambda event: adicionarTarefa())

label_prioridade = tk.Label(root, text="Prioridade:")
label_prioridade.grid(row=1, column=0, padx=10, pady=10)

entradaPrioridade = tk.Entry(root, width=10)
entradaPrioridade.grid(row=1, column=1, padx=10, pady=10)
entradaPrioridade.bind("<Return>", lambda event: adicionarTarefa())

botaoAdicionar = tk.Button(root, text="Adicionar Tarefa", command=adicionarTarefa)
botaoAdicionar.grid(row=2, column=0, columnspan=2, pady=10)

frameTarefas = tk.Frame(root)
frameTarefas.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

botaoRemover = tk.Button(root, text="Remover Tarefa com Maior Prioridade", command=removerTarefa)
botaoRemover.grid(row=4, column=0, columnspan=2, pady=10)

root.mainloop()