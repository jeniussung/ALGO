#include <iostream>
#include <algorithm>
using namespace std;

int search(int *arr,int n);


int main()
{
	int n;
	int arr[11] = {0,1,5,8,9,10,17,17,20,24,30};
	cin>>n;
	cout<<search(arr,n)<<endl;
	return 0;
}

int search(int * arr, int n)
{
	int result = -1;
	int sol[11] = {0,1};
	int q = 0;

	for(int i = 1 ;i <= n ; i++)
	{	
		q = arr[i];

		for(int j = 1 ; j <= i ; j++)
		{
			q = max(q,arr[i-j]+sol[j]);
			result = max(q,result);		
		}

		sol[i] = result;
	}

	return sol[n];
}
