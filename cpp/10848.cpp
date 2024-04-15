#include <bits/stdc++.h>
#include <cassert>
#define _CRT_SECURE_NO_WARNING
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
const int mod = 1e9 + 9; //prime number
bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first + a.second < b.first + b.second;
}
priority_queue<int>lpq;
priority_queue<int, vector<int>, greater<int>>rpq;
void put(int x, ll& ls, ll& rs) {
	int m = 1000000009;
	if (!lpq.empty())m = lpq.top();
	if (x <= m) {
		lpq.push(x);
		ls += x;
	}
	else {
		rpq.push(x);
		rs += x;
	}
	if (rpq.size() + 1 < lpq.size()) {
		int nx = lpq.top();
		lpq.pop();
		rpq.push(nx);
		ls -= nx;
		rs += nx;
	}
	else if (lpq.size() < rpq.size()) {
		int nx = rpq.top();
		rpq.pop();
		lpq.push(nx);
		ls += nx;
		rs -= nx;
	}
}
int main() {
	fastio;
	int n, k;
	cin >> k >> n;
	vector<pair<int, int>>arr(1, { 0,0 });
	ll ans_one = 0;
	for (int i = 0; i < n; i++) {
		char a, b;
		int x, y;
		cin >> a >> x >> b >> y;
		if (a == b)ans_one += (ll)abs(x - y);
		else arr.push_back({ x,y });
	}
	sort(all(arr), cmp);
	n = arr.size();
	ans_one += (ll)n - 1;
	vector<ll>s(n + 10, 0);
	ll ls = 0, rs = 0;
	for (int i = 1; i < n; i++) {
		put(arr[i].first, ls, rs);
		put(arr[i].second, ls, rs);
		s[i] = rs - ls;
	}
	ll ans_two = s[n - 1];
	if (k == 2) {
		while (!lpq.empty())lpq.pop();
		while (!rpq.empty())rpq.pop();
		ls = 0; rs = 0;
		for (int i = n - 1; i >= 1; i--) {
			put(arr[i].first, ls, rs);
			put(arr[i].second, ls, rs);
			ans_two = min(ans_two, rs - ls + s[i - 1]);
		}
	}
	cout << ans_one + ans_two;
	return 0;
}