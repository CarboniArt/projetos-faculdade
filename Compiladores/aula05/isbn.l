/* (978|979)-?[0-9]{1,5}-?[0-9]{1,7}-?[0-9]{1,6}-?[0-9X] */

%option noyywrap

SEP     "-"?
ISBN13  (978|979){SEP}[0-9]{1,5}{SEP}[0-9]{1,7}{SEP}[0-9]
ISBN10  [0-9]{1,5}{SEP}[0-9]{1,7}{SEP}[0-9]{1,6}{SEP}[0-9X]

%%

{ISBN13} {
    printf("ISBN-13 VALIDO: %s\n", yytext);
}

{ISBN10} {
    printf("ISBN-10 VALIDO: %s\n", yytext);
}

.|\n  { /* ignora */ }

%%

void main() {
    yylex();
}