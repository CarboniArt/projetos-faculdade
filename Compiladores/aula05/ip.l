/* IPv4: (25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])(\.(mesmo)){3} */
/* IPv6: ([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4} */

%option noyywrap

OCT     (25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])
IPV4    {OCT}"."{OCT}"."{OCT}"."{OCT}
CIDR    {OCT}"."{OCT}"."{OCT}"."{OCT}"/"([0-9]|[12][0-9]|3[0-2])
HEX     [0-9a-fA-F]{1,4}
IPV6    {HEX}":"{HEX}":"{HEX}":"{HEX}":"{HEX}":"{HEX}":"{HEX}":"{HEX}

%%

{CIDR} {
    printf("IPv4/CIDR VALIDO: %s\n", yytext);
}

{IPV4} {
    printf("IPv4 VALIDO: %s\n", yytext);
}

{IPV6} {
    printf("IPv6 VALIDO: %s\n", yytext);
}

"::1" {
    printf("IPv6 LOOPBACK: %s\n", yytext);
}

.|\n  { /* ignora */ }

%%

void main() {
    yylex();
}