
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
#define PI 3.14159265359

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    double angle = 84.28940686;
    double pos[2] = {0,0}; // y and x;
    char in;
    double temp;

    loop(i, n) {
        cin >> in >> temp;
        if (in == 'E') {
            pos[1] += temp;
        } else if (in == 'N') {
            pos[0] += temp;
        } else if (in == 'S') {
            pos[0] -= temp;
        } else if (in == 'W') {
            pos[1] -= temp;
        } else if (in == 'F') {
            pos[0] += cos(angle*PI/180)*temp;
            pos[1] += sin(angle*PI/180)*temp;
        } else if (in == 'R') {
            angle += temp;
            angle = fmod(angle, 360);
        } else {
            angle -= temp + 360;
            angle = fmod(angle, 360);
        }
    }

    cout << abs(pos[0]) + abs(pos[1]); nl;

    return 0;
}
