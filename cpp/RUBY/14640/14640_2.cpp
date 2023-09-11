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
const int mod = 1e9 + 7; //prime number
int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>>arr(n);
    vector<int>end(n), ban(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        end[i] = arr[i].second;
    }
    sort(all(arr)), sort(all(end));
    for (int i = 0; i < n; i++)ban[i] = arr[i].first;
    bool check = true;
    for (int i = 0; i < n; i++) {
        int c = end[i] - t, m = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (arr[j].second <= end[i]) {
                while (m > 0 and c < arr[m].first) {
                    c = min(c, ban[m]);
                    m--;
                }
                if (c < arr[j].first) {
                    check = false;
                    goto END;
                }
                if (c - t < arr[j].first) {
                    ban[j] = min(ban[j], c - t);
                }
                c -= t;
            }
        }
    }
END:
    cout << (check ? "yes" : "no");
    return 0;
}