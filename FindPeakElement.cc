class Solution {
    public:
        int findPeakElement(const vector<int> &num) {
            return findPeakElementBinary(num, 0, num.size());
        }

        int findPeakElementBinary(const vector<int> & num, int begin, int end) {
            if (begin >= end) {
                return -1;
            }
            if (begin == end - 1) {
                return begin;
            }
            if (begin == end - 2) {
                return num[begin] > num[begin + 1] ? begin : begin + 1;
            }

            int mid = begin + (end - begin) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) {
                return mid;
            } else if (num[mid - 1] > num[mid]) {
                return findPeakElementBinary(num, begin, mid);
            } else {
                return findPeakElementBinary(num, mid + 1, end);
            }
        }
};
