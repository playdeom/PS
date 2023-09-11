#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNING
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}
bool cmp2(pair<int, int>a, pair<int, int>b) {
	return a.second > b.second;
}
int ans,d;
void func(vector<pair<int,int>>arr){
    for (int i = 0; i < arr.size(); i++) {
		if (d <= arr[i].first) {
			ans += arr[i].first;
			d = arr[i].second;
		}
		else {
			d -= arr[i].first;
			ans += arr[i].first;
			d += arr[i].second;
		}
	}
}
int main() {
	upgrade;
	int n;
	cin >> n;
	vector<pair<int, int>>down, up;
	for (int a, b, i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b) {
			up.push_back({a,b});
		}
		else down.push_back({a,b});
	}
	sort(all(down), cmp);
	sort(all(up), cmp2);
    func(down);
    func(up);
	cout << ans + d;
	return 0;
}