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

int eval(queue *q);
token *bracket(node **x) {
	int open = 0, close = 0;
	token *t1;
	t1 = (token *)malloc(sizeof(token));
	if(t1 == NULL) {
		return NULL;
	}
	queue temp;
	qinit(&temp);	
	open++;
	while(open != close) {
		if((*x)->a.type == OPERAND) {
			enqueue(&temp, &((*x)->a));
		}
		if((*x)->a.type == OPERATOR) {
			enqueue(&temp, &((*x)->a));
		}
		if((*x)->a.type == BRACKETO) {
			enqueue(&temp, &((*x)->a));
			open++;
		}
		if((*x)->a.type == BRACKETC) {
			if(open != close + 1) {
				enqueue(&temp, &((*x)->a));
			}
			close++;
		}
		
		(*x) = (*x)->next;
	}
	t1->type = ENDT;
	t1->d.op = '\0';
	enqueue(&temp, t1);
	t1->type = OPERAND;
	t1->d.num = eval(&temp);
	return t1;
}

int eval(queue *q) {
	int temp = 0;
	token *t, *t2, *t3;
	queue q1;
	node *tok, *tem;
	qinit(&q1);
	tok = q->head;
	while(1) {
		if(tok->a.type == OPERAND) {
			enqueue(&q1, &(tok->a));
		}
		if(tok->a.type == OPERATOR) {
			switch(tok->a.d.op) {
				case '+':
					enqueue(&q1, &(tok->a));
					break;
				case '-':
					enqueue(&q1, &(tok->a));
					break;
				case '*':
					if(tok->next->a.type == BRACKETO) {
						tem = tok->next->next;
						t = bracket(&tem);
						if(t == NULL) {
							printf("SORRY, BRO\n");
							return INT_MIN;
						}						
						tok = tem->prev;
					}
					else {
						t = &(tok->next->a);
						tok = tok->next;
					}		
					t3 = pop(&q1);
					t->d.num *= t3->d.num;
					enqueue(&q1, t);
					free(t);
					free(t3);
					break;
				case '/':
					if(tok->next->a.type == BRACKETO) {
						tem = tok->next->next;
						t = bracket(&(tem));
						if(t == NULL) {
							printf("SORRY, BRO\n");
							return INT_MIN;
						}
						tok = tem->prev;
					}
					else {
						t = &(tok->next->a);
						tok = tok->next;
					}			
					t3 = pop(&q1);					
					t->d.num = t3->d.num / t->d.num;
					enqueue(&q1, t);
					free(t);
					free(t3);
					break;
				case '%':
					if(tok->next->a.type == BRACKETO) {
						tem = tok->next->next;
						t = bracket(&(tem));
						if(t == NULL) {
							printf("SORRY, BRO\n");
							return INT_MIN;
						}
						tok = tem->prev;
					}
					else {
						t = &(tok->next->a);
						tok = tok->next;
					}			
					t3 = pop(&q1);
					t->d.num = t3->d.num % t->d.num;
					enqueue(&q1, t);
					free(t);
					free(t3);
					break;
				default:
					break;
			}
		}
		if(tok->a.type == BRACKETO) {
			tem = tok->next;
			t2 = bracket(&tem);
			if(t2 == NULL) {
				printf("SORRY, BRO\n");
				return INT_MIN;
			}
			tok = tem->prev;
			enqueue(&q1, t2);
			free(t2);			
		}
		if(tok->a.type == ENDT) {
			break;
		}
		if(tok->next != NULL) {
			tok = tok->next;
		}
		
	}
	while(!qempty(&q1)) {
		t = dequeue(&q1);
		if(t->type == OPERAND) {
			temp = t->d.num;
		}
		if(t->type == OPERATOR) {
			switch(t->d.op) {
				case '+':
					t2 = dequeue(&q1);
					temp += t2->d.num;
					free(t2);
					break;
				case '-':
					t2 = dequeue(&q1);
					temp -= t2->d.num;
					free(t2);
					break;
				default:
					break;
			}
		}
		free(t);
	}
	return temp;
}
