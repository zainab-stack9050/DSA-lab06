#include <iostream>
#include <vector>
using namespace std;

// Merging the two sorted subarrays into one sorted range
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    //to copy remaining element of the left array if any exist 
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    //to copy remaining element of the right array if any exist
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

//Divides and sorts the array using recursion 
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; //Array contains 0 or 1 element, no need to sort
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);}

// Displays the array before and after sorting
void displayArray(const vector<int>& arr, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ",";}
    cout << "]" << endl;
}

int main() {
    int n;
    cout << "Enter number of marks: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Output: []\n";
        return 0;}
    
    vector<int> arr(n);
    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];}
    
    cout << "Before sorting: ";
    displayArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "After sorting: ";
    displayArray(arr, n);
    
    return 0;
}