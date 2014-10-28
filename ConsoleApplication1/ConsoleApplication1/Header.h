#include<iostream>
#include<string>
#include<vector>
using namespace std;
//find the a maximum subarray in arry A using O(nlgn) running time
//the idea  to handle the problem is divide and conquer
//author:Haoxin Sun data:10-28-2014
class maximum_subarray
{
public:
	maximum_subarray(){}
	maximum_subarray(vector<int>::iterator low, vector<int>::iterator high) :low(low), high(high), sum(calculate_sum()){}
	vector<int>::iterator get_low(){ return low; }
	vector<int>::iterator get_high(){ return high; }
	double get_sum(){ return sum; }
private:
	double calculate_sum();
	vector<int>::iterator low;
	vector<int>::iterator high;
	double sum;
};
maximum_subarray Find_maximum_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator high);
maximum_subarray Max_cross_subarray(vector<int> A, vector<int>::iterator low, vector<int>::iterator middle, vector<int>::iterator high);
// a linear running time to handle maximum subarray
maximum_subarray Linear_find_max(vector<int> A, vector<int>::iterator low, vector<int>::iterator high);