#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 60

typedef struct node{
	int data;
	struct node *next;
}NODE;

void push(NODE**, int);
void pop(NODE**);
void op(NODE*);

int main(){
	FILE *fptr;
	char ch[L] = {'\0'};
	int s, c = 0, ii = 0, again, find;
	int d[L] = {0};
	NODE *TOP = NULL;
	NODE *tmp = NULL;
	
	if((fptr = fopen("input.txt", "r")) == NULL)
		printf("error 檔案無法開啟\n");
	else{
		while(!feof(fptr)){
			fscanf(fptr, "%c", &ch[c]);
			c++;
		}
		s = strlen(ch);
	}
	c = 0;
	if((ch[c]>= '0') && (ch[c] <= '9')){
		while(ch[c] != '\n')
			c++;
		for(int i = 0; i < c; i++){
			d[ii] += (ch[i] - '0');
			if((ch[i+1] != ' ') && (ch[i+1] != '\n'))
				d[ii] *= 10;
			else{
				i++;
				ii++;
			}
		}
		for(int i = 0; i < ii; i++)
			push(&TOP, d[i]);
		c++;		
	}
	for(int i = 0; i < ii; i++)
		d[i] = 0;	
	for(int i = c, ii = 0; i < s; i++){
		c = 0;
		if((ch[i] == 'P') && (ch[i+1] == 'u')){
			while((ch[i] < '0') || (ch[i] > '9'))
				i++;
			tmp = TOP;
			while(tmp != NULL){
				c++;
				tmp = tmp->next;
			}
			if(c == 5)
				printf("error 箱子已滿\n");
			else{
				while((ch[i] != '\n') && (ch[i] != '\0')){
					d[ii] += (ch[i] - '0');
					if((ch[i+1] != '\n') && (ch[i+1] != '\0'))
						d[ii] *= 10;
					i++;
				}
				tmp = TOP;
				again = 0;
				while(tmp != NULL){
					if(d[ii] == tmp->data){
						printf("error 重複的數字方塊\n");
						again = 1;
						break;
					}
					tmp = tmp->next;
				}
				if(again == 0)
					push(&TOP, d[ii]);
			}
			ii++;
		}
		else if((ch[i] == 'P') && (ch[i+1] == 'o')){
			while((ch[i] < '0') || (ch[i] > '9'))
				i++;
			while((ch[i] != '\n') && (ch[i] != '\0')){
				d[ii] += (ch[i] - '0');
				if((ch[i+1] != '\n') && (ch[i+1] != '\0'))
					d[ii] *= 10;
				i++;
			}
			if(TOP == NULL)
				printf("error 箱子是空的\n");
			else if(d[ii] != TOP->data)
				printf("error 不是最後放進去的數字方塊\n");
			else{
				tmp = TOP;
				find = 0;
				while(tmp != NULL){
					if(d[ii] == tmp->data){
						find = 1;
						break;
					}
					tmp = tmp->next;
				}
				if(find == 0)
					printf("error 無此數字方塊\n");
				else
					pop(&TOP);
			}
			ii++;
		} 
	}
	printf("箱子裡的數字方塊：");
	op(TOP);
	printf("\n");
	
	system("pause");
	return 0;
}

void push(NODE** TOP, int value){
	NODE* newp;
	
	newp = (NODE*)malloc(sizeof(NODE));
	newp->data = value;
	newp->next = NULL;
	newp->next = *TOP;
	*TOP = newp;
}

void pop(NODE** TOP){
	NODE* temp;
	
	temp = *TOP;
	*TOP = (*TOP)->next;
	free(temp);
}

void op(NODE* TOP){
	if(TOP->next == NULL)
		printf("%d ",TOP->data);
	else{
		op(TOP->next);
		printf("%d ",TOP->data);
	}
}
