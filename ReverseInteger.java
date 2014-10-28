public class Solution {
	public int reverse(int x) {
		boolean negative = x < 0 ? true : false;
		x = x < 0 ? -x : x;
		int result = 0;
		while(x > 0) {
			result *= 10;
			result += x % 10;
			x /= 10;
		}
		return result * (negative ? -1 : 1);
	}
}
