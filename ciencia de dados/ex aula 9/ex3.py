import firebase_admin
from firebase_admin import credentials, firestore

if not firebase_admin._apps:
    cred = credentials.Certificate("serviceAccountKey.json")
    firebase_admin.initialize_app(cred)

db = firestore.client()

def atualizar_preco(produto_id: str, novo_preco: float):
    ref = db.collection("produtos_mysql").document(produto_id)
    ref.update({
        "preco": novo_preco,
        "atualizado_em": firestore.SERVER_TIMESTAMP
    })
    print(f"Produto '{produto_id}' atualizado para R$ {novo_preco:.2f}")

atualizar_preco("prod_001", 19.90)