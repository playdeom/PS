#include <bits/stdc++.h>
#define endl "\n"
#define upgrade ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
struct partial {
    int t, c, np, d;
    ll sum;
    bool ap;
    bool operator<(const partial& p) const {
        if (t != p.t) {
            return t > p.t;
        }
        if (np != p.np) {
            return np < p.np;
        }
        return sum < p.sum;
    }
};
bool cmp(pair<int, int>a, pair<int, int>b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    upgrade;
    int n, t;
    bool check = false;
    cin >> n >> t;
    vector<pair<int, int>>arr(n);
    for (auto& v : arr) {
        cin >> v.first >> v.second;
    }
    sort(all(arr),cmp);
    priority_queue<partial>pq;
    vector<priority_queue<int>>deadlines(1);
    partial s{ 0,0,0,0,0,false };
    pq.push(s);
    while (!pq.empty()) {
        partial p = pq.top();
        while (!pq.empty() and pq.top().t == p.t) {
            pq.pop();
        }
        if (p.np == n) {
            check = true;
            break;
        }
        if (p.ap) {
            deadlines[p.d].pop();
        }
        else {
            deadlines.push_back(deadlines[p.d]);
            p.d = deadlines.size() - 1;
        }
        priority_queue<int>& dl = deadlines[p.d];
        while (p.c < arr.size() and arr[p.c].first <= p.t) {
            dl.push(-arr[p.c].second);
            p.c++;
        }
        if (dl.size() and -dl.top() < p.t + t) {
            continue;
        }
        if (p.c < arr.size() and (!dl.size() or arr[p.c].first < p.t + t)) {
            p.ap = false;
            int ot = p.t;
            p.t = arr[p.c].first;
            pq.push(p);
            p.t = ot;
        }
        if (!dl.empty()) {
            p.ap = true;
            p.np++;
            p.sum += p.t;
            p.t += t;
            pq.push(p);
        }
    }
    cout << (check ? "yes" : "no");
    return 0;
}