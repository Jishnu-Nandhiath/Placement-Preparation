#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i+1; j < nums.size() ; j++ )
            {
                if(nums[i] + nums[j] == target)
                {
                return vector<int> {i,j};
                } 
            }           
        }
            throw invalid_argument("This is here for formality");
    }
};

int main()
{
	vector<int> out;
	vector<int> inputVector = {1,2,3};
	
	Solution SolutionObject = Solution();
	out = SolutionObject.twoSum(inputVector,5);	
	
	for(auto index = out.begin(); index != out.end() ; index++ )
	{
		cout<<*index<<",";
	}
	cout<<endl;
	return 0;
}
