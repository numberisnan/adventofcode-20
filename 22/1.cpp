
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>


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

bool p1Wins(queue<int> &p1, int n1, queue<int> &p2, int n2) {
    int c1, c2;
    while (p1.size() && p2.size()) {
        c1 = p1.front();
        c2 = p2.front();
        p1.pop();
        p2.pop();

        if (c1 > c2) {
            p1.push(c1);
            p1.push(c2);
        } else {
            p2.push(c2);
            p2.push(c1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    queue<int> p1, p2;
    cin >> n;

    loop(i, n) {
        cin >> temp;
        p1.push(temp);
    }

    loop(i, n) {
        cin >> temp;
        p2.push(temp);
    }

    bool p1winner = p1Wins(p1, n, p2, n);
    queue<int> winner;
    if (p1winner) {
        winner = p1;
    } else {
        winner = p2;
    }

    ll score = 0;
    int s = winner.size();
    loop(i, s) {
        //cout << winner.front() << " ";
        score += winner.front() * (s-i);
        winner.pop();
    }nl;

    cout << score; nl;

    return 0;
}
