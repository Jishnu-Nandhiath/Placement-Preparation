#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> twoSum(vector<int>& nums, int target) {
    	
        for(int i=0; i<nums.size() ; i++)
        {
        	for(int j=i;j<nums.size();i++)
        	{
        		if(nums[i]+nums[j] == target)
        		{
        			return new int[] {i,j};
				}
			}
	
		}

        
    }
};
