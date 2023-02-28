#include<iostream>
#define max 8
using namespace std;
void enqueue();
void dequeue();
void display();
int a[max],f1,r1,f2,r2;
int main()
{
	f1 = 0, r1 = -1;
	f2 = max-1, r2 = max;
	int ch;
	do
	{
		cout<<"\n 1 ENQUEUE 2 DEQUEUE 3 DISPLAY 4 EXIT \n Enter choice=";
		cin>>ch;
		switch(ch)
		{
			case 1: enqueue();break;
			case 2: dequeue();break;
			case 3: display();break;
			case 4: break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=4);
}
void enqueue()
{
	if(  r2-r1 == 1  )
		cout<<"\n Queue overflow " <<endl;
	else
	{
		int ele,chInsert;		
		cout<<"\n Enter the ele = ";
		cin>>ele;
		
		cout<<"\n 1 LEFT TO RIGHT\n 2 RIGHT TO LEFT ";
		cin>>chInsert;
		
		switch(chInsert)
		{
			case 1:  a[++r1]=ele;break;
				
			case 2:  a[--r2]=ele;break;
			
			default:cout<<"\n Invalid choice \n";
		}
	}	
}
void dequeue()
{
	int chDel;
	cout<<"\n 1 LEFT TO RIGHT\n 2 RIGHT TO LEFT ";
	cin>>chDel;
	
	switch(chDel)
	{
		case 1: if(f1>r1)
					cout<<"\n underflow from left end \n";
				else
					cout<<"\n Delete the element ="<<a[f1++];
		        break;
		case 2: if(f2<r2)
					cout<<"\n underflow from right end \n";
				else
					cout<<"\n Delete the element ="<<a[f2--];
		        break;
		default:cout<<"\n Invalid choice \n";
	}
}
void display()
{
	if(f1>r1)
			cout<<"\n underflow from left end \n";
	if(f2<r2)
			cout<<"\n underflow from right end \n";
				
	if(f1<=r1 || f2>=r2)
	{
		cout<<"\n the elements of queue (L-->R)= \n";
		for(int i=f1;i<=r1;i++)
			cout<<a[i]<<"\t";
			
		cout<<"\n the elements of queue (R-->L)= \n";
		for(int i=f2;i>=r2;i--)
			cout<<a[i]<<"\t";
	}
}
