#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows == 0) {
            return vector<vector<int> >();
        }
        
        vector<vector<int> > result(numRows);
        vector<int> line1(1);
        line1[0] = 1;
        result[0] = line1;
        
        for (int i = 1; i < numRows; i++) {
            vector<int> line(i + 1);
            vector<int> above_line = result[i - 1];
            
            line[0] = 1;
            for (int j = 1; j < i; j++) {
                line[j] = above_line[j] + above_line[j -1];
            }
            line[i] = 1;
            
            result[i] = line;
        }
        
        return result;
    }
    
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int> > result = solution.generate(5);
    
    for (vector<vector<int> >::iterator it1 = result.begin(); it1 != result.end(); it1++) {
        for (vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    
    return 0;
}
