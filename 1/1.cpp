
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, temp, fin;
    cin >> n;
    set<int> s;
    ll d[5000];

    fill_n(d, 5000, 0);

    loop(i, n) {
        cin >> temp;
        s.insert(temp);
    }

    for(auto f : s) {
        for(auto sec : s) {
            d[f+sec] = f*sec;
        }
    }

    for (auto v : s) {
        if (d[2020-v]) {
            fin = d[2020-v]*v;
        }
    }

    cout << fin; nl;

    return 0;
}
