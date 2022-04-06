#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) {
        string res ="";
        for(int i=0;i<s.size();i++){
            char curr = tolower(s[i]);
            if((curr >= '0' && curr <= '9' ) || (curr >='a' && curr <='z')){
                res+=curr;
            }
        }
        string res_reversed = string(res.rbegin(),res.rend());
        cout << res << endl;
        cout << res_reversed << endl;
        return res == res_reversed;
    }
    static bool isPalindrome_optimized(string s) {
        int start_pos = 0;
        int end_pos   = s.size()-1;
        while( start_pos < end_pos ){
            char c_start = tolower(s[start_pos]);
            char c_end = tolower(s[end_pos]);

            if(!( (c_start >= '0' && c_start <= '9' ) || (c_start >='a' && c_start <='z') ) ){
                start_pos++;
                continue;
            }

            if(!( (c_end >= '0' && c_end <= '9' ) || (c_end >='a' && c_end <='z') ) ){
                end_pos--;
                continue;
            }

            if(c_start!=c_end)return false;

            start_pos++;
            end_pos--;
        }
        return true;
    }
};

int main(){
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "0P";
    cout << Solution::isPalindrome_optimized(s1)<<endl;
    cout << Solution::isPalindrome_optimized(s2)<<endl;

    return  0;
}