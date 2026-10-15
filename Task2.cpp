#include <iostream>
#include <vector>
using namespace std;

//Checking whether the input is sorted in ascending order
bool isSorted(const vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;}
    }
    return true;
}

//reading the registration numbers in ascorder
void inputSortedIDs(vector<int>& arr, int n) {
    cout << "Enter " << n << " Registration no.s in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

//Returns the target index
int binarySearch(const vector<int>& arr, int low, int high, int target) {
    while (low <= high) {

        // Calculate the middle index to prevent overflow
        int mid = low + (high - low) / 2;
        //if the middle element matches the target, return its index
        if (arr[mid] == target) {
            return mid; }
        //if the target is smaller, search the left half. Otherwise, search the right half
        else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; //if the target is absent
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Input array is empty. Result: Not found\n";
        return 0;
    }
    
    vector<int> arr(n);
    inputSortedIDs(arr, n);
    
    //  Checking the array is sorted
    if (!isSorted(arr, n)) {
        cout << "Error: Input array is not sorted in non-decreasing order!\n";
        return 1;
    }

    cout << "Enter target registration number: ";
    cin >> target;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Found at index " << result << endl;
    }else {
        cout << "Not found" << endl;
    }
    
    return 0;
}