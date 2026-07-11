#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    int total_masks = 1 << n;
    vector<vector<int>> dp(total_masks, vector<int>(n, INF));

    dp[1][0] = 0;

    for (int mask = 1; mask < total_masks; ++mask) {
        for (int v = 0; v < n; ++v) {
            if (!(mask & (1 << v))) continue;
            if (dp[mask][v] == INF) continue;

            for (int u = 0; u < n; ++u) {
                if (mask & (1 << u)) continue;
                int new_mask = mask | (1 << u);
                dp[new_mask][u] = min(dp[new_mask][u], dp[mask][v] + cost[v][u]);
            }
        }
    }

    int full_mask = (1 << n) - 1;
    int ans = INF;
    for (int v = 0; v < n; ++v) {
        ans = min(ans, dp[full_mask][v] + cost[v][0]);
    }

    cout << ans << '\n';

    return 0;
}
