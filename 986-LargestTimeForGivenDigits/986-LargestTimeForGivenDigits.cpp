// Last updated: 1/16/2026, 8:20:49 PM
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int maxx  = -1;
        do{
            int h = 10*arr[0] + arr[1];
            int m = 10*arr[2]+  arr[3];
            if(h<24 && m <60){
               maxx = max(maxx, h*60+m);
            }
            
        }while(next_permutation(arr.begin(), arr.end()));
        if(maxx ==-1) return "";
        
        int h = maxx/60;
        int m = maxx%60;
        
        return ((h<10?"0":"")+ to_string(h)+ ":"+( m<10?"0":"")+ to_string(m));
    }
    
    
};