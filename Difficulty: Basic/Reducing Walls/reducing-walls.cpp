// Function to count the number of walls that need to be reduced.
class Solution {
  public:
    int reducingWalls(vector<int>& arr, int k) {
        int operations = 0 ;
        
        for(int x : arr){
            if(x > k){
                operations += (x - 1) / k;
            }
        }
        
        return operations;
    }
};