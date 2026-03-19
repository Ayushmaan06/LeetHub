class Solution {
public:
    int cc(char c){
        if(c=='X')return 1;
        if(c=='Y')return -1;
        return 0;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans=0, n = grid.size(),m=grid[0].size();
        int s= cc(grid[0][0]);
        
        vector<vector<int>> b(n,vector<int>(m,INT_MAX)),x(n,vector<int>(m,0));
        b[0][0]=s;
        if(s==1)x[0][0]=1;
        bool f=false;
        if(s==1)f=true;
        for(int i = 1 ; i < n ; i++){
            s+=cc(grid[i][0]);
            x[i][0]|=x[i-1][0];
            if(cc(grid[i][0])==1)f=true,x[i][0]=1;
            b[i][0]=s;
            if(s==0 && f)ans++;
        }
        s= cc(grid[0][0]);
        f=false;
        if(s==1)f=true;
        for(int i = 1 ; i < m ; i++){
            s+=cc(grid[0][i]);x[0][i]|=x[0][i-1];if(cc(grid[0][i])==1)f=true,x[0][i]=1;
            b[0][i]=s;
            if(s==0 && f)ans++;
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                b[i][j] = cc(grid[i][j]) + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
                x[i][j]=x[i-1][j]|x[i][j-1];
                if(cc(grid[i][j])==1)x[i][j]=1;
                if(b[i][j]==0 && x[i][j])ans++;
            }
        }
        return ans;
    }
};