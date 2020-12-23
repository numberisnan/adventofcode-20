
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


// From https://dmoj.ca/tips/
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loopfrom(r, i, n) for(int i = r; i < n; i++)
#define printarr(arr) for (auto i : arr) { cout << i << " ";} cout << "\n";
#define printarrn(arr, n) loop(i, n) { cout << arr[i] << " ";} cout << "\n";
#define nl cout << "\n";
#define ll long long
#define ull unsigned long long
#define INF(type) numeric_limits<type>::max()

using namespace std;

ll arr[1000], pre[1000];
unordered_set<int> s;

bool check(int pos) {
    loopfrom(pos-25, i, pos) {
        if (s.find(arr[pos] - arr[i]) != s.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<ll> s;

    ll n, index, su = 27911108;
    cin >> n;

    loop(i, n) {
        cin >> arr[i];
        if (!i) {
            pre[i] = arr[i];
            s.insert(arr[i]);
        } else {
            pre[i] = arr[i] + pre[i-1];
            s.insert(arr[i] + pre[i-1]);
        }
    }

    ll ri, li;

    loop(i, n) {
        auto res = s.find(su+pre[i]);
        if (res != s.end()) {
            li = i;
            ri = distance(pre, find(pre, pre+n, *res));
            if (ri < li) {
                swap(ri, li);
            }
            break;
        }
    }

    cout << arr[li+1] + arr[ri]; nl;
    cout << pre[li] << " " << pre[ri]; nl;
    cout << li << " " << ri; nl;

    return 0;
}
