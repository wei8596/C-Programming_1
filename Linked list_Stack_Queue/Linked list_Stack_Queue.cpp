#include<stdio.h>
#include<stdlib.h>

#define L 20

typedef struct node1{
	char data;
	struct node1 *next;
}NODE1;

typedef struct node2{
	char data;
	struct node2 *next;
	struct node2 *prev;
}NODE2;

void push(NODE1**, char);
void pop(NODE1**);
void in(NODE1**, char, int);
void de(NODE1**, char);
int op(NODE1*);

void enquence(NODE2**, NODE2**, char);
void dequence(NODE2**, NODE2**);
void in2(NODE2**, NODE2**, char, int);
void de2(NODE2**, NODE2**, char);
int op2(NODE2*);

int main(){
	char voc = 'A';
	char str[L] = {'\0'};
	int i, n, c, cc;
	NODE1 *top = NULL, *tmp = NULL;
	NODE2 *tail = NULL, *head = NULL, *tmp2 = NULL;
	
	for(int i = 0; i < 4; i++){
		push(&top, voc);
		voc++;
	}
	voc = 'A';
	for(int i = 0; i < 4; i++){
		enquence(&head, &tail, voc);
		voc++;
	}
	printf("Please enter sequence¡G");
	while(1){
		for(int j = 0; j < L; j++){
			scanf("%c", &str[j]);
			if(str[j] == '\n'){
				str[j] = '\0';
				break;
			}
		}
		i = 0;
		if((str[i] == '-') && (str[i+1] == '1'))
			break;
		else if(str[i] == 'S'){
			for(int j = 0; j < L; j++)
				str[j] = '\0';
			printf("\nCommand¡G");
			while(1){
				for(int j = 0; j < L; j++){
					scanf("%c", &str[j]);
					if(str[j] == '\n'){
						str[j] = '\0';
						break;
					}
				}
				i = 0;
				if((str[i] == '-') && (str[i+1] == '1')){
					printf("End\n\n");
					for(int j = 0; j < L; j++)
						str[j] = '\0';
					break;
				}
				else if((str[i] == 'p') && (str[i+1] == 'o') && (str[i+2] == 'p')){					
					if(top == NULL)
						printf("No Ball\n");
					else{
						i += 3;						
						tmp = top;
						c = 0;
						while(tmp != NULL){
							c++;
							tmp = tmp->next;
						}
						if(str[i] == '\0'){
							printf("pop the last ball %c\n", top->data);
							pop(&top);
							printf("Box¡G");
							if(top == NULL)
								printf("NULL\n");
							else{
								op(top->next);
								printf("%c\n", top->data);
							}						
						}
						else if(str[i] == 'o'){
							i += 4;
							n = 0;
							while(str[i] != '\0'){
								n *= 10;
								n += str[i] - '0';							
								i++;
							}
							if(n > c || n < 1){
								printf("wrong number\n");
								printf("Box¡G");
								op(top->next);
								printf("%c\n", top->data);
							}
							else{
								tmp = top;
								cc = c - n;
								while(cc--)
									tmp = tmp->next;
								printf("pop number %d ball %c\n", n, tmp->data);
								printf("Box¡G");
								de(&top, tmp->data);
								if(top == NULL)
									printf("NULL\n");
								else{
									op(top->next);
									printf("%c\n", top->data);
								}
							}
						}
					}
				}
				else if((str[i] == 'p') && (str[i+1] == 'u') && (str[i+2] == 's') && (str[i+3] == 'h')){
					i += 4;
					tmp = top;
					c = 0;
					while(tmp != NULL){
						c++;
						tmp = tmp->next;
					}
					if(str[i] == ' '){
						printf("push %c ball to the last location\n", str[i+1]);
						push(&top, str[i+1]);
						printf("Box¡G");
						op(top->next);
						printf("%c\n", top->data);
					}
					else if(str[i] == 'i'){
						i += 3;
						n = 0;
						while(str[i] != ' '){
							n *= 10;
							n += str[i] - '0';							
							i++;
						}
						if(n > c+1 || n < 1){
							i++;
							printf("push %c ball to the last location\n", str[i]);
							push(&top, str[i]);
							printf("Box¡G");
							op(top->next);
							printf("%c\n", top->data);
						}
						else if(n == c+1){
							i++;
							printf("push %c ball to number %d location\n", str[i], n);
							printf("Box¡G");
							push(&top, str[i]);
							op(top->next);
							printf("%c\n", top->data);
						}
						else{
							i++;							
							printf("push %c ball to number %d location\n", str[i], n);
							printf("Box¡G");
							in(&top, str[i], n);
							op(top->next);
							printf("%c\n", top->data);
						}
					}					
				}
				printf("\nCommand¡G");
				for(int j = 0; j < L; j++)
					str[j] = '\0';
			}
				
		}
		else if(str[i] == 'Q'){
			for(int j = 0; j < L; j++)
				str[j] = '\0';
			printf("\nCommand¡G");
			while(1){
				for(int j = 0; j < L; j++){
					scanf("%c", &str[j]);
					if(str[j] == '\n'){
						str[j] = '\0';
						break;
					}
				}
				i = 0;
				if((str[i] == '-') && (str[i+1] == '1')){
					printf("End\n\n");
					for(int j = 0; j < L; j++)
						str[j] = '\0';
					break;
				}
				else if((str[i] == 'p') && (str[i+1] == 'o') && (str[i+2] == 'p')){
					if(head == NULL)
						printf("No Ball\n");
					else{						
						i += 3;
						tmp2 = head;
						c = 0;
						while(tmp2 != NULL){
							c++;
							tmp2 = tmp2->next;
						}
						if(str[i] == '\0'){
							printf("pop the first ball %c\n", head->data);
							dequence(&head, &tail);
							printf("Box¡G");
							if(head == NULL)
								printf("NULL\n");
							else{
								op2(tail->prev);
								printf("%c\n", tail->data);
							}						
						}
						else if(str[i] == 'o'){
							i += 4;
							n = 0;
							while(str[i] != '\0'){
								n *= 10;
								n += str[i] - '0';							
								i++;
							}
							if(n > c || n < 1){
								printf("wrong number\n");
								printf("Box¡G");
								op2(tail->prev);
								printf("%c\n", tail->data);
							}
							else{
								if(n == 1){
									printf("pop number 1 ball %c\n", head->data);
									dequence(&head, &tail);									
								}
								else{
									if(c == n){
										printf("pop number %d ball %c\n", n, tail->data);
										de2(&head, &tail, tail->data);
									}
									else{
										tmp2 = head;
										cc = c - n;
										while(cc--)
											tmp2 = tmp2->next;
										printf("pop number %d ball %c\n", n, tmp2->data);
										de2(&head, &tail, tmp2->data);
									}									
								}								
								printf("Box¡G");								
								if(head == NULL)
									printf("NULL\n");
								else{
									op2(tail->prev);
									printf("%c\n", tail->data);
								}
							}
						}
					}
				}
				else if((str[i] == 'p') && (str[i+1] == 'u') && (str[i+2] == 's') && (str[i+3] == 'h')){
					i += 4;
					tmp2 = head;
					c = 0;
					while(tmp2 != NULL){
						c++;
						tmp2 = tmp2->next;
					}
					if(str[i] == ' '){
						printf("push %c ball to the last location\n", str[i+1]);						
						printf("Box¡G");
						enquence(&head, &tail, str[i+1]);
						op2(tail->prev);
						printf("%c\n", tail->data);
					}
					else if(str[i] == 'i'){
						i += 3;
						n = 0;
						while(str[i] != ' '){
							n *= 10;
							n += str[i] - '0';							
							i++;
						}
						if(n > c+1 || n < 1){
							i++;
							printf("push %c ball to the last location\n", str[i]);						
							printf("Box¡G");
							enquence(&head, &tail, str[i]);
							op2(tail->prev);
							printf("%c\n", tail->data);
						}
						else if(n == c+1){
							i++;							
							printf("push %c ball to number %d location\n", str[i], n);
							printf("Box¡G");
							enquence(&head, &tail, str[i]);
							op2(tail->prev);
							printf("%c\n", tail->data);
						}
						else{
							i++;							
							printf("push %c ball to number %d location\n", str[i], n);
							printf("Box¡G");
							in2(&head, &tail, str[i], n);
							op2(tail->prev);
							printf("%c\n", tail->data);
						}
					}
				}
				printf("\nCommand¡G");
				for(int j = 0; j < L; j++)
					str[j] = '\0';
			}
		}
		printf("please enter sequence¡G");
	}
	
	system("pause");
	return 0;
}

