#include <stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count += n % 2;
            n /= 2;
        }
        return count;
    }
};
int main(int argc, char** argv) {
    return 0;
}
