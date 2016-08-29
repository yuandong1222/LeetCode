#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0], min = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = max;
            max = std::max(nums[i], std::max(nums[i] * max, nums[i] * min));
            min = std::min(nums[i], std::min(nums[i] * temp, nums[i] * min));
            result = max > result ? max : result;
        }
        return result;
    }
};
int main(int argc, char** argv) {
    return 0;
}
