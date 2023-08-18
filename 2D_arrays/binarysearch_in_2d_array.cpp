 #include <iostream>
#include <vector>

using namespace std;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int s=0;
        int n = matrix.size(); 
        int m = matrix[0].size();
        int e=(n*m)-1;
        int mid=s+(e-s)/2;
        while(s<=e)
        {   
            int element=matrix[mid/m][mid%m];
            if(element==target)
            {
                return 1;

            }
            else if(target>element){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
       return 0; 
    }
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    
    int target = 16;
    
    bool result = searchMatrix(matrix, target);
    
    if (result) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }
    
    return 0;
}
