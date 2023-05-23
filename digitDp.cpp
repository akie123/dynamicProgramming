// Author: Aalhad Kate

//find total number of numbers in range [0,n] whose sum is x.

#include <bits/stdc++.h>
typedef long long int ll;
#define fast()  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dp[1000][1000][2];
void table(string ak, int x)
{
	for (int i = 0; i <= 9; i++)
	{
		dp[0][i][0] = 1;
	}
	for (int i = 0; i <= (ak[ak.size() - 1] - '0'); i++)
	{
		dp[0][i][1] = 1;
	}
	for (int i = 1; i < ak.size(); i++)
	{
		for (int j = 0; j <= x; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				if (j - k >= 0)
				{
					dp[i][j][0] = dp[i][j][0] + dp[i - 1][j - k][0];
				}
			}
		}
	}

	for (int i = 1; i < ak.size(); i++)
	{
		for (int j = 0; j <= x; j++)
		{
			for (int k = 0; k < (ak[ak.size() - 1 - i] - '0'); k++)
			{
				if (j - k >= 0)
				{
					dp[i][j][1] = dp[i][j][1] + dp[i - 1][j - k][0];
				}
			}
			int last = (ak[ak.size() - 1 - i] - '0');
			if (j - last >= 0)
			{
				dp[i][j][1] = dp[i][j][1] + dp[i - 1][j - last][1];
			}
		}
	}

	for (int i = 0; i < ak.size(); i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			cout << dp[i][j][1] << " ";
		}
		cout << endl;
	}

}

void force(int n, int x)
{
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = i;
		int co = 0;
		while (j > 0)
		{
			co = co + (j % 10);
			j = j / 10;
		}
		if (co == x)
			ans++;
	}

	cout << ans << endl;
}

void me() {


	memset(dp, 0, sizeof dp);


	string ak = "5859";

	int x = 15;

	table(ak, x);
	force(5859, 15);






}

int main()
{

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif
	fast();

	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++)
		me();
	return 0;

}
