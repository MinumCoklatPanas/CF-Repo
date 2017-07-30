#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int i,j,k,n,pintu[30];
char guest[1000010];
bool cek[30];

int main()
{
	
	cin>>n>>k;
	memset(pintu,0,sizeof(pintu));
	memset(cek,0,sizeof(cek));
	for (i=1;i<=n;i++)
	 {
	 	cin>>guest[i];
	 	int asc=(int) guest[i];
	 	asc-=64;
	 	pintu[asc]++;
	 }
	int hitung=0;
	for (i=1;i<=n;i++)
	{
		int asc=(int) guest[i];
		asc-=64;
		if (!cek[asc])
		{
			cek[asc]=1;
			hitung++;
			pintu[asc]--;
		}
		else
		 {
		 	//hitung++;
		 	pintu[asc]--;
			
		 }
		if (hitung>k)
		{
			cout<<"YES\n";
			return 0;
		}
		if (pintu[asc]<=0)
		 hitung--;
	}
	cout<<"NO\n";
}
