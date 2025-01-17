#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element in the array using Moore's Voting Algorithm
pair<int, bool> majorityElement(vector<int>& nums) {
    // Initialize frequency counter and current candidate for majority element
    int freq = 0, curr = nums[0];

    // Traverse the array to find a candidate for the majority element
    for (int i : nums) {
        // If frequency counter is 0, update the candidate to the current element
        if (freq == 0) {
            curr = i;
        }

        // Update frequency counter
        if (curr == i) {
            freq++;  // Increment if the current element matches the candidate
        } else {
            freq--;  // Decrement otherwise
        }
    }

    // Verify if the candidate is a majority element
    int count = 0;
    for (int i : nums) {
        if (i == curr) {
            count++;
        }
    }

    // Return the result as a pair: candidate and validity flag
    if (count > nums.size() / 2) {
        return {curr, true};
    } else {
        return {0, false}; // Use `false` to indicate no majority element
    }
}

int main() {
    // Example usage
    vector<int> nums;

    // Input the size of the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    // Call the function to find the majority element
    pair<int, bool> result = majorityElement(nums);

    // Output the result
    if (result.second) {
        cout << "The majority element is: " << result.first << "\n";
    } else {
        cout << "The majority element does not exist.\n";
    }

    return 0;
}
