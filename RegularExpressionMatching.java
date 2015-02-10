public class Solution {
	public boolean isMatch(String s, String p) {
		if (p.isEmpty()) {
			return s.isEmpty();
		}

		if (p.length() == 1) {
			return s.length() == 1 && (p.charAt(0) == '.' || p.charAt(0) == s.charAt(0));
		}

		char c = p.charAt(0);
		if (p.charAt(1) != '*') {
			return !s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') && isMatch(s.substring(1), p.substring(1));
		}

		if (isMatch(s, p.substring(2))) {
			return true;
		}

		for(int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == p.charAt(0) || p.charAt(0) == '.') {
				if (isMatch(s.substring(i+1), p.substring(2))) {
					return true;
				}
			} else {
				break;
			}
		}

		return false;
	}
}
