#include<iostream>
#include<string>
#include<vector>
#include"Header.h"
using namespace std;

void main()
{
	vector<int> ievc{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	//maximum_subarray Find_maximum_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator high);
	maximum_subarray result;
	result = Linear_find_max(ievc, ievc.begin(), ievc.end() - 1);
	// result = Find_maximum_subarray(ievc, ievc.begin(), ievc.end() - 1);

	cout << "The maximum subarray's sum is" << result.get_sum() << endl;
	cout << *(result.get_low()) << endl;
	cout << *(result.get_high()) << endl;
	
	

	


	system("pause");
}




