#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            cut[i] = i - 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; i - j >= 0 && i + j < n; j++) {
                if (s[i + j] != s [i - j]) {
                    break;
                }
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j] + 1);
            }
            for (int j = 1; i - j + 1 >= 0 && i + j < n; j++) {
                if (s[i + j] != s [i - j + 1]) {
                    break;
                }
                cut[i + j + 1] = min(cut[i + j + 1], cut[i - j + 1] + 1);
            }
        }

        return cut[n];
    }
};

int main(int argc, char** argv) {
    Solution solution;
    printf("%d\n", solution.minCut("aab"));
    printf("%d\n", solution.minCut("aba"));
    printf("%d\n", solution.minCut("aabbaacc"));
}
