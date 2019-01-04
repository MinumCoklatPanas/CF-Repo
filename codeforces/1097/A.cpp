#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	cin >> s1;
	for (int i = 1 ; i <= 5 ; i++)
	{
		cin >> s2;
		if (s2[0] == s1[0] || s2[1] == s1[1])
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}