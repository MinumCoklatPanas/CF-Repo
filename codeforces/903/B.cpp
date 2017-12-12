#include <bits/stdc++.h>
using namespace std;

int cei(int x,int y)
{
	float f=(float)x/y;
	int e=x/y;
	return (e==f ? e : e+1);
}

int main()
{
	int h1,a1,c1;
	cin>>h1>>a1>>c1;
	int h2,a2;
	cin>>h2>>a2;
	int SeranganSaya=cei(h2,a1);
	int SeranganMusuh=cei(h1,a2);
//	cout<<SeranganMusuh<<" "<<SeranganSaya<<"\n";
	if (SeranganSaya<=SeranganMusuh)
	{
		cout<<SeranganSaya<<"\n";
		for (int i=1;i<=SeranganSaya;i++)
		{
			cout<<"STRIKE\n";
		}
	}
	else
	 {
	 	int heal=cei(((SeranganSaya-1)*a2+1)-h1,c1-a2);
	 	cout<<SeranganSaya+heal<<"\n";
	 	for (int i=1;i<=heal;i++)
	 	 cout<<"HEAL\n";
	 	for (int i=1;i<=SeranganSaya;i++)
	 	 cout<<"STRIKE\n";
	 }
}
