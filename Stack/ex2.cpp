#include<stdio.h>
#include<stdlib.h>

#define L 10

int first(char (*str1)[L], int, int, char*);
int check(char (*str1)[L],int ,int ,int ,int ,char*);

int main(){
	FILE *fptr1, *fptr2;
	int m, n;
	char str2[L] = {'\0'};
	
	if((fptr1 = fopen("input2.txt", "r")) == NULL)
		printf("檔案無法開啟\n");
	else{
		fscanf(fptr1, "%d%d", &m, &n);
		char str1[m][L] = {'\0'};
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				fscanf(fptr1, "%c", &str1[i][j]);
				if(str1[i][j] == '\n')
					fscanf(fptr1, "%c", &str1[i][j]);
			}
		}
		if((fptr2 = fopen("output2.txt", "w")) == NULL)
			printf("檔案無法開啟\n");
		else{
			while(!feof(fptr1)){
				fscanf(fptr1, "%s", str2);
				if(first(str1, m, n, str2) == 1)
					fprintf(fptr2,"Yes\n");
				else
					fprintf(fptr2,"No\n");
			}
			fclose(fptr2);
		}
	}
	
	
	system("pause");
	return 0;
}

int first(char (*str1)[L], int m, int n, char* str2){
	for(int i = 0; i < m; i++){
		for(int j = 0 ;j < n ; j++){
			if(str2[0] == str1[i][j]){
				if(check(str1, i, j, m, n, str2) == 1)
					return 1;
				else
					continue;
			}
		}
	}					
	return 0;
}

int check(char (*str1)[L],int i,int j,int m,int n,char* str2){
	int x[m][n] = {0};
	x[i][j] = 1;
	
	for(int k = 1; str2[k] != '\0'; k++){
		if((str2[k] == str1[i][j+1]) && (x[i][j+1] == 0)){
			j++;
			x[i][j] = 1;
		}
		else if((str2[k] == str1[i][j-1]) && (x[i][j-1] == 0)){
			j--;
			x[i][j] = 1;
		}
		else if((str2[k] == str1[i+1][j]) && (x[i+1][j] == 0)){
			i++;
			x[i][j] = 1;
		}
		else if((str2[k] == str1[i-1][j]) && (x[i-1][j] == 0)){
			i--;
			x[i][j] = 1;
		}
		else
			return 0;
		}		
	return 1;
}
