#include <iostream>
#include<set>
using namespace std;

int main()
{
    //creating an array
    int arr[]={5,23,51,40,10,9,20,51,26,84,75,84,92,84,2,4};
    cout<<"Elements in the Array : "<<endl;

    //printing array elements
    for(int i:arr)
        cout<<i<<" ";
    cout<<"\n";

    int sizeofarray = sizeof(arr)/sizeof(arr[0]);
    cout<<"The number of elements in the array : "<<sizeofarray<<endl;

    //creating and pushing array values into the set
    set<int> s;
    for(int i=0;i<sizeofarray;i++){
        s.insert(arr[i]);
    }

    //printing the number of elements in the set since set only stores unique elements
    cout<<"Number of unique elements in the array : "<<s.size()<<endl;

    return 0;
}

