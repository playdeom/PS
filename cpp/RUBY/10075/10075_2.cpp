#include <bits/stdc++.h>
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
struct network {
	int host;
	int protocol;
	int trust;
};
int main() {
	upgrade;
	int n;
	cin >> n;
	vector<network>party(n + 10);
	vector<pair<int, int>>ft(n + 10);//final trust value
	for (int i = 0; i < n; i++) {
		//각 사람들의 신뢰도
		cin >> party[i].trust;
		ft[i].first = party[i].trust;
	}
	for (int i = 1; i < n; i++) {
		//초대자와 발동할 프로토콜 명칭 저장
		cin >> party[i].host >> party[i].protocol;
	}
	//0: IAYF: 사람 i를 초대자의 친구로만 등록

	//1: MFAYF: 사람 i를 초대자의 현재 모든 친구의 친구로 등록
	// (사람 i는 초대자의 친구가 아님)

	//2: WAYF: 사람 i를 초대자와, 초대자의 현재 모든 친구의 친구로 등록

	for (int i = n - 1; i >= 1; i--) {
		int protocol = party[i].protocol;
		int host = party[i].host;
		if (protocol == 0) {
			ft[host].first = ft[host].first + ft[i].second;
			ft[host].second = ft[host].second + max(ft[i].first, ft[i].second);
		}
		if (protocol == 1) {
			int save = max(ft[i].first, ft[i].second);
			ft[host].first = max(ft[host].first + save, ft[i].first + ft[host].second);
			ft[host].second = ft[host].second + ft[i].second;
		}
		if (protocol == 2) {
			ft[host].first = max(ft[i].first + ft[host].second, ft[host].first + ft[i].second);
			ft[host].second = ft[i].second + ft[host].second;
		}
	}
	int ans = 0;
	ans = max(ft[0].first, ft[0].second);
	cout << ans;
	return 0;
}