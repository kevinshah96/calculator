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
#include <stdlib.h>
#include <limits.h>
#include "myqueue.h"

#define OPERAND 1
#define OPERATOR 2
#define BRACKETO 3
#define BRACKETC 4
#define ENDT 5
#define INVALID 6

enum states {SPC, NUM, OPR, OPEN, CLOSE, END, ERROR};

queue *getnext(char *string) {
	int currstate = SPC, nextstate, i = 0, sum;
	token p;
	queue *q;
	q = (queue *)malloc(sizeof(queue));
	if(q == NULL) {
		return NULL;
	}
	qinit(q);
	while(1) {
		switch(string[i]) {
			case '1': case'2': case '3': case '4':
			case '5': case'6': case '7': case '8':
			case '9': case'0': 
				nextstate = NUM;
				break;
			case '+': case '-': case '*': case '/':
			case '%':
				nextstate = OPR;
				break;
			case '(':
				nextstate = OPEN;
				break;
			case ')':
				nextstate = CLOSE;
				break;
			case '\0':
				nextstate = END;
				break;
			case ' ':
				nextstate = SPC;
				break;
			default:
				nextstate = ERROR;
				break;
		}
		switch(currstate) {
			case SPC:
				switch(nextstate){
					case SPC:
						/* Do nothing */
						break;
					case NUM:
						sum = string[i] - '0';	
						break;
					case OPR:
						/* Do nothing */
						break;
					case OPEN:
						/* Do nothing */
						break;
					case CLOSE:
						/* Do nothing */
						break;
					case END:
						break;
					case ERROR:
						break;
					default:
						break;
				}
				break;
			case NUM:
				switch(nextstate){
					case SPC:
						/* Num completed */
						p.type = OPERAND;
						p.d.num = sum;
						enqueue(q, &p);
						break;
					case NUM:
						sum = sum * 10 + string[i] - '0';
						break;
					case OPR:
						p.type = OPERAND;
						p.d.num = sum;
						enqueue(q, &p);
						break;
					case OPEN:
						p.type = OPERAND;
						p.d.num = sum;
						enqueue(q, &p);
						break;
					case CLOSE:
						p.type = OPERAND;
						p.d.num = sum;
						enqueue(q, &p);
						break;
					case END:
						p.type = OPERAND;
						p.d.num = sum;
						enqueue(q, &p);
						break;
					case ERROR:
						p.type = OPERAND;
						p.d.num = sum;
						enqueue(q, &p);
						break;
					default:
						break;
				}
				break;
			case OPR:
				switch(nextstate){
					case SPC:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case NUM:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						sum = string[i] - '0';
						break;
					case OPR:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case OPEN:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case CLOSE:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case END:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case ERROR:
						p.type = OPERATOR;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					default:
						break;
				}
				break;
			case OPEN:
				switch(nextstate){
					case SPC:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case NUM:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						sum = string[i] - '0';	
						break;
					case OPR:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case OPEN:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case CLOSE:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case END:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case ERROR:
						p.type = BRACKETO;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					default:
						break;
				}
				break;
			case CLOSE:
				switch(nextstate){
					case SPC:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case NUM:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						sum = string[i] - '0';	
						break;
					case OPR:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case OPEN:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case CLOSE:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case END:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					case ERROR:
						p.type = BRACKETC;
						p.d.op = string[i - 1];
						enqueue(q, &p);
						break;
					default:
						break;
				}
				break;
			case END:
				p.type = ENDT;
				p.d.op = '\0';
				enqueue(q, &p);
				return q;
				break;
			case ERROR:
				nextstate = ERROR;
				p.type = INVALID;
				enqueue(q, &p);
				return q;
				break;
			default:
				break;
		}
		currstate = nextstate;
		i++;
		
	}
	return NULL;	
}
