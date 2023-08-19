#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

#ifndef SOLUTIONS_H
#define SOLUTIONS_H



class solution {

public:

	//solutions
	 
	 static set<vector<int>> getAllZeroSumSubarrays(vector<int> const& nums);

	 static bool is_subs(string org, string driven);

	 static pair<int, int> max_pair_finder(vector<int> nums);

	 static pair<int, int> findsum(vector<int> nums, int target);

	 static bool zerosum(vector<int> nums);

	 static vector<vector<int>> rotate_vecs_90(vector<vector<int>> nums);

};


class test {

private:
	
	//functions type definations
	
	typedef vector<vector<int>>(*rotate_vecs_90)(vector<vector<int>>);
	typedef bool(*zerosum)(vector<int>);
	typedef pair<int, int>(*findsum)(vector<int>, int);
	typedef bool(*is_subs)(string, string);
	typedef set<vector<int>>(*getAllZeroSumSubarrays)(vector<int> const&);
	typedef pair<int, int>(*max_pair_finder)(vector<int>);


	//result
	
	bool passed;

public:
	
	//tests
	
	test(rotate_vecs_90 func, vector<vector<int>> test_value, vector<vector<int>> expected_result);
	test(zerosum func, vector<int> test_value, bool expected_result);
	test(is_subs func, string test_value_1, string test_value_2, bool expected_result);
	test(getAllZeroSumSubarrays func, vector<int> const& test_value, set<vector<int>> expected_result);
	test(findsum func, vector<int> test_value_1, int test_value_2, pair<int, int> expected_result);


    //other member functions
	
	void get_result();
		
};

#endif

using namespace std;

#ifndef SOLUTIONS_H
#define SOLUTIONS_H


pair<int, int> pairfinder(vector<int> nums, int tar);

set<vector<int>> getAllZeroSumSubarrays(vector<int> const& nums);

bool is_subs(string org, string driven);

pair<int, int> max_pair_finder(vector<int> nums);

pair<int, int> findsum(vector<int> nums, int target);

bool zerosum(vector<int> nums);

vector<vector<int>> rotate_vecs_90(vector<vector<int>> nums);


#endif
