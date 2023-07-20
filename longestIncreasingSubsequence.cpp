#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void longestSubsequence( int *arr, int n )
{
    int  i, j, max = 0;

    vector<int> ls(n);
    fill(ls.begin(),ls.end(),1);

    for ( i = 1; i < n; i++ ){
        for ( j = 0; j < i; j++ ){}
            if ( arr[i] > arr[j] && ls.at(i) < ls.at(j) + 1){
                ls.at(i) = ls.at(j) + 1;
            }
        }
    }

    max = *max_element(ls.begin(),ls.end());

    int temp = max;

    vector<int> indexes;

    for(i=n-1; i >= 0; --i)
        if( ls.at(i) == temp)
        {
            indexes.push_back(i);
            --temp;
        }
    reverse(indexes.begin(), indexes.end());

    cout<<"\nLength of the Longest Increasing Subsequence : "<<max<<endl;

    cout<<"\nThe values of the longest Increasing Subsequence is : "<<endl;

    for(auto i:indexes)
    {
        cout<<arr[i]<<endl;
    }
   //Free memory to avoid memory leak
   ls.clear();
}

int main()
{
    int arr[]={10, 2, 5, 6, 1, 8, 9, 3, 4, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    longestSubsequence(arr,n);

    return 0;
}

