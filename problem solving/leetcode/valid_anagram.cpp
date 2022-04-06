#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;

        map<char,int> m_s,m_t;

        for (int i = 0; i < s.size(); i++)
        {
            m_s[s[i]]+=1;
            m_t[t[i]]+=1;
        }
        for(pair<char,int> itr:m_s){
            if(m_s[itr.first]!=m_t[itr.first])return false;
        }
        return true;
    }
     static bool isAnagram_optimized(string s, string t) {
        if(s.size()!=t.size())return false;
        int vct[26]={0};
        for(int i=0;i<s.size();i++){
            vct[s[i]-'a']++;
            vct[t[i]-'a']--;
        }
        for(int x:vct) if(x)return false;
        return true;
    }
};

int main(){
    string s ="anagram" , t ="nagaram" ;
    string s2 = "rat"    , t2 = "car"    ;
    cout <<Solution::isAnagram_optimized(s,t)<<endl;
    cout <<Solution::isAnagram_optimized(s2,t2)<<endl;
    return 0;
}