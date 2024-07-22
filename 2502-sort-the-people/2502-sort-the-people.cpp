class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
    for (int i = 0; i < names.size(); ++i) {
        // Note: We use -heights[i] to sort in descending order by height
        people.push_back({-heights[i], names[i]});
    }

    // Sort the vector of pairs
    sort(people.begin(), people.end());

    // Extract the sorted names based on height
    vector<string> sortedNames;
    for (auto& p : people) {
        sortedNames.push_back(p.second);
    }

    return sortedNames;
    }
};