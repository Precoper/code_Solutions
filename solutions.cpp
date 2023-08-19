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

//Given an integer array, find a pair with the maximum product in it.
pair<int, int> solution::max_product_finder(vector<int> nums) {


	pair<int, int> max_pair; max_pair.first = 0; max_pair.second = 0;

	if (nums.size() <= 1) {
		max_pair.first = -1;
		max_pair.second = -1;
		return max_pair;
	}


	int start = 0;
	int end = start + 1;

	while (start < nums.size() - 1) {
		int max_pair_sum = max_pair.first + max_pair.second;

		if (end < nums.size() - 1) {
			int current_pair_sum = nums[start] + nums[end];
			int next_pair_sum = nums[start] + nums[end + 1];
			if (abs(current_pair_sum) >= abs(next_pair_sum) && abs(current_pair_sum) >= abs(max_pair_sum)) {
				max_pair.first = nums[start];
				max_pair.second = nums[end];
			}
			else if (abs(current_pair_sum) <= abs(next_pair_sum) && abs(next_pair_sum) >= abs(max_pair_sum)) {
				max_pair.first = nums[start];
				max_pair.second = nums[end + 1];
			}
			end++;
		}
		else if (start == nums.size() - 2) {
			int current_pair_sum = nums[start] + nums[end];
			if (abs(current_pair_sum) >= abs(max_pair_sum)) {
				max_pair.first = nums[start];
				max_pair.second = nums[end];

			}
			start++;
			end = start + 1;
		}
		else {
			start++;
			end = start + 1;
		}
	}


	return max_pair;

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
                                          
