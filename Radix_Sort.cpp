#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the maximum element from the array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Function to perform counting sort based on the digit represented by exp
void countSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());  // Output array to store sorted numbers
    vector<int> count(10, 0);  // Count array for digits (0-9)

    // Store count of occurrences of digits in count[]
    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Main function to implement radix sort
void radixSort(vector<int>& arr) {
    // Get the maximum element to determine the number of digits
    int max = getMax(arr);

    // Do counting sort for every digit. The exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    printArray(arr);

    // Perform Radix Sort
    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

