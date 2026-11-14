#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
#define faster() (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0))

int n, k;
int a, b, c;
string s;

int xx1[132675], yy1[132675], xx2[132675], yy2[132675];
int px1[132675], py1[132675], px2[132675], py2[132675];
int sx1[132675], sy1[132675], sx2[132675], sy2[132675];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> xx1[i] >> yy1[i] >> xx2[i] >> yy2[i];

    px1[0] = xx1[0], py1[0] = yy1[0], px2[0] = xx2[0], py2[0] = yy2[0];
    for (int i = 1; i < n; i++)
        px1[i] = max(px1[i-1], xx1[i]),
        py1[i] = max(py1[i-1], yy1[i]),
        px2[i] = min(px2[i-1], xx2[i]),
        py2[i] = min(py2[i-1], yy2[i]);

    sx1[n-1] = xx1[n-1], sy1[n-1] = yy1[n-1],
    sx2[n-1] = xx2[n-1], sy2[n-1] = yy2[n-1];
    for (int i = n - 2; i >= 0; i--)
        sx1[i] = max(sx1[i+1], xx1[i]),
        sy1[i] = max(sy1[i+1], yy1[i]),
        sx2[i] = min(sx2[i+1], xx2[i]),
        sy2[i] = min(sy2[i+1], yy2[i]);

    for (int i = 0; i < n; i++) {
        int curx1 = -2e9, cury1 = -2e9, curx2 = 2e9, cury2 = 2e9;

        if (i > 0) {
            curx1 = max(curx1, px1[i-1]);
            cury1 = max(cury1, py1[i-1]);
            curx2 = min(curx2, px2[i-1]);
            cury2 = min(cury2, py2[i-1]);
        }

        if (i < n - 1) {
            curx1 = max(curx1, sx1[i+1]);
            cury1 = max(cury1, sy1[i+1]);
            curx2 = min(curx2, sx2[i+1]);
            cury2 = min(cury2, sy2[i+1]);
        }

        if (curx1 <= curx2 && cury1 <= cury2) {
            cout << curx1 << " " << cury1 << endl;
            return;
        }
    }
}

signed main() {
    faster();
    ll tt = 1;
    // cin>>tt;
    while (tt--) solve();
    return 0;
}