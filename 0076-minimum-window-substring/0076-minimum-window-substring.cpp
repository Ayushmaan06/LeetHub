class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c : t)mp[c]++;
        int i=0,j=0,n=s.length();
        while(i < n && mp.find(s[i]) == mp.end()) i++; 
        j=i;
        int tc=t.length();
        queue<int> q;
        vector<pair<int,int>> vp;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                if(mp[s[j]] > 0) tc--;
                mp[s[j]]--;
                q.push(j);
            }
            while(tc==0){
                vp.push_back({j-i+1,i});
                
                mp[s[i]]++;
                if(mp[s[i]] > 0) tc++; 
                q.pop(); 
                
                if(!q.empty()) i = q.front();
                else i++; 
            }
            j++;
        }
        if(vp.empty()) return "";
        sort(vp.begin(),vp.end());
        return s.substr(vp[0].second,vp[0].first);
    }
};