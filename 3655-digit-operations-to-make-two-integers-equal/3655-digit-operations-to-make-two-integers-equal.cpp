class Solution {
public:
    vector<bool> generatePrimes(int a, int b) {

        a = max(a, 2);
        vector<bool> isPrime(b + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= b; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= b; j += i)
                    isPrime[j] = false;
            }
        }
    
        return isPrime;
    }
    int minOperations(int n, int m) {
        
        int d = floor(log10(n)) + 1; 
        int lowerBound = pow(10, d-1);
        int upperBound = pow(10, d) - 1;
        vector<bool> p = generatePrimes(2, upperBound);
        if(n==m && p[n])return -1;
        if(n==m)return n;
        if(p[n] || p[m]) return -1;
        vector<int> cs(upperBound+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        cs[n] = n;
        pq.push({n, n});
        
        while(!pq.empty()){
            auto [cost, u] = pq.top(); pq.pop();
            if(cost > cs[u]) continue;
            if(u == m)
                return cost;
                
            // Process each digit position.
            for(int i = 0; i < d; i++){
                int multiplier = pow(10, d-1-i);
                int digit = (u / multiplier) % 10;
                if(digit < 9) {
                    int v = u + multiplier;
                    if(v >= lowerBound && v <= upperBound && !p[v]){
                        if(cost + v < cs[v]){
                            cs[v] = cost + v;
                            pq.push({cs[v], v});
                        }
                    }
                }
                if(digit > 0) {
                    if(i == 0 && digit == 1) {
                    } else {
                        int v = u - multiplier;
                        if(v >= lowerBound && v <= upperBound && !p[v]){
                            if(cost + v < cs[v]){
                                cs[v] = cost + v;
                                pq.push({cs[v], v});
                            }
                        }
                    }
                }
            }   
        }
        return -1;
    }
};