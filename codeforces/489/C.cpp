#include <bits/stdc++.h>
using namespace std;

bool can(int m,int s)
{
	return (s>=0) && (s<=9*m);
}

int main()
{
	int m,s;
	cin>>m>>s;
	string mn="-1";
	int sum=s;
	for (int i=1;i<=m;i++)
	 for (int j=0;j<10;j++)
	 {
	 	if ((i>1) && (mn=="-1")) goto hell;
	 	if (((i>1) || (j>0) || (m==1 && j==0)) && can(m-i,sum-j))
	 	{
//	 		cout<<i<<" "<<j<<"\n";
	 		if (mn=="-1")
	 		 mn=j+'0';
	 		else
	 		 mn+=j+'0';
			sum-=j;	
			break; 
		}
	 }
	hell:;
	string mx="-1";
	sum=s;
	for (int i=1;i<=m;i++)
	 for (int j=9;j>=0;j--)
	 {
	 	if ((i>1) && (mx=="-1")) goto school;
	 	if (((i>1) || (j>0) || (m==1 && j==0)) && can(m-i,sum-j))
	 	{
//	 		cout<<i<<" "<<j<<"\n";
	 		if (mx=="-1")
	 		 mx=j+'0';
	 		else
	 		 mx+=j+'0';
			sum-=j;	
			break; 
		}
	 }
	school:;
	int hehe;
	assert((mn.size()==m) || (mn=="-1"));
	assert((mx.size()==m) || (mx=="-1"));
	cout<<mn<<" "<<mx<<"\n";
}
