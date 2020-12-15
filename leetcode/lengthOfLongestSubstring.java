// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        return solution2(s);
    }

    // brute-force
    private int solution1(String s) {
        char[] str = s.toCharArray();
        int lss = 0;
        for (int i = 0; i < str.length; i++) {
            for (int j = i; j < str.length; j++) {
                Set<Character> visited = new HashSet<>();
                boolean unique = true;
                for (int k = i; k <= j; k++) {
                    if (!visited.add(str[k])) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    lss = Math.max(j - i + 1, lss);
                }
            }
        }
        return lss;
    }

    // sliding window - linear time
    private int solution2(String s) {
        Set<Character> visited = new HashSet<>();
        int lss = 0, l=0, r=0;
        while(l<s.length() && r<s.length()) {
            if(visited.add(s.charAt(r))) {
                lss = Math.max(lss, r-l+1);
                r++;
            } else {
                visited.remove(s.charAt(l));
                l++;
            }
        }
        return lss;
    }

    // linear time, map
    private int solution3(String s) {
        Map<Character, Integer> pos = new HashMap<>();
        int lss = 0;
        int l = 0;
        for(int r=0;r<s.length();r++) {
            Integer oldPos = pos.put(s.charAt(r), r);
            if(oldPos==null) {
                oldPos = -1;
            }
            l = Math.max(l, oldPos+1);
            lss = Math.max(r-l+1, lss);
        }
        return lss;
    }
}

