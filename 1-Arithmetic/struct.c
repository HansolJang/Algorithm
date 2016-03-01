#include <stdio.h>

typedef struct person {
	char name[20];
	char pID[20];
	person* frnd;
} person;

int main() {
	person man1 = {"Mr.Lee", "820204-0000512"};
	person man2 = {"Mr.Lee's Friend", "820000-0000101"};

	man1.frnd = &man2;  //person* 이므로 주소를 넘겨준다

	printf("[Mr.Lee]\n");
	printf("name : %s\n", man1.name);
	printf("pID : %s\n", man1.pID);

	printf("[Mr.Lee's Friend]\n");
	printf("name : %s\n", man1.frnd->name);  //man1.frnd(포인터 )가 가리키는 이름
	printf("pID : %s\n", man1.frnd->pID);

	return 0;
}