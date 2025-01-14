#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& arr, int l, int mid, int r) {
        // Create a temporary array for merging
        std::vector<int> temp(r - l + 1);
        int i = l, j = mid + 1, k = 0;

        // Merge the two halves
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        // Copy remaining elements from the left half
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements from the right half
        while (j <= r) {
            temp[k++] = arr[j++];
        }

        // Copy merged elements back to the original array
        for (int i = 0; i < temp.size(); i++) {
            arr[l + i] = temp[i];
        }
    }

    void mergeSort(std::vector<int>& arr, int l, int r) {
        if (l >= r) {
            return; // Base case
        }

        int mid = l + (r - l) / 2;

        // Sort the left and right halves recursively
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        // Merge the sorted halves
        merge(arr, l, mid, r);
    }
};

int main() {
    // Input array
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    // Create an instance of Solution and perform merge sort
    Solution solution;
    solution.mergeSort(arr, 0, arr.size() - 1);

    // Output the sorted array
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
