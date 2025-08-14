class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>prices(n,INT_MAX);
        prices[src] = 0;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0], v = flights[i][1],price = flights[i][2];
            adj[u].push_back({v,price});            
        }
        queue<vector<int>>q;
        q.push({0,0,src});

        while(!q.empty()){
            int city = q.front()[2];
            int pprice = q.front()[1];
            int pstops = q.front()[0];
            q.pop();
            if(pstops > k ) continue;

            for(auto &it:adj[city]){
                
                int  city = it.first;
                int in_between_price = it.second;

                int tprice = in_between_price + pprice;
                int tstops = pstops + 1;
                if(prices[ city]  > tprice){
                    prices[ city] = tprice;
                    q.push({pstops+1,tprice, city});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};