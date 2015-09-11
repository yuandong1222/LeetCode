#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int sign = 1;
        int num = 0;
        int result = 0;

        signs.push(1);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                result = result + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                result = result + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }

        if (num) {
            result = result + signs.top() * sign * num;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    return 0;
}
