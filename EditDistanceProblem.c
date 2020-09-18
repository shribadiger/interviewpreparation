/*
 * Edit String Distance problem, this basically used to convert the string another form
 * basically used in Word Document, mobile keyboard
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(int** arryPtr, int m, int n) {
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("\t%d",arryPtr[i][j]);
		}
		printf("\n");
	}
}

int getMinValue(int a, int b, int c) {
	if( a<=b && a<=c)
		return a;
	else if(b<=a && b<=c)
		return b;
	else
		return c;
}

int convertStrings(char* str1, char* str2) {
	int rows = strlen(str1);
	int col = strlen(str2);
	int result = 0;
	int **mArray;
	int i,j;
	mArray =(int**)malloc(rows*sizeof(int*));
	for(i=0;i<=rows;i++) {
		mArray[i]=(int*)malloc(sizeof(int)*col);
	}

	printf("\n Array [%d][%d]\n", rows,col);
	for(i=0;i<=rows;i++) {
		for(j=0;j<=col;j++){
			if(i == 0 && j == 0) {
				mArray[i][j]=0;
			} else if(i==0) {
				mArray[i][j]=mArray[i][j-1]+1;
			}
			else if(j==0) {
				mArray[i][j]=mArray[i-1][j]+1;
			}
			else {
				//Main Condition to fill Array
				if(str1[i-1] == str2[j-1])
				{
					mArray[i][j]=mArray[i-1][j-1];
				}
				else {
					mArray[i][j]=getMinValue(mArray[i][j-1],mArray[i-1][j-1],mArray[i-1][j])+1;
				}
			}
		}
	}

	printArray(mArray,rows,col);
        result = mArray[rows][col];	
	return result;
}
int main() {
	char* str1 = "adceg";
	char* str2 = "abcfg";

	/*
	 +---+---+---+---+---+
	 | a | D | c | E | g |
	 +---+---+---+---+---+
	 | a | B | c | F | g |
	 +---+---+---+---+---+
	 converstion of string are represented in capital letters
	 total 2 operations are required
	 */

	int NumOfOperation = convertStrings(str1,str2);

	printf("\n Number of Operation  : %d", NumOfOperation);

	return 0;
}

