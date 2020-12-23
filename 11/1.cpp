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
char grid[93][97], newgrid[93][97];
int as = 0;
int n, w;

bool validsquare(int r, int c) {
    return r < n && r >= 0 && c < w && c >= 0 && grid[r][c] != '.';
}

void evolve() {
    loop(i, n) {
        loop(j, w) {
            grid[i][j] = newgrid[i][j];
        }
    }

    int adj;
    int dv[] = {1, 0, -1};
    int dh[] = {1, 0, -1};
    int tempi, tempj;
    loop(i, n) {
        loop(j, w) {
            if (!validsquare(i, j)) {
                continue;
            }
            adj = 0;
            //cout << "Checking " << i << " " << j; nl;
            // check all adjecent squares
            loop(dvi, 3) {
                loop(dhi, 3) {
                    if (!dhi && !dvi) {
                        continue;
                    }
                    tempi = i+dv[dvi];
                    tempj = j+dh[dhi];
                    while(validsquare(tempi, tempj)) {
                        if (grid[tempi][tempj] == '#') {
                            adj++;
                            break;
                        }
                        tempi += dv[dvi];
                        tempj += dh[dhi];
                    }
                }
            }

            //cout << adj; nl;
            if (adj >= 5) {
                newgrid[i][j] = 'L';
                if (grid[i][j] == '#') {
                    as--;
                }
            } else if (!adj) {
                newgrid[i][j] = '#';
                if (grid[i][j] == 'L') {
                    as++;
                    //cout << "here";
                }
            } else {
                newgrid[i][j] = grid[i][j];
            }
        }
    }

    //newgrid is new grid
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string temp;
    cin >> n;

    loop(i, n) {
        cin >> temp;
        w = temp.length();
        loop(j, w) {
            newgrid[i][j] = temp[j];
        }
    }

    int cos = 0, pos = 1;
    while (cos != pos) {
        pos = as;
        evolve();
        /*loop(i, n) {
            loop(j, w) {
                cout << newgrid[i][j] << " ";
            }
            nl;
        }*/
        //cout << as; nl;
        cos = as;
    }

    cout << cos; nl;


    return 0;
}
