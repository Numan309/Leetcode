// import java.util.Arrays;
// import java.util.Comparator;

class Solution {
    public int countDays(int days, int[][] meetings) {
        if (meetings.length == 0) {
            return days;
        }
        
        // Sort meetings by their start times
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));

        int strt = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.length; i++) {
            if (meetings[i][0] <= end) {
                end = Math.max(end, meetings[i][1]);
            } else {
                days -= end - strt + 1;
                strt = meetings[i][0];
                end = meetings[i][1];
            }
        }
        days -= end - strt + 1;

        return days;
    }
}
