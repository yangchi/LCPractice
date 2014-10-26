public class Solution {
	public int minDistance(String word1, String word2) {
		int [][] distance = new int[word1.length() + 1][word2.length() + 1];
		if(word1.isEmpty())
			return word2.length();
		if(word2.isEmpty())
			return word1.length();
		for(int i = 0; i < word1.length() + 1; i++)
			distance[i][0] = i;
		for(int i = 0; i < word2.length() + 1; i++)
			distance[0][i] = i;
		for(int i = 0; i < word1.length(); i++) {
			for(int j = 0; j < word2.length(); j++) {
				if(word1.charAt(i) == word2.charAt(j)) {
					distance[i + 1][j + 1] = distance[i][j];
				} else {
					int insert = 1 + distance[i][j + 1];
					int replace = 1 + distance[i][j];
					int remove = 1 + distance[i + 1][j];
					int min = Math.min(insert, Math.min(replace, remove));
					distance[i + 1][j + 1] = min;
				}
			}
		}
		return distance[word1.length()][word2.length()];
	}
}
