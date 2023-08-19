#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <string>
#include "solutions.h"

using namespace std;


//solution class function definations


//constructors


//other member funcitons

set<vector<int>> solution::getAllZeroSumSubarrays(vector<int> const& nums)
{
	set<vector<int>> subarrays;


	int start = 0; //starting to add numbers to tmp for chcking them  
	int end = start;  //ending  point


	while (!(start >= nums.size())) {



		//  **potential error**
		vector<int>tmp(nums.begin() + start, nums.begin() + end + 1); //for storing the numbers temporary and checking their sum  
		int sum = accumulate(tmp.begin(), tmp.end(), 0);

		if (sum == 0) {
			//adding current zero sum subvec to the set and clearing it for next iteration
			subarrays.insert(tmp);
			tmp.clear();
			end++;

			if (end >= nums.size()) {
				start++;
				end = start;
			}


		}
		else {
			end++;

			//if we checked all of subarray in the vector and didn't find matching one we would add one to start to start a new window
			if (end >= nums.size()) {
				start++;
				end = start;
				tmp.clear();
			}

			tmp.clear();

		}

	}




	return subarrays;

}

//Check if a given string can be derived from another string by circularly rotating it. The rotation can be in a clockwise or anti-clockwise rotation.
bool solution::is_subs(string org, string driven) {
	string clockwise, anti_clockwise;
	int unit = 1;

	for (int i = 0; i < org.size(); i++) {

		clockwise = "";
		for (int i = 0; i < org.size(); i++) {

			int indx = i - unit;

			if (indx > org.size() - 1) {
				while (indx > org.size() - 1) {
					indx += org.size();
				}
				clockwise += org[indx];
			}
			else if (indx < 0) {
				while (indx < 0) {
					indx += org.size();
				}
				clockwise += org[indx];
			}
			else
				clockwise += org[indx];
			if (driven == clockwise) {
				return true;
			}


		}
		unit++;
	}
	for (int i = 0; i < org.size(); i++) {

		anti_clockwise = "";
		for (int i = 0; i < org.size(); i++) {

			int indx = i + unit;

			if (indx > org.size() - 1) {
				while (indx > org.size() - 1) {
					indx -= org.size();
				}
				anti_clockwise += org[indx];
			}
			else if (indx < 0) {
				while (indx < 0) {
					indx -= org.size();
				}
				anti_clockwise += org[indx];
			}
			else
				anti_clockwise += org[indx];
			if (driven == anti_clockwise) {
				return true;
			}


		}
		unit++;
	}

	return  false;

}


pair<int, int> solution::findsum(vector<int> nums, int target) {

	pair<int, int> tar_pair; tar_pair.first = -1; tar_pair.second = -1;

	int start = 0;
	int end = 1;

	while (start != nums.size() - 1) {

		int current_pair_sum = nums[start] + nums[end];
		if (current_pair_sum == target) {
			tar_pair.first = nums[start];
			tar_pair.second = nums[end];
			break;
		}
		end++;
		if (end > nums.size() - 1) {
			start++;
			end = start + 1;
		}
	}
	
	return tar_pair;

}

bool solution::zerosum(vector<int> nums) {

	if (nums.size() == 1) {
		if (nums[0] == 0) {
			return true;
		}
		return false;
	}

	int start = 0;
	int end = 1;
	while (start < nums.size() - 1) {
		//must be sum of a range 
		int current_sum = accumulate(nums.begin() + start, nums.begin() + end + 1, 0);
		if (current_sum == 0) {
			return true;
		}
		end++;
		if (end >= nums.size() - 1) {
			start++;
			end = start + 1;
		}
	}

	return false;
}

//Given an `N × N` integer matrix, rotate the matrix by 90 degrees in a clockwise direction. The transformation should be done in-place and in quadratic time
vector<vector<int>> solution::rotate_vecs_90(vector<vector<int>> nums) {

	vector<vector<int>> rotated;
	vector<int> tmp;
	int which_num = 0;
	
	while (which_num < nums.size()) {
		for (int i = nums.size() - 1; i >= 0; i--) {
			tmp.push_back(nums[i][which_num]);	
		}
		rotated.push_back(tmp);
		tmp.clear();
		which_num++;
	}


	return rotated;
}


//<--------------------------------------------------------------------------------------->





//test class functions definations


//constructors

test::test(zerosum func, vector<int> test_value, bool expected_result){
	func = &solution::zerosum;
	bool result = func(test_value);
	(result == expected_result) ? passed = true : passed = false;
}

test::test(rotate_vecs_90 func, vector<vector<int>> test_value, vector<vector<int>> expected_result) {
	func = &solution::rotate_vecs_90;
	vector<vector<int>> result = func(test_value);
	(result == expected_result) ? passed = true : passed = false;
}

test::test(findsum func, vector<int> test_value_1, int test_value_2, pair<int, int> expected_result) {
	func = &solution::findsum;
	pair<int, int> result = func(test_value_1, test_value_2);
	(result == expected_result) ? passed = true : passed = false;
}

test::test(is_subs func, string test_value_1, string test_value_2, bool expected_result){
	func = &solution::is_subs;
	bool result = func(test_value_1, test_value_2);
	(result == expected_result) ? passed = true : passed = false;

}

test::test(getAllZeroSumSubarrays func, vector<int> const& test_value, set<vector<int>> expected_result) {
	func = &solution::getAllZeroSumSubarrays;
	set<vector<int>> result = func(test_value);
	(result == expected_result) ? passed = true : passed = false;
}

//other member functions

void test::get_result(){
	(passed == true) ? cout << "test result: " << "passed" << endl : cout << "test result: " << "failed" << endl;
}


//<--------------------------------------------------------------------------------------->
                                          
