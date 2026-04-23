import firebase_admin
from firebase_admin import credentials, auth, exceptions

if not firebase_admin._apps:
    cred = credentials.Certificate("serviceAccountKey.json")
    firebase_admin.initialize_app(cred)

def buscar_usuario_seguro(uid: str):
    try:
        user = auth.get_user(uid)
        print(f"Encontrado: {user.email}")
        return user

    except auth.UserNotFoundError:
        print(f"Usuário '{uid}' não encontrado.")

    except exceptions.InvalidArgumentError as e:
        print(f"Argumento inválido: {e}")

    except exceptions.FirebaseError as e:
        print(f"Erro Firebase [{e.code}]: {e}")

    except Exception as e:
        print(f"Erro inesperado: {e}")

    return None

buscar_usuario_seguro("uid_inexistente_xyz")
buscar_usuario_seguro("")