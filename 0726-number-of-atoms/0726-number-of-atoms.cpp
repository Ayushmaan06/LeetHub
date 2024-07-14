class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    string countOfAtoms(string formula) {
        map<string, int> atomCounts;
        stack<map<string, int>> stack;
        int i = 0;
        while (i < formula.length()) {
            if (formula[i] == '(') {
                stack.push(atomCounts);
                atomCounts.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int val = 0;
                while (i < formula.length() && isDigit(formula[i])) {
                    val = val * 10 + (formula[i] - '0');
                    i++;
                }
                val = max(val, 1);
                if (!stack.empty()) {
                    map<string, int> temp = atomCounts;
                    atomCounts = stack.top();
                    stack.pop();
                    for (auto &pair : temp) {
                        atomCounts[pair.first] += pair.second * val;
                    }
                }
            } else {
                int start = i++;
                while (i < formula.length() && islower(formula[i])) i++;
                string atom = formula.substr(start, i - start);
                int val = 0;
                while (i < formula.length() && isDigit(formula[i])) {
                    val = val * 10 + (formula[i] - '0');
                    i++;
                }
                val = max(val, 1);
                atomCounts[atom] += val;
            }
        }

        string result;
        for (auto &pair : atomCounts) {
            result += pair.first;
            if (pair.second > 1) result += to_string(pair.second);
        }
        return result;
    }
};