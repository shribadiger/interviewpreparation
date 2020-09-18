/*
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int A = 25;
	int B = 5;
	int C = 1;

	int input=0;
	printf("\n Enter Input: ");
	scanf("%d",&input);

	int temp = input;
	int numberOfCoins = 0;
	int numberOfA=0;
	int numberOfB=0;
	int numberOfC=0;
	if(temp > A){
		numberOfA=(temp/A);
		temp=temp%A;
		printf("\n Num Of A Coins: %d\nTemp        : %d",numberOfA,temp);
	}
	if(temp > B) {
		numberOfB =(temp/B);
		temp = temp%B;
		printf("\n Num Of B Coins: %d\nTemp        : %d",numberOfB,temp);
	}

	printf("\n Remaining : %d",temp);
	printf("\n Num of Coins: %d",numberOfCoins);

	numberOfCoins = numberOfA + numberOfB+temp;

	printf("\n Number of Coins : %d", numberOfCoins);

	return 0;
}
