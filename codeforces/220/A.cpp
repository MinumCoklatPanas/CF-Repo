#include <bits/stdc++.h>
using namespace std;

int tab[100010];
int sorted[100010];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	sorted[i]=tab[i];
	 }
	sort(sorted+1,sorted+n+1);
	int cnt=0;
	for (int i=1;i<=n;i++)
	 cnt+=(sorted[i]!=tab[i]);
	cout<<(cnt<=2 ? "YES" : "NO")<<"\n";
}
