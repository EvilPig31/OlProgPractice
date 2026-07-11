#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> c(n, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> c[i][j];
            }
            c[i][0] = 0;
        }

        vector<vector<int>> profit(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= m; ++s) {
                for (int j = 0; j <= s; ++j) {
                    profit[i][s] = max(profit[i][s], profit[i - 1][s - j] + c[i - 1][j]);
                }
            }
        }

        cout << profit[n][m] << '\n';
    }

    return 0;
}
