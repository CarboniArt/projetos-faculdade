import firebase_admin
from firebase_admin import credentials, auth


if not firebase_admin._apps:
    cred = credentials.Certificate("serviceAccountKey.json")
    firebase_admin.initialize_app(cred)


user = auth.create_user(
    email="joao@exemplo.com",
    password="senha123",
    display_name="João Silva"
)

print(f"Usuário criado com sucesso!")
print(f"UID: {user.uid}")

usuario = auth.get_user(user.uid)

print(f"\nDados do usuário:")
print(f"  Nome:  {usuario.display_name}")
print(f"  Email: {usuario.email}")
print(f"  UID:   {usuario.uid}")