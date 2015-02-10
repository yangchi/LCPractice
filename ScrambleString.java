public class Solution {
	public boolean isScramble(String s1, String s2) {
		if (s1.length() != s2.length()) {
			return false;
		}
		boolean [][][] dp = new boolean[s1.length()][s2.length()][s1.length() + 1];
		for (int i = 0; i < s1.length(); i++) {
			for (int j = 0; j < s2.length(); j++) {
				dp[i][j][0] = true;
				dp[i][j][1] = s1.charAt(i) == s2.charAt(j);
			}
		}

		for(int len = 2; len <= s1.length(); len++) {
			for(int i = 0; i <= s1.length() - len; i++) {
				for (int j = 0; j <= s2.length() - len; j++) {
					for (int cut = 1; cut < len; cut++) {
						dp[i][j][len] = dp[i][j][len] || (dp[i][j][cut] && dp[i + cut][j + cut][len - cut] || dp[i][j + len - cut][cut] && dp[i + cut][j][len - cut]);
						if (dp[i][j][len]) {
							break;
						}
					}
				}
			}
		}

		return dp[0][0][s1.length()];
	}
}
