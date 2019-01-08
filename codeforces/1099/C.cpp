#include <bits/stdc++.h>
using namespace std;

bool on[210];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(on,1,sizeof(on));
	cin >> s;
	int k;
	cin >> k;
	int cnt = 0;
	int len = s.length();
	int bintang = 0;
	int tanya = 0;
	for (int i = 0 ; i < s.length() ; i++)
	{
		// if (s[i] == '*' || s[i] == '?')
		// 	++cnt;
		bintang += (s[i] == '*');
		tanya += (s[i] == '?');
	}
	// cout << len << " " << bintang << " " << tanya << endl;
	cnt = len - 2 *(bintang + tanya);
	// cout << cnt << endl;
	if  (cnt > k)
		cout << "Impossible\n";
	else
	if (cnt == k)
	{
		for (int i = 0 ; i < s.length() ; i++)
		{
			if (s[i] == '*' || s[i] == '?')
				on[i - 1] = 0;
		}
		string ans;
		ans = "";
		for (int i = 0 ; i < len ; i++) if (on[i] && s[i] != '*' && s[i] != '?')
			ans += s[i];
		cout << ans << endl;
	}
	else
	{
		int butuh = k - cnt;
		if (bintang > 0)
		{
			bool sudah = 0;
			int simpan;
			for (int i = 0 ; i < len ; i++) 
			{
				if (s[i] == '?')
					on[i - 1] = 0;
				if (s[i] == '*' && sudah)
				{
					on[i - 1] = 0;
					sudah = 1;
				}
				else
				if (s[i] == '*')
				{
					sudah = 1;
					simpan = i - 1;
				}
			}
			string ans;
			for (int i = 0 ; i < len ; i++) if (on[i] && s[i] != '*' && s[i] != '?')
			{
				ans += s[i];
				if (i == simpan)
				{
					for (int j = 1 ; j < butuh ; j++)
						ans += s[i];
				}
			}
			cout << ans << endl;
		}
		else
		if (butuh > tanya)
		{
			cout << "Impossible" << endl;
		}
		else
		{
			// cout << "yo" << endl;
			for (int i = 0 ; i < len ; i++) if (s[i] == '?')
			{
				if (!butuh)
					on[i - 1] = 0;
				else
					--butuh;
			}
			string ans;
			for (int i = 0 ; i < len ; i++) if (on[i] && s[i] != '*' && s[i] != '?')
				ans += s[i];
			cout << ans << endl;
		}
	}
}