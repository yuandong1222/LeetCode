#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPathForCell(
            vector<vector<int> >& matrix,
            vector<vector<int> >& result,
            int i,
            int j) {

        if (result[i][j] != 0) {
            return result[i][j];
        }

        result[i][j] = 1;
        if (i > 0 && matrix[i - 1][j] < matrix[i][j]) {
            result[i][j] = max(result[i][j], 1 + longestIncreasingPathForCell(matrix, result, i - 1, j));
        }
        if (i < matrix.size() - 1 && matrix[i + 1][j] < matrix[i][j]) {
            result[i][j] = max(result[i][j], 1 + longestIncreasingPathForCell(matrix, result, i + 1, j));
        }
        if (j > 0 && matrix[i][j - 1] < matrix[i][j]) {
            result[i][j] = max(result[i][j], 1 + longestIncreasingPathForCell(matrix, result, i, j - 1));
        }
        if (j < matrix[0].size() - 1 && matrix[i][j + 1] < matrix[i][j]) {
            result[i][j] = max(result[i][j], 1 + longestIncreasingPathForCell(matrix, result, i, j + 1));
        }

        return result[i][j];
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int max = 0;

        vector<vector<int> > result(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            result[i].resize(matrix[0].size());
            for (int j = 0; j < matrix[0].size(); j++) {
                result[i][j] = 0;
            }
        }

        for (int i = 0; i <  matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int cell_max = longestIncreasingPathForCell(matrix, result, i, j);
                max = cell_max > max ? cell_max : max;
            }
        }

        return max;
    }
};

int main(int argc, char** argv) {
    vector<vector<int> > result(3);
    for (int i = 0; i < 3; i++) {
        result[i].resize(3);
    }
    result[0][0] = 9;
    result[0][1] = 9;
    result[0][2] = 4;

    result[1][0] = 6;
    result[1][1] = 6;
    result[1][2] = 8;

    result[2][0] = 2;
    result[2][1] = 1;
    result[2][2] = 1;

    Solution solution;
    return solution.longestIncreasingPath(result);
}
