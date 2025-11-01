class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> hashSet;
        for(auto it : nums){
            if(hashSet.find(it) != hashSet.end()){
               return true; 
            }
            hashSet.insert(it);
        }
        return false;
    }
};
