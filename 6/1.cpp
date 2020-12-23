
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>


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

    int n = 2082;
    int sum = 0;
    int ln = 0;
    string temp;
    set<char> s, t;

    loop(i, n) {
        getline(cin, temp);
        if (temp == "") {
            /*for (auto it : s) {
                cout << it;
            } nl;*/
            sum += s.size();
            s.clear();
            ln = 0;
        } else {
            ln++;
            if (ln == 1) {
                loop(ind, temp.size()) {
                    s.insert(temp[ind]);
                }
            } else {
                vector<char> rem;
                t.clear();
                loop(ind, temp.size()) {
                    t.insert(temp[ind]);
                }
                for (auto it = s.begin(); it != s.end(); it++) {
                    if (t.find(*it) == t.end()) {
                        // not in all
                        rem.push_back(*it);
                    }
                }

                loop(ind, rem.size()) {
                    s.erase(rem[ind]);
                }
            }

        }
    }

    cout << sum; nl;

    return 0;
}
