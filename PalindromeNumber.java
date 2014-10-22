public class Solution {
	public boolean isPalindrome(int x) {
		if(x < 0)
			return false;
		int temp = x;
		int check = 0;
		while(x > 0) {
			check = check * 10;
			check += x % 10;
			x /= 10;
		}
		return check == temp;
	}
}
