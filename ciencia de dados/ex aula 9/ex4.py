import firebase_admin
from firebase_admin import credentials, firestore

if not firebase_admin._apps:
    cred = credentials.Certificate("serviceAccountKey.json")
    firebase_admin.initialize_app(cred)

db = firestore.client()

produtos_ref = (
    db.collection("produtos_mysql")
      .where("preco", ">", 15.00)
      .order_by("preco", direction=firestore.Query.DESCENDING)
)

resultados = produtos_ref.stream()

for doc in resultados:
    dados = doc.to_dict()
    print(f"{dados['nome']}  R$ {dados['preco']:.2f}")