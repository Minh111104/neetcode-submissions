// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    // Implementation of Insertion Sort
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size();
        vector<vector<Pair>> res;  // To store the intermediate states of the array

        for (int i = 0; i < n; i++) {
            int j = i - 1;
            
            // Move elements that are greater than key one position ahead
            while (j >= 0 && pairs[j].key > pairs[j + 1].key) {
                swap(pairs[j], pairs[j + 1]);
                j--;
            }

            // Clone and save the entire state of the array at this point
            res.push_back(pairs);
        }
        return res;
    }
};
