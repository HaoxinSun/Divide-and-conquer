#include"Header.h"


//find the a maximum subarray in arry A using O(nlgn) running time
//the idea  to handle the problem is divide and conquer
//author:Haoxin Sun data:10-28-2014
//member function to calculate the sum of elements between low and high iterator
double maximum_subarray::calculate_sum()
{
	double add_ele = 0;
	for (vector<int>::iterator curr = low; curr <= high; ++curr)
	{
		add_ele += *curr;
	}
	return add_ele;
}
maximum_subarray Find_maximum_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator high)
{
	maximum_subarray Max_cross_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator middle, vector<int>::iterator high);
	if (low == high)
	{
		maximum_subarray sub(low, high);
		return sub;
	}
	vector<int>::iterator middle = low + (high - low) / 2;
	//these three objects to hold the left ,cross, right maximum subarray
	maximum_subarray l_max;
	maximum_subarray r_max;
	maximum_subarray cross_max;
	l_max = Find_maximum_subarray(A, low, middle);
	r_max = Find_maximum_subarray(A, middle + 1, high);
	cross_max = Max_cross_subarray(A, low, middle, high);
	//define a class object to hold the a maximum subarray from the three objects
	maximum_subarray max_sub;
	max_sub = l_max.get_sum() > r_max.get_sum() ? (l_max.get_sum() > cross_max.get_sum() ? l_max : cross_max) : (r_max.get_sum() > cross_max.get_sum() ? r_max : cross_max);
	return max_sub;
}

