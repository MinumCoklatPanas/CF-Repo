#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		int l,r,d;
		cin >> l >> r >> d;
		if (l <= d)
		{
			int tmp = (r / d) + (r % d != 0); 
			tmp *= d;
			if (tmp == r)
				cout << tmp + d << endl;
			else
				cout << tmp << endl;
		}
		else
		{
			cout << d << endl;
		}
	}
}