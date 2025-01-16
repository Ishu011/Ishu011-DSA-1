//Approach 1: Two Pointers

//Intuition : The goal is to reveal the deck in increasing order. We start by sorting the deck in increasing order, so we can work backward to the special order. We create an array result to store the cards in the special order.
//Approach : i) Initialize variables Required
//ii) Fill the result array
//iii) Flip the value of skip (toggle between true and false).
//iv) Increment indexInResult and Return the result array, which contains the cards in the special order.

//Time complexity: O(nlogn), Space complexity: O(n) or O(logn).

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        vector<int> result(N);
        bool skip = false;
        int indexInDeck = 0;
        int indexInResult = 0;
        sort(deck.begin(), deck.end());

        while (indexInDeck < N) {
            if (result[indexInResult] == 0) {
                if (!skip) {
                    result[indexInResult] = deck[indexInDeck];
                    indexInDeck++;
                }

                // Toggle skip to alternate between adding and skipping cards
                skip = !skip;
            }
            // Progress to the next index of result array
            indexInResult = (indexInResult + 1) % N;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result = solution.deckRevealedIncreasing(deck);
    cout << "Test Case 1 Result: ";
    for (int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------

//Approach 2: Simulation with Queue

//Intuition : The above solution made multiple passes through result to add the cards.In this solution, we also start by sorting the deck and creating a result array.
//Algorithm : i)Initialize N to the length of the deck.
//ii) Create a queue to store the indices of the cards, and add the indices 0 to N to the queue.
//iii) Sort the deck and Initialize an array result of size N to store the answer.
//iv)Loop through the cards, Set result at the front index in the queue to deck[i].
//v)Take the next index in the queue and move it to the back of the queue. Return result.
//Time complexity: O(nlogn), Space complexity: O(n)

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        // Step 1: Create a queue of indexes
        for (int i = 0; i < N; i++) {
            queue.push(i);
        }

        // Step 2: Sort the deck in increasing order
        sort(deck.begin(), deck.end());

        // Step 3: Initialize result array and simulate the card revealing process
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            // Reveal Card by placing it at the front index in the queue
            result[queue.front()] = deck[i];
            queue.pop();

            // Move next card index to the bottom of the queue
            if (!queue.empty()) {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result = solution.deckRevealedIncreasing(deck);
    cout << "Test Case Result: ";
    for (int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
