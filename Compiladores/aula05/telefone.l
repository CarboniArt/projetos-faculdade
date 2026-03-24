/* (\+55[ ]?)?(\(0?[1-9][0-9]\)|0?[1-9][0-9])[ \-]?(9[0-9]{4}|[2-9][0-9]{3})[\-]?[0-9]{4} */

%option noyywrap

PAIS        (\+55[ ]?)?
DDD         (\(0?[1-9][0-9]\)|0?[1-9][0-9])
SEP         [ \-]?
PREFIXO9    9[0-9]{4}
PREFIXO_FIX [2-9][0-9]{3}
SUFIXO      [0-9]{4}

%%

{PAIS}{DDD}{SEP}({PREFIXO9}|{PREFIXO_FIX}){SEP}{SUFIXO} {
    printf("TELEFONE VALIDO: %s\n", yytext);
}

.|\n  { /* ignora */ }

%%

void main() {
    yylex();
}