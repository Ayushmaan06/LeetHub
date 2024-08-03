class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int n = garbage.size();
    int totalTime = 0;
    int lastM = 0, lastP = 0, lastG = 0;
    int timeM = 0, timeP = 0, timeG = 0;

    // Calculate the total time to collect garbage at each house
    for (int i = 0; i < n; ++i) {
        for (char c : garbage[i]) {
            if (c == 'M') {
                timeM++;
                lastM = i;
            } else if (c == 'P') {
                timeP++;
                lastP = i;
            } else if (c == 'G') {
                timeG++;
                lastG = i;
            }
        }
    }

    // Calculate the travel time for each type of garbage
    for (int i = 0; i < n - 1; ++i) {
        if (i < lastM) {
            timeM += travel[i];
        }
        if (i < lastP) {
            timeP += travel[i];
        }
        if (i < lastG) {
            timeG += travel[i];
        }
    }

    // Sum up the total time
    totalTime = timeM + timeP + timeG;
    return totalTime;
}
    
};