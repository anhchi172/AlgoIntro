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

// output: 1
vector <int> test2 = {1,5,4,2};
int k2 = 4;
cout << findK(test2, k2)<< endl;

//output: 10
vector<int> test3 = {7,9,10,3};
int k3 = 1;
cout << findK(test3, k3)<< endl;


}
