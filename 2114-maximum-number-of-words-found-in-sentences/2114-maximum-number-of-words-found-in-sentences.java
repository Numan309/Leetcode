class Solution {
    public int mostWordsFound(String[] sentences) {
        int n = sentences.length;
        int maxwords = 0;
        for(int i = 0; i<n; i++){
            int cnt = 1;
            for(int j = 0; j<sentences[i].length(); j++){
                if(sentences[i].charAt(j) == ' ') cnt++;
            }
            maxwords = Math.max(cnt,maxwords);
        }
        return maxwords; 
    }
}