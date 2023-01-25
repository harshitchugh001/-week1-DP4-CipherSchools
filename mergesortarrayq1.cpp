#include <bits/stdc++.h>


using namespace std;
void mergeSortedArrays(vector<int> &a,int m,vector<int> &b,int n){
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0 && j>=0){
        if(a[i]>b[j]){
            a[k]=a[i];
            i--;
        }
        else{
            a[k]=b[j];
            j--;
        }
        k--;
    }
    while(j>=0){
        a[k]=b[j];
        j--;
        k--;
    }
}
int main()
{
   vector<int> a ={1,2,3,0,0,0};
   vector<int> b={2,5,6};
   cout<<mergeSortedArrays(a,3,b,3);

    return 0;
}