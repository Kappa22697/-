#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Linear Search
// Search array from beginning to end
// Time Complexity: O(n)
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Binary Search
// Search by comparing with middle value and narrowing range
// Time Complexity: O(log n)
// Note: Array must be sorted
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Return index if found
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Search right half
        }
        else {
            right = mid - 1;  // Search left half
        }
    }
    return -1;  // Return -1 if not found
}

// Binary Search (Recursive version)
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;  // Not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
    else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

// Print search result
void printResult(int index, int target) {
    if (index != -1) {
        cout << "Value " << target << " found at index " << index << endl;
    }
    else {
        cout << "Value " << target << " not found" << endl;
    }
}

int main() {
    // Test data (unsorted)
    vector<int> unsortedArr = {64, 34, 25, 12, 22, 11, 90};

    // Test data (sorted)
    vector<int> sortedArr = {11, 12, 22, 25, 34, 64, 90};

    cout << "=== Linear Search Test ===" << endl;
    cout << "Array: ";
    for (int num : unsortedArr) {
        cout << num << " ";
    }
    cout << endl << endl;

    int target1 = 22;
    int result1 = linearSearch(unsortedArr, target1);
    printResult(result1, target1);

    int target2 = 100;
    int result2 = linearSearch(unsortedArr, target2);
    printResult(result2, target2);

    cout << "\n=== Binary Search Test ===" << endl;
    cout << "Sorted Array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl << endl;

    int target3 = 25;
    int result3 = binarySearch(sortedArr, target3);
    printResult(result3, target3);

    int target4 = 50;
    int result4 = binarySearch(sortedArr, target4);
    printResult(result4, target4);

    cout << "\n=== Binary Search (Recursive) Test ===" << endl;
    int target5 = 64;
    int result5 = binarySearchRecursive(sortedArr, target5, 0, sortedArr.size() - 1);
    printResult(result5, target5);

    return 0;
}
