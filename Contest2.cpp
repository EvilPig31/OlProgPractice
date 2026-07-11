#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = static_cast<int>(s.size());
    std::vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }

    int L = n - pi[n - 1];
    if (n % L == 0) {
        std::cout << L << '\n';
    } else {
        std::cout << n << '\n';
    }

    return 0;
}
