#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n;
	char kanan[4]= {'^','>','v','<'};
	char kiri[4]={'^','<','v','>'};
	char tanya1,tanya2;
	cin>>tanya1>>tanya2;
	cin>>n;
	bool cw,ccw;
	cw=false; ccw=false;
	//cek kanan
	int pos1=-1;
	for (i=0;i<4;i++)
	{
		if (kanan[i]==tanya1)
		{
			pos1=i;
			break;
		}
	}
	int pos2=-1;
	for (i=0;i<4;i++)
	{
		if (kanan[i]==tanya2)
		{
			pos2=i;
			break;
		}
	}
	int jarak=pos2-pos1;
	if (jarak<0)
	 jarak+=4;
	if (jarak%4==n%4)
	 cw=true;
	 
	 
	 pos1=-1;
	for (i=0;i<4;i++)
	{
		if (kiri[i]==tanya1)
		{
			pos1=i;
			break;
		}
	}
	 pos2=-1;
	for (i=0;i<4;i++)
	{
		if (kiri[i]==tanya2)
		{
			pos2=i;
			break;
		}
	}
	 jarak=pos2-pos1;
	if (jarak<0)
	 jarak+=4;
	if (jarak%4==n%4)
	 ccw=true;
	if (cw && ccw)
	{
		cout<<"undefined\n";
		return 0;
	}
	else
	 if (cw)
	 {
	 	cout<<"cw\n";
	 	return 0;
	 }
	 else
	  {
	  	cout<<"ccw\n";
	  	return 0;
	  }
}
