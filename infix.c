
/*  Calculator with twist.
 *  Copyright (C) 2015 kevinshahcool@gmail.com Kevin shah.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "myqueue.h"

#define OPERAND 1
#define OPERATOR 2
#define BRACKETO 3
#define BRACKETC 4
#define ENDT 5
#define INVALID 6

enum states {NUM, OP, SPC, BRACO, BRACC, END, OTHER};
queue *getnext(char *string);
int eval(queue *q);
int infixeval(char *a) {
	int i = 0, currstate = SPC, nextstate = SPC, nc, oc, boc, bcc, done;
	queue *q;
	nc = oc = boc = bcc = done = 0;
	while(done != 1) {
		switch(a[i]) {
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9':
				nextstate = NUM;
				break;
			case '+': case '-': case '*': case '/':
			case '%':
				nextstate = OP;
				break;
			case '(':
				nextstate = BRACO;
				break;
			case ')':
				nextstate = BRACC;
				break;
			case ' ': case '\t':
				nextstate = SPC;
				break;
			case '\0':
				nextstate = END;
				break;
			default:
				nextstate = OTHER;
				break;
		}
		switch(currstate) {
			case NUM:
				switch(nextstate) {
					case NUM:
						break;
					case OP: case BRACC: case SPC: case END:
						nc++;
						break;
					case BRACO: case OTHER:
						printf("INCORRECT FORMAT\n");
						return INT_MIN;
						break;
					default:
						break;	
				}
				break;
			case OP:
				switch(nextstate) {
					case NUM: case BRACO: case SPC:
						oc++;
						break;
					case OP: case BRACC: case OTHER: case END:
						printf("INCORRECT FORMAT\n");
						return INT_MIN;
						break;
					default:
						break;
				}
				break;
			case SPC:
				switch(nextstate) {
					case NUM: case OP: case BRACO: case BRACC:
					case SPC: case END:
						break;
					case OTHER:
						printf("INCORRECT FORMAT\n");
						return INT_MIN;
						break;
					default:
						break;
				}
				break;
			case BRACO:
				switch(nextstate) {
					case NUM: case BRACO: case SPC:
						boc++;
						break;
					case OP: case BRACC: case END: case OTHER:
						printf("INCORRECT FORMAT\n");						
						return INT_MIN;
						break;
					default:
						break;
				}
				break;
			case BRACC:
				switch(nextstate) {
					case NUM: case BRACO: case OTHER:
						printf("INCORRECT FORMAT\n");
						return INT_MIN;
						break;
					case OP: case BRACC: case SPC: case END:
						bcc++;
						break;
					default:
						break;
				}
				break;
			case END:
				done = 1;
				break;
			case OTHER:
				break;
			default:
				break;
		}	
		currstate = nextstate;
		i++;
	}
	if(nc != oc + 1) {
		printf("OPERATORS DON'T MATCH OPERANDS\n");
		return INT_MIN;
	}
	if(bcc != boc) {
		printf("CHECK BRACKETS\n");
		return INT_MIN;
	}
	q = getnext(a);
	if(q == NULL) {
		printf("SORRY, BRO\n");
		return INT_MIN;
	}
	i = eval(q);
	free(q);
	return i;
}
