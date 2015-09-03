#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int num2 = target -num;
            
            if (map.find(num2) != map.end()) {
                result.push_back(map[num2] + 1);
                result.push_back(i + 1);
                break;
            }

            map[num] = i;
        }
        return result;
    }
};
int main(int argc, char **argv) {
    return 0;
};
