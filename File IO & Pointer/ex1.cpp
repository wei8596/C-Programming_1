/*�̧ǿ�J��Ӱ���M�BN(����JM�A��JN)�A4 < M < N�C���۹��
���j�󵥩�M�B�p�󵥩�N�����ơA�i���Ƥ��ѭp��Aex : 8 = 3 + 5
�A���ӽd�Ү榡��X��Output.txt�A�ѩ��Ƥ��ѨëD�ߤ@�ѡA��
��X���Ƭۮt�ȳ̤j���@�աA�B���p���ȩ�e���C*/

#include<stdio.h>
#include<stdlib.h>

int determine_condition(int, int);  //�P�_M�BN������O�_����
void swap(int*, int*);  //�NM�BN��ƥ洫
int is_prime(int);  //�P�_�O�_�����

int e1, e2, t;

int main(){
	FILE *fptr;
	
	t = 1;
	while(t == 1){
		scanf("%d%d", &e1, &e2);
		t = determine_condition(e1, e2);  //�P�_M�BN������O�_����
	}	
	if((fptr = fopen("Output.txt", "w")) == NULL)  //�}Output.txt
			printf("�ɮ׵L�k�}��\n");
	else{
		while(e1 <= e2){
			int i = e1;
			for(int j = 2; j < e1; j++ ){
				if((is_prime(j)) && (is_prime(i-j))){
					fprintf(fptr, "%d = %d + %d\n", e1, j, i-j);
					break;
				}					
			}
			e1+=2;
		}
	}
	
	system("pause");
	return 0;
}

int determine_condition(int m, int n){  //�P�_M�BN������O�_����
	if(((m%2) != 0) || ((n%2) != 0)){
		printf("�п�J��Ӥj��4������\n\n");
		return 1;
	}
	else if((m <= 4) || (n <= 4)){
		printf("�п�J��Ӥj��4������\n\n");
		return 1;
	}
	else if(m == n){
		printf("�п�J��Ӱ���M�BN�A4 < M < N\n\n");
		return 1;
	}
	else if(m > n){
		swap(&e1, &e2);
		return 0;
	}
	else
		return 0;
}

void swap(int* m, int* n){  //�NM�BN��ƥ洫
	int tmp;
	
	if(*m > *n){
		tmp = *m;
		*m = *n;
		*n = tmp;
	}
}

int is_prime(int even){  //�P�_�O�_�����
	for(int i = 2; i < even; i++){
		if((even % i) == 0)
			return 0;
	}
	return 1;
}
