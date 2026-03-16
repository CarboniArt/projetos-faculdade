import pandas as pd

for chunk in pd.read_csv(
        "transacoes_grandes.csv",
        sep=";",
        decimal=",",
        chunksize=10):

    media_valor = chunk["valor_unitario"].mean()
    peso_total = chunk["peso_kg"].sum()

    print("Valor médio:", media_valor)
    print("Peso total:", peso_total)
    print("-" * 30)