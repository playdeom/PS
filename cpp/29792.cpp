#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define repair(x) x.erase(unique(all(x)),x.end())
using namespace std;
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
const int mod = 1e9 + 9; //prime number
template<class T>T gcd(T x, T y) { if (!y)return x; return gcd(y, x % y); }
template<class T>T lcm(T x, T y) { return (x * y) / gcd(x, y); }
int main() {
	fastio;
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll>arr(n);
	for (auto& v : arr)cin >> v;
	vector<pair<ll, ll>>mon(k);
	for (auto& v : mon)cin >> v.first >> v.second;
	sort(all(arr), greater<ll>());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (!m)break;
		m--;
		vector<ll>save(k+1), dp(909);
		for (int j = 0; j < k; j++) {
			save[j + 1] = mon[j].first % arr[i] ? mon[j].first / arr[i] + 1 : mon[j].first / arr[i];
		}
		for (int j = 1; j <= k; j++) {
			for (int w = 900; w >= 1; w--) {
				if (save[j] <= w) {
					dp[w] = max(dp[w], dp[w - save[j]] + mon[j - 1].second);
				}
			}
		}
		ans += dp[900];
	}
	cout << ans;
	return 0;
}