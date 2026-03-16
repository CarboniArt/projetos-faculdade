import pandas as pd
df = pd.read_csv(
    'big_data_simulado.csv',
    engine='python',  

)


print(df.info)