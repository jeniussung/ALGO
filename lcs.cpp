#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char str_a[] = "abcd";
	char str_b[] = "bca";

	int a = strlen(str_a);
	int b = strlen(str_b);

	int lcs[a+1][b+1];

	cout<<a<<" "<<b<<endl;

	for(int i = 0 ; i < a+1 ; i++)
		lcs[i][0]=0;
	for(int i = 0 ; i < b+1 ; i++)
		lcs[0][i]=0;

	cout<<lcs[4][0]<<endl;		

	for(int i = 0 ;  i < a ; i++)
		for(int j = 0 ; j < b ; j++){	
			if(str_a[i]==str_b[j]){
				lcs[i+1][j+1] = lcs[i][j]+1;
			}
			else{
				lcs[i+1][j+1] = max(lcs[i][j+1],lcs[i+1][j]);
			}
		}			
			

	cout<<lcs[a][b]<<endl;
	
	return 0;
}
