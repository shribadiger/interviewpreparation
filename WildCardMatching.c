/*
 * Lets Try to implement the wild char matching in string 
 * 1. String: [ababbbbaaaaa] -- Pattern:[aba] -> True
 * 2. String: [ababbbbaaaaa] -- Pattern:[aba.] -> True :. Matches to all  charector when i place .
 * 3. String: [ababbbbaaaaa] -- Pattern:[*bbb*] -> True :. Matches to all  charector [Previous]bbb[After]
 * 4. String: [ababbbbaaaaa] -- Pattern:[abba*] -> False :. No Match to previous char.
 *
 * Just I am starting with this assumption
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define I 'I'
#define W 'W'
#define E 'E'
#define D 'D'

bool isPatternMatches(char* input, char* pattern) {
	//let define boolean output
	bool result = false;
	int inputLength = strlen(input);
	int patternLength = strlen(pattern);
	//printf("\n Lenght of Input - %d", inputLength);
	//printf("\n Lenght of Pattern - %d", patternLength);
	//Let consider sequence match
	int i,j=0;
	int pBegin = 0;
	int pEnd = patternLength-1;
	int matchingCount = 0;
	int iEnd=0;
	for(i=0;i<inputLength;) {
		//is beging string matches
		/*printf("\n iBegin : %d",i);
		printf("\n iEnd : %d",iEnd);
	        printf("\n pBegin: %d",pBegin);
	        printf("\n pEnd: %d",pEnd);*/

		if(input[i] == pattern[pBegin]){
			//printf("\n[%c] -- [%c]",input[i],pattern[pBegin]);
			matchingCount++;
			if(matchingCount == patternLength) {
				//printf("\n Match Found at beging compare\n");
				return true;
			}
			/*printf("\n iEnd : %d",i+pEnd);
	        	printf("\n pEnd: %d",pEnd);*/
			if(input[iEnd] == pattern[pEnd]){
			        //printf("\n[%c] -- [%c]",input[iEnd],pattern[pEnd]);
				matchingCount++;
			        if(matchingCount == patternLength) {
				//printf("\n Match Found at beging compare\n");
				return true;
				}
				pBegin++;
				pEnd--;
				iEnd--;
				i++;
			}
		        else {
				i=i+pEnd;
				pBegin = 0;
				pEnd = patternLength-1;
				//printf("\n No match, so restart from %d",i);
				matchingCount = 0;
			}
					
		} 
		else {
			//printf("\n Matching count : %d", matchingCount);
			i++;
			pBegin = 0;
			pEnd = patternLength-1;
			iEnd = i+pEnd;
			matchingCount = 0;
		}
	}
	return result;
}

void printMemoryMatrix(char** array, int m, int n) {
	int i,j;
	for(i=0;i<=m;i++) {
		for(j=0;j<=n;j++) {
			printf("\t%c",array[i][j]);
		}
		printf("\n");
	}
}

bool isRegExpressMatches(){
	printf("\n[Debug]: isRegExpressMatches started\n");
	bool result = false;
	char str[] = "ababab";
	char pattern[]= "a*ab";

	int lenOfStr = strlen(str);
	int lenOfPat = strlen(pattern);

	int i,j;

	//Memorize Matrix of dimenstions lenOfStr x lenOfPat
	char **memMatrix;
        memMatrix = (char**) malloc(sizeof(char*)*lenOfStr);
	for(i=0;i<=lenOfStr;i++){
		memMatrix[i] = (char*) malloc(sizeof(char)*lenOfPat);
	}
        
	//Base condition memMatrix[0][0] = true
	memMatrix[0][0]='T';

	for(i=0;i<=lenOfStr;i++) {
		for(j=0;j<=lenOfPat; j++) {
			if(i==0 && j==0){
				memMatrix[i][j]='T';;
			} else if(j==0) {
				memMatrix[i][j]='F';
			} else if(pattern[j-1] == '*') {
				memMatrix[i][j]='T';
			} else if(pattern[j-1] == '?') {
				memMatrix[i][j]=memMatrix[i-1][j-1];
			} else if(pattern[j-1] == str[i-1]){
				memMatrix[i][j]=memMatrix[i-1][j-1];
			} else {
				memMatrix[i][j]='F';
			}
		}
	}

	printMemoryMatrix(memMatrix,lenOfStr,lenOfPat);

	return result;
}


int main() {
	//Begining Time
	clock_t begin_time = clock();
	char input_str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabbbababababababbababababababbbbbaaabb"; //simple one
	char pattern[] ="baaab"; //Let consider simple pattern

	if(isPatternMatches(input_str,pattern))
		printf("\nMatch Found");
	else 
		printf("\nNo Match Found");
	
	//End Time
	clock_t end_time = clock();
	double time_spent = ((double)(end_time - begin_time)/CLOCKS_PER_SEC);
	printf("\n Time of Execution : %f",time_spent); 

	bool val = isRegExpressMatches();
	return 0;
}
