#include<iostream>
#include<vector>
using namespace std;
int firstOccurence(vector<int> &arr, int x){

    int n = arr.size();

    int s=0;

    int e= n-1;

    int fir =-1;

    while(s<=e){

        int mid = s+(e-s)/2;

        if(arr[mid]==x){

            fir = mid;

            e=mid-1;

        }

        else if(arr[mid]>x){

            e=mid-1;

        }

        else{

            s=mid+1;

        }

    }

 

    return fir;

    

}

 

int lastOccurence(vector<int> &arr, int x){

    int n = arr.size();

    int s=0;

    int e=n-1;

    int las =-1;

    while(s<=e){

        int mid = s+(e-s)/2;

        if(arr[mid] == x){

            las = mid;

            s=mid+1;

        }

        else if(arr[mid]>x){

            e=mid-1;

        }

        else{

            s=mid+1;

        }

    }

    return las;

}

vector<int> searchRange(vector<int> &arr, int x)

{

    
    vector<int> ans;

    ans.push_back(firstOccurence(arr,  x));

    ans.push_back(lastOccurence(arr,  x));

 

    return ans;  

}
int main() {
    std::vector<int> arr = {2, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    int x = 5;

    std::vector<int> result = searchRange(arr, x);

    std::cout << "Search range for " << x << " is: [" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}