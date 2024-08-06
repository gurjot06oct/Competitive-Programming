#include<iostream>
#include<vector>
using namespace std;
int min(int a, int b){
    return a>b?b:a;
}
int max(int a, int b){
    return a<b?b:a;
}
int main(){
    vector<int> height{1,8,6,2,5,4,8,3,7}; // 49 ---- 8,7
    int i=0,j=height.size()-1;
    int max,temp;
    while (i<j)
    {
        temp=(j-i+1)*min(height[i],height[j]);
        if(temp){

        }else{

        }
    }
    
    return 0;
}