//calculate the maximum subarray that  cross middle point 
maximum_subarray Max_cross_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator middle, vector<int>::iterator high)
{
	//calculate the maximum subarray of left part(included middle)
	maximum_subarray l_sub(middle, middle);
	for (int curr = 0; curr <= middle - low; ++curr)
	{
		maximum_subarray curr_sum(middle - curr, middle);
		//double cur_sum = *(middle - curr - 1) + l_sub.get_sum();
		if (curr_sum.get_sum()>l_sub.get_sum())
		{
			l_sub = curr_sum;
		}
	}
	// calculate the right part
	maximum_subarray r_sub(middle + 1, middle + 1);
	for (vector<int>::iterator r_beg = middle + 1; r_beg <= high; ++r_beg)
	{
		maximum_subarray curr_sum(middle + 1, r_beg);
		if (curr_sum.get_sum() > r_sub.get_sum())
		{
			r_sub = curr_sum;
		}
	}
	maximum_subarray cross_sub(l_sub.get_low(), r_sub.get_high());
	return cross_sub;
}
//a linear running time to handle maximum subarray,exercise 4.1-5(introduction to algorithms)
maximum_subarray Linear_find_max(vector<int> A, vector<int>::iterator low, vector<int>::iterator high)
{
	//define a variable to hold the first positive number
	vector<int>::iterator curr = low;
	/*while (*curr<=0)
	{
		++curr;

	}*/
	//using two class objects to hold the current maximum subarray and 
	maximum_subarray curr_sum(curr, curr);
	for (vector<int>::iterator beg=low; beg != high; ++beg)
	{
		maximum_subarray sum(curr, beg);
		if (sum.get_sum() <= 0)
		{
			curr = beg + 1;
		}
		else
		{
			if (sum.get_sum() > curr_sum.get_sum())
			{
				curr_sum = sum;

			}
		}
	}
	return curr_sum;
}
//square matrices multiplications 
//the idea to handle this problem is divide and conquer,which the running time is O(n*n*n)
//the two matrices' type must match.... have identical rows and columns,we assume that the rows number is a power of 2.
vector<vector<double>> matrices_multi(vector<vector<double>> A, vector<vector<double>> B)
{
	//cout << "top" << endl;
	// define the result matrix and let it size equals matrix A
	vector<vector<double>> C;
	for (vector < vector<double>>::size_type i = 0; i != A.size(); ++i)
	{
		vector<double> ievc;
		C.push_back(ievc);
		for (vector<double>::size_type j = 0; j != A[i].size(); ++j)
		{
			C[i].push_back(0);
			//cout << "here" << endl;
		}
	}
	cout << "here" << endl;
	//if there is only one element in the matrix
	//finish the recursion
	if (A.size() == 1&&A[0].size()==1)
	{
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}

	cout << "123" << endl;
	//define A11,A12,A21,A22......(the same operation to B,and C),and initialize with correspond value that is in the maxtrix A and B;
	//split the matrix A
	vector<vector<double>> A11;
	for (vector<vector<double>>::size_type i = 0; i != A.size() / 2; ++i)
	{
		vector<double> ievc(A.size()/2,0);
		A11.push_back(ievc);
		for (vector<double>::size_type j = 0; j != A[i].size() / 2; ++j)
		{
			A11[i][j] = A[i][j];
		}
	}
	vector<vector<double>> A12;
	for (vector<vector<double>>::size_type i = 0; i != A.size() / 2; ++i)
	{
		vector<double> ievc(A.size()/2, 0);
		A12.push_back(ievc);
		for (vector<double>::size_type j = A[i].size() / 2; j != A[i].size(); ++j)
		{
			int index = j - A[i].size()/ 2;
			A12[i][index] = A[i][j];
		}
	}
	vector<vector<double>> A21;
	for (vector<vector<double>>::size_type i = A.size() / 2; i != A.size(); ++i)
	{
		vector<double> ievc(A.size()/2, 0);
		A21.push_back(ievc);
		int index = i - A.size() / 2;
		for (vector<double>::size_type j = 0; j != A[i].size() / 2; ++j)
		{
			A21[index][j] = A[i][j];
		}
	}
	vector<vector<double>> A22;
	for (vector<vector<double>>::size_type i = A.size() / 2; i != A.size(); ++i)
	{
		vector<double> ievc(A.size()/2, 0);
		A22.push_back(ievc);
		int r_index = i - A.size() / 2;
		for (vector<double>::size_type j = A[i].size() / 2; j != A[i].size(); ++j)
		{
			int col_index = j - A[i].size() / 2;
			A22[r_index][col_index] = A[i][j];
		}
	}

	cout<< "171" << endl;
	//do the same opertions to B like A
	vector<vector<double>> B11;
	for (vector<vector<double>>::size_type i = 0; i != B.size() / 2; ++i)
	{
		vector<double> ievc(B.size()/2, 0);
		B11.push_back(ievc);
		for (vector<double>::size_type j = 0; j != B[i].size() / 2; ++j)
		{
			B11[i][j] = B[i][j];
		}
	}
	vector<vector<double>> B12;
	for (vector<vector<double>>::size_type i = 0; i != B.size() / 2; ++i)
	{
		vector<double> ievc(B.size() / 2, 0);
		B12.push_back(ievc);
		for (vector<double>::size_type j = B[i].size() / 2; j != B[i].size(); ++j)
		{
			int index = j - B[i].size() / 2;
			B12[i][index] = B[i][j];
		}
	}
	vector<vector<double>> B21;
	for (vector<vector<double>>::size_type i = B.size() / 2; i != B.size(); ++i)
	{
		vector<double> ievc(B.size() / 2, 0);
		B21.push_back(ievc);
		int index = i - B.size() / 2;
		for (vector<double>::size_type j = 0; j != B[i].size() / 2; ++j)
		{
			B21[index][j] = B[i][j];
		}
	}
	vector<vector<double>> B22;
	for (vector<vector<double>>::size_type i = B.size() / 2; i != B.size(); ++i)
	{
		vector<double> ievc(B.size() / 2, 0);
		B22.push_back(ievc);
		int r_index = i - B.size() / 2;
		for (vector<double>::size_type j = B[i].size() / 2; j != B[i].size(); ++j)
		{
			int col_index = j - B[i].size() / 2;
			B22[r_index][col_index] = B[i][j];
		}
	}

	//cout << "218" << endl;
	//the same operations to c
	vector<vector<double>> C11;
	for (vector<vector<double>>::size_type i = 0; i != C.size() / 2; ++i)
	{
		vector<double> ievc(C.size() / 2, 0);
		C11.push_back(ievc);
		for (vector<double>::size_type j = 0; j != C[0].size() / 2; ++j)
		{
			C11[i][j] = 0;
		}
	}
	vector<vector<double>> C12;
	for (vector<vector<double>>::size_type i = 0; i != C.size() / 2; ++i)
	{
		vector<double> ievc(C.size() / 2, 0);
		C12.push_back(ievc);
		for (vector<double>::size_type j = 0; j != C[0].size() / 2; ++j)
		{
			C12[i][j] = 0;
		}
	}
	vector<vector<double>> C21;
	for (vector<vector<double>>::size_type i = 0; i != C.size() / 2; ++i)
	{
		vector<double> ievc(C.size() / 2, 0);
		C21.push_back(ievc);
		for (vector<double>::size_type j = 0; j != C[0].size() / 2; ++j)
		{
			C21[i][j] = 0;
		}
	}
	vector<vector<double>> C22;
	for (vector<vector<double>>::size_type i = 0; i != C.size() / 2; ++i)
	{
		vector<double> ievc(C.size() / 2, 0);
		C22.push_back(ievc);
		for (vector<double>::size_type j = 0; j != C[0].size() / 2; ++j)
		{
			C22[i][j] = 0;
		}
	}
	//cout << "260" << endl;
	//the step of conquer,calculate the C11,C12,C21,C22,recursively
	vector<vector<double>> C_1 = matrices_multi(A11, B11);
	vector<vector<double>> C_2 = matrices_multi(A12, B21);
	for (vector<vector<double>>::size_type i = 0; i != C11.size(); ++i)
	{
		for (vector<double>::size_type j = 0; j != C11[i].size(); ++j)
		{
			C11[i][j] = C_1[i][j] + C_2[i][j];
		}
	}

	//calculate C12;
	vector<vector<double>> C_3 = matrices_multi(A11, B12);
	vector<vector<double>> C_4 = matrices_multi(A12, B22);
	for (vector<vector<double>>::size_type i = 0; i != C12.size(); ++i)
	{
		for (vector<double>::size_type j = 0; j != C12[i].size(); ++j)
		{
			C12[i][j] = C_3[i][j] + C_4[i][j];
		}
	}

	//calculate C21;
	vector<vector<double>> C_5 = matrices_multi(A21, B11);
	vector<vector<double>> C_6 = matrices_multi(A22, B21);
	for (vector<vector<double>>::size_type i = 0; i != C21.size(); ++i)
	{
		for (vector<double>::size_type j = 0; j != C21[i].size(); ++j)
		{
			C21[i][j] = C_5[i][j] + C_6[i][j];
		}
	}

	//C22
	vector<vector<double>> C_7= matrices_multi(A21, B12);
	vector<vector<double>> C_8= matrices_multi(A22, B22);
	for (vector<vector<double>>::size_type i = 0; i != C22.size(); ++i)
	{
		for (vector<double>::size_type j = 0; j != C22[i].size(); ++j)
		{
			C22[i][j] = C_7[i][j] + C_8[i][j];
		}
	}
	
	//the step of combine the C11 C12,C21,C22 to the maxtrix C
	for (vector<vector<double>>::size_type i = 0; i != C.size(); ++i)
	{
		if (i < C.size()/2)
		{
			for (vector<double>::size_type j = 0; j != C[i].size() / 2; ++j)
			{
				C[i][j] = C11[i][j];
			}
			for (vector<double>::size_type j = C[i].size() / 2; j != C[i].size(); ++j)
			{
				int index = j - C[i].size() / 2;
				C[i][j] = C12[i][index];
			}
		}
		else
		{
			int r_index = i - C.size() / 2;
			for (vector<double>::size_type j = 0; j != C[i].size() / 2; ++j)
			{
				C[i][j] = C21[r_index][j];
			}
			for (vector<double>::size_type j = C[i].size() / 2; j != C[i].size(); j++)
			{
				int col_index = j - C[i].size() / 2;
				C[i][j] = C22[r_index][col_index];
			}
		}
	}
	return C;




	






}