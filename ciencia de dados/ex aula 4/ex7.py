import pandas as pd
df = pd.read_csv(
    'experimento.csv',
    engine='python',

)

print(df.head(3))
print(df.tail())
print(df.describe()) 