/*讀取input.txt(內容如EX)，內容為西元日期(yyyymmdd)，判斷此
日期為星期幾，輸出至Output2.txt。*/

#include<stdio.h>
#include<stdlib.h>

void determine_date(int*, int*, int*);  //判斷輸入日期是否直接正確
int of_the_week(int, int, int);  //分別傳入yy,mm,dd，算出星期幾

int w;
FILE *fptr, *fptr1;

int main(){	
	int y, m, d;
	
	if((fptr = fopen("input.txt", "r")) == NULL)  //開input.txt
		printf("檔案無法開啟\n");
	else{
		if((fptr1 = fopen("Output2.txt", "w")) == NULL)  //開Output2.txt
			printf("檔案無法開啟\n");
		else{
			while(fscanf(fptr, "%4d %2d %2d", &y, &m, &d) != EOF)  //讀input.txt
			determine_date(&y, &m, &d);	
		}				
	}
	fclose(fptr);  //關閉檔案
	fclose(fptr1);  //關閉檔案
	
	system("pause");
	return 0;
}

void determine_date(int* y, int* m, int* d){  //判斷輸入日期是否直接正確
	int feb_days;
	
	if(((*y%4==0) && (*y%100!=0)) || (*y%400==0))  //判斷該年是否為閏月 
		feb_days =29;				
	else
		feb_days =28;
	int days[13]={0,31,feb_days,31,30,31,30,31,31,30,31,30,31};  //月份天數
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

int of_the_week(int y, int m, int d){  //分別傳入yy,mm,dd，算出星期幾
	if((m == 1) || (m == 2)){
		m += 12;
		y--;
	}	
	w = (d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
	return w;
}
