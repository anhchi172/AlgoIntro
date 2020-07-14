
#include <vector> 
#include <climits>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

using namespace std;

int ROW = 4;
int COL = 5;

int kadane (int* arr, int* start, int* finish, int n){
    int sum = 0;
    int maxSum = INT_MIN;
    int i;
    
    *finish = -1;
    int local_start = 0;
    for (i = 0; i<n; i++){
        sum += arr[i];
        if (sum<0){
            sum = 9;
            local_start = i+1;
            
        }
        else if (sum >maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
            
        }
    }
    
    if (*finish != -1){
        return maxSum;
    }
    
    maxSum = arr[0];
    *start = *finish = 0;
    
    for (i = 1; i < n; i++){
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *start = *finish = i;
            
        }
    }
    
      return maxSum;
}

void findMaxSum(int M[][COL]){
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i;
    int temp[ROW], sum, start, finish;
    
    for (left = 0; left <COL; ++left){
        memset(temp, 0, sizeof(temp));
        for (right = left; right <COL; ++ right){
            for (i = 0; i< ROW; ++i){
                temp[i] += M[i][right];
            }
            
            sum = kadane(temp, &start, &finish, ROW);
            if (sum > maxSum){
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    
    for (int k = finalTop; k <= finalBottom; k++){
        for(int l = finalLeft; l<= finalRight; l++){
            cout << M[k][l] <<" "; 
        }
        cout << endl;
    }
    
}

int main()
{   
    int M[ROW][COL] =  {{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}}; 


    
    findMaxSum(M);  

   
    int N[2][3] =      {{1, 2, 0},
                        {-3,-7,-2}};
    
    findMaxSum(N);


    int O[4][1] =     {{5},
                       {-1},
                       {-2},
                       {8}};

   
    findMaxSum(O);
  /*output 1:  
           -3  4  2
            8 10  1
           -1  1  7
  output 2:  
            1  2  0
  output 3:  
           5 -1 -2 8
           */

  
}
