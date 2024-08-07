class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num).substr(1);
    }

private:
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> below_100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", " Thousand", " Million", " Billion"};

    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return " " + below_20[num];
        else if (num < 100) return " " + below_100[num / 10] + helper(num % 10);
        else if (num < 1000) return helper(num / 100) + " Hundred" + helper(num % 100);
        else {
            int i = 0;
            string words = "";
            while (num > 0) {
                if (num % 1000 != 0) words = helper(num % 1000) + thousands[i] + words;
                num /= 1000;
                i++;
            }
            return words;
        }
    }
};