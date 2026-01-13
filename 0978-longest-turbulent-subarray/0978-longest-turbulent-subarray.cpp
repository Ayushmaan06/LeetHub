class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int a=0,ca=0,caa=0,aa=0,n=arr.size();
        for(int i = 0 ; i < n-1 ; i++){
            if(i%2){
                if(arr[i] > arr[i+1])ca++;
                else ca=0;
            }
            else{
                if(arr[i] < arr[i+1])ca++;
                else ca=0;
            }
            a=max(a,ca);
        }
        for(int i = 0 ; i < n-1 ; i++){
            if(i%2){
                if(arr[i] < arr[i+1])caa++;
                else caa=0;
            }
            else{
                if(arr[i] > arr[i+1])caa++;
                else caa=0;
            }
            aa=max(aa,caa);
        }
        return max(a,aa)+1;
    }
};