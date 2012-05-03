import java.util.*;
public class Anagram {
    public ArrayList<String> anagrams(String[] strs) {
        ArrayList<String> list = new ArrayList<String>();
        Map<String, ArrayList<String>> map = new 
            HashMap<String,ArrayList<String>>();
        for (String s : strs) {
            char[] a = s.toCharArray();
            Arrays.sort(a);
            String s_sorted = new String(a);
            ArrayList<String> l;
            if (map.containsKey(s_sorted)) {
                l = map.get(s_sorted);
            } else {
                l = new ArrayList<String>();
            }
            l.add(s);
            map.put(s_sorted, l);
        }
        for (ArrayList<String> l : map.values()) {
            if (l.size()>1) {
                list.addAll(l);
            }
        }
        return list;
    }
}
