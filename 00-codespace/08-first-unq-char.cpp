#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
  string s = "aabb";
  unordered_map<char, int> umap;
  int nr_char_idx = 0;
  int nr_char_ptr = 0;
  char nr_char = s[nr_char_ptr];
  umap[s[0]]+=1;
  for(int i=1; i<s.size(); i++){
    umap[s[i]]+=1;
    if(nr_char == s[i]){
      while( umap[s[nr_char_ptr]] > 1 ){
        nr_char_ptr++;
        if(nr_char_ptr >= s.size()){
          cout << -1;
        }
      }
      nr_char = s[nr_char_ptr];
      nr_char_idx = nr_char_ptr;
    }
  }
  cout << nr_char_idx;
}