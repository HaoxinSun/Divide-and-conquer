#include<iostream>
#include<string>
#include<vector>
#include"Header.h"
using namespace std;

void main()
{
	/*vector<int> ievc{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	//maximum_subarray Find_maximum_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator high);
	maximum_subarray result;
	result = Linear_find_max(ievc, ievc.begin(), ievc.end() - 1);
	// result = Find_maximum_subarray(ievc, ievc.begin(), ievc.end() - 1);

	cout << "The maximum subarray's sum is" << result.get_sum() << endl;
	cout << *(result.get_low()) << endl;
	cout << *(result.get_high()) << endl;*/
	//matrices multiplication
	//attention!!!!!! the square matrix's  row size  here we assume is  the power of 2
	vector<vector<double>> A{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<vector<double>> B(A);
	vector<vector<double>> C;
	C=matrices_multi(A, B);
	for (vector<vector<double>>::size_type i = 0; i != C.size(); ++i)
	{
		for (vector<double>::size_type j = 0; j != C[i].size(); ++j)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	
	

	


	system("pause");
}




