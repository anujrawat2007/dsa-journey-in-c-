#include<iostream>
#include<utility>
using namespace std;
int main() {
    pair<int,int> p = {1,2};
    cout<< p.first <<" "<< p.second <<endl;
     pair<int, pair<int, int>> q = {1, {4, 3}};
    cout << q.first << " " << q.second.first << " " << q.second.second<<endl;
    pair<int,int>arr[] = {{1,3},{3,2},{5,7}};
    cout << arr[0].first << " " << arr[1].second << " " << arr[2].first;
    
return 0;
}