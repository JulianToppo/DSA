#include<bits/stdc++.h>
using namespace std;

//Bubble sort :
void bubbleSort(vector<int> &a){
    int n=a.size();

    for(int i=0;i<n-1;i++){
        //n-1-i account for the sorted number at the end of the list
        for(int j=0;j<n-1-i;j++){

                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                }

        }
    }


}

//Selection Sort
//iterate throguht the array find the minimum value and then replace it with the first iterator
void selectionSort(vector<int> &a){
    int n=a.size();
    int idx=-1,mininum_idx=0;
    int min=0;
    for(int i=0;i<n-1;i++){
        mininum_idx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mininum_idx]){
                mininum_idx=j;
            }
        }
        swap(a[++idx],a[mininum_idx]);
    }
    return;
}

//Insertion sort (Card sorting) Fit the element in their respective 
void insertionSort(vector<int> &a){
    int n=a.size();
    
    for(int i=1;i<n;i++){
        int key=i-1;
        int x=a[i];
        while(key>=0 && x<=a[key]){
            a[key++]=a[key];
            key--;            
        }
        a[++key]=x;
    }
}

//mergesort
void merge(vector<int> &a,int low,int mid,int high){
  //  cout<<"check"<<low<<" "<<mid<<" "<<high<<" \n";
    int k=low;
    int size_left=(mid-low+1);  //accomodating the left secton including the middle so we have +1
    int size_right=(high-mid);
    int left[size_left];
    int right[size_right];

    for(int i=0;i<size_left;i++){
        left[i]=a[low+i];
    }

    for(int i=0;i<size_right;i++){
        right[i]=a[mid+1+i];
    }


    int i=0,j=0;

    while (i<size_left && j<size_right)
    {
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<size_left){
        a[k]=left[i];
            k++;
            i++;
    }

    while (j<size_right)
    {
        a[k]=right[j];
            k++;
            j++;
    }
}

void mergesort(vector<int> &a,int low,int high){

    if(low<high){
    int mid=low+(high-low)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
    } 
}






int main(){

    //enter the number of values
    int n;
    vector<int> a(n);
    int val;
    cout<<"Enter count";
    cin>>n;
    cout<<"Enter values";
    for(int i=0;i<n;i++){
        cin>>val;
        a.push_back(val);
    }

    for(auto x:a){
        cout<<x<<" ";
    }
    mergesort(a,0,n-1);

    cout<<"size: "<<a.size()<<"\n";
    //print the elements

    for(auto x:a){
        cout<<x<<" ";
    }

    return 0;
}