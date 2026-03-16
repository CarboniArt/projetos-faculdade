import pandas as pd
df = pd.read_csv(
    'transacoes.csv',
    engine='python',  
    thousands='.',
    decimal=','
    

)

print(df)
print(df.dtypes)