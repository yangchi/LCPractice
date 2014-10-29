public class Solution {
	public int removeElement(int[] A, int elem) {
		if (A.length == 0)
			return 0;
		if (A.length == 1)
			return A[0] == elem ? 0 : 1;
		int left = 0, right = A.length - 1;
		while(left <= right) {
			if (A[left] == elem) {
				while(right >= 0 && A[right] == elem) {
					right--;
				}
				if(right < left){
					return left > 0 ? left : 0;
				} else {
					int temp = A[left];
					A[left] = A[right];
					A[right] = temp;
					right--;
					left++;
				}
			} else {
				left++;
			}
		}
		return left > 0 ? left : 0;
	}
}
