class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //makeing copies so we can safely swap
        vector<int> A = nums1;
        vector<int> B = nums2;

        //to Ensure A is smaller array
        if(B.size() < A.size()){
            swap(A ,B);
        }

        int n = (int)A.size();
        int m = (int)B.size();
        int total = n +m ;
        int half = (total + 1) / 2; 

        int l = 0 ;
        int r = n;

        while( l <= r){
            int i = l + (r -l) / 2; //Partition index for A
            int j = half - i ; //partition index for B

            int Aleft = (i > 0) ? A[i-1] : INT_MIN;
            int Aright = ( i < n) ? A[i] : INT_MAX;

            int Bleft = (j > 0) ? B[j-1] : INT_MIN;
            int Bright = (j < m) ? B[j] : INT_MAX;


            if(Aleft <= Bright && Bleft <= Aright){
                //odd total length return middle element
                if(total % 2 == 1){
                    return (double)max(Aleft , Bleft );
                }
                //even the averate of middle two
                else{
                    return (max(Aleft , Bleft) + min(Aright , Bright)) / 2.0;
                }
            }
            //too big on A side so move left
            else if(Aleft > Bright){
                r = i -1;
            }
            //Too small on A side move right
            else{
                l = i +1;
            }
        }
        return 0.0; 
    }
};
