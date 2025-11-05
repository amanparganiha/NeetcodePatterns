class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 ) return 0;
        unordered_set <int> st;
        int longest = 1;
        
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int length = 1;
                while(st.find(it+length) != st.end()){
                    length++;
                }
                longest = max(longest , length);
            }
        }
        return longest;
    }
};
