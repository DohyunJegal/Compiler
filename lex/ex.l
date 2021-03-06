%{
#define IF 100
#define ID 101
#define RELOP 102
#define WHILE 103
#define FOR 104
#define SWITCH 105
#define CASE 106
#define COMMENT 107
#define LE 201
int yywrap() {return(0);};
int yylval, tok;
%}
delim [ \t\n]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
%%
{ws} {/* do nothing */}
if {return(IF); }
while {return(WHILE);}
for {return(FOR);}
switch {return(SWITCH);}
case {return(CASE);}
"//".* {return(COMMENT);}
{id} {yylval = install_id(); return(ID);}
"<=" {yylval= LE; return(RELOP);}
%%
int install_id() { return(1); }
main(){ while(1){ tok = yylex(); printf("%d %d\n", tok, yylval);}}