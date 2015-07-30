#include <stdio.h>

int main(void){
	int input;
	int i;
	int isPrime = false;
	printf("입력\n");
	scanf("%d", &input);
	for(i = 2; i < input; i++) {
		if(i % input != 0) {
			isPrime = true;
			break;
		}
	}

	if(isPrime) {
		printf("%s\n", "prime");
	} else {
		printf("%s\n", "not prime");
	}

	// return 0;
}