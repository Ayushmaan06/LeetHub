class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp;  // taskId -> {userId, priority}
    unordered_set<int> removedTasks; 
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
                   function<bool(pair<int, int>, pair<int, int>)>> pq;

    TaskManager(vector<vector<int>>& tasks) 
        : pq([](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) {
                return a.first < b.first;  // descending order of priority (first)
            } else {
                return a.second < b.second;  // descending order of taskId (second)
            }
        }) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            mp[taskId] = {userId, priority};
            pq.push({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        if (mp.find(taskId) != mp.end()) {
            mp[taskId].second = newPriority;  
            pq.push({newPriority, taskId});   
        }
    }

    void rmv(int taskId) {
        if (mp.find(taskId) != mp.end()) {
            removedTasks.insert(taskId);  
            mp.erase(taskId);  
        }
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            auto it = mp.find(taskId);
            if (it == mp.end() || it->second.second != priority) {
                pq.pop();
                continue;
            }

            int userId = it->second.first;
            pq.pop();
            rmv(taskId); 
            return userId;  
        }
        return -1;  
    }
};