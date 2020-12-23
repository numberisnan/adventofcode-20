
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    int inp, n, line, acc;
    vector<pair<string, int>> cmds;
    bitset<1000> r;

    cin >> n;

    loop(i, n) {
        cin >> cmd >> inp;
        cmds.push_back({cmd, inp});
    }

    loop(i, n) {
        line = 0;
        r.reset();
        acc = 0;
        if (cmds[i].first == "jmp" || cmds[i].first == "nop") {
            cmds[i].first = (cmds[i].first == "jmp" ? "nop" : "jmp");
        }

        while(!r[line] && line < n) {
            r[line] = 1;
            if (cmds[line].first == "acc") {
                acc += cmds[line].second;
                line++;
            } else if (cmds[line].first == "nop") {
                line++;
            } else {
                line += cmds[line].second;
            }
        }

        if (line == n) {
            break;
        } else {
            if (cmds[i].first == "jmp" || cmds[i].first == "nop") {
                cmds[i].first = (cmds[i].first == "jmp" ? "nop" : "jmp");
            }
        }
    }


    cout << acc; nl;



    return 0;
}
