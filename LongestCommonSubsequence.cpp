#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
int LCS_Tabulation(const T& a, const T& b, std::vector<std::vector<int>>& dp)
{
    int n = a.size();
    int m = b.size();

    dp.assign(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

template <typename T>
T LCS_Reconstruct(const T& a, const T& b, const std::vector<std::vector<int>>& dp)
{
    int i = a.size();
    int j = b.size();
    T result;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            result.insert(result.begin(), a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return result;
}
template <typename T>
int LCS_Memo_Helper(const T& a, const T& b, int i, int j, std::vector<std::vector<int>>& memo)
{
    if (i == 0 || j == 0)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (a[i - 1] == b[j - 1])
        memo[i][j] = 1 + LCS_Memo_Helper(a, b, i - 1, j - 1, memo);
    else
        memo[i][j] = std::max(
            LCS_Memo_Helper(a, b, i - 1, j, memo),
            LCS_Memo_Helper(a, b, i, j - 1, memo)
        );

    return memo[i][j];
}

template <typename T>
int LCS_Memo(const T& a, const T& b)
{
    int n = a.size();
    int m = b.size();

    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(m + 1, -1));

    return LCS_Memo_Helper(a, b, n, m, memo);
}
int main()
{
    std::string s1 = "subsequence";
    std::string s2 = "sueen";
    std::cout << "A = " << s1 << std::endl<<"B = " << s2 << std::endl;

    std::vector<std::vector<int>> dp1;
    int len1 = LCS_Tabulation(s1, s2, dp1);
    auto common1 = LCS_Reconstruct(s1, s2, dp1);

    std::cout << "LCS (Tabulation) = " << len1 << std::endl;
    std::cout << "Common sequence = " << common1 << std::endl;
    std::cout << "LCS (Memo) = " << LCS_Memo(s1, s2) << std::endl << std::endl;
    std::vector<int> v1 = { 1, 3, 4, 1, 2, 3 };
    std::vector<int> v2 = { 3, 4, 1, 2, 1, 3 };
    std::cout << "A = {1,3,4,1,2,3}" << std::endl;
    std::cout << "B = {3,4,1,2,1,3}" << std::endl;

    std::vector<std::vector<int>> dp2;
    int len2 = LCS_Tabulation(v1, v2, dp2);
    auto common2 = LCS_Reconstruct(v1, v2, dp2);

    std::cout << "LCS (Tabulation) = " << len2 << std::endl;
    std::cout << "Common sequence = ";
    for (int x : common2) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "LCS (Memo) = " << LCS_Memo(v1, v2) << std::endl;

    return 0;
}
