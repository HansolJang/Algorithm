/*
https://www.acmicpc.net/problem/10426
*/
#include <stdio.h>

char input[15];
int anni;
int year;
int month;
int date;

int get_max_date(int year, int month);

int main()
{
	scanf("%s %d", input, &anni);
	year = ((input[0]-'0') * 1000) + ((input[1]-'0') * 100) + ((input[2]-'0') * 10) + (input[3]-'0');
	month = ((input[5]-'0') * 10) + (input[6]-'0');
	date = ((input[8]-'0') * 10) + (input[9] - '0');

	date += (anni - 1);

	while(1)
	{
		int max = get_max_date(year, month);
		if(date > max)
		{
			date -= max;
			month++;
		}

		if(month > 12)
		{
			month = 1;
			year++;
		}

		max = get_max_date(year, month);
		if(date <= max)
		{
			break;
		}
	}

	char m[2];
	char d[2];
	if(month < 10)
	{
		m[0] = '0';
		m[1] = month + '0';
	} else {
		m[0] = month/10 + '0';
		m[1] = month%10 + '0';
	}

	if(date < 10)
	{
		d[0] = '0';
		d[1] = date + '0';
	} else {
		d[0] = date/10 + '0';
		d[1] = date%10 + '0';
	}
	printf("%d-%c%c-%c%c\n", year, m[0],m[1], d[0], d[1]);

	return 0;
}

int get_max_date(int year, int month)
{
	switch(month){
		case 1:
			return 31;
		case 2:
			if(year % 4 == 0)
			{
				if(year % 100 == 0)
				{
					if(year % 400 == 0)
					{
						return 29;
					} else return 28;
				}
				else {
					return 29;
				}
				
			}
			else return 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
	}
}