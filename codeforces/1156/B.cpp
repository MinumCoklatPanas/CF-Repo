#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int frek[30];

void maju(int start,string &tmp)
{
	for (int i = start ; i <= 26 ; i += 2)
	{
		for (int j = 1 ; j <= frek[i] ; j++)
			tmp += 'a' + i - 1;
	}
}

void mundur(int start,string &tmp)
{
	for (int i = start ; i >= 1 ; i -= 2)
	{
		for (int j = 1 ; j <= frek[i] ; j++)
			tmp += 'a' + i - 1;
	}
}

bool cek(string s)
{
	for (int i = 0 ; i + 1 < s.length() ; i++)
	{
		if (abs(s[i] - s[i + 1]) == 1) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(frek,0,sizeof(frek));
		string s;
		cin >> s;
		string ans;
		for (int i = 0 ; i < s.length() ; i++)
			frek[s[i] - 'a' + 1]++;
		maju(1,ans);
		maju(2,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		maju(2,ans);
		maju(1,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		maju(1,ans);
		mundur(26,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		mundur(26,ans);
		maju(1,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		maju(2,ans);
		mundur(25,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		mundur(25,ans);
		maju(2,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		mundur(25,ans);
		mundur(26,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		ans = "";
		mundur(26,ans);
		mundur(25,ans);
		if (cek(ans))
		{
			cout << ans << endl;
			continue;
		}
		cout << "No answer\n";
	}
}