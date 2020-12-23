
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


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
vector<int> arr, graph[100];
ll dp[100];

ll getPaths(int index) {
    if (dp[index]) {
        return dp[index];
    }
    if (!graph[index].size()) {
        return 1;
    }
    ll count = 0;
    for (int next : graph[index]) {
        count += getPaths(next);
    }

    dp[index] = count;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_n(dp, 100, 0);

    int temp, n;
    cin >> n;

    arr.push_back(0);
    loopfrom(1, i, n+1) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    arr.push_back(arr[n]+3);

    int next = 0;
    loop(i, n+2) {
        next = i+1;
        while (next < n+2 && arr[next]-arr[i] <= 3) {
            graph[i].push_back(next);
            next++;
        }
    }

    cout << getPaths(0); nl;

    return 0;
}
