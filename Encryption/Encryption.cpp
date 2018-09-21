#include<stdio.h>
#include<stdlib.h>

#define L 30

void encryption_table(char* key, char(*table)[5]);
void encryption_number(char* text, char(*table)[5]);
void BubbleSort(char*);
void swap(char*, char*);

int main(){
	char key[L] = {'\0'};
	char text[L] = {'\0'};
	char table[5][5] = {'\0'};
	FILE* fptr1;
	FILE* fptr2;
	
	printf("2.1 & 2.2\n");
	printf("請輸入加密金鑰：");
	while(scanf("%s", key)){
		if((key[0] == '-') && (key[1] == '1')){
			printf("結束本題\n");
			break;
		}
		else{
			printf("加密表格為：\n");
			encryption_table(key, table);
			
			printf("\n請輸入欲加密內容：");
			for(int i = 0; i < L; i++)
				text[i] = '\0';
			scanf("%s", text);
			printf("加密結果為：");
			encryption_number(text, table);
			if((fptr1 = fopen("text1.txt", "w")) == NULL)
				printf("檔案無法開啟\n");
			else{
				fprintf(fptr1, "%s", text);
				fclose(fptr1);
			}
		}
		printf("\n請輸入加密金鑰：");
	}
	
	
	
	printf("\n\n\n\n2.3\n");
	for(int i = 0; i < L; i++)
		text[i] = '\0';
	printf("泡沫排序後結果：");
	if((fptr2 = fopen("text1.txt", "r")) == NULL)
		printf("檔案無法開啟\n");
	else
		fscanf(fptr2, "%s", text);
	BubbleSort(text);
	printf("結束本題\n");
	
	system("pause");
	return 0;
}

void encryption_table(char* key, char(*table)[5]){
	int c = 0, cc = 0;
	char voc[25], voc1 = 'A';
	
	for(int i = 0; i < 25; i++, voc1++){
		if(voc1 == 'J')
			voc1++;
		voc[i] = voc1;
	}
	for(int i = 0; i < L; i++){
		if(key[i] == '\0')
			break;
		else if(key[i] == 'J')
			key[i] = 'I';
	}
	for(int i = 0; i < L-1; i++){
		for(int j = i+1; j < L; j++){
			if(key[j] == key[i])
				key[j] = '0';
		}
	}
	for(int i = 0; i < L; i++){
		for(int j = 0; j < 25; j++){
			if(voc[j] == key[i])
				voc[j] = '0';
		}		
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			while(key[c] == '0')
				c++;
			if(key[c] != '\0'){
				table[i][j] = key[c];
				c++;
			}
			else{
				while(voc[cc] == '0')
					cc++;
				table[i][j] = voc[cc];
				cc++;
			}
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++)			
			printf("%c ", table[i][j]);
		printf("\n");
	}
}

void encryption_number(char* text, char(*table)[5]){
	int c = 0, ti1, tj1, ti2, tj2;
	
	for(int i = 0; i < L; i+=2){
		if(text[i] == '\0')
			break;
		else if(text[i] == text[i+1]){
			for(int j = L-2; j > i; j--)
				text[j] = text[j-1];
			text[i+1] = 'X';
		}
		else if(text[i+1] == '\0')
			text[i+1] = 'X';
	}

	while(text[c] != '\0'){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(text[c] == table[i][j]){
					ti1 = i;
					tj1 = j;
				}
				if(text[c+1] == table[i][j]){
					ti2 = i;
					tj2 = j;
				}
			}
		}
		if(tj1 == tj2){
			if(ti1 == 4){
				text[c] = table[0][tj1];
				text[c+1] = table[ti2+1][tj2];
			}
			else if(ti2 == 4){
				text[c+1] = table[0][tj2];
				text[c] = table[ti1+1][tj1];
			}
			else{
				text[c] = table[ti1+1][tj1];
				text[c+1] = table[ti2+1][tj2];
			}
		}
		else if(ti1 == ti2){
			if(tj1 == 4){
				text[c] = table[ti1][0];
				text[c+1] = table[ti2][tj2+1];
			}
			else if(tj2 == 4){
				text[c+1] = table[ti2][0];
				text[c] = table[ti1][tj1+1];
			}
			else{
				text[c] = table[ti1][tj1+1];
				text[c+1] = table[ti2][tj2+1];
			}
		}
		else{
			text[c] = table[ti1][tj2];
			text[c+1] = table[ti2][tj1];
		}
		c += 2;
	}
	printf("%s\n", text);
}

void BubbleSort(char* text){
	for(int i = 0; i < L-1; i++){
		if(text[i] == '\0')
			break;
		for(int j = i+1; j < L; j++){
			if(text[j] == '\0')
				break;
			if(text[i] > text[j])
				swap(&text[i], &text[j]);
		}
	}
	printf("%s\n", text);
}

void swap(char* ch1, char* ch2){
	char tmp;
	
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}
