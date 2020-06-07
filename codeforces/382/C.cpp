#include <bits/stdc++.h>
using namespace std;

int tab[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++) 
		cin >> tab[i];
	sort(tab + 1,tab + n + 1);
	if (n == 1)
		cout << - 1 << endl;
	else
	if (n == 2)
	{
		int beda = tab[2] - tab[1];
		if (beda == 0)
		{
			cout << 1 << endl;
			cout << tab[1] << endl;
		}
		else
		if (beda % 2 == 0)
		{
			cout << 3 << endl;
			cout << tab[1] - beda << " " << tab[1] + (beda / 2) << " " << tab[2] + beda << endl;
		}
		else
		{
			cout << 2 << endl;
			cout << tab[1] - beda << " " << tab[2] + beda << endl;
		}
	}
	else
	{
		vector<int> beda;
		for (int i = 2 ; i <= n ; i++)
			beda.push_back(tab[i] - tab[i - 1]);
		sort(beda.begin(),beda.end());
		beda.erase(unique(beda.begin(),beda.end()),beda.end());
		if (beda.size() == 1)
		{
			// cout << "yo" << endl;
			int diff = beda[0];
			if (diff == 0)
			{
				cout << 1 << endl;
				cout << tab[1] << endl;
			}
			else
			{
				cout << 2 << endl;
				cout << tab[1] - diff << " " << tab[n] + diff << endl;
			}
		}
		else
		if (beda.size() > 2)
		{
			cout << 0 << endl;
		}
		else
		{
			int satu = 0;
			int dua = 0;
			for (int i = 2 ; i <= n ; i++)
			{
				if (tab[i] - tab[i - 1] == beda[0])
					++satu;
				else
					++dua;
			}
			if (dua > 1 || 2 * beda[0] != beda[1])
				cout << 0 << endl;
			else
			{
				cout << 1 << endl;
				for (int i = 2 ; i <= n ; i++)
				{
					if (tab[i] - tab[i - 1] == beda[1])
					{
						cout << tab[i] - beda[0] << endl;
						return 0;
					}
				}
			}
		}
	}
}