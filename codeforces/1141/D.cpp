#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

queue<int> ix1[30];
queue<int> ix2[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	int n;
	cin >> n;
	cin >> s1 >> s2;
	queue<int> tanya1;
	queue<int> tanya2;
	for (int i = 0 ; i < n ; i++)
	{
		if (s1[i] != '?')
		 	ix1[s1[i] - 'a' + 1].push(i + 1);
		else
			tanya1.push(i + 1);
		if (s2[i] != '?')
			ix2[s2[i] - 'a' + 1].push(i + 1);
		else
			tanya2.push(i + 1);
	}
	vector< pair<int,int> > ans;
	//pair biasa
	for (int i = 1 ; i <= 26 ; i++)
	{
		while (!ix1[i].empty() && !ix2[i].empty())
		{
			ans.push_back(make_pair(ix1[i].front(),ix2[i].front()));
			ix1[i].pop();
			ix2[i].pop();
		}
	}
	// return 0;
	//'?' -> huruf
	for (int i = 1 ; i <= 26 ; i++)
	{
		//s1 -> s2
		while (!ix2[i].empty() && !tanya1.empty())
		{
			ans.push_back(make_pair(tanya1.front(),ix2[i].front()));
			ix2[i].pop();
			tanya1.pop();
		}
		//s2 -> s1
		while (!ix1[i].empty() && !tanya2.empty())
		{
			ans.push_back(make_pair(ix1[i].front(),tanya2.front()));
			ix1[i].pop();
			tanya2.pop();
		}
	}
	//'?' -> '?'
	while (!tanya1.empty() && !tanya2.empty())
	{
		ans.push_back(make_pair(tanya1.front(),tanya2.front()));
		tanya1.pop();
		tanya2.pop();
	}
	cout << ans.size() << endl;
	for (int i = 0 ; i < ans.size() ; i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}