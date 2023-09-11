#include <bits/stdc++.h>
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
int main() {
	upgrade;
	int n;
	cin >> n;
	vector<ll>arr(n + n + 1, 0);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 1; i <= n + n; i++) {
        if(i<=n){
        arr[n+i]=arr[i];
        }
		arr[i] += arr[i - 1];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			double save = arr[j + i] - arr[j];
			if (save < 0) {
				ans += ll(ceil(abs(save) / sum));
			}
		}
	}
	cout << ans;
	return 0;
}