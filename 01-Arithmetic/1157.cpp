#include <cstdio>
using namespace std;
char input[1000001];
int main() {
	scanf("%s", input);
	int count[30] = {0, };
	for(int i = 0; i < 1000001; i++) {
		if (input[i] == '\0') break;
		count[input[i] >= 'a' ? input[i] - 'a' : input[i] - 'A']++;
	}
	int maxindex = 0;
	bool multians = false;
	for(int i = 1; i < 26; i++) {
		if (count[i] >= count[maxindex]) {
			multians = count[maxindex] == count[i] ? true : false;
			maxindex = i;
		}
	}
	printf("%c\n", multians ? '?' : 'A' + maxindex);
	return 0;
}