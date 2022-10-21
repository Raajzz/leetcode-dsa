#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool utilityFn(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else return a.first < b.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int h;
        int s;
        vector<pair<int,int>> vec_pair;
        vec_pair.reserve(n);
        while(n--){
            int a;
            int b;
            cin>>a>>b;
            vec_pair.push_back(make_pair(a,b));
        }
        pair<int,int> res = *min_element(vec_pair.begin(), vec_pair.end(), utilityFn);
        if(res.first > h){

        } else if(res.first == h) {
            if(res.second == s){
                cout << 0;
            }
        }
    }
}