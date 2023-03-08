#include<iostream>
using namespace std;
void output(int a[],int n)
{
	cout<<"\n Enter the array elements = \n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
		
	cout<<endl;
}
void input(int a[],int n)
{
	cout<<"\n Enter the array elements = \n";
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void merge(int a[],int b[],int c[],int i,int j,int s1,int s2)
{
	if(i==s1 && j==s2)
		return;
	if((i<s1 && a[i]<b[j] )||(i<s1 && j>=s2))
	{
		c[i+j] = a[i];	i++;
	}		
	else if((j<s2 && b[j]<=a[i]) || (j<s2 && i>=s1))
	{
		c[i+j] = b[j]; j++;
	}		
	merge(a,b,c,i,j,s1,s2);
}
int main()
{
	int s1,s2;
	cout<<"\n enter the no of elements of 2 arrays = ";
	cin>>s1>>s2;
	int a[s1],b[s2],c[s1+s2];
	input(a,s1);
	input(b,s2);
	merge(a,b,c,0,0,s1,s2);
	output(c,s1+s2);
}
