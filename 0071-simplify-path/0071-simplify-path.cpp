class Solution {
public:
    string simplifyPath(string path) {
    vector<string> stack;
    stringstream ss(path);
    string temp;

    while (getline(ss, temp, '/')) {
        if (temp == "" || temp == ".") continue;
        if (temp == ".." && !stack.empty()) stack.pop_back();
        else if (temp != "..") stack.push_back(temp);
    }

    string result = "";
    for (auto &str : stack) result += "/" + str;
    return result.empty() ? "/" : result;
}
};