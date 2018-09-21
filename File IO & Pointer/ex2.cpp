/*Ū��input.txt(���e�pEX)�A���e���褸���(yyyymmdd)�A�P�_��
������P���X�A��X��Output2.txt�C*/

#include<stdio.h>
#include<stdlib.h>

void determine_date(int*, int*, int*);  //�P�_��J����O�_�������T
int of_the_week(int, int, int);  //���O�ǤJyy,mm,dd�A��X�P���X

int w;
FILE *fptr, *fptr1;

int main(){	
	int y, m, d;
	
	if((fptr = fopen("input.txt", "r")) == NULL)  //�}input.txt
		printf("�ɮ׵L�k�}��\n");
	else{
		if((fptr1 = fopen("Output2.txt", "w")) == NULL)  //�}Output2.txt
			printf("�ɮ׵L�k�}��\n");
		else{
			while(fscanf(fptr, "%4d %2d %2d", &y, &m, &d) != EOF)  //Ūinput.txt
			determine_date(&y, &m, &d);	
		}				
	}
	fclose(fptr);  //�����ɮ�
	fclose(fptr1);  //�����ɮ�
	
	system("pause");
	return 0;
}

void determine_date(int* y, int* m, int* d){  //�P�_��J����O�_�������T
	int feb_days;
	
	if(((*y%4==0) && (*y%100!=0)) || (*y%400==0))  //�P�_�Ӧ~�O�_���|�� 
		feb_days =29;				
	else
		feb_days =28;
	int days[13]={0,31,feb_days,31,30,31,30,31,31,30,31,30,31};  //����Ѽ�
		if((*y < 1) || (*m < 1) || (*m > 12) || (*d < 1) || (*d > 31))
			fprintf(fptr1, "No such date!\n");
		else if(*d > days[*m])
			fprintf(fptr1, "No such date!\n");
		else{
			w = of_the_week(*y, *m, *d);
			switch(w){
				case 0:
					fprintf(fptr1, "Sunday\n");
					break;
				case 1:
					fprintf(fptr1, "Monday\n");
					break;
				case 2:
					fprintf(fptr1, "Tuesday\n");
					break;
				case 3:
					fprintf(fptr1, "Wednesday\n");
					break;
				case 4:
					fprintf(fptr1, "Thursday\n");
					break;
				case 5:
					fprintf(fptr1, "Friday\n");
					break;
				case 6:
					fprintf(fptr1, "Saturday\n");
					break;		
			}
		}			
}

int of_the_week(int y, int m, int d){  //���O�ǤJyy,mm,dd�A��X�P���X
	if((m == 1) || (m == 2)){
		m += 12;
		y--;
	}	
	w = (d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
	return w;
}
