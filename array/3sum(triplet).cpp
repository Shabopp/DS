#include<iostream>
using namespace std;
int main(){
    int arr[]={-1,0,-1,2,1,0,-4};
     int length1 = sizeof(arr)/sizeof(arr[0]);  

   for(int i=0;i<length1; i++ )
   {
   		for(int j = i+1; j<length1; j++) {
            for(int k=j+1;k<length1;k++){
        	if(arr[i] +arr[j] + arr[k]==0)
            {
            	cout<<arr[i]<<" "arr[j]<<" "<<arr[k]<<endl;
            }
        }
   }
   }
   return 0;
}