void push(NODE1** TOP, char value){
	NODE1 *newp;
	
	newp = (NODE1*)malloc(sizeof(NODE1));
	newp->data = value;
	newp->next = NULL;
	newp->next = *TOP;
	*TOP = newp;
}

void pop(NODE1** TOP){
	NODE1 *temp;
	char value;
	
	temp = *TOP;
	*TOP = (*TOP)->next;
	value = temp->data;
	free(temp);
}

void in(NODE1** TOP, char value, int n){
	NODE1 *newp, *prev, *current;
	
	newp = (NODE1*)malloc(sizeof(NODE1));
	newp->data = value;
	newp->next = NULL;		
	prev = NULL;
	current = *TOP;
	while(current != NULL && n > 0){
		prev = current;
		current = current->next;
		n--;
	}
	if(prev == NULL){
		newp->next = *TOP;
		*TOP = newp;
	}
	else{
		prev->next = newp;
		newp->next = current;
	}
}

void de(NODE1** TOP, char value){
	NODE1 *prev, *current, *tmp;
	
	if(value == (*TOP)->data){
		tmp = *TOP;
		*TOP = (*TOP)->next;
		free(tmp);
	}
	else{
		prev = *TOP;
		current = (*TOP)->next;
		while(current != NULL && current->data != value){
		prev = current;
		current = current->next;
		}
		if(current != NULL){
			tmp = current;
			prev->next = current->next;
			free(tmp);
		}
	}
}

