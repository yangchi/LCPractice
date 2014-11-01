public class Solution {
	public String multiply(String num1, String num2) {
		ArrayList<Integer> final_result = new ArrayList<Integer>();
		for(int i = 0; i < num1.length() + num2.length() + 1; i++)
			final_result.add(0);
		for(int i = 0; i < num2.length(); i++) {
			int curr2 = num2.charAt(num2.length() - 1 - i) - '0';
			for(int j = 0; j < num1.length(); j++) {
				int curr1 = num1.charAt(num1.length() - 1 - j) - '0';
				int curr = curr1 * curr2 + final_result.get(i + j);
				final_result.add(i + j, curr % 10);
				final_result.add(i + j + 1, final_result.get(i + j + 1) + curr / 10);
			}
		}
		String result = "";
		int index = final_result.size() - 1;
		while(index >=0 && final_result.get(index) == 0)
			index--;
		if(index < 0)
			return "0";
		while(index >= 0) {
			result.concat(new String(Character.toChars(final_result.get(index--))));
		}
		return result;
	}
}
