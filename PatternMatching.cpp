#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPatternMatched(char* input, char* pattern) {
	int lenOfInput = strlen(input);
	int lenOfPattern = strlen(pattern);
	int matchCount=0;
	int index = 0;
	bool retVal = false;
	int i=0;
	printf("\n[Log]: Length of Input : %d",lenOfInput);
	printf("\n[Log]: Length of Pattern: %d",lenOfPattern);
	while(i<lenOfInput && retVal == false){
		if(pattern[matchCount] == input[i]){
			matchCount++;
			retVal=(matchCount==lenOfPattern ? true:false);
		}
		else {
			i=i-matchCount;
			matchCount = 0;
		}
		i++;
	}
	return retVal;
}


int main() {
	char *input="abbbbaaabb";
	char *pattern="aabb";

	if(isPatternMatched(input,pattern))
		printf("\nTRUE");
	else
		printf("\nFALSE");
	return 0;
}
