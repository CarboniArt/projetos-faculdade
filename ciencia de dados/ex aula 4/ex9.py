import pandas as pd
df = pd.read_csv(
    'notas.csv',
    engine='python',  

)


print(df.describe)