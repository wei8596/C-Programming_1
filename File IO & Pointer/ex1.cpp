/*依序輸入兩個偶數M、N(先輸入M再輸入N)，4 < M < N。接著對所
有大於等於M且小於等於N的偶數，進行質數分解計算，ex : 8 = 3 + 5
，按照範例格式輸出至Output.txt，由於質數分解並非唯一解，請
輸出兩質數相差值最大的一組，且較小的值放前面。*/

#include<stdio.h>
#include<stdlib.h>

int determine_condition(int, int);  //判斷M、N的條件是否滿足
void swap(int*, int*);  //將M、N兩數交換
int is_prime(int);  //判斷是否為質數

int e1, e2, t;

int main(){
	FILE *fptr;
	
	t = 1;
	while(t == 1){
		scanf("%d%d", &e1, &e2);
		t = determine_condition(e1, e2);  //判斷M、N的條件是否滿足
	}	
	if((fptr = fopen("Output.txt", "w")) == NULL)  //開Output.txt
			printf("檔案無法開啟\n");
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

int determine_condition(int m, int n){  //判斷M、N的條件是否滿足
	if(((m%2) != 0) || ((n%2) != 0)){
		printf("請輸入兩個大於4的偶數\n\n");
		return 1;
	}
	else if((m <= 4) || (n <= 4)){
		printf("請輸入兩個大於4的偶數\n\n");
		return 1;
	}
	else if(m == n){
		printf("請輸入兩個偶數M、N，4 < M < N\n\n");
		return 1;
	}
	else if(m > n){
		swap(&e1, &e2);
		return 0;
	}
	else
		return 0;
}

void swap(int* m, int* n){  //將M、N兩數交換
	int tmp;
	
	if(*m > *n){
		tmp = *m;
		*m = *n;
		*n = tmp;
	}
}

int is_prime(int even){  //判斷是否為質數
	for(int i = 2; i < even; i++){
		if((even % i) == 0)
			return 0;
	}
	return 1;
}
