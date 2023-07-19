#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//finding the Kth smallest element using priority queue
int findKthSmallest(const vector<int>& arr, int k) {
    priority_queue<int, vector<int>, less<int>> maxHeap;

    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main() {
    int n, k;

    cout << "Enter the size of the array and the value of K: ";
    cin >> n >> k;
    //checking if the input is valid
    if (n <= 0 || k <= 0 || k > n) {
        cout << "Invalid input. The array size and K must be positive integers, and K should be between 1 and array size.\n";
        return 1;
    }

    vector<int> arr(n);
    //storing the elements inside a vector
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int kthSmallest = findKthSmallest(arr, k);
    cout << "The " << k << "th smallest element is: " << kthSmallest << "\n";

    return 0;
}

