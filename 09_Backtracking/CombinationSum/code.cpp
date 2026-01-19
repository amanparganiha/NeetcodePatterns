class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        dfs(0 , {} , 0 , candidates , target);
        return res;
    }

    void dfs(int i , vector<int> cur , int total , vector<int> &candidates , int target){
        if(total == target){
            res.push_back(cur);
            return;
        }
        
        for(int j = i; j < candidates.size() ; j++){
            if(total + candidates[j] > target){
                return ;
            }
            cur.push_back(candidates[j]);
            dfs(j , cur , total + candidates[j] , candidates , target);
            cur.pop_back();
        }
    }
};
