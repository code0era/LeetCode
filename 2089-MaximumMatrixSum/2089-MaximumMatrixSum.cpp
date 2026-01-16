// Last updated: 1/16/2026, 8:20:22 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // even number of negatives then we can make all of the positive using this operation
        // If odd number of operation are there then we have to left atleast  one negative to be counted 

        long long sum =0 ;
        int ng =  0 ;
        int minn = INT_MAX;
        for(auto row : matrix){
            for(auto i : row)
            {sum+=abs(i);
            if(i<0) {
                ng++;
            }
            minn = min(minn,abs(i));}
        }
        if(ng % 2 == 1){
            sum -= 2*(minn);
        }
        return sum;
    }
};