int op(NODE1* TOPn){
	if(TOPn == NULL)
		return 0;
	else if(TOPn->next == NULL)
		printf("%c->",TOPn->data);
	else{
		op(TOPn->next);
		printf("%c->",TOPn->data);
	}
}

void enquence(NODE2** head, NODE2** tail, char value){
	NODE2 *newp;
	
	newp = (NODE2*)malloc(sizeof(NODE2));
	newp->data = value;
	newp->next = NULL;
	newp->prev = NULL;
	if(*head == NULL)
		*head = newp;
	else
		(*tail)->next = newp;
	newp->prev = *tail;
	*tail = newp;
}

void dequence(NODE2** head, NODE2** tail){
	NODE2 *temp;
	
	temp = *head;
	*head = (*head)->next;
	if(*head == NULL)
		*tail = NULL;
	else
		(*head)->prev = NULL;
	free(temp);
}

void in2(NODE2** head, NODE2** tail, char value, int n){
	NODE2 *newp, *p, *c;
	
	newp = (NODE2*)malloc(sizeof(NODE2));
	newp->data = value;	
	newp->next = NULL;	
	newp->prev = NULL;	
	p = NULL;
	c = *head;
	while(c != NULL && n > 0){
		p = c;
		c = c->next;
		n--;
	}
	if(p == NULL){
		newp->prev = *tail;
		*tail = newp;
	}
	else{
		p->prev->next = newp;
		newp->prev = p->prev;
		p->prev = newp;
		newp->next = p;		
	}
}

void de2(NODE2** head, NODE2** tail, char value){
	NODE2 *p, *c, *tmp;
	
	if(value == (*head)->data){
		tmp = *head;
		*head = (*head)->next;
		if(*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
	}
	else if(value == (*tail)->data){
		tmp = *tail;
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
		free(tmp);
	}
	else{
		p = *head;
		c = (*head)->next;
		while(c != NULL && c->data != value){
			p = c;
			c = c->next;
		}
		if(c != NULL){			
			tmp = c;
			p->next = c->next;
			c->next->prev = p;
			free(tmp);
		}
	}
}

int op2(NODE2* tailn){
	if(tailn == NULL)
		return 0;
	else if(tailn->prev == NULL)
		printf("%c->",tailn->data);
	else{
		op2(tailn->prev);
		printf("%c->",tailn->data);
	}
}
