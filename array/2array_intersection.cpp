#include <iostream>  
using namespace std;
   
int main()  
{  
    //Initialize array   
    int arr1[] = {11,22,33,46,55,66};                    
    int arr2[] = {0, 33, 44, 55};  
    //Calculate length of array arr  
    int length1 = sizeof(arr1)/sizeof(arr1[0]);  
     int length2 = sizeof(arr2)/sizeof(arr2[0]);  
      
    cout<<"Duplicate elements in given array: "<<endl;  
    //Searches for duplicate element  
    for(int i = 0; i < length1; i++) {  
        int element=arr1[i];
        for(int j = 0; j < length2; j++) {  
            if(element == arr2[j])  
                cout<<arr2[j];  
        }  
    }  
    return 0;  
}  