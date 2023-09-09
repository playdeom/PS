#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNING
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
const int mod = 1e9 + 7; //prime number
struct professer {
	int s, e, num;
};
struct cmppq {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	}
};
struct cmppq2 {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};
bool cmp(professer a, professer b) {
	if (a.s == b.s)return a.e < b.e;
	return a.s < b.s;
}
pair<int, int>now, save;
int t, n, i;
int main() {
	upgrade;
	cin >> t;
	//vector<int>ans;
	while (t--) {
		cin >> n;
		vector<professer>arr(n);//s,e
		for (i = 0; i < n; i++) {
			cin >> arr[i].s >> arr[i].e;
			arr[i].num = i + 1;
		}
		sort(all(arr), cmp);
		//cout << endl;
		//for (auto& v : arr) {
		//	cout << v.s << " " << v.e << " " << v.num << endl;
		//}

		//while (!pqtest.empty()) {
		//	cout << pqtest.top().first << " " << pqtest.top().second << endl;
		//	pqtest.pop();
		//}
		if (n & 1) {
			priority_queue<pair<int, int>, vector<pair<int, int>>, cmppq>pq;
			pq.push({ arr[0].e, arr[0].num });
			for (i = 1; i < n; i++) {
				save = pq.top();
				//cout << "arr now: ";
				//cout << arr[i].s << " " << arr[i].e << " " << arr[i].num << endl;
				//cout << "save: ";
				//cout << save.first << " " << save.second << endl;
				pq.pop();
				if (save.second == 1 or save.second == 2) {
					if (pq.empty()) {
						if (arr[i].num == 1 or arr[i].num == 2) {
							//cout << 1 << endl;
							pq.push(save);
							pq.push({ arr[i].e, arr[i].num });
							continue;
						}
						else {
							if (save.first <= arr[i].s) {
								//cout << 2 << endl;
								pq.push({ arr[i].e, save.second });
								continue;
							}
							else {
								//cout << 3 << endl;
								pq.push(save);
								pq.push({ arr[i].e, arr[i].num });
								continue;
							}
						}
					}
					else {
						if (arr[i].num == 1 or arr[i].num == 2) {
							now = pq.top();
							pq.pop();
							if (now.first <= arr[i].s) {
								//cout << 4 << endl;
								pq.push({ arr[i].e, arr[i].num });
								pq.push(save);
								continue;
							}
							else {
								//cout << 5 << endl;
								pq.push({ arr[i].e, arr[i].num });
								pq.push(save);
								pq.push(now);
								continue;
							}
						}
						else {
							if (save.first <= arr[i].s) {
								//cout << 6 << endl;
								pq.push({ arr[i].e, save.second });
								continue;
							}
							else {
								//cout << 7 << endl;
								pq.push(save);
								pq.push({ arr[i].e, arr[i].num });
								continue;
							}
						}
					}
				}
				else {
					if (save.first <= arr[i].s) {
						//cout << 8 << endl;
						pq.push({ arr[i].e, arr[i].num });
						continue;
					}
					else {
						//cout << 9 << endl;
						pq.push(save);
						pq.push({ arr[i].e, arr[i].num });
						continue;
					}
				}
			}
			cout << pq.size() << endl;
			continue;
			//ans.push_back(pq.size());
		}
		else {
			priority_queue<pair<int, int>, vector<pair<int, int>>, cmppq2>pq;
			pq.push({ arr[0].e, arr[0].num });
			for (int i = 1; i < n; i++) {
				save = pq.top();
				//cout << "arr now: ";
				//cout << arr[i].s << " " << arr[i].e << " " << arr[i].num << endl;
				//cout << "save: ";
				//cout << save.first << " " << save.second << endl;
				pq.pop();
				if (save.second == 1 or save.second == 2) {
					if (pq.empty()) {
						if (arr[i].num == 1 or arr[i].num == 2) {
							//cout << 1 << endl;
							pq.push(save);
							pq.push({ arr[i].e, arr[i].num });
							continue;
						}
						else {
							if (save.first <= arr[i].s) {
								//cout << 2 << endl;
								pq.push({ arr[i].e, save.second });
								continue;
							}
							else {
								//cout << 3 << endl;
								pq.push(save);
								pq.push({ arr[i].e, arr[i].num });
								continue;
							}
						}
					}
					else {
						if (arr[i].num == 1 or arr[i].num == 2) {
							now = pq.top();
							pq.pop();
							if (now.first <= arr[i].s) {
								//cout << 4 << endl;
								pq.push({ arr[i].e, arr[i].num });
								pq.push(save);
								continue;
							}
							else {
								//cout << 5 << endl;
								pq.push({ arr[i].e, arr[i].num });
								pq.push(save);
								pq.push(now);
								continue;
							}
						}
						else {
							if (save.first <= arr[i].s) {
								//cout << 6 << endl;
								pq.push({ arr[i].e, save.second });
								continue;
							}
							else {
								//cout << 7 << endl;
								pq.push(save);
								pq.push({ arr[i].e, arr[i].num });
								continue;
							}
						}
					}
				}
				else {
					if (save.first <= arr[i].s) {
						//cout << 8 << endl;
						pq.push({ arr[i].e, arr[i].num });
						continue;
					}
					else {
						//cout << 9 << endl;
						pq.push(save);
						pq.push({ arr[i].e, arr[i].num });
						continue;
					}
				}
			}
			cout << pq.size() << endl;
			continue;
			//ans.push_back(pq.size());
		}
	}
	//for (auto& v : ans)cout << v << endl;
	return 0;
}