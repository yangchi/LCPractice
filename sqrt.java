public class Solution {
	public int sqrt(int x) {
		long result = 0;
		long bit = 1 << 16;
		while(bit > 0) {
			result |= bit;
			if(result * result > x) {
				result ^= bit;

			}
			bit >>= 1;
		}
		return (int)result;
	}
}
