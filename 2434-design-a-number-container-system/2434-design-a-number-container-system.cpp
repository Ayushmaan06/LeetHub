class NumberContainers {
public:
unordered_map<int,set<int>> num;
        unordered_map<long,long> idx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx.find(index)!=idx.end()){
            num[idx[index]].erase(index);
            if(num[idx[index]].empty())num.erase(idx[index]);
            idx[index]=number;
            num[number].insert(index);
        }
        else{
            idx[index]=number;
            num[number].insert(index);
        }
    }
    
    int find(int number) {
        if(num.find(number)==num.end())return -1;
        return *num[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */