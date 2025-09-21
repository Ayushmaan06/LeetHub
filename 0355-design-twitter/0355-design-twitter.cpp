class Twitter {
public:
    int timeStamp;
    unordered_map<int, unordered_set<int>> f; // followers
    unordered_map<int, vector<pair<int,int>>> mp; // uid -> (time, tweetId)
    
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; // (time, tweetId)
        for (auto &tw : mp[userId]) {
            pq.push(tw);
        }
        for (int followee : f[userId]) {
            for (auto &tw : mp[followee]) {
                pq.push(tw);
            }
        }
        vector<int> res;
        int count = 0;
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // avoid self-follow
        f[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};
