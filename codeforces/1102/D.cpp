#include <bits/stdc++.h>
using namespace std;

vector<int> pos[3];
int Lptr[3];
int Rptr[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0 ; i < n ; i++)
	{
		pos[s[i] - '0'].push_back(i);
	}
	int target = n / 3;
	for (int i = 0 ; i < 3 ; i++)
	{
		Lptr[i] = 0;
		Rptr[i] = pos[i].size();
		// cout << Lptr[i] << " " << Rptr[i] << endl;
	}
	sort(pos[0].begin(),pos[0].end());
	
	int k = pos[0].size();
	while (k > target)
	{
		if (pos[2].size() < target)
		{
			pos[2].push_back(pos[0][Rptr[0] - 1]);
			--Rptr[0];
			++Rptr[2];
			// pos[0].pop_back();
		}
		else
		{
			pos[1].push_back(pos[0][Rptr[0] - 1]);
			--Rptr[0];
			++Rptr[1];
		}
		--k;
	}
	// for (int i = 0 ; i < 3 ; i++)
	// {
	// 	// Lptr[i] = 0;
	// 	// Rptr[i] = pos[i].size();
	// 	cout << Lptr[i] << " " << Rptr[i] << endl;
	// 	for (int j = 0 ; j < pos[i].size() ; j++)
	// 	{
	// 		cout << pos[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	sort(pos[1].begin(),pos[1].end());
	k = pos[1].size();
	// Rptr[1] = k;
	while (k > target)
	{
		if (pos[0].size() < target)
		{
			pos[0].push_back(pos[1][Lptr[1]]);
			++Lptr[1];
			++Rptr[0];
			// pos[1].erase(pos[1].begin());
		}
		else
		{
			pos[2].push_back(pos[1][Rptr[1] - 1]);
			--Rptr[1];
			++Rptr[2];
			// pos[1].pop_back();
		}
		--k;
	}
	sort(pos[2].begin(),pos[2].end());
	k = pos[2].size();
	// Rptr[2] = k;
	while (k > target)
	{
		if (pos[0].size() < target)
		{
			pos[0].push_back(pos[2][Lptr[2]]);
			++Lptr[2];
			++Rptr[0];
			// pos[2].erase(pos[2].begin());
		}
		else
		{
			pos[1].push_back(pos[2][Lptr[2]]);
			++Lptr[2];
			++Rptr[1];
			// pos[2].erase(pos[2].begin());
		}
		--k;
	}
	for (int i = 0 ; i < 3 ; i++)
	{
		// assert(pos[i].size() == target);
		// cout << Lptr[i] << " " << Rptr[i] << endl;
		for (int j = Lptr[i] ; j < Rptr[i] ; j++)
			s[pos[i][j]] = i + '0';
	}
	cout << s << endl;
}