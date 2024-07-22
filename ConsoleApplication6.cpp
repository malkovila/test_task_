#include <iostream>
#include <vector>

const int DIGITS = 13;
const int HALF_DIGITS = 6;
const int MAX_SUM = HALF_DIGITS * (DIGITS - 1);

std::vector<std::vector<long long>> sum_comminations(int digits, int base, std::vector<std::vector<long long>>& dp) {
    dp[0][0] = 1;

    for (int d = 0; d < digits; ++d) {
        for (int s = 0; s <= MAX_SUM; ++s) {
            for (int b = 0; b < base; ++b) {
                if (s + b <= MAX_SUM) {
                    dp[d + 1][s + b] += dp[d][s];
                }
            }
        }
    }

    return dp;
}

int main() {
    std::vector<std::vector<long long>> dp(HALF_DIGITS + 1, std::vector<long long>(MAX_SUM + 1, 0));
    sum_comminations(HALF_DIGITS, DIGITS, dp);
    long long res = 0;

    for (int s = 0; s <= MAX_SUM; ++s) {
        res += dp[HALF_DIGITS][s] * dp[HALF_DIGITS][s];
    }

    std::cout << res << std::endl;
    return 0;
}
