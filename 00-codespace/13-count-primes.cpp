// seive of erastothenes

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> primes(n, 1);
  primes[0] = 0;
  primes[1] = 0;
  primes[2] = 1;
  for(int i=3; i<=n; i++){
    if(i%2 != 0 && primes[i]==1){
      int j=2;
      while( i*j <= n ){
        primes[i*j] = 0;
        j++;
      }
    }
  }
  int t = 3;
  int res_primes = 1;
  while(t<=n){
    if( t % 2 != 0 && primes[t] == 1){
      res_primes++;
    }
    t++;
  }
  cout << res_primes;
}