#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string r;
        int balance = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (balance > 0) {
                    r += ch;
                }
                balance++;
            } else {
                balance--;
                if (balance > 0) {
                    r += ch;
                }
            }
            
        }
        return r;
    }
};


