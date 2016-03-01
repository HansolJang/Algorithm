#include <stdio.h>
#include <string.h>

int getLastDate(int year, int month);
int iskw(char date[]);

int main() {
	int i=1;  // 배열의 인덱스
	int yyyy = 1970;
	int mm = 1;  //1~12
	int lastDate;
	int dd = 1;  //1~28,29,30,31 
	int hh = 0;  //00~24
	int MM = 0;  //00~59
	int ss = 0;  //00~59
	int kw[11111];

	lastDate = getLastDate(yyyy, mm);
	for(int j=0; j<10000; j++) {
		//iskw == true면 
		//	yyyy-mm-dd hh:MM:ss형식으로 바꾸기
		//	결과 배열에 넣기

		//시간계산
		ss++;
		if(ss % 60 == 0) {
			MM++;
		}
		if(MM % 60 == 0 && MM != 0) {
			hh++;
		}
		if(hh%24 == 0 && hh != 0) {
			dd++;
		}
		if(dd == lastDate+1) {
			dd = 1;
			mm++;
			lastDate = getLastDate(yyyy, mm);
		}
		if(mm%13 == 0) {
			yyyy++;
		}

		int res = yyyy*10000000000 + (mm%13)*100000000 + dd*1000000 + (hh%24)*10000 + (MM%60)*100 + ss%60;

		
		char date[14]={res};
		printf("%s\n", date);

		if(iskw(date)) {
			//성시
			int res = yyyy*10000000000 + (mm%13)*100000000 + dd*1000000 + (hh%24)*10000 + (MM%60)*100 + ss%60;
			kw[i] = res;
			i++;
		}
		printf("%s\n", date);
	}

	int testCase;
	scanf("%d", &testCase);
	for(int k=0; k<testCase; k++) {
		printf("#testCase%d\n", k+1);
		int input;
		scanf("%d", &input);
		printf("%d", kw[input]);
	}
}

int getLastDate(int year, int month) {
	switch(month) {
		case 1: return 31;
		case 2:
			if(year%4 == 0) {  //윤년
				if(year%100 == 0) {
					if(year%400 == 0) {
						return 29;  //윤년
					} else {
						return 28;  //윤년X
					}
				} else {  //윤년
					return 29;
				}
			} else {
				return 28;
			}
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

int iskw(char date[14]) {
	//현재 날짜 뒤집기
	//현재 날짜와 같은지 확인
	// true, false 반환
	char rdate[14];
	rdate[0] = date[13];
	rdate[1] = date[12];
	rdate[2] = date[11];
	rdate[3] = date[10];
	rdate[4] = date[9];
	rdate[5] = date[8];
	rdate[6] = date[7];
	rdate[7] = date[6];
	rdate[8] = date[5];
	rdate[9] = date[4];
	rdate[10] = date[3];
	rdate[11] = date[2];
	rdate[12] = date[1];
	rdate[13] = date[0];

	// return strcmp(&date, &rdate);
	return true;
}