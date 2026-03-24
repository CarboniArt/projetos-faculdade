/* (https?|ftp)://[a-zA-Z0-9\-]+(\.[a-zA-Z0-9\-]+)+(:[0-9]{1,5})?(/...)? */

%option noyywrap

SCHEME  (https?|ftps?)
LABEL   [a-zA-Z0-9][a-zA-Z0-9\-]*
DOMAIN  {LABEL}("."{LABEL})+
PCHAR   [a-zA-Z0-9\-._~!$&()*+,;=:@%]
PATH    ("/"{PCHAR}*)*
QCHAR   [a-zA-Z0-9\-._~!$&()*+,;=:@/?%]
QUERY   "?"{QCHAR}+
FRAG    "#"{QCHAR}+

%%

{SCHEME}"://"{DOMAIN}(":"[0-9]{1,5})?{PATH}?{QUERY}?{FRAG}? {
    printf("URL VALIDA: %s\n", yytext);
}

"www."{LABEL}("."{LABEL})+{PATH}?{QUERY}?{FRAG}? {
    printf("URL-WWW VALIDA: %s\n", yytext);
}

.|\n  { /* ignora */ }

%%

void main() {
    yylex();
}