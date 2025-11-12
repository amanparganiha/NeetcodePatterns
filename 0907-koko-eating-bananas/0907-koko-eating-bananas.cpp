class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin() , piles.end());
        int res = r;

        while(l <= r){
            int k = l + (r- l) / 2;

            long long totalTime = 0;
            for(int it : piles){
                totalTime += (it + k -1) / k;
            }

            if(totalTime <= h){
                res = k;
                r = k - 1;
            }else {
                l = k+ 1;
            }
        }
        return res;

    }
};