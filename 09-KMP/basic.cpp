#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m, 0);
	pi[0] = 0;
	int j = 0;
	for(int i=1; i<m; i++) {
		/*
		----비교할 자리를 찾는 부분
		한글자 이상 맞았었는데 그 다음이 틀린 경우
		맨처음부터 다시 보는것이 아니라 중복될 경우엔 그 다음부터 보면 되므로
		pi[j-1]부터 다시 이어서 볼 자리를 찾음
		ex) p = "abcabe"일때 e에서 틀렸을 경우 ab건너뛰고 c부터 다시 비교 
		*/
		while(j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if(p[i] == p[j])
			pi[i] = ++j;
		else
			pi[i] = 0;
	}
	return pi;
}
//s:원본 p:찾을 문자열
vector<int> kmp(string s, string p) {
	vector<int> pi = preprocessing(p);
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int j = 0;
	for(int i=0; i<n; i++) {
		while(j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if(s[i] == p[j]) {
			//맞는 문자열 하나 찾았을 경우 시작 인덱스 푸시
			if(j == m - 1) {
				ans.push_back(i - j);
				//찾는 문자열의 중복되지 않는 첫번째 글자부터 다시 시작
				//ex) p = "abca" 일경우 b부터 다시 비교 시작
				j = pi[j];
			} else {
				j += 1;
			}
		}
	}
	return ans;
}
int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	vector<int> ans = kmp(s, p);
	printf("%d\n", ans.size());
}