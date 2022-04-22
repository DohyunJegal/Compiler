#include <stdio.h>

void nexttoken();
char nextchar();

void main() {
	nexttoken();
}

void nexttoken() {
	int state = 0;
	char ch;

	while (1) {
		switch (state) {
		case 0:
			ch = nextchar();

			if (ch == 'f') state = 1;
			else if (ch == 'i') state = 4;
			else if (isalpha(ch)) state = 8;
			else state = 9;
			break;
		case 1:
			ch = nextchar();

			if (ch == 'o') state = 2;
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else state = 9;
			break;
		case 2:
			ch = nextchar();

			if (ch == 'r') state = 3;
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else state = 9;
			break;
		case 3:
			ch = nextchar();

			if (ch == '\n') { putchar('1'); return; }
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else { putchar('1'); state = 9; }
			break;
		case 4:
			ch = nextchar();

			if (ch == 'f') state = 5;
			else if (ch == 'n') state = 6;
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else state = 9;
			break;
		case 5:
			ch = nextchar();

			if (ch == '\n') { putchar('2'); return; }
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else { putchar('2'); state = 9; }
			break;
		case 6:
			ch = nextchar();

			if (ch == 't') state = 7;
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else state = 9;
			break;
		case 7:
			ch = nextchar();

			if (ch == '\n') { putchar('3'); return; }
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else { putchar('3'); state = 9; }
			break;
		case 8:
			ch = nextchar();

			if (ch == '\n') { putchar('9'); return; }
			else if (isdigit(ch) || isalpha(ch)) state = 8;
			else { putchar('9'); state = 9; }
			break;
		case 9:
			printf(" invalid char \'%c\'", ch);
			return;
		}
	}
}

char nextchar() {
	char c;

	while (1) {
		c = getchar();
		if (c == ' ' || c == '\t' || c == '\0') continue;
		return(c);
	}
}