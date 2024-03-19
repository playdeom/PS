#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNING
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
	upgrade;
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll sum = 0;
		multiset<ll>arr;
		for (int a, i = 0; i < n; i++) {
			cin >> a;
			arr.insert(a);
			sum += a;
		}
		int mobilization = 0;
		int check = 0;
		while (sum > k) {
			auto iter = arr.upper_bound(k);
			if (iter == arr.begin()) {
				check = 1;
				break;
			}
			iter--;
			mobilization++;
			k += *iter;
			sum -= *iter;
			arr.erase(iter);
		}
		cout << (check ? -1 : mobilization) << endl;
	}
	return 0;
}