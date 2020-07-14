 //how to trim ending 0 for all cases
#include <vector> 
#include <climits>
#include <iostream>

using namespace std;

int findMaxSubarr(vector<int> vec){
  int max_so_far = INT_MIN;
    int max_end_here = 0;
    int start = 0;
    int end = 0;
    int temp_s = 0;
    
    for (int i = 0; i< vec.size(); i++){
        max_end_here += vec[i];
        if (max_end_here > max_so_far){
            max_so_far = max_end_here;
            start = temp_s;
            end = i;
        }
        
        if (max_end_here <0){
            max_end_here = 0;
            temp_s = i+1;
        }
    }     
    for (int j = start; j <= end; j++){
        cout << vec[j] << " ";
    }

    return 0;
}
 
int main()
{

    vector<int> vec1 = { -9, 4, 2, 3, -5, 6, -7, 1, -10, 4};
    // output [4,2,3,-5,6]
    cout<< findMaxSubarr(vec1)<< endl;
    
    vector<int> vec2 = {1, -5, 3, -2, 1, -7};
    //output = [3]
    cout<< findMaxSubarr(vec2)<<endl;

    vector<int> vec3 = {-6,-8,-3,-10};
    //output = [-3]
    cout<< findMaxSubarr(vec3) <<endl;

  
}

