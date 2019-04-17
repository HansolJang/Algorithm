#include <cstdio>
using namespace std;

int main() {
	int input;
	scanf("%d", &input);
	int count = 0;
	int current = input;
	int temp = 0;
	do {
		temp = current % 10 + current / 10;
		temp = current % 10 * 10 + temp % 10;
		current = temp;
		count++;
	} while(current != input);
	printf("%d\n", count);
	return 0;
}