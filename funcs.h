#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

#ifndef FUNCS_H
#define FUNCS_H


pair<int, int> pairfinder(vector<int> nums, int tar);

set<vector<int>> getAllZeroSumSubarrays(vector<int> const& nums);

bool is_subs(string org, string driven);

pair<int, int> max_pair_finder(vector<int> nums);

pair<int, int> findsum(vector<int> nums, int target);

bool zerosum(vector<int> nums);

vector<vector<int>> rotate_vecs_90(vector<vector<int>> nums);


#endif
