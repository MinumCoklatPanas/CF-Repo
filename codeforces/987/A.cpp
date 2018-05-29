#include <bits/stdc++.h>
using namespace std;

bool ada[6];

int main()
{
//	freopen("input.txt","r",stdin);
	string name[6]={"Power","Time","Soul","Reality","Mind","Space"};
	string col[6]={"purple","green","orange","red","yellow","blue"};
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for (int j=0;j<6;j++)
		{
			if (col[j]==s)
			{
				ada[j]=1;
				break;
			}
		}
	}
	cout<<6-n<<"\n";
	for (int i=0;i<6;i++)
	{
		if (!ada[i])
		{
			cout<<name[i]<<"\n";
		}
	}
}
