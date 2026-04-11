import string
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer, CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity

documents = [
    "Em um futuro próximo, as lutas de boxe não são mais travadas entre seres humanos, e sim por robôs enormes, capazes de desferir golpes ultrapotentes. Neste cenário, Charlie Kenton, interpretado por Hugh Jackman, é um ex-boxeador decadente que perdeu sua chance de conquistar um título quando os robôs de aço tomaram conta dos ringues.",
    "Charlie Kenton se tornou um insignificante promotor de lutas, juntando sucatas de robôs para sobreviver e passando de arena em arena. Quando chega ao fundo do poço, ele se vê obrigado a formar uma equipe com seu filho afastado, Max, interpretado por Dakota Goyo, para tentar uma nova chance no esporte.",
    "Charlie e Max descobrem um robô descartado em um ferro velho, chamado Atom, construído a partir de peças de baixa qualidade e restos de outras máquinas. Juntos, eles começam a treinar Atom para competir nas arenas de boxe robótico, desafiando adversários muito mais poderosos e sofisticados.",
    "Conforme as apostas na brutal arena sem limites aumentam, Charlie e Max enfrentam desafios cada vez maiores. O vínculo entre pai e filho se fortalece ao longo da jornada, transformando a batalha no ringue em muito mais do que uma simples disputa esportiva.",
    "Gigantes de Aço é uma história eletrizante de ação e emoção, ambientada em 2020, quando o boxe humano foi proibido e robôs humanoides peso-pesado assumiram o espetáculo. Charlie e Max, contra todas as probabilidades, têm uma última chance de dar a volta por cima com seu improvável campeão, o robô Atom.",
]

stopwords = {
    "o", "a", "os", "as", "um", "uma", "uns", "umas", "de", "do", "da", "dos", "das",
    "em", "no", "na", "nos", "nas", "por", "pelo", "pela", "pelos", "pelas",
    "para", "ao", "aos", "à", "às", "com", "sem", "e", "ou", "mas", "que", "se", "como", "até",
    "nem", "porém", "ele", "ela", "eles", "elas", "seu", "sua", "seus", "suas", "este", "esta",
    "estes", "estas", "esse", "essa", "esses", "essas", "neste", "nesta", "nestes", "nestas",
    "isso", "isto", "aqui", "é", "são", "ser", "está", "era", "foi", "há", "tem", "ter",
    "não", "mais", "muito", "também", "já", "bem", "toda", "todo", "todos", "todas",
    "menos", "apenas", "nada", "depois",
}

def preprocessamento(text: str) -> str:
    text = text.lower()
    text = text.replace("-", " ")
    text = text.translate(str.maketrans("", "", string.punctuation))
    tokens = text.split()
    tokens = [t for t in tokens if t not in stopwords]
    return " ".join(tokens)

docs_processado = [preprocessamento(doc) for doc in documents]

print("=" * 60)
print("DOCUMENTOS PROCESSADOS")
print("=" * 60)
for i, doc in enumerate(docs_processado):
    print(f"\nDoc {i}: {doc}")

count_vectorizer = CountVectorizer()
tf_matrix = count_vectorizer.fit_transform(docs_processado)
tf_dense = tf_matrix.toarray().T
vocab_count = count_vectorizer.get_feature_names_out()

print("\n")
print("=" * 60)
print("MATRIZ TERMO-DOCUMENTO (TF bruto)")
print("=" * 60)
header_tf = "Termo".ljust(20) + "".join(f"Doc{i}".rjust(8) for i in range(len(documents)))
print(header_tf)
print("-" * len(header_tf))
for j, term in enumerate(vocab_count):
    coluna = term.ljust(20) + "".join(f"{tf_dense[j, i]:8d}" for i in range(len(documents)))
    print(f"{coluna}")

vectorizer = TfidfVectorizer()
tfidf_matrix = vectorizer.fit_transform(docs_processado)
vocabulario = vectorizer.get_feature_names_out()
matrix_dense = tfidf_matrix.toarray().T

print("\n")
print("=" * 60)
print("MATRIZ TERMO-DOCUMENTO (TF-IDF)")
print("=" * 60)
header = "Termo".ljust(20) + "".join(f"Doc{i}".rjust(8) for i in range(len(documents)))
print(header)
print("-" * len(header))
for j, term in enumerate(vocabulario):
    coluna = term.ljust(20) + "".join(f"{matrix_dense[j, i]:8.4f}" for i in range(len(documents)))
    print(f"{coluna}")

query = "Charlie robô boxe arena"
query_processada = preprocessamento(query)
query_vector = vectorizer.transform([query_processada])
pontuacao = cosine_similarity(query_vector, tfidf_matrix).flatten()
ranking = np.argsort(pontuacao)[::-1]

print("\n")
print("=" * 60)
print(f'CONSULTA: "{query}"')
print("=" * 60)
print(f"\nConsulta processada: \"{query_processada}\"")

print("\nVetor da consulta (TF-IDF):")
for i, val in enumerate(query_vector.toarray()[0]):
    if val > 0:
        print(f"  {vocabulario[i]}: {val:.4f}")

print("\nPontuação de Similaridade (cosseno):")
for i, pont in enumerate(pontuacao):
    print(f"  Doc {i}: {pont:.4f}")

print("\n")
print("=" * 60)
print("RANKING FINAL (por relevância)")
print("=" * 60)
for pos, i in enumerate(ranking, start=1):
    print(f"  {pos}º — Doc {i} (score = {pontuacao[i]:.4f})")

print("\n")
print("=" * 60)
print("DOCUMENTO MAIS RELEVANTE")
print("=" * 60)
best = ranking[0]
print(f"\n  Doc {best} (score = {pontuacao[best]:.4f}):")
print(f"  \"{documents[best]}\"")