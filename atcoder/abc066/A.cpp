#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a,b,c;
	int tab[5];
	for (int i=1;i<=3;i++)
	 cin>>tab[i];
	sort(tab+1,tab+4);
	int ans=tab[1]+tab[2];
	cout<<ans<<"\n";
	return 0;
}