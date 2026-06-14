// Last updated: 6/14/2026, 9:37:52 AM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twt=0;
        for(int bill : bills){
            if(bill == 5){
                five++;
            }
            else if (bill == 10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                if( ten && five ){
                    ten--;
                    five--;
                    twt++;
                }
                else if( five>2){
                    five -=3;
                    twt++;
                }
                else return false;
            }
        }
        return true;
    }
};