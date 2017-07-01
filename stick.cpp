#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[11] = {0,1,5,8,9,10,17,17,20,24,30};

	return 0;
}

int search(int * arr, int n)
{
	int result = -1;
	int sol[11] = {0};

	for(int i = 1 ;i <= n ; i++)
	{
		for(int j = 1 ; j <= i ; j++)
		{
			result = max(arr[i],sol[j-1]+arr[j-1]);
		}

		sol[i] = result;
	}

	return sol[n];
}
