#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAlphanumeric(char c) {
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        
        int front = 0;
        int end = (int)(s.size()) - 1;
        while (front <= end) {
            char front_char = s[front];
            if (!isAlphanumeric(front_char)) {
                front++;
                continue;
            } else if (front_char >= 'A' && front_char <= 'Z') {
                front_char += 'a' - 'A';
            }
            
            char end_char = s[end];
            if (!isAlphanumeric(end_char)) {
                end--;
                continue;
            } else if (end_char >= 'A' && end_char <= 'Z') {
                end_char += 'a' - 'A';
            }
            
            if (front_char != end_char)
                return false;
            front++;
            end--;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    string s("a.");
    cout << solution.isPalindrome(s) << endl;
    return 0;
}
