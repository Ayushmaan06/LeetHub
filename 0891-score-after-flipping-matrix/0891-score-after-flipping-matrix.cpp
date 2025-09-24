class Solution {
public:
    int binaryVectorToDecimal(const std::vector<int>& binaryVector) {
        int decimalNumber = 0;
        int size = binaryVector.size();
        for (int i = 0; i < size; ++i) {
            decimalNumber = decimalNumber * 2 + binaryVector[i];
        }
        return decimalNumber;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            if(!grid[i][0]){
                for(int j = 0 ; j < m ; j++) grid[i][j]=grid[i][j]^1;
            }
        }
        for(int i = 0 ; i < m ; i++){
            int oc=0,zc=0;
            for(int j = 0 ; j < n ; j++){
                if(grid[j][i])oc++;
                else zc++;
            }
            if(zc>oc){
                for(int j = 0 ; j < n ; j++) grid[j][i]=grid[j][i]^1;
            }
        }
        int ans=0;
        for(vector<int> g : grid){
            ans+=binaryVectorToDecimal(g);
        }
        return ans;
    }
};