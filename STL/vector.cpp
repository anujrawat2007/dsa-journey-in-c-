#include<iostream>
#include<vector>
using namespace std;

void explainVector(){
    vector <int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector <pair<int,int>> u ;
    u.push_back ({1,2});
    u.emplace_back (2,3); //don't need curly brackets here
    
    vector<int> v1 (5,100); //{100,100,100,100,100};
    vector<int> v2 (5); // {0,0,0,0,0};
    vector<int> v3 (v2); // copy of v2;

    //accessing the elements of vectors
    vector<int>:: iterator it = v3.begin();
    it++; 
    cout<< *(it)<<" ";  
    it = it+2;
    cout<< *(it)<<endl;

    vector<int>:: iterator pt = v1.end(); //points at the right after last element 
    vector<int>:: reverse_iterator qt = v1.rend();
    vector<int>:: reverse_iterator rt = v1.rbegin();

    cout<<v1[2]<<" "<<endl;
    cout<<v1.at(2)<<" "<<endl;

    for (vector<int>:: iterator it =v1.begin(); it < v1.end(); it++)
    {
        cout<< *(it) << " ";
    }
    
    cout<< endl;

    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }
    
    cout<< " ";

    for(auto x : v1){
        cout<< x << " ";
    }

    cout<< endl;

    vector<int> v4; // vector<int> v4 = {11,12,19,13,15}
    v4.push_back(11);
    v4.push_back(12);
    v4.push_back(19);
    v4.push_back(13);
    v4.push_back(15);

   // v4.erase(v4.begin()+1); //11 19 13 15 
    v4.erase(v4.begin()+2,v4.begin()+4); //11 12 15
   

    v4.insert(v4.begin()+1,32);
    v4.insert(v4.begin()+2,3,13); // three times 13 printed

    vector<int> v5 = {2,3};
    v5.insert(v5.begin(), v4.begin(), v4.end());
    for(auto x : v5){
        cout<< x << " "; 
    }
    cout<<endl;

    cout<<v5.size()<< endl;
    
    v5.pop_back(); //last element pops out

    v5.swap(v4);

    v4.clear();

    cout<<v4.empty();

}

int main() {
explainVector();
return 0;

}