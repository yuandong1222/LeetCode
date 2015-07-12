#include <vector>
#include <iostream>

using namespace std;

class Solution003 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lineA(rowIndex + 1);
        
        lineA[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            lineA[i] = 1;
            for (int j = i - 1; j > 0; j--) {
                lineA[j] = lineA[j] + lineA[j - 1];
            }
        }
        
        return lineA;
    }
    
};

int main003(int argc, char* argv[]) {
    Solution003 solution;
    vector<int> result = solution.getRow(4);
    
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
