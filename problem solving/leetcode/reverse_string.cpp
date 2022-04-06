#include <bits/stdc++.h>

using namespace std;

void reverse(string &in);
void reverse_recursive(string &in);

int main(){
    string input = "12345";
    reverse_recursive(input);
    cout << input <<endl;
    input = "1234";
    reverse_recursive(input);
    cout << input <<endl;
    input = "1";
    reverse_recursive(input);
    cout << input <<endl;
}

void reverse(string &in){
    int last = in.size()-1;
    int middle = last % 2 == 0 ? last / 2 : ( last + 1 ) / 2;
    for(int i = 0;i<=middle;i++){
        char temp = in[i];
        in[i] = in[last-i];
        in[last-i] = temp;
    }
}

void _reverse_rec(string &in , int left , int right){
    if(left<right){
        char temp = in[left];
        in[left] = in[right];
        in[right] = temp;
        _reverse_rec(in,left+1,right-1);
    }
}

void reverse_recursive(string &in){
    _reverse_rec(in ,0 ,in.size()-1);
}


