#include <vector>

using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int p = nums[left], l = left + 1, r = right - 1;
        while (l <= r) {
            if (nums[l] < p && nums[r] > p) swap(nums[l], nums[r]);
            if (nums[l] >= p) l++;
            if (nums[r] <= p) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos = 0, left = 0, right = nums.size();
        while (true) {
            pos = partition(nums, left, right);
            if (pos == k - 1) break;
            if (pos <  k - 1) left = pos + 1;
            if (pos >  k - 1) right = pos;
        }
        return nums[pos];
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums {7, 6, 5, 4, 3, 2, 1};
    int r = solution.findKthLargest(nums, 5);
    return 0;
};
