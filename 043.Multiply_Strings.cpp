#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    
    vector<int> string_to_vector(string s) {
        vector<int> l(s.size());
        
        int index = 0;
        for (index = 0; index < s.size(); index++) {
            l[s.size() - index - 1] = s[index] - '0';
        }
        return l;
    }
    string vector_to_string(vector<int> a) {
        int size = a.size();
        while (a[size - 1] == 0) {
            size--;
        }
        
        string s(size, '0');
        for (int i = 0; i < size; i++) {
            s[s.size() - i -1] = a[i] + '0';
        }
        return s;
    }
    
    void _multiply(vector<int> a, vector<int> b, vector<int>* sum) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                (*sum)[i + j] += a[i] * b[j];
            }
        }
        
        for (int i = 0; i < sum->size() - 1; i++) {
            (*sum)[i + 1] += (*sum)[i] / 10;
            (*sum)[i] %= 10;
        }
    }
    
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        vector<int> vector_a(num1.size());
        vector<int> vector_b(num2.size());
        vector<int> vector_sum(num1.size() + num2.size());
        
        vector_a = string_to_vector(num1);
        vector_b = string_to_vector(num2);
        
        _multiply(vector_a, vector_b, &vector_sum);
        
        string result;
        result = vector_to_string(vector_sum);
        
        return result;
    };
};

int main(int argc, char* argv[]) {
    Solution solution;
    string a("0");
    string b("0");
    
    cout << solution.multiply(a, b) << endl;
    return 0;
}
