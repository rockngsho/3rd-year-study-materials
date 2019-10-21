#include<bits/stdc++.h>
using namespace std;

int file,v,maxi,n;
multimap <int,int> block;
multimap <int,int> :: iterator it;
void dis()
{
    cout<<"\nsizes remaining in each block\n";
    for(auto u:block)
    {
	cout<<"block "<<u.second<<" - "<<u.first<<"\n";
    }
}
int func()
{
    int choice;
    cout<<"enter\n1.first fit\n2.best fit\n3.worst fit\n:";
    cin>>choice;
    if(maxi<v)
    {
	cout<<"page miss\n";
        return 0;
    }
	
    if(choice==1)
    {
	int i;
	while(true)
        {
//cout<<"entered\n";
	    i=rand()%n;
	    it=block.begin();
	    for(int j=0;j<i;j++)it++;
	    if((it->first)>=v)
	    {
		block.insert(make_pair((it->first)-v,it->second));
		cout<<"file alloted to block "<<it->second<<"\n";
		block.erase(it);
 		break;
	    }
	}
	
    }
    else if(choice==2)
    {
	for(it=block.begin();it!=block.end();it++)
	{
//cout<<"entered\n";
	    if(it->first>=v)
 	    {
		block.insert(make_pair((it->first)-v,it->second));
		cout<<"file alloted to block "<<it->second<<"\n";
		block.erase(it);
 		break;
	    }
	}
    }
    else if(choice==3)
    {
//cout<<"entered\n";
	it=block.end();
	it--;
	block.insert(make_pair((it->first)-v,it->second));
	block.erase(it);
	cout<<"file alloted to block "<<n-1<<"\n";
    }
}

main()
{
    
    cout<<"enter the no of blocks: ";
    cin>>n;
    
    cout<<"enter the size of each block: ";
    for(int i=0;i<n;i++)
    {
	cout<<"size of block "<<i<<": ";
	cin>>v;
        block.insert(make_pair(v,i));
    }
    it=block.end();
    it--;
    maxi=it->first;
    while(true)
    {
	cout<<"enter the size of file: ";
	cin>>v;
	func();
	it=block.end();
        it--;
        maxi=it->first;
	dis();
	cout<<"\nenter 1 to continue 0 to quit";
        cin>>v;
        if(v==0)
	break;
    }
    
}
