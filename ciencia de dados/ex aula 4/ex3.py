import pandas as pd
df = pd.read_csv(
    'log_sistema.csv', 
    engine='python',
    skiprows= 2,
    nrows=2
)



print(df)
