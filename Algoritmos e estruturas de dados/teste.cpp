função analisar(entrada):
    i ← 0
    enquanto i < tamanho(entrada):
        c ← entrada[i]

        se c é espaço:
            i ← i + 1 
            continua

        se c é dígito:
            lexema ← ""
            enquanto i < tamanho(entrada) e entrada[i] é dígito:
                lexema ← lexema + entrada[i]
                i ← i + 1
            se i < tamanho(entrada) e entrada[i] == '.':
                lexema ← lexema + '.'
                i ← i + 1
                se entrada[i] não é dígito: ERRO("esperado dígito após '.'")
                enquanto i < tamanho(entrada) e entrada[i] é dígito:
                    lexema ← lexema + entrada[i]
                    i ← i + 1
                emitir token(NUM_REAL, lexema)
            senão:
                emitir token(NUM_INT, lexema)

        senão se c ∈ {'+', '-', '*', '/'}:
            emitir token(OP, c)
            i ← i + 1

        senão se c == '(':
            emitir token(ABRE_PAR, c)
            i ← i + 1

        senão se c == ')':
            emitir token(FECHA_PAR, c)
            i ← i + 1

        senão:
            emitir token(ERRO, c)
            i ← i + 1




    TOKEN_SPEC = [
    ('NUM_REAL',    r'\d+\.\d+'),
    ('NUM_INT',     r'\d+'),
    ('OP',          r'[+\-*/]'),
    ('ABRE_PAR',    r'\('),
    ('FECHA_PAR',   r'\)'),
    ('ESPACO',      r'\s+'),
    ('ERRO',        r'.'),
]