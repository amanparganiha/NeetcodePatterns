class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int ,int> freq;
        for(int x : nums) freq[x]++;

        //bucked index by frequency o....n
        vector<vector<int>> buckets(n+1);
        for(auto &pair : freq){
            int val = pair.first;
            int f = pair.second;
            buckets[f].push_back(val);
        }

        vector<int> result;
        //Iterate through highest frequency to lowest
        for(int f = n ; f >= 1 && (int)result.size() < k ; f--){
            for(int val : buckets[f]){
                result.push_back(val);
                if((int)result.size() == k) break ;
            }
        }
        return result;
    }
};
