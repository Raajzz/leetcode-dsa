#include <iostream>
#include <string>

using namespace std;

int main(){
  int x = -123;
  string x_str = to_string(x);
  int start;
  string str_int_max = to_string(INT_MAX);
  string str_int_min = to_string(INT_MIN);
  if(x_str[0] == '-'){
      start = 1;
  } else {
      start = 0;
  }
  int x_str_size = x_str.size();
  for(int i=start; i<(x_str_size-start/2); i++){
      swap(x_str[i], x_str[x_str_size - 1 - i]);
  }
  cout << x_str << "\n";
}