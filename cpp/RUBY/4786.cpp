#include <bits/stdc++.h>
#include <cassert>
#define _CRT_SECURE_NO_WARNING
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int inf = 1e9 - 1; //integer maximum
const int mod = 1000000007; //prime number
int main() {
	upgrade;
	ll n, k, t;
	while (1) {
		cin >> n >> k >> t;
		if (!n and !k and !t) {
			return 0;
		}
		vector<ll>arr(t - 1, 0);
		for (auto& v : arr)cin >> v;
		if (arr.front() > n or arr.front() > k) {
			cout << -1 << endl;
			continue;
		}
		arr.push_back(0);
		ll attack = arr.front();
		ll ans = 0;
		for (int i = 0; i < t; i++) {
			ll save1 = min(n, k) - attack;
			if (i + 1>= t - 1) {
				ans += save1;
				k = (k >= n ? k : n);
				attack = 0;
				if (i == t - 1) {
					cout << ans << endl;
				}
				continue;
			}
			//min(n,k)+n
			save1 = min(n, k) - attack;
			ll save2 = arr[i + 1] - n;
			ll save3 = min(n, k) + n - attack - arr[i + 1];
			ll be = max((ll)0, k - n);
			ll save4 = min(be, arr[i + 1] - n);
			if (arr[i + 1] > min(n, k) + n - attack) {
				cout << -1 << endl;
				break;
			}
			else if (arr[i + 1] <= n) {
				k += n - attack - save1;
                attack = arr[i + 1];
				n += save1;
			}
			else {
				k += n - save2 - save3 - attack;
				attack = n + save4;
				n += save3 + save4;
			}
		}
	}
	return 0;
}
/*
* input
8 4 6
22 6 10 14 0
4 3 3
0 0
6 9 7
0 0 11 0 7 0
0 0 0
* output
-1
11
101
*/