#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
struct network {
	int data;
	int left,right;
};
struct cmp{
	bool operator()(network a, network b) {
		return a.data > b.data;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k;
	cin >> n>>k;
	int first,end;
	cin >> first;
	priority_queue<network,vector<network>,cmp>data;
	vector<network>arr(n+100);
	for (int i = 1; i < n; i++) {
		cin >> end;
		arr[i].data = end - first;
		arr[i].left = i - 1;
		arr[i].right = i + 1;
		data.push({ arr[i].data,i,i + 1 });
		first = end;
	}
	arr[n] = { 0,n - 1,n + 1 };
	int ans = 0;
	int i = 0;
	while(i<k) {
		network save = data.top();
		data.pop();
		network a{ 0,save.left,save.right };
		if (a.left>=1 and a.right<=n and a.right == arr[a.left].right and a.left == arr[a.right].left) {
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