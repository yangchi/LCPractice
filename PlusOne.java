public class Solution {
	public int[] plusOne(int[] digits) {
		int carry = 0;
		int index = digits.length - 1;
		digits[index]++;
		while(index >= 0 && digits[index] > 9) {
			digits[index] = 0;
			if(index > 0) {
				digits[index - 1]++;
			} else if(index == 0) {
				carry = 1;
			}
			index--;
		}
		if(carry == 1) {
			int [] result = new int[digits.length + 1];
			for(int i = 1; i < result.length; i++) {
				result[i] = digits[i - 1];
			}
			result[0] = carry;
			return result;
		} else {
			int [] result = new int[digits.length];
			for(int i = 0; i < result.length; i++) {
				result[i] = digits[i];
			}
			return result;
		}
	}
}
