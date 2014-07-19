public class Solution {
	public String reverseWords(String s) {
		String [] word_list = s.split(" ");
		ArrayList<String> reversed_words = new ArrayList<String>();
		for(int i = word_list.length - 1; i >= 0; i--)
		{
			if (!word_list[i].isEmpty() && word_list[i] != " ")
				reversed_words.add(word_list[i]);
		}
		String ret = new String("");
		for(String word: reversed_words)
		{
			ret += word + " ";
		}
		return ret.substring(0, ret.length() - 1 < 0 ? 0 : ret.length() - 1);
	}
}
