class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2; // work for both odd and even lengths

        if (B.size() < A.size()) {
            swap(A, B); // ensure A is the smaller array
        }
        int l = 0;
        int r = A.size();

        while (l <= r) {
            int i = l + (r - l) / 2; // i is the cut index (midpoint) in A
            int j = half - i; // j is the cut index in B (so that total elements on the left of both arrays equals half)
            
            // define border values around the cut
            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            // check if the partition is valid
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) { // total is odd
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) { // move the cut in A left
                r = i - 1;
            } else { // move the cut in A right
                l = i + 1;
            }
        }
        return -1;
    }
};
