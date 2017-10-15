#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> tab;
	for (int i=1;i<=3;i++)
	{
		int n;
		cin>>n;
		tab.push_back(n);
	}
	sort(tab.begin(),tab.end());
	cout<<(tab[0]==tab[1] ? tab[2] : tab[0])<<"\n";
}