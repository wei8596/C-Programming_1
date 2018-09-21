/*河內塔
讓使用者輸入圓環的數目，輸出最少的移動步數。
無限次輸入，直到 EOF。*/
/*Hint: 輸出的步數應剛好為 2^n-1。*/ 

#include<stdio.h>
#include<stdlib.h>

void h(int, char, char, char);  //(圓環數, 起始, 中, 目標)
int c;  //計算次數 

int main(){
	int n;  //圓環的數目 
	
	printf("請輸入圓環的數目: ");
	while(scanf("%d", &n) != EOF){  //無限次輸入，直到 EOF 
		c = 0;  //歸零 
		h(n, 'A', 'B', 'C');  //將 N 層圓環由 A 移到 C
		printf("移動次數: %d\n\n", c);
		printf("請輸入圓環的數目: ");
	}	
	
	system("pause");
	return 0;
}

void h(int n, char A, char B, char C){  //(圓環數, 起始, 中, 目標)
	if(n == 1)  //將 1 層圓環從 A 移到 C
		c++;
	else{
		h(n-1, A, C, B);  //先將 N - 1 層圓環移到 B
		c++;
		h(n-1, B, A, C);  //將 B 上的圓環全部移到 C
	}	
}
