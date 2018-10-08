#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int num1 = 0;
    double num2 = 0l;
    string str;
    scanf("%d %lf\n", &num1, &num2);
    getline(cin, str);
    printf("%d\n%.1f\n", (int)i + num1, num2 + (double)d);
    cout << s << str << "\n";
    return 0;
}