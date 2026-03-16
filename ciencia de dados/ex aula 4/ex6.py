import pandas as pd
df = pd.read_csv(
    'transacoes.csv',
    engine='python',  
    na_values=['-', 'NA']
    

)

print(df)
print(df.info)