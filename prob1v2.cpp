#include<vector>
#include<queue>
#include<iostream>


using namespace std;


int findK(vector<int> vec, int k){
    priority_queue<int, vector<int>, greater<>> pq (vec.begin(), vec.begin()+k);

    for (int i = k; i< vec.size(); i++){
      if (vec[i] > pq.top()){
        pq.pop();
        pq.push(vec[i]);
      }
    }

    return pq.top();
}

int main(){

//output: 4
vector<int> test1 = {4,2,5,4,2,3,5};
int k1 = 3;
cout << findK(test1, k1)<<endl;

// output:-5 
vector <int> test2 = {-1,-5,-4,-2};
int k2 = 4;
cout << findK(test2, k2)<< endl;

//output: 907
vector<int> test3 = {73, 548, 316, 311, 904, 886, 948, 44, 294, 517, 74, 291, 669, 274, 693, 439, 582, 866, 72, 240, 855, 237, 514, 306, 975, 619, 774, 770, 547, 905, 556, 669, 889, 220, 267, 756, 9, 862, 804, 437, 352, 950, 131, 78, 248, 705, 629, 985, 174, 907};
int k3 = 5;
cout << findK(test3, k3)<< endl;


}
