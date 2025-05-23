class RandomizedSet {
public:
    vector<int>v;
    map<int,int>cnt;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(cnt.count(val)){
            return false;
        }
        v.push_back(val);
        cnt[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(cnt.count(val)){
            v[cnt[val]]=v[v.size()-1];
            cnt[v[v.size()-1]]=cnt[val];
             v.pop_back();
            cnt.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */