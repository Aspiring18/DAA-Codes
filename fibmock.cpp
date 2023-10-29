#include<iostream>
using namespace std;

int recursive(int n)
{
	if(n<=1)
	return n;
	cout<<n;
	return recursive(n-1)+recursive(n-2);
}
int main()
{
	int n;
	cout<<"Enter the fibonacci number: "<<endl;
	cin>>n;
	
	int ans = recursive(n);
	cout<<"Ans is "<<ans;
	return 0;
}
