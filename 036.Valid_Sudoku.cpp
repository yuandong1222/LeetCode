#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        set<char> set;

        //check lines
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (set.count(c) != 0) return false;
                if (c != '.') set.insert(c);
            }
            set.clear();
        }
        
        //check columns
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (set.count(c) != 0) return false;
                if (c != '.') set.insert(c);
            }
            set.clear();
        }

        //check sub squares
        for (int i_offset = 0; i_offset < 3; i_offset++) {
            for (int j_offset = 0; j_offset < 3; j_offset++) {

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[i + i_offset * 3][j + j_offset * 3];
                        if (set.count(c) != 0) return false;
                        if (c != '.') set.insert(c);
                    }
                }
                set.clear();

            }
        }
        
        return true;
    }
};

int main(int argc, char **argv) {
    return 0;
}

