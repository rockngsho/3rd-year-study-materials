#include<bits/stdc++.h>
using namespace std;
stack <int> buffer;
int N,choice,temp,val;
main()
{
	cout<<"Enter the size of buffer:";
	cin>>N;
	while(1)
	{
		cout<<"Enter the option: \n1.produce\n2.consume\n3.exit:\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(temp==N)
					cout<<"buffer is full\n";
				else
				{
					cout<<"enter the value to be produced:\n";
					cin>>val;
					buffer.push(val);
					temp++;
				}
				break;
				
			case 2:
				if(buffer.empty())
					cout<<"buffer is empty\n";
				else
				{
					cout<<"consumer consumes "<<buffer.top()<<"\n";
					buffer.pop();
					temp--;
				}
				break;
			case 3:
				exit(0);
		}
	}
}
