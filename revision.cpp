#include <iostream>
#include<cmath>
using namespace std;
int sm = 0;

int sum(int n,int i){
 if(i>n)return sm;
 sm+=i++;
 sum(n,i);
}


int main(){
cout<<sum(4,1);

return 0;
}