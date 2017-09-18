#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool cmp(pii p,pii q)
{
	return (p.second<q.second);
}

int cei(int x,int y)
{
	float f=(float)x/y;
	int e=x/y;
	if (e==f)
	 return e;
	return e+1;
}


int main()
{
	//freopen("input.txt","r",stdin);
	int i,j,k,n,m,f;
	pii tab[110];
	cin>>n>>m;
	for (i=1;i<=m;i++)
	 cin>>tab[i].first>>tab[i].second;
	sort(tab+1,tab+m+1,cmp);
	int bisa=0;
	int simpan=-1;
	tab[0]=make_pair(1,1);
	for (i=1;i<=100;i++)
	{
		//cout<<i<<" i\n";
		bool cek=true;
		for (j=1;j<=m;j++)
		{
			int bawah=(i*(tab[j].second-1))+1;
			int atas=bawah+i-1;
			//cout<<bawah<<" "<<atas<<"\n";
			if (tab[j].first<bawah || tab[j].first>atas)
			{
				//cout<<j<<" mati\n";
				cek=false;
				break;
			}
		}
		if (cek)
		{
			bisa++;
			if (simpan==-1)
			 simpan=cei(n,i);
			else
			 {
			 	int now=cei(n,i);
			 	if (now!=simpan)
			 	 {
			 	 	cout<<-1<<"\n";
			 	 	return 0;
				  }
			 }
		}
	}
	//cout<<simpan<<" simpan\n";
	cout<<simpan<<"\n";
}
