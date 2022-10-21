#include <iostream>
#include <unordered_map>

using namespace std;

int dp_prog(int n, unordered_map<int,int> &umap){
    int val = umap[n];
    if(val != 0){
        return val;
    } 
    if(n==0 || n==1){
        return 1;
    }
    return umap[n] = dp_prog(n-1, umap) + dp_prog(n-2, umap);
}

int main(){
    int n = 0;
    cin>>n;

    unordered_map<int,int> umap;

    cout << dp_prog(n, umap);
}