#include<iostream>
using namespace std;

int fibb(int n)
{
	if(n<=1)
	return n;
	
	int a=0,b=1,c;
	for(int i=2; i<=n ; i++)
	{
		c = a+b;
		a=b;
		b=c;
	}
	return b;
}
int main()
{
	int n;
	cout<<"Enter the number you want fibonacci series of: "<<endl;
	cin>>n;
	
	int ans = fibb(n);
	cout<<"Ans is "<<ans;
	return 0;
}
