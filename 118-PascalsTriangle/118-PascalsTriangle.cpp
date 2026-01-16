// Last updated: 1/16/2026, 8:21:34 PM
class Solution {
public:
    vector<int> genRow(int r){
        vector<int> row;
        int num= 1;
        row.push_back(1);
        for(int col = 1 ; col<=r ;col++){
            num = num*(r-col+1);
            num = num/(col);
            row.push_back(num);
        }

        return row;
    }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;

       for(int i = 0 ; i < numRows; i++)
       {
            vector<int> row=genRow(i);
            ans.push_back(row);
       } 
       return ans;
    }
};