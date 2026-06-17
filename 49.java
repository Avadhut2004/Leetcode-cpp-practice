class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String , List> mp = new HashMap<>();

        for(String s : strs){
            int[] count = new int[26];

            for(char c : s.toCharArray()){
                count[c-'a']++;
            }

            StringBuilder sb = new StringBuilder();
            for(int i:count){
                sb.append("#");
                sb.append(i);
            }

            String key = sb.toString();
          
// key generation for rach string done
          
            if(!mp.containsKey(key)){
                mp.put(key , new ArrayList<String>());
            }
            mp.get(key).add(s);
        }
        return new ArrayList(mp.values());
    }
}
