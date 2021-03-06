#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int index = 0; index < nums.size(); index++) {
            result ^= nums[index];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> a(5);
    a[0] = 0;
    a[0] = 2;
    a[0] = 0;
    a[0] = 2;
    a[0] = 1;
    cout << solution.singleNumber(a) << endl;
    return 0;
}
