#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int mang[100][100];

int dp (int i, int j)
{
	if (mang[i][j] > -1)
	{
		// cout << mang[i][j] << endl;
		return mang[i][j];
	}
	if (i == j)
	{
		return 1;
	}
	if (i > j)
	{
		return 0;
	}

	if (s[i] == s[j])
	{
		mang[i][j] = dp(i+1,j-1) + 2;
		cout << i << " " << j << endl;
		// cout << mang[i][j] << endl;
		return mang[i][j];
	}
	else
	{
		mang[i][j] = max(dp(i+1,j), dp(i,j-1));
		cout << i << " " << j << endl;
		// cout << mang[i][j] << endl;
		return mang[i][j];
	}
}

string build (int i, int j)
{
	// cout << i << " " << j << "\n";
	if (i == j)
	{
		string p = " ";
		p[0] = s[i];
		// cout << p << endl; 
		return p;
	}
	if (i > j)
	{
		return "";
	}

	if (s[i] == s[j])
	{
		string p = s[i] + build(i+1,j-1) + s[j];
		cout << p << endl;
		return p;
	}
	else
	{
		if (dp(i,j) == dp(i+1,j))
		{
			return build(i+1,j);
		}
		else
		{
			return build(i,j-1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	memset(mang, -1, sizeof(mang));

	cout << dp(0,s.size()-1) << endl;
	cout << build(0,s.size()-1) << endl;
}

// abcdba
// abcdaba
