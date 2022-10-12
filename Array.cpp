#include<iostream>
using namespace std;

//inserting an element at specific position
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* InsertAtposition(int arr[], int size, int position, int element){
        for(int i=size; i>=position; i--){
            arr[i]=arr[i-1];
        }
        arr[position-1]=element;
      return arr;
}   

int main(){
    int arr[100]={10, 20, 30, 40, 50};

    int size=5;


   printArray(arr,5);

  InsertAtposition(arr,5,3,40);
  for(int i=0; i<size+1; i++){
    cout<<arr[i]<<" ";
  }


  return 0;
}
