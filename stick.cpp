#include <iostream>
#include <algorithm>
using namespace std;

int search(int *arr,int n);


int main()
{
	int arr[11] = {0,1,5,8,9,10,17,17,20,24,30};
	cout<<search(arr,7)<<endl;
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
			q = max(q,arr[j]+sol[i-j]);
			result = max(q,result);		
		}

		sol[i] = result;
	}

	return sol[n];
}
