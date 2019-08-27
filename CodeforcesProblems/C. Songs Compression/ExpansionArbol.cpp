#include <bits/stdc++.h>
using namespace std;

int solve(int dp[][2], int wt, int K, int used)
{
    if (wt < 0)
        return 0;
    if (wt == 0) {
        if (used)
            return 1;
        return 0;
    }
    if (dp[wt][used] != -1)
        return dp[wt][used];
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        ans += solve(dp, wt - i, K, used | 1);
    }
    return dp[wt][used] = ans;
}
int main()
{
    int K;
    int W;
    cout<<"Ingrese la cantidad de hijos: ";
    cin>>K;
    cout<<"Ingrese la suma de nodos a hallar: ";
    cin>>W;
    int dp[W + 1][2];
    memset(dp, -1, sizeof(dp));
    cout << solve(dp, W, K, 0) << endl;
    return 0;
}
