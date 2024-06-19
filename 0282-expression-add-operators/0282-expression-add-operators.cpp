
class Solution {
public:
    int evaluateExpression(const std::string& expr) {
        long long prev = 0, curr = 0;
        char operation = '+';
        std::vector<long long> nums;
        
        for (size_t i = 0; i < expr.size(); ++i) {
            char ch = expr[i];
            
            if (isdigit(ch)) {
                curr = curr * 10 + (ch - '0');
            }
            
            if (!isdigit(ch) || i == expr.size() - 1) {
                if (operation == '+') {
                    nums.push_back(curr);
                } else if (operation == '-') {
                    nums.push_back(-curr);
                } else if (operation == '*') {
                    long long last = nums.back();
                    nums.pop_back();
                    nums.push_back(last * curr);
                }
                
                operation = ch;
                curr = 0;
            }
        }
        
        long long result = 0;
        for (long long num : nums) {
            result += num;
        }
        
        return result;
    }

    void solve(const std::string& num, const std::string& expr, std::vector<std::string>& results, int target, int pos, long long prev, long long curr, char operation) {
        if (pos == num.size()) {
            if (prev + curr == target) {
                results.push_back(expr);
            }
            return;
        }
        
        for (size_t i = pos; i < num.size(); ++i) {
            if (i > pos && num[pos] == '0') break;  // Skip leading zeroes
            std::string part = num.substr(pos, i - pos + 1);
            long long value = std::stoll(part);

            if (pos == 0) {
                solve(num, part, results, target, i + 1, 0, value, '+');
            } else {
                solve(num, expr + "+" + part, results, target, i + 1, prev + curr, value, '+');
                solve(num, expr + "-" + part, results, target, i + 1, prev + curr, -value, '-');
                solve(num, expr + "*" + part, results, target, i + 1, prev, curr * value, operation);
            }
        }
    }

    std::vector<std::string> addOperators(std::string num, int target) {
        std::vector<std::string> results;
        if (num.empty()) return results;
        solve(num, "", results, target, 0, 0, 0, '+');
        return results;
    }
};
