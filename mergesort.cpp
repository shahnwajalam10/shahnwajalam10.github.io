#include<iostream>
using namespace std;

void merge(int arr[],int s, int mid,int e){
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    //copy values
    int i=0;
    for(int index=s; index<=mid; index++){
        first[i]=arr[index];
        i++;
    }

    int j=0;
    for(int index=mid+1; index<=e; index++){
        second[j]=arr[index];
        j++;
    }

    //merge these two arrays into the original array
    int originArrayIndex=s;
    int index1=0;
    int index2=0;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[originArrayIndex]=first[index1];
            index1++;
            originArrayIndex++;
        }
        else{
            arr[originArrayIndex]=second[index2];
            index2++;
            originArrayIndex++;
        }
    }

    //exhaust first array
    while (index1<len1){
        arr[originArrayIndex]=first[index1];
        index1++;
        originArrayIndex++;   
    }

    //exhaust second array
    while (index2<len2){
        arr[originArrayIndex]=second[index2];
        index2++;
        originArrayIndex++ ;   
    }
    
    
}

void mergeSort(int arr[],int s, int e){

    //base case
    if(s>=e){
        return;
    }

    int mid=(s+e)/2;

    //left part recursion sort
    mergeSort(arr,s,mid);

    //right part recursion sort
    mergeSort(arr,mid+1,e);

    //merge sorted array
    merge(arr,s,mid,e);
}

bool binarySearch(int *arr, int s, int e,  int target ){

    //base case condition
    if(s>e){
        return false;
    }

    int mid=(s+e)/2;

    if(target==arr[mid]){
        return true;
    }

    else if(target<arr[mid]){
        //search in left side

        return binarySearch(arr,s,mid-1,target);
    }

    else{
        //search in right side

        return binarySearch(arr,mid+1,e,target);
    }
    


}


int main(){
    int arr[]={3,6,9,12,15,17,19};
    int size=7;

    mergeSort(arr,0,size-1);
    cout<<"printing the sorted array"<<endl;

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    cout<<"printing the binary search  "<<binarySearch(arr,0,size-1,20);

    return 0;
}