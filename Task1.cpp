#include <iostream>
#include <vector>
using namespace std;

//reads student IDs forming an array 
void inputIDs(vector<int>& arr, int n) {
    cout << "Enter " << n << " student IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; }
}

//returns the index of the target 
int linearSearch(const vector<int>& arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
        //returns as the ID is found
            return i; 
        }
    }
    return -1; //returns -1 if the ID is not present 
}

//displays the search result
void displayResult(int index) {
    if (index != -1) {
        cout << "ID found at Index " << index << endl;
    } else {
        cout << "ID is not registered (Not found)." << endl;
    }
}

int main() {
    int n, target;
    cout << "Enter number of students: ";
    cin >> n;
    if (n <= 0) {

        cout << "Array is empty.\n";
        return 0;}
    
    vector<int> arr(n);
    inputIDs(arr, n);
    
    cout << "Enter target ID to search: ";
    cin >> target;
    int resultIndex = linearSearch(arr, n, target);
    displayResult(resultIndex);
    
    return 0;
}