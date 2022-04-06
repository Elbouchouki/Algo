#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged;

        int i=0 , j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }
        while(i<m)merged.push_back(nums1[i++]);
        while(j<n)merged.push_back(nums2[j++]);

        nums1 = merged;
    }
};

int main(){
   vector<int>nums1 = {0},nums2 = {1};
   int m = 0, n = 1;
   Solution::merge(nums1,m,nums2,n);
   for(int x=0; x < m+n ;x++){
       cout<<nums1[x]<<"";
   }
}