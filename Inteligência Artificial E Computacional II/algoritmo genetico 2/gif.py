import glob
from PIL import Image
import os
import sys
from tqdm import tqdm

EVOLUTION_DIR = "evolucao"
FILE_PATTERN = "gen_*.png"
OUTPUT_GIF_NAME = "evolucao.gif"
FRAME_SAMPLE_RATE = 100 
FRAME_DURATION_MS = 200
LOOP_COUNT = 0

def create_evolution_gif():
    all_files = sorted(glob.glob(os.path.join(EVOLUTION_DIR, FILE_PATTERN)))
    
    if not all_files:
        print(f"Erro: Nenhuma imagem encontrada em '{EVOLUTION_DIR}' com o padrao '{FILE_PATTERN}'.")
        return

    print(f"Total de frames de evolucao encontrados: {len(all_files)}")
    
    sampled_files = all_files[::FRAME_SAMPLE_RATE]
    
    print(f"Total de frames a serem usados no GIF (Taxa de Amostragem {FRAME_SAMPLE_RATE}): {len(sampled_files)}")
    
    if not sampled_files:
        print("Erro: A taxa de amostragem é muito alta. Nenhum frame foi selecionado.")
        return

    frames = []
    
    print("Carregando frames...")
    for file_path in tqdm(sampled_files):
        try:
            frames.append(Image.open(file_path))
        except IOError:
            print(f"\nAviso: Não foi possível carregar a imagem {file_path}. Pulando.", file=sys.stderr)

    if not frames:
        print("Erro: Nenhum frame pôde ser carregado. Não é possível criar o GIF.")
        return

    output_path = os.path.join(EVOLUTION_DIR, OUTPUT_GIF_NAME)
    
    try:
        frames[0].save(
            output_path,
            save_all=True,
            append_images=frames[1:],
            duration=FRAME_DURATION_MS,
            loop=LOOP_COUNT,
            optimize=True
        )
        print(f"\nGIF criado com sucesso em {output_path}")
    except Exception as e:
        print(f"\nErro ao tentar salvar o GIF: {e}")

if __name__ == "__main__":
    create_evolution_gif()