public class Solution {
	public String addBinary(String a, String b) {
		String result = "";
		int carry = 0;
		int i = 0;
		for(; i < Math.max(a.length(), b.length()); i++) {
			int digit_a, digit_b;
			if(i < a.length()) {
				char char_a = a.charAt(a.length() - 1 - i);
				digit_a = (char_a == '0' ? 0 : 1);
			} else {
				digit_a = 0;
			}

			if(i < b.length()) {
				char char_b = b.charAt(b.length() - 1 - i);
				digit_b = (char_b == '0' ? 0 : 1);
			} else {
				digit_b = 0;
			}
			int newcarry = (carry + digit_a + digit_b) / 2;
			int result_digit = (carry + digit_a + digit_b) % 2;
			result = (result_digit == 0 ? "0" : "1") + result;
			carry = newcarry;
		}
		if(carry == 1)
			return "1" + result;
		else
			return result;
	}
}
