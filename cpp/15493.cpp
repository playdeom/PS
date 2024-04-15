#include <bits/stdc++.h>
#define endl "\n"
#define upgrade ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
struct network {
	int data;
	int left, right;
};
struct cmp {
	bool operator()(network a, network b) {
		return a.data < b.data;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int d;
	priority_queue<network, vector<network>, cmp>data;
	vector<network>arr(n + 100);
	for (int i = 1; i <= n; i++) {
		cin >> d;
		arr[i].data = d;
		if (i == 1) {
			arr[i].left = n;
		}
		else arr[i].left = i - 1;
		if (i == n) {
			arr[i].right = 1;
		}
		else {
			arr[i].right = i + 1;
		}
		if (i == 1)data.push({ arr[i].data,i,i + 1 });
		else if (i == n)data.push({ arr[i].data,i,1});
		else data.push({ arr[i].data,i,i + 1 });
	}
	arr[n+1] = { 0,n,n + 2 };
	int ans = 0;
	int i = 0;
	while (i < k) {
		network save = data.top();
		data.pop();
		network a{ 0,save.left,save.right };
		if (a.left >= 1 and a.right <= n and a.right == arr[a.left].right and a.left == arr[a.right].left) {
			ans += save.data;
			network s{ 0,arr[a.left].left,arr[a.right].right };
			save.left = s.left; save.right = s.right;
			arr[s.left].data = arr[s.left].data + arr[a.right].data - save.data;
			save.data = arr[s.left].data;
			data.push(save);
			arr[s.left].right = s.right;
			arr[s.right].left = s.left;
			i++;
		}
	}
	cout << ans;
	return 0;
}