import pandas as pd
df = pd.read_csv(
    'estoque.csv',
    engine='python',
    dtype = {
        'valor_unitario' : 'float64',
        'peso_kg' : 'float64'
    }
    

)


print(df.dtypes)