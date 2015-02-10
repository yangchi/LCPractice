public class Solution {
    public int[] searchRange(int[] A, int target) {
        return searchRangeRecur(A, target, 0, A.length - 1);
    }

    public int[] searchRangeRecur(int[] A, int target, int begin, int end) {
        int[] result = {-1, -1};
        if (end < begin) {
            return result;
        }

        if (begin == end) {
            if (A[begin] == target) {
                result[0] = begin; result[1] = end;
                return result;
            } else {
                return result;
            }
        }

        int mid = begin + (end - begin) / 2;
        if (A[mid] == target) {
            int[] left_result = searchRangeRecur(A, target, begin, mid - 1);
            int[] right_result = searchRangeRecur(A, target, mid + 1, end);
            if (left_result[0] != -1) {
                result[0] = left_result[0];
            } else {
                result[0] = mid;
            }

            if (right_result[1] != -1) {
                result[1] = right_result[1];
            } else {
                result[1] = mid;
            }

            return result;
        } else if (A[mid] < target) {
            return searchRangeRecur(A, target, mid + 1, end);
        } else {
            return searchRangeRecur(A, target, begin, mid - 1);
        }
    }
}
