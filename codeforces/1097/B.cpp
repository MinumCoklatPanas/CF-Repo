#include <bits/stdc++.h>
using namespace std;

int tab[20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++)
		cin >> tab[i];
	for (int mask = 0 ; mask < (1<<n) ; mask++)
	{
		int now = 0;
		// cout << mask << endl;
		for (int i = 0 ; i < n ; i++)
		{
			int state = ((mask & (1<<i)) > 0);
			// cout << state;
			if (state)
				now -= tab[i];
			else
				now += tab[i];
			// now += (-1 * state) * tab[i];
			if (now < 0)
				now += 360;
			if (now > 360)
				now -= 360;
		}
		// cout << endl;
		if (now == 0)
		{
			// cout << mask << endl;
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}