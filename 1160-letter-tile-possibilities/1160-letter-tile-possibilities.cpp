class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> result;  
        unordered_map<char, int> counter;  

        for (char tile : tiles) {
            counter[tile]++;
        }
        
        backtrack("", counter, result);
        
        return result.size();  
    }

private:
    void backtrack(string path, unordered_map<char, int>& counter, unordered_set<string>& result) {
        if (!path.empty()) {
            result.insert(path);
        }
        for (auto& [char_, count] : counter) {
            if (count > 0) {
                counter[char_]--;
                backtrack(path + char_, counter, result);
                // Backtrack and restore the count
                counter[char_]++;
            }
        }
    }
};


