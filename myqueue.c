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
#include "myqueue.h"

#define OPERAND 1
#define OPERATOR 2
#define BRACKETO 3
#define BRACKETC 4
#define ENDT 5
#define INVALID 6

void qinit(queue *q) {
	q->head = NULL;
	q->tail = NULL;
}

void enqueue(queue *q, token *t) {
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	if(tmp == NULL) {
		printf("SORRY, BRO\n");
		exit(1);
	}
	tmp->a.type = t->type;
	if(tmp->a.type == OPERAND) {
		tmp->a.d.num = t->d.num;
	}
	else {
		tmp->a.d.op = t->d.op;
	}
	tmp->next = NULL;
	tmp->prev = q->tail;
	if(q->tail == NULL) {
		q->head = tmp;
	}
	else {
		q->tail->next = tmp;
	}
	q->tail = tmp;
}

token *dequeue(queue *q) {
	node *tmp = q->head->next;
	token *rd = (token *)malloc(sizeof(token));
	if(rd == NULL) {
		printf("SORRY, BRO\n");
		exit(1);
	}	
	rd->type = q->head->a.type;
	if(rd->type == OPERAND) {
		rd->d.num = q->head->a.d.num;
	}
	else {
		rd->d.op = q->head->a.d.op;
	}
	free(q->head);
	q->head = tmp;
	if(q->head != NULL) {	
		tmp->prev = NULL;
	}
	else {
		q->tail = NULL;
	}
	return rd;
}

token *pop(queue *q) {
	node *tmp = q->tail->prev;
	token *rd = (token *)malloc(sizeof(token));
	if(rd == NULL) {
		printf("SORRY, BRO\n");
		exit(1);
	}	
	rd->type = q->tail->a.type;
	if(rd->type == OPERAND) {
		rd->d.num = q->tail->a.d.num;
	}
	else {
		rd->d.op = q->tail->a.d.op;
	}
	free(q->tail);
	q->tail = tmp;
	if(q->tail != NULL) {
		tmp->next = NULL;
	}	
	else {
		q->head = NULL;
	}
	return rd;
}	

int qempty(queue *q) {
	if(q->head == NULL) {
		return 1;
	}
	return 0;
}

void printqueue(queue *q) {
	node *tmp = q->head;
	printf("Queue: [");
	while(tmp) {
		switch(tmp->a.type) {
				case OPERAND:
					printf("%d ", tmp->a.d.num);
					break;
				case OPERATOR:
					printf("%c ", tmp->a.d.op);
					break;
				case BRACKETO:
					printf("%c ", tmp->a.d.op);
					break;
				case BRACKETC:
					printf("%c ", tmp->a.d.op);
					break;
				case ENDT:
					printf("END ");
					break;
				default:
					break;
		}
		tmp = tmp->next;
	}
	printf("]\n");
}
