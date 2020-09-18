#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int main() {
	char *name = "aabbaabb";
	char *small="ab";

	char *just = (char*)malloc(2);
	memcpy(just,name,2);
	printf("\nCopied char: %s",just);
        
	printf("Bitwise add : %d",(*small & *just));


	return 0;
}
