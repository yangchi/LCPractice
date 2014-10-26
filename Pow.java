public class Solution {
	public double pow(double x, int n) {
		if(n == 0)
			return 1;
		if (n < 0) {
			n = -n;
			x = 1/x;
		}
		double result = 1;
		double temp = x;
		while(n > 0) {
			int curr = 1 & n;
			if(curr == 1)
				result *= temp;
			temp *= temp;
			n >>= 1;
		}
		return result;
	}
}
