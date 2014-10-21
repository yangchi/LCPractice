public class Solution {
	public int removeDuplicates(int[] A) {
		if(A.length < 3) {
			return A.length;
		}
		HashMap<Integer, Integer> counter = new HashMap<Integer, Integer>();
		int value = A[0];
		counter.put(A[0], 1);
		int index = 1;
		for(int i = 1; i < A.length; i++) {
			if(A[i] == value) {
				if(counter.get(A[i]) == null) {
					counter.put(A[i], 1);
					A[index++] = A[i];
				} else if (counter.get(A[i]) < 2) {
					counter.put(A[i], counter.get(A[i]) + 1);
					A[index++] = A[i];
				} else {
					continue;
				}
			} else {
				A[index++] = A[i];
				value = A[i];
				counter.put(A[i], 1);
			}
		}
		return index;
	}
}
