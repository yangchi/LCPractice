import java.util.HashMap;

public class MinimumWindowSubstring {
    public String minWindow(String S, String T) {
        String minimalString = "";
        HashMap<Character, Integer> needs = new HashMap<Character, Integer>();
        for(int i = 0; i < T.length(); i++) {
            if(needs.get(T.charAt(i)) == null) {
                needs.put(T.charAt(i), 1);
            } else {
                needs.put(T.charAt(i), needs.get(T.charAt(i)) + 1);
            }
        }
        HashMap<Character, Integer> hasFound = new HashMap<Character, Integer>();
        for(Character ch : needs.keySet()) {
            hasFound.put(ch, 0);
        }
        int count = 0;
        int begin = -1;
        int minimal = Integer.MAX_VALUE;
        for(int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            if(needs.get(ch) == null)
                continue;
            if(begin == -1)
                begin = i;
            hasFound.put(ch, hasFound.get(ch) + 1);
            if(needs.get(ch) >= hasFound.get(ch)) {
                count++;
            }
            if(count == T.length()) {
                while(begin < S.length() && (hasFound.get(S.charAt(begin)) == null || hasFound.get(S.charAt(begin)) > needs.get(S.charAt(begin)))) {
                    if(hasFound.get(S.charAt(begin)) != null) {
                        hasFound.put(S.charAt(begin), hasFound.get(S.charAt(begin)) - 1);
                    }
                    begin++;
                }
                if (minimal > i - begin + 1) {
                    minimal = i - begin + 1;
                    minimalString = S.substring(begin, minimal + begin);
                }
            }
        }
        return minimalString;
    }

    public static void main(String [] args) {
        MinimumWindowSubstring mws = new MinimumWindowSubstring();
        mws.minWindow("abcabdebac", "cda");
    }
}
