class Solution {
public:
    bool isPathCrossing(string path) {
        // Custom hash function for pair<int,int>
        struct pair_hash {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };

        unordered_set<pair<int, int>, pair_hash> s;
        pair<int, int> p = {0, 0};
        s.insert(p); // Start position also needs to be inserted

        for (char c : path) {
            if (c == 'N') p.second += 1;
            if (c == 'S') p.second -= 1;
            if (c == 'E') p.first += 1;
            if (c == 'W') p.first -= 1;

            if (s.count(p)) return true; // Already visited
            s.insert(p);
        }

        return false;
    }
};
