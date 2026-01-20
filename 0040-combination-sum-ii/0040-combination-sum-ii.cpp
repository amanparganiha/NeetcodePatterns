class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> cur;
        dfs(0 , cur , 0 , candidates , target);
        return res;
    }

    void dfs(int idx , vector<int> &cur , int sum,
            vector<int> &nums, int target){
                if(sum == target){
                    res.push_back(cur);
                    return;
                }

                for(int j = idx; j < nums.size() ; j++){
                    
                    if(j >idx && nums[j] == nums[j-1]) continue;

                    if(sum + nums[j] > target) break;

                    cur.push_back(nums[j]);
                    dfs(j+1 , cur , sum + nums[j] , nums , target);
                    cur.pop_back();
                }
            }

};