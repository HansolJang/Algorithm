#include <stdio.h>

int getLastDate(int month);

int main() {
	int itr;
	int testCase;
	scanf("%d", &testCase);

	for(itr=0; itr<testCase; itr++) {
		printf("testCase%d\n", itr+1);
		int month;
		int date;
		int lastDate;
		int preLastDate;
		int dayindex;
		char d[30];
		scanf("%d %d %s", &month, &date, &d);
		// printf("%s", d);
		lastDate = getLastDate(month);
		preLastDate = getLastDate(month-1);

		switch(d[0]) {
			case 'S':
				if(d[1] == 'u') {
					dayindex = 0;
					break;
				} else {
					dayindex = 6;
					break;
				}
			case 'M':
				dayindex = 1;
				break;
			case 'T':
				if(d[1] == 'u') {
					dayindex = 2;
					break;
				} else {
					dayindex = 4;
					break;
				}
			case 'W':
				dayindex = 3;
				break;
			case 'F':
				dayindex = 5;
				break;	
		}
		printf("%d\n", lastDate);

		int res[6];
		for(int i=0; i<7; i++) {
			if(dayindex == i) {
				res[i] = date;
			} else if (dayindex < i) {
				if(date+(i-dayindex) > lastDate) {
					res[i] = (date+(i-dayindex))%lastDate;
				} else {
					res[i] = date+(i-dayindex);
				}
			} else {
				if(date-i < 0) {
					res[i] = preLastDate - (date-i);
				} else {
					res[i] = date-(dayindex-i);
				}
			}
		} 

		printf("%d %d %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6]);
	}
}

int getLastDate(int month) {
	switch(month) {
		case 1: return 31;
		case 2: return 28;
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
	}
}