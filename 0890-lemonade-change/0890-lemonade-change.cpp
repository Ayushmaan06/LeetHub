class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> m;
        m[5]=0;
        m[10]=0;
        m[20]=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                m[5]++;
            }
            if(bills[i]==10){
                if(m[5]==0) return false;
                else{
                    m[5]--;
                    m[10]++;
                }
            }
            if(bills[i]==20){
                if(((m[5]<1)||( m[10]<1))){
                    if(m[5]<3){
                        return false;
                    }
                    else{
                        m[5]-=3;
                        m[20]++;
                    }
                }
                else{
                    m[5]--;
                    m[10]--;
                    m[20]++;
                } 
            }
        }
        return true;
    }
};