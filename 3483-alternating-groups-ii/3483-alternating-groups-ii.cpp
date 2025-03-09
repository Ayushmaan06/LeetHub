class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = (int)colors.size();
    vector<int> alt(n), prefix(2*n+1, 0);

    for(int i = 0; i < n; i++){
        alt[i] = (colors[i] != colors[(i+1) % n]) ? 1 : 0;
    }

    // Duplicate alt for handling circular wrap
    for(int i = 0; i < 2*n; i++){
        prefix[i+1] = prefix[i] + alt[i % n];
    }

    int count = 0;
    // Slide over prefix array to see if sum of length (k-1) is (k-1)
    for(int i = 0; i < n; i++){
        if(prefix[i + (k-1)] - prefix[i] == (k-1)) count++;
    }
    return count;
}
};
