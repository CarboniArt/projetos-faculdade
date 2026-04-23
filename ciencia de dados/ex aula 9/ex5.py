import firebase_admin
from firebase_admin import credentials, storage
import tempfile, os

if not firebase_admin._apps:
    cred = credentials.Certificate("serviceAccountKey.json")
    firebase_admin.initialize_app(cred, {
        "storageBucket": "cienciadados-ba9c1.appspot.com"
    })

bucket = storage.bucket()

with tempfile.NamedTemporaryFile(mode="w", suffix=".txt", delete=False) as f:
    f.write("Olá, Firebase Storage!")
    caminho_local = f.name

blob = bucket.blob("uploads/meu_arquivo.txt")
blob.upload_from_filename(caminho_local, content_type="text/plain")

print(f"Arquivo enviado: gs://{bucket.name}/uploads/meu_arquivo.txt")
os.unlink(caminho_local)