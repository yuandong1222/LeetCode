#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
private:
    void _subset(vector<int>& nums, int start,
                 vector<int> current,
                 vector<vector<int> >& result,int result_length) {
        if (result_length == 0) {
            result.push_back(current);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            _subset(nums, i + 1, current, result, result_length - 1);
            current.pop_back();
        }
    }
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++) {
            _subset(nums, 0, current, result, i);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<vector<int> > result;
    Solution solution;
    result = solution.subsets(nums);
    
    cout << result.size() << endl;

    return 0;
}
