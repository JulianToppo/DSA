#include<bits/stdc++.h>
using namespace std;

//Delete if the count of consecutive char are B
string consecutiveOccurene(string A, int B) {
    int n = A.size();

   string ans = "";
   int i=0;
   while(i < n){
       string temp = "";
       int j = i;
       while(j<A.size() and A[i] == A[j]){
           temp.push_back(A[j]);
           j++;
       }
       if(j-i != B){
           ans += temp;
       }
       i = j;
   }
   return ans;
}



int main(){

}