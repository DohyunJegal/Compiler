#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void match(char);
char nexttoken();
void term();
void expr();
void R();
void R2();
void factor();

char lookahead;

void main() {
	lookahead = nexttoken();
	expr();

	if (lookahead == '$')
		printf("\n");
	else
		printf(" error\n");
}

void match(char token) {
	if (lookahead == token) {
		lookahead = nexttoken();
	}
	else {
		printf(" error\n");
		exit(1);
	}
}

char nexttoken() {
	char c;

	while (1) {
		c = getchar();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
		return(c);
	}
}

void term() {
	factor();  putchar('6'); R2();
}

void expr() {
	term();  putchar('3'); R();
}

void R() {
	while (1) {
		if (lookahead == '+') {
			match('+'); term(); putchar('1');
		}
		else if (lookahead == '-') {
			match('-'); term(); putchar('2');
		}
		else break;
	}
}

void R2() {
	while (1) {
		if (lookahead == '*') {
			match('*'); factor(); putchar('4');
		}
		else if (lookahead == '/') {
			match('/'); factor(); putchar('5');
		}
		else break;
	}
}

void factor() {
	if (isdigit(lookahead)) {
		match(lookahead);
	}
	else if (lookahead == '(') {
		match('('); expr(); putchar('7');

		if (lookahead == ')') {
			match(')');
		}
		else {
			printf(" error\n");
			exit(1);
		}
	}
	else {
		printf(" error\n");
		exit(1);
	}
}