/*�]�p�@�ӵL���j�骽���J -1 �~����O��ƦC�A���ϥΪ̿�
�J��� N (50 <= N <= 150)�A��X�O��ƦC���� N �ӼƦr�A�ñN��s�J
FS.txt ��r��(���ƿ�J�h�N�ɮפ���r�л\)�C*/

#include<stdio.h>
#include<stdlib.h>
#define L 100 

void f(int);

FILE *fptr;

int main(){
	int n;
	
	printf("�п�J��ơG");
	while(scanf("%d", &n)){  //��J��� 
		if(n == -1){
			printf("��J����\n");  //��J -1 ����
			break;
		}
		else{
			if((fptr = fopen("FS.txt", "w")) == NULL)  //�}FS.txt
				printf("�ɮ׵L�k�}��\n");
			else{
				printf("The Fibonacci number for %d is�G\n", n);
				f(n);
			}
		}
		printf("�п�J��ơG");
	}
	
	system("pause");
	return 0;
}

void f(int x){
	int a[L], b[L], c[L], k;
	
	for(int i = 0; i < L; i++){  //�k�s 
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	b[0] = 1;
	for(int i = 0; i < x-1; i++){  //��n-2�� 
		for(int j = 0; j < L; j++){  //�C�@��Ƭۥ[(�ӡB�Q�B��...)
			c[j]+=(a[j]+b[j]);
			if(c[j] >= 10){
				c[j+1] += c[j]/10;  //>=10�i��
    			c[j] %= 10;    			
   			}		
		}
		if(i != x-2){  //�̫�@�����ǻ� 
   			for(int w = 0; w < L; w++){
   				a[w] = b[w];  //b���ȵ�a
   				b[w] = c[w];  //c���ȵ�b
   				c[w] = 0;  //c�k�s
			}   				
		}					
	}
	for(k = L-1; k > 0; k--){  //�q�}�C�̫᭱(��Ƴ̤j)���^��Ĥ@�Ӥ��O 0 ���Ʀr
		if(c[k] != 0)
			break;
	} 
	for(; k >= 0; k--){
		printf("%d", c[k]);  //��X�O��ƦC���� N �ӼƦr
		fprintf(fptr, "%d", c[k]);  //�s�JFS.txt
	}
	fclose(fptr);
	printf("\n\n");
}
