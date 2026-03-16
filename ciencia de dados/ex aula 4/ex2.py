import pandas as pd

df = pd.read_csv(
    'clima.csv',
    parse_dates=['data'],
    decimal=',' 
)



print(df.dtypes)
