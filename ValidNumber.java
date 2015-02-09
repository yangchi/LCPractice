public class Solution {
    public boolean isNumber(String s) {
        String trimmed = s.trim();
        if (trimmed.isEmpty())
            return false;
        boolean hasDot = false;
        boolean hasE = false;
        boolean hasNumber = false;
        boolean hasNumberAfterE = true;
        for(int i = 0; i < trimmed.length(); i++) {
            if(trimmed.charAt(i) >= '0' && trimmed.charAt(i) <= '9') {
                hasNumber = true;
                if(hasE)
                    hasNumberAfterE = true;
            } else if(trimmed.charAt(i) == '.') {
                if(hasDot || hasE)
                    return false;
                hasDot = true;
            } else if(trimmed.charAt(i) == 'e' || trimmed.charAt(i) == 'E') {
                if(!hasNumber)
                    return false;
                if(hasE)
                    return false;
                hasE = true;
                hasNumberAfterE = false;
            } else if(trimmed.charAt(i) == '-'){
                if(i != 0)
                    if(trimmed.charAt(i - 1) != 'e' && trimmed.charAt(i - 1) != 'E')
                        return false;
            } else if(trimmed.charAt(i) == '+'){
                if (i != 0) {
                    if(trimmed.charAt(i - 1) != 'e' && trimmed.charAt(i - 1) != 'E')
                        return false;
                }  
            } else if(trimmed.charAt(i) == ' ') {
                return false;
            } else {
                return false;
            }
        }
        return hasNumber && hasNumberAfterE;
    }
}
