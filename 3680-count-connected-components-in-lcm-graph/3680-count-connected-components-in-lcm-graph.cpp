class DSU {
    vector<int> parent, rnk, sz;
public:
    DSU(int n){
        parent.resize(n);
        rnk.assign(n,0);
        sz.assign(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int a){
        if(parent[a]!=a) parent[a]=find(parent[a]);
        return parent[a];
    }
    void unionByRank(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(rnk[a]<rnk[b]) swap(a,b);
        parent[b]=a;
        if(rnk[a]==rnk[b]) rnk[a]++;
    }
};

class Solution {
public:
    int gcd(int a,int b){ return b==0? a : gcd(b,a%b); }
    long long lcmLL(int a,int b){ return 1LL*a/gcd(a,b)*b; }

    int countComponents(vector<int>& nums,int t){
        DSU dsu(t+1);
        int n = nums.size();
        for(int i : nums){
            if(i<=t){
                for(int j=i;j<=t;j+=i)dsu.unionByRank(i,j);
            }
        }
        set<int> st;
        int ans=0;
        for(int i : nums){
            if(i>t)ans++;
            else st.insert(dsu.find(i));
        }
        ans+=st.size();
        return ans;
    }
};