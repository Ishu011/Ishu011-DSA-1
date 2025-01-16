// Problem Intuition:The goal of the problem is to merge list2 into list1 after removing the nodes from index a to index b (inclusive).
//BRUTEFORCE-APPROACH:
// Approach: 1).Find pre and post:** Traverse list1 to identify the nodes at index a-1 (pre) and index b+1 (post).
// 2)Modify Links:- Set the next pointer of pre to the head of list2. then Traverse list2 to find its tail, and set its next pointer to post.
// 3) Return Modified List: After the modification, return list1, which now has the merged content.

// Time Complexity:O(N), where N is the number of nodes in list1
// Space Complexity:O(1), as no additional data structures are used, and only pointers are manipulated.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to merge list2 into list1 between indices a and b
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* pre = nullptr;  // Node at index a-1
    ListNode* post = list1;  // Node at index b+1

    // Step 1: Traverse to find the node at index a-1 (pre)
    ListNode* curr = list1;
    for (int i = 0; i < a - 1; i++) {
        curr = curr->next;
    }
    pre = curr;

    // Step 2: Traverse to find the node at index b+1 (post)
    curr = list1;
    for (int i = 0; i <= b; i++) {
        curr = curr->next;
    }
    post = curr;

    // Step 3: Connect pre's next to the head of list2
    pre->next = list2;

    // Step 4: Traverse to the end of list2
    while (list2->next != nullptr) {
        list2 = list2->next;
    }

    // Step 5: Connect the tail of list2 to post
    list2->next = post;

    return list1;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver function to test the implementation
int main() {
    // Create list1: 0 -> 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    // Create list2: 100 -> 101 -> 102
    ListNode* list2 = new ListNode(100);
    list2->next = new ListNode(101);
    list2->next->next = new ListNode(102);

    // Merge list2 into list1 between indices 2 and 4
    list1 = mergeInBetween(list1, 2, 4, list2);

    // Print the modified list1
    printList(list1);

    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------


//OPTIMAL-APPROACH-SOLUTION

//Approach: 
//i) Finding the pre and post Nodes:You first traverse list1 to find the nodes just before index a (pre) and just after index b (post).
//ii)Connecting the Lists: Set pre->next to the head of list2. and then Traverse list2 to find its last node and set its next pointer to the post node.
//iii)Returning the Modified List:The modified list1 (with the merged list2 inserted) is returned.
//Time Complexity:O(N): the overall time complexity is linear in terms of the size of the lists.
//Space Complexity:O(1): You are only modifying pointers and not using any extra space.

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre = nullptr;
        ListNode* post = nullptr;
        ListNode* current = list1;
        int index = 0;
        
        // Traverse the list to find the node just before index 'a' (pre) 
        // and the node just after index 'b' (post)
        while (current) {
            if (index == a - 1) pre = current; // Node before index 'a'
            if (index == b + 1) post = current; // Node after index 'b'
            current = current->next;
            index++;
        }

        // Connect pre to the head of list2
        if (pre) pre->next = list2;

        // Traverse list2 to find its last node
        while (list2 && list2->next) list2 = list2->next;

        // Connect the last node of list2 to post
        if (list2) list2->next = post;

        return list1;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Initialize list1 and list2
    vector<int> list1_vals = {0, 1, 2, 3, 4, 5};
    vector<int> list2_vals = {1000000, 1000001, 1000002};
    
    // Create the linked lists from vectors
    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);
    
    // Instantiate Solution class and merge the lists
    Solution sol;
    ListNode* result = sol.mergeInBetween(list1, 3, 4, list2);
    
    printList(result); 
    
    return 0;
}

