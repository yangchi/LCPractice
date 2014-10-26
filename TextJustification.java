public class Solution {
	public List<String> fullJustify(String[] words, int L) {
		int count = 0;
		ArrayList<String> current_words = new ArrayList<String>();
		List<String> justified = new ArrayList<String>();
		for(int index = 0; index < words.length; index++) {
			String word = words[index];

			int current_length = word.length();
			if (count + current_words.size() + current_length > L) {
				int to_insert = L - count;
				int slots = current_words.size() > 1 ? current_words.size() - 1 : 1;
				String justified_str = new String();
				if (current_words.size() == 1) {
					justified_str = current_words.get(0);
					while(justified_str.length() < L)
						justified_str += " ";
				} else {
					to_insert = to_insert / slots;
					int diff = L - count - slots * to_insert;
					for(int i = 0; i < current_words.size(); i++) {
						justified_str += current_words.get(i);
						if(i != current_words.size() - 1) {
							for(int j = 0; j < to_insert; j++) {
								justified_str += " ";
							}
							if(diff-- > 0)
								justified_str += " ";
						}
					}
				}
				justified.add(justified_str);
				count = 0;
				current_words.clear();
				current_words.add(word);
				count += word.length();
			} else {
				count += word.length();
				current_words.add(word);
			}
			if(index == words.length - 1) {
				String last_line = new String();
				for(int i = 0; i < current_words.size(); i++) {
					last_line += current_words.get(i);
					if(i != current_words.size() - 1) {
						last_line += " ";
					}
				}
				while(last_line.length() < L) {
					last_line += " ";
				}
				justified.add(last_line);
				return justified;
			}
		}
		return justified;
	}
}
