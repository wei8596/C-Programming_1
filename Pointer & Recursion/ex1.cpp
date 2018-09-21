/*設計一個無限迴圈直到輸入 -1 才停止的費氏數列，讓使用者輸
入整數 N (50 <= N <= 150)，輸出費氏數列中第 N 個數字，並將其存入
FS.txt 文字檔(重複輸入則將檔案內文字覆蓋)。*/

#include<stdio.h>
#include<stdlib.h>
#define L 100 

void f(int);

FILE *fptr;

int main(){
	int n;
	
	printf("請輸入整數：");
	while(scanf("%d", &n)){  //輸入整數 
		if(n == -1){
			printf("輸入結束\n");  //輸入 -1 停止
			break;
		}
		else{
			if((fptr = fopen("FS.txt", "w")) == NULL)  //開FS.txt
				printf("檔案無法開啟\n");
			else{
				printf("The Fibonacci number for %d is：\n", n);
				f(n);
			}
		}
		printf("請輸入整數：");
	}
	
	system("pause");
	return 0;
}

void f(int x){
	int a[L], b[L], c[L], k;
	
	for(int i = 0; i < L; i++){  //歸零 
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	b[0] = 1;
	for(int i = 0; i < x-1; i++){  //算n-2次 
		for(int j = 0; j < L; j++){  //每一位數相加(個、十、百...)
			c[j]+=(a[j]+b[j]);
			if(c[j] >= 10){
				c[j+1] += c[j]/10;  //>=10進位
    			c[j] %= 10;    			
   			}		
		}
		if(i != x-2){  //最後一次不傳遞 
   			for(int w = 0; w < L; w++){
   				a[w] = b[w];  //b的值給a
   				b[w] = c[w];  //c的值給b
   				c[w] = 0;  //c歸零
			}   				
		}					
	}
	for(k = L-1; k > 0; k--){  //從陣列最後面(位數最大)往回找第一個不是 0 的數字
		if(c[k] != 0)
			break;
	} 
	for(; k >= 0; k--){
		printf("%d", c[k]);  //輸出費氏數列中第 N 個數字
		fprintf(fptr, "%d", c[k]);  //存入FS.txt
	}
	fclose(fptr);
	printf("\n\n");
}
