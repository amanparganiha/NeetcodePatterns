class Solution {
  public:
    pair<int, int> maxSum(vector<int> &arr, int k) {
        
        sort(arr.begin() , arr.end());
        
        int l = 0;
        int r = arr.size() - 1;
        int bestSum = -1;
        pair<int , int> ans = {-1, -1};
        
        while(l < r){
            int sum = arr[l] + arr[r];
            
            if(sum < k){
                if(sum > bestSum){
                    bestSum = sum;
                    ans = {arr[l] , arr[r]};
                }else if(sum == bestSum){
                    if(abs(arr[l] - arr[r]) > abs(ans.first - ans.second))
                    ans = {arr[l] , arr[r]};
                }
                l++;
            }else{
                r--;
            }
        }
        return ans;
        
    }
};
