/*讀取 FS.txt 文字檔先輸出至視窗上，再建立三個整數 A、 B、 C，
A 為文字檔內的前四個數字， B 為接續 A 後面的四個數字， C 為接續 B
後面的兩個數字並將三個整數都輸出，以1234567890為例， A = 1234， B =
5678， C = 90，試求出 ( A ^ B ) % C 的值為何並輸出 。*/
/*Hint：(拆次方)
偶數 A^B%C = (A^B/2 % C)*(A^B/2 % C) %C
奇數 A^B%C = (A^B/2 % C)*(A^B/2 % C)*A %C*/

#include<stdio.h>
#include<stdlib.h>
#define L 1000

void changetoInt(char*);  //將文字檔的內容轉為整數型態
int longpow(int A , int B , int C);  //算出 ( A ^ B )% C

int ii[L];  //儲存轉換後的整數 

int main(){
	FILE *fptr;
	char ch[L] = {'\0'};
	int a = 0, b = 0, c = 0, cc = 0;  //cc為計算位數 
	
	if((fptr = fopen("FS.txt", "r")) == NULL)  //開FS.txt
				printf("檔案無法開啟\n");
	else{
		printf("輸入整數為：");
		system("type FS.txt");  //將文字檔輸出至視窗上 
		printf("\n");
		fscanf(fptr, "%s", ch);  //讀FS.txt 
		changetoInt(ch);  //將文字檔的內容轉為整數型態	
		for(int k = 0; k < L; k++){  //建立三個整數 a、 b、 c 
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
			printf("b = 0%d\n", b);  //補0
		else if((b%100) == b)
			printf("b = 00%d\n", b);  //補0
		else if((b%10) == b)
			printf("b = 000%d\n", b);  //補0
		else
			printf("b = %d\n", b);
		if((c%10) == c)
			printf("c = 0%d\n", c);  //補0
		else
			printf("c = %d\n", c);
		printf("餘數為：%d\n", longpow(a, b, c));
	}
	
	system("pause");
	return 0;
}

void changetoInt(char* d){  //將文字檔的內容轉為整數型態
	for(int i = 0; i < L; i++)  //歸零 
		ii[i] = 0;	
	for(int i = 0; i < L; i++){
		if(d[i] != '\0')		
			ii[i] = d[i] - '0';
	}		
}

int longpow(int A , int B , int C){  //算出 ( A ^ B )% C
	if(B == 0)  //0次方=1 
		return 1;
	else if(B % 2)
		return longpow(A, B/2, C)*longpow(A, B/2, C)*A%C;  //奇數 
	else
		return longpow(A, B/2, C)*longpow(A, B/2, C)%C;  //偶數
}
