/*�e����
���ϥΪ̿�J�������ƥءA��X�̤֪����ʨB�ơC
�L������J�A���� EOF�C*/
/*Hint: ��X���B������n�� 2^n-1�C*/ 

#include<stdio.h>
#include<stdlib.h>

void h(int, char, char, char);  //(������, �_�l, ��, �ؼ�)
int c;  //�p�⦸�� 

int main(){
	int n;  //�������ƥ� 
	
	printf("�п�J�������ƥ�: ");
	while(scanf("%d", &n) != EOF){  //�L������J�A���� EOF 
		c = 0;  //�k�s 
		h(n, 'A', 'B', 'C');  //�N N �h������ A ���� C
		printf("���ʦ���: %d\n\n", c);
		printf("�п�J�������ƥ�: ");
	}	
	
	system("pause");
	return 0;
}

void h(int n, char A, char B, char C){  //(������, �_�l, ��, �ؼ�)
	if(n == 1)  //�N 1 �h�����q A ���� C
		c++;
	else{
		h(n-1, A, C, B);  //���N N - 1 �h�������� B
		c++;
		h(n-1, B, A, C);  //�N B �W�������������� C
	}	
}
