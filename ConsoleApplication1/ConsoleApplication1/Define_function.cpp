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