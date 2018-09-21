#include<stdio.h>
#include<stdlib.h>

void abc();
int check(int,int);
void queen(int);
int c[9];
int sum=0;

int main(){
	queen(1);
	system("pause");
	return 0;
}

void abc(){
	printf("第 %d 種\n",sum);
	for(int i=1;i<9;i++){
		for(int j=1;j<9;j++){
			if(c[i]==j)
				printf("Q");
			else
				printf("-");
		}
		printf("\n");
	}
	printf("\n");
}

int check(int a,int b){
	for(int i=a-1;i>0;i--){						//上 
		if(c[i]==b)
			return 0;
	}
	for(int i=a-1,j=b+1;i>0&&j<9;i--,j++){		//右上 
		if(c[i]+i==i+j)
			return 0;
	}
	for(int i=a-1,j=b-1;i>0&&j>0;i--,j--){		//左上 
		if(c[i]-i==j-i)
			return 0;
	}
	return 1;
}

void queen(int q){
	if(q>8){
		sum++;
		abc();
	}
	else{
		for(int i=1;i<9;i++){
			if(check(q,i)){
				c[q]=i;
				queen(q+1);
			}
		}
	}
}
