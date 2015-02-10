public class Solution {
	public boolean isMatch(String s, String p) {
		int index_s = 0, index_p = 0;
		int s_covered_by_star = -1;
		int star_index = -1;
		while(index_s < s.length()) {
			if (index_p < p.length() && (s.charAt(index_s) == p.charAt(index_p) || p.charAt(index_p) == '?')) {
				index_s++; index_p++;
			} else if (index_p < p.length() && p.charAt(index_p) == '*') {
				s_covered_by_star = index_s;
				star_index = index_p;
				index_p++;
			} else if (s_covered_by_star != -1) {
				index_p = star_index + 1;
				s_covered_by_star++;
				index_s = s_covered_by_star;
			} else {
				return false;
			}
		}

		if (index_s < s.length()) {
			return false;
		}

		while (index_p < p.length() && p.charAt(index_p) == '*') {
			index_p++;
		}

		return index_p == p.length();
	}
}
