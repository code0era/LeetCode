// Last updated: 5/1/2026, 11:23:00 PM
1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int five=0;
5        int ten=0;
6        int twt=0;
7        for(int bill : bills){
8            if(bill == 5){
9                five++;
10            }
11            else if (bill == 10){
12                if(five){
13                    five--;
14                    ten++;
15                }
16                else return false;
17            }
18            else{
19                if( ten && five ){
20                    ten--;
21                    five--;
22                    twt++;
23                }
24                else if( five>2){
25                    five -=3;
26                    twt++;
27                }
28                else return false;
29            }
30        }
31        return true;
32    }
33};