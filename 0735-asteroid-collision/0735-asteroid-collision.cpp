class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int i = 0; i < asteroids.size(); i++) {
            bool isDestroyed = false;
            while (!s.empty() && s.top() > 0 && asteroids[i] < 0) {
                if (s.top() < -asteroids[i]) { // Current asteroid is larger; pop the stack
                    s.pop();
                    continue;
                } else if (s.top() == -asteroids[i]) { // Equal size; both destroy
                    s.pop();
                }
                isDestroyed = true; // Current asteroid is destroyed in collision
                break;
            }
            if (!isDestroyed) {
                s.push(asteroids[i]);
            }
        }

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }
        return result;
    }
};