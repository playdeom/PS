#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
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
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
int main() {
	int K, M, N;
	cin >> K >> M >> N;
	vector<pair<int, int>> patches(K + M); // patches and Nhoj's cows
	for (int i = 0; i < K; ++i)
		cin >> patches[i].first >> patches[i].second;
	for (int i = K; i < K + M; ++i) {
		cin >> patches[i].first;
		patches[i].second = -1;
	}
	sort(begin(patches), end(patches));
	vector<uint64_t> increases;
	int last_i = -1;
	uint64_t sum_range = 0;
	for (int i = 0; i < (int)patches.size(); ++i) {
		if (patches[i].second == -1) {
			if (last_i == -1) { // try placing to left of Nhoj's leftmost cow
				increases.push_back(sum_range);
			} else {
				uint64_t cur_ans_1 = 0;	 // current sum of window
				uint64_t best_ans_1 = 0; // best sum over all windows
				for (int j = last_i + 1, r = last_i; j < i; ++j) {
					// assume j is the leftmost patch in the window
					while (r + 1 < i &&
						   (patches[r + 1].first - patches[j].first) * 2 <
						patches[i].first - patches[last_i].first) {
						cur_ans_1 += patches[++r].second;
					}
					// window sum is now sum(tastinesses(j..r))
					best_ans_1 = max(best_ans_1, cur_ans_1);
					cur_ans_1 -= patches[j].second;
				}
				assert(2 * best_ans_1 >= sum_range);
				// answer for one cow
				increases.push_back(best_ans_1);
				// answer for two cows - answer for one cow
				increases.push_back(sum_range - best_ans_1);
			}
			last_i = i;
			sum_range = 0;
		} else {
			sum_range += patches[i].second;
		}
	}
	// try placing to right of Nhoj's rightmost cow
	increases.push_back(sum_range);
	// sort in decreasing order
	sort(rbegin(increases), rend(increases));
	increases.resize(N);
	uint64_t ans = 0;
	for (auto val : increases)
		ans += val;
	cout << ans << "\n";
}