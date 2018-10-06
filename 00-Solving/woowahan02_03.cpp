#include <cstdio>
#include <algorithm>
using namespace std;

bool isOverlap(int start1, int end1, int start2, int end2) {
	if (start2 >= end1) return false;
	if (start1 >= end2) return false;
	return true;
}

int getArea(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (y2 - y1);
}

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5, &x6, &y6);
	
	bool onetwo = isOverlap(x1, x2, x3, x4) && isOverlap(y1, y2, y3, y4);
	bool onethree = isOverlap(x1, x2, x5, x6) && isOverlap(y1, y2, y5, y6);
	
	if(onetwo) {
		if(x3 < x1) x3 = x1;
		if(x4 > x2) x4 = x2;
		if(y3 < y1) y3 = y1;
		if(y4 > y2) y4 = y2;
	}
	
	if(onethree) {
		if(x5 < x1) x5 = x1;
		if(x6 > x2) x6 = x2;
		if(y5 < y1) y5 = y1;
		if(y6 > y2) y6 = y2;
	}
	
	int result = getArea(x1, y1, x2, y2);
	if(onetwo) result -= getArea(x3, y3, x4, y4);
	if(onethree) result -= getArea(x5, y5, x6, y6);
	
	bool twothree = isOverlap(x3, x4, x5, x6) && isOverlap(y3, y4, y5, y6);
	if(twothree) {
		result += (min(x4, x6) - max(x3, x5)) * (min(y4, y6) - max(y3, y5));
	}
	
	printf("%d\n", result < 0 ? 0 : result);
	return 0;
}