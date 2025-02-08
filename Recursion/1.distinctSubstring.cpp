#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
    public:
        void solve(string str1, set<string>& d1, int index, string op) {
                int n = str1.size();
                
                if (index >= n) {
                        d1.insert(op);
                        return;
                }
                
                solve(str1, d1, index + 1, op);
                op += str1[index];
                solve(str1, d1, index + 1, op);
                op.pop_back();
        }

        string betterString(string str1, string str2) {
                set<string> d1;
                string op = "";
                int index = 0;
                
                solve(str1, d1, index, op);
                
                set<string> d2;
                string op2 = "";
                int index2 = 0;
                
                solve(str2, d2, index2, op2);
                
                if (d1.size() >= d2.size()) {
                        return str1;
                } else {
                        return str2;
                }
        }
};

int main() {
        Solution solution;
        string str1 = "abc";
        string str2 = "abcd";
        cout << "Better string: " << solution.betterString(str1, str2) << endl;
        return 0;
}