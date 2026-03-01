// Last updated: 3/1/2026, 9:34:17 AM
class Solution {
public:
    string mergeCharacters(string s, int k) {
        list<char> l(s.begin(), s.end());
        for( auto  it = l.begin() ; it !=l.end();){
             auto  sit = next(it);
            bool m = false;
            for( int d  = 1 ; sit != l.end()  && d<= k; ++d, ++sit){
                 if(*sit == *it){
                     l.erase(sit);
                     m = true;
                      break;
                 }
            }
            if(m){
               it= l.begin();
                
            }else{
                ++it;
            }
        }
        return string(l.begin() , l.end());
    }
};