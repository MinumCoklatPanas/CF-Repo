#include <iostream>
using namespace std;

int main()
{
	int i,j,k,n,now,start,total,tambah,mundur,awal,maxi;
	cin>>total>>awal>>maxi>>tambah>>mundur;
	now=0;
	int day=0;
	while (now<total)
	{
		day++;
		now+=awal;
		if (now>=total)
		 break;
		now-=mundur;
		awal+=tambah;
		if (awal>=maxi)
		 awal=maxi;
	}
	cout<<day<<"\n";
}
