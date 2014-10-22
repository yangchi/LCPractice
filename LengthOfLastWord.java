public class Solution {
	public int lengthOfLastWord(String s) {
		if(s.trim().isEmpty())
			return 0;
		s = s.trim();
		int index = s.lastIndexOf(' ');
		if(index == -1)
			return s.length();
		if(index == s.length() - 1) {
			return s.length() - s.indexOf(' ');
		}
		return s.length() - 1 - index;
	}
}
