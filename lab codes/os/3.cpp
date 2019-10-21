//SJF arrival time differs
#include<bits/stdc++.h>
using namespace std;
map <int,int> pa;
vector < pair<int,int> > bp[100];
vector < pair<int,int> > :: iterator itr;
int wt[10];
int last[10];
int a,b,comp=0,i=0,temp=0,n,p,turn,executed,flag;
float avg=0;

main()
{
   
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p>>a>>b;
		bp[b].push_back(make_pair(a,p));
		wt[p]=0;
		last[p]=a;
    }
    for(int j=1;j<10;j++)
		sort(bp[j].begin(), bp[j].end());
    while(executed<n)
    {
    	flag=0;
		for(int x=1;x<10;x++)
		{
			for(itr=bp[x].begin();itr!=bp[x].end();itr++)
			{
				int z=(*itr).first,y=(*itr).second;
	    		if(z>i)
					break;
	    		if(x!=0)
	    		{
					flag=1;
					wt[y]=wt[y]+i-last[y];
					last[y]=i+1;
					if(x-1!=0)
						bp[x-1].push_back(make_pair(z,y));
					else
						executed++;
					
					bp[x].erase(itr);
					for(int j=1;j<10;j++)
						sort(bp[j].begin(), bp[j].end());
					break;
	    		}
	    		
			}
			if(flag)
	    		break;
		}
		i++;
    }
  
    for(int i=1;i<=n;i++)
    {
    	cout<<"waiting time of process "<<i<<": "<<wt[i]<<"\n";	
    	avg+=wt[i];
    }
		
    cout<<"average waiting time:"<<(avg/n)<<"\n";
    cout<<"turn around time:"<<i;
}
