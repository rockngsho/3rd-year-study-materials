//for multiple instances
#include<bits/stdc++.h>
using namespace std;
int ava[10],maxi[10][10],allocated[10][10],need[10][10],executed=0,P,R;

main()
{
    
    cout<<"enter the no of resources:";
    cin>>R;
    cout<<"enter the instances of each resource:\n";
    for(int i=1;i<=R;i++)
    {
	cout<<"for resource "<<i<<":";
        cin>>ava[i];
    }
    cout<<"enter the no of processes:";
    cin>>P;
    cout<<"enter the maximum resources needed by each process:\n";
    for(int i=1;i<=P;i++)
    {
		cout<<"process "<<i<<":";
		for(int j=1;j<=R;j++)
	    	cin>>maxi[i][j];
    }
    cout<<"enter the allocated resources of each process:\n";
    for(int i=1;i<=P;i++)
    {
		cout<<"process "<<i<<":";
		for(int j=1;j<=R;j++)
    	{
		    cin>>allocated[i][j];
		    ava[j]=ava[j]-allocated[i][j];
		}
    }
    for(int i=1;i<=P;i++)
    {
		for(int j=1;j<=R;j++)
	    	need[i][j]=maxi[i][j]-allocated[i][j];
    }
    while(1)
    {
        int i;
		for(i=1;i<=P;i++)
        {
            if(allocated[i][1]==-1)
				continue;
			int temp=0;
			for(int j=1;j<=R;j++)
			{
				if(ava[j]>=need[i][j])
					temp++;
			}
			if(temp==R)
			{
				for(int j=1;j<=R;j++)
				{
					ava[j]=ava[j]+allocated[i][j];
					allocated[i][j]=-1;
				}
		        executed++;
		        break;
			}
    	}
        if(executed==P)
        {
	    	cout<<"No deadlock";
            break;
        }
	
        else if(i==P+1 && executed!=P)
        {
            cout<<"deadlock";
            break;
        }
    }
}
