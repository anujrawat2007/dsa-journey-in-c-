#include<iostream>
using namespace std;

void sum(int *arr, int n){
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    cout<<total<<endl;
}

int main() {

    // int i = 5;
    // int &j = i;
    // j++;
    // cout<< i;

    // char ch = 'a';
    // cout<<sizeof(ch)<<endl;
    // char *c = &ch;
    // cout<<sizeof(c)<<endl;

    // int *p = new int;
    // *p = 10;
    // cout<<sizeof(p)<<endl;

    int n ;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    sum(arr, n);

return 0;
}