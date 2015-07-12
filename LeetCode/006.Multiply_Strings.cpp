#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution006 {
public:
    
    vector<int> string_to_vector(string s) {
        vector<int> l(s.size());
        
        int index = 0;
        for (index = 0; index < s.size(); index++) {
            l[s.size() - index] = s[index] - '0';
        }
        return l;
    }
    string vector_to_string(vector<int> a) {
        string s(a.size(), '0');
        int index = 0;
        for (index = 0; index < s.size(); index++) {
            s[index] = a[index] + '0';
        }
        return s;
    }
    
    string multiply(string num1, string num2) {
        vector<int> vector_a(num1.size());
        vector<int> vector_b(num2.size());
        vector<int> vector_sum(num1.size() + num2.size());
        
        vector_a = string_to_vector(num1);
        vector_b = string_to_vector(num2);
        
        //_multiply(vector_a, vector_b, vector_sum);
        
        
        string result;
        result = vector_to_string(vector_sum);
        
        return result;
    };
};

int main006(int argc, char* argv[]) {
    Solution006 solution;
    string a("1234567890");
    string b("1234567890");
    
    cout << solution.multiply(a, b) << endl;
    return 0;
}
