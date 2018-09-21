/*Ū�� FS.txt ��r�ɥ���X�ܵ����W�A�A�إߤT�Ӿ�� A�B B�B C�A
A ����r�ɤ����e�|�ӼƦr�A B ������ A �᭱���|�ӼƦr�A C ������ B
�᭱����ӼƦr�ñN�T�Ӿ�Ƴ���X�A�H1234567890���ҡA A = 1234�A B =
5678�A C = 90�A�ըD�X ( A ^ B ) % C ���Ȭ���ÿ�X �C*/
/*Hint�G(���)
���� A^B%C = (A^B/2 % C)*(A^B/2 % C) %C
�_�� A^B%C = (A^B/2 % C)*(A^B/2 % C)*A %C*/

#include<stdio.h>
#include<stdlib.h>
#define L 1000

void changetoInt(char*);  //�N��r�ɪ����e�ର��ƫ��A
int longpow(int A , int B , int C);  //��X ( A ^ B )% C

int ii[L];  //�x�s�ഫ�᪺��� 

int main(){
	FILE *fptr;
	char ch[L] = {'\0'};
	int a = 0, b = 0, c = 0, cc = 0;  //cc���p���� 
	
	if((fptr = fopen("FS.txt", "r")) == NULL)  //�}FS.txt
				printf("�ɮ׵L�k�}��\n");
	else{
		printf("��J��Ƭ��G");
		system("type FS.txt");  //�N��r�ɿ�X�ܵ����W 
		printf("\n");
		fscanf(fptr, "%s", ch);  //ŪFS.txt 
		changetoInt(ch);  //�N��r�ɪ����e�ର��ƫ��A	
		for(int k = 0; k < L; k++){  //�إߤT�Ӿ�� a�B b�B c 
			cc++;
			if(cc <= 4){
				a *= 10;
				a += ii[k];
			}
			else if((cc > 4) && (cc <= 8)){
				b *= 10;
				b += ii[k];
			}
			else if((cc > 8) && (cc <= 10)){
				c *= 10;
				c += ii[k];
			}
		}
		printf("a = %d\n", a);
		if((b%1000) == b)
			printf("b = 0%d\n", b);  //��0
		else if((b%100) == b)
			printf("b = 00%d\n", b);  //��0
		else if((b%10) == b)
			printf("b = 000%d\n", b);  //��0
		else
			printf("b = %d\n", b);
		if((c%10) == c)
			printf("c = 0%d\n", c);  //��0
		else
			printf("c = %d\n", c);
		printf("�l�Ƭ��G%d\n", longpow(a, b, c));
	}
	
	system("pause");
	return 0;
}

void changetoInt(char* d){  //�N��r�ɪ����e�ର��ƫ��A
	for(int i = 0; i < L; i++)  //�k�s 
		ii[i] = 0;	
	for(int i = 0; i < L; i++){
		if(d[i] != '\0')		
			ii[i] = d[i] - '0';
	}		
}

int longpow(int A , int B , int C){  //��X ( A ^ B )% C
	if(B == 0)  //0����=1 
		return 1;
	else if(B % 2)
		return longpow(A, B/2, C)*longpow(A, B/2, C)*A%C;  //�_�� 
	else
		return longpow(A, B/2, C)*longpow(A, B/2, C)%C;  //����
}
