#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int low=0;
    int high=size-1;

    int mid=low+(high-low)/2;

    while(low<=high){

        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}



int main(){
    int arr[]={1,3,4,5,6,7,8,9};
    int size=9;

    int target=6;

    cout<<binarySearch(arr,9,6);



    
    return 0;

}