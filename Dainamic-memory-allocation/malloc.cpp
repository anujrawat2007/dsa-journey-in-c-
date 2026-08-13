#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
    int number = 0;
    cout<<"Enter number of grades"<<endl;
    cin>>number;
    // char *grades = (char *)malloc(number * sizeof(char));
    char *grades = (char *)calloc(number , sizeof(char));
    
    if(grades == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 1; // Exit with an error code
    }
    for(int i=0;i<number;i++){
        cout<<"Enter grade "<<i+1<<endl;
        cin>>grades[i];
    }

    for (int i = 0; i < number; i++)
    {
        cout<<grades[i]<<endl;
    }
    
    free(grades);
    grades = NULL;

return 0;
}