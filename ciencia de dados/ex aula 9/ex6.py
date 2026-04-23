import firebase_admin
from firebase_admin import credentials, messaging

if not firebase_admin._apps:
    cred = credentials.Certificate("serviceAccountKey.json")
    firebase_admin.initialize_app(cred)

msg_topico = messaging.Message(
    notification=messaging.Notification(
        title="Nova oferta disponível!",
        body="Confira os produtos em destaque hoje."
    ),
    topic="ofertas"
)

resp_t = messaging.send(msg_topico)
print(f"Tópico — ID da mensagem: {resp_t}")

TOKEN_DISPOSITIVO = "425226826"

msg_token = messaging.Message(
    notification=messaging.Notification(
        title="Olá, usuário!",
        body="Você tem uma nova mensagem."
    ),
    token=TOKEN_DISPOSITIVO
)

resp_d = messaging.send(msg_token)
print(f"Token — ID da mensagem: {resp_d}")