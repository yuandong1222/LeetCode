#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > results(1 << nums.size(), vector<int>());
        for (int i = 0; i < results.size(); i++)
            for (int j = 0; j < nums.size(); j++) 
                if ((1 << j) & i)
                    results[i].push_back(nums[j]);

        return results;
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    Solution solution;
    vector<vector<int> > result = solution.subsets(nums);
    cout << result.size() << endl;

    return 0;
}
