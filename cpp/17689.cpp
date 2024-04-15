#include <bits/stdc++.h>
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
struct candy {
	ll candy;
	ll left;
	ll right;
	ll check;
};
candy arr[10101010];
// 백업==사탕
int main() {
	int n;
	cin >> n;
	int t =(n + 1) / 2;
	priority_queue<array<ll,2>>pq;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].candy;
		pq.push({ arr[i].candy,i });
		arr[i].left = i - 1;
		arr[i].right = i + 1;
		//arr[i].check = 0;
	}
	arr[0].candy = -2e18;
	//arr[0].candy = 0;
	arr[n + 1].candy = -2e18;
	//arr[n + 1].check = 0;
	ll ans = 0;
	while (t--) {
		while (arr[pq.top()[1]].check) {
			pq.pop();
		}
		pair<ll, ll>save;
		save.first = pq.top()[0];
		save.second = pq.top()[1];
		pq.pop();
		arr[arr[save.second].left].check = 1;
		arr[arr[save.second].right].check = 1;
		ans += save.first;
		cout << ans << endl;
		arr[save.second].candy = arr[arr[save.second].left].candy + arr[arr[save.second].right].candy - arr[save.second].candy;
		pq.push({ arr[save.second].candy,save.second });
		arr[save.second].left = arr[arr[save.second].left].left;
		arr[arr[save.second].left].right = save.second;
		arr[save.second].right = arr[arr[save.second].right].right;
		arr[arr[save.second].right].left = save.second;
	}
}