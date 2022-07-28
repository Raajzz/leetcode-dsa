#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int x = 0;
  cin>>x;
  string str_x = to_string(x);
  int first = (str_x[0]=='-')?1:0;
  reverse(str_x.begin()+first, str_x.end());
  string str_max = to_string(INT_MAX);
  string str_min = to_string(INT_MIN);
  if(first == 0){
    if(str_x.size() < str_max.size()){
      cout << atoi(str_x.c_str());
      exit(0);
    } else if(str_x.size() > str_max.size()){
      cout << 0;
      exit(0);
    } else {
      for(int i=0; i<str_x.size(); i++){
        if(str_x[i] > str_max[i]){
          cout << 0;
          exit(0);
        } else if(str_x[i] < str_max[i]){
          cout << atoi(str_x.c_str());
          exit(0);
        }
      }
      cout << atoi(str_x.c_str());
      exit(0);
    }
  } else if (first == 1){
    if(str_x.size() < str_min.size()){
      cout << atoi(str_x.c_str());
      exit(0);
    } else if(str_x.size() > str_min.size()){
      cout << 0;
      exit(0);
    } else {
      for(int i=0; i<str_x.size(); i++){
        if(str_x[i] > str_max[i]){
          cout << 0;
          exit(0);
        } else if(str_x[i] < str_min[i]){
          cout << atoi(str_x.c_str());
          exit(0);
        }
      }
      cout << atoi(str_x.c_str());
      exit(0);
    }
  }
  return 0;
}