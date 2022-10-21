#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int myAtoi(string s) {
    string fill_string = "";
    int res = 0;
    int idx = 0;
    bool pos = true;
    int s_size = s.size();
    while(s[idx] == ' ' && s[idx] != '+' && s[idx] != '-' && !isdigit(s[idx]) && idx < s_size){
        idx++;
    }

    while( (s[idx] == '+' || s[idx] == '-') && idx+1 < s_size && (s[idx+1] == '+' || s[idx+1] == '-')){
        return 0;
    }
    
    if(s[idx] == '-'){
        fill_string += '-';
        pos = false;
        idx++;
    } else if(s[idx] == '+') {
        idx++;
        pos = true;
    } 
    
    while(s[idx] == '0' && !isdigit(s[idx]) && idx < s_size){
        idx++;
    }
    
    while(isdigit(s[idx]) && idx < s_size){
        fill_string += s[idx];
        idx++;
    }
    
    if(fill_string.empty()){
        return res;
    }
    
    string int_max_string = to_string(INT_MAX);
    string int_min_string = to_string(INT_MIN);

    if(fill_string[0] == '-'){
        if(fill_string.size() < int_min_string.size()){
            return stoi(fill_string);
        } else if(fill_string.size() == int_min_string.size()){
            for(int i=0; i<fill_string.size(); i++){
                if(fill_string[i] > int_min_string[i]){
                    return INT_MIN;
                }
            }
            return stoi(fill_string);
        }
        else {
            return INT_MIN;
        }
    } else {
        if(fill_string.size() < int_max_string.size()){
            return stoi(fill_string);
        } else if (fill_string.size() == int_max_string.size()) {
            for(int i=0; i<fill_string.size(); i++){
                if(fill_string[i] > int_max_string[i]){
                    return INT_MAX;
                }
            }
            return stoi(fill_string);
        } else {
            return INT_MAX;
        }
    }
    
}

int main(){
    string s;
    cin>>s;
    cout << myAtoi(s);
    return 0;
}