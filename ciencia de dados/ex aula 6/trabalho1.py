import json
import requests
from PIL import Image
from io import BytesIO
from newsapi import NewsApiClient

KEY_FILE = 'SECRET.key'
with open(KEY_FILE, 'r', encoding='utf-8') as f:
    api_key = f.read().strip()

newsapi = NewsApiClient(api_key=api_key)

with open('keywords.json', 'r', encoding='utf-8') as f:
    keywords = json.load(f)['keywords']

for keyword in keywords:
    print(f'\n===== {keyword.upper()} =====\n')
    
    top_headlines = newsapi.get_top_headlines(
        sources='bbc-news,the-verge,cnn,fox-news,reuters,bloomberg,'
        'techcrunch,wired,ars-technica,engadget,the-washington-post,the-new-york-times,'
        'associated-press,business-insider,espn',
        language='en',
        q=keyword
    )

    articles = top_headlines.get('articles', [])

    if len(articles) == 0:
        print("Nenhuma notícia encontrada.")
        continue

    article = articles[0]

    source = article.get('source', {}).get('name', 'N/A')
    title = article.get('title', 'N/A')
    description = article.get('description', 'N/A')
    url = article.get('url', 'N/A')
    image_url = article.get('urlToImage')

    print(f'{source}: {title}')
    print(description)
    print(url)
    print(image_url)
    print('-' * 50)

    with open(f'{keyword}_news.txt', 'w', encoding='utf-8') as f:
        f.write(f'{source}: {title}\n{description}\n{url}\n{image_url}\n')

    if image_url:
        try:
            resposta = requests.get(image_url, timeout=5)

            if resposta.status_code == 200:
                img = Image.open(BytesIO(resposta.content))
                caminho = f"{keyword}.jpg"
                img.convert("RGB").save(caminho, "JPEG")
                print(f"Imagem salva: {caminho}")
            else:
                print("Erro ao baixar imagem")

        except Exception as e:
            print("Erro:", e)
    else:
        print("Notícia sem imagem")