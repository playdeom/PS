#include <bits/stdc++.h>
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
struct network {
	int host;
	int protocol;
};
network party[100001];
int trust[100001];
int main() {
	upgrade;
	int n;
	cin >> n;
	//vector<int>trust(n + 10);
	//vector<network>party(n + 10);
	for (int i = 0; i < n; i++) {
		//각 사람들의 신뢰도
		cin >> trust[i];
	}
	for (int i = 1; i < n; i++) {
		//초대자와 발동할 프로토콜 명칭 저장
		cin >> party[i].host >> party[i].protocol;
	}
	//0: IAYF: 사람 i를 초대자의 친구로만 등록
	//1: MFAYF: 사람 i를 초대자의 현재 모든 친구의 친구로 등록(사람 i는 초대자의 친구가 아님)
	//2: WAYF: 사람 i를 초대자와, 초대자의 현재 모든 친구의 친구로 등록
	//세 프로토콜은 반드시 한번 이상 나온다
	int ans=0;
	for (int i = n-1; i >= 1; i--) {
		int proto = party[i].protocol;
		int host = party[i].host;
		if (proto == 1) {
			trust[host] += trust[i];
		}
		else if (proto == 0) {
			ans += trust[i];
            trust[party[i].host]=max(0,trust[party[i].host]-trust[i]);
		}
		else if (proto == 2) {
			trust[host] = max(trust[host], trust[i]);
		}
	}
	cout << ans+trust[0];
	return 0;
}