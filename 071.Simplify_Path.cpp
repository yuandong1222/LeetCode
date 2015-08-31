#include <list>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty() || path == "/") return "/";

        list<string> list;
        int current_pos = 0;
        int next_pos = 0;
        do {
            next_pos = path.find_first_of('/', current_pos + 1);
            if (next_pos == string::npos) next_pos = path.size();

            string s = path.substr(current_pos + 1, next_pos - current_pos - 1);
            if (s.empty() || s == ".") {
                //do nothing
            } else if (s == "..") {
                //cd ..
                if (!list.empty()) list.pop_back(); 
            } else {
                //part of the path
                list.push_back(s);
            }
            
            current_pos = next_pos;
        } while (next_pos != path.size());

        if (list.empty()) return "/";

        string result;
        while (!list.empty()) {
            result.append("/");
            result.append(list.front());
            list.pop_front();
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.simplifyPath("/../") << endl;
    return 0;
}

