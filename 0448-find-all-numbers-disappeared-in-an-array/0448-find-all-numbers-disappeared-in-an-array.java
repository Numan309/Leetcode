class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
       List<Integer> result = new ArrayList<>();
        
        // Create a HashSet to store the numbers that appear in the array
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        
        // Iterate from 1 to n and check if each number is in the set
        for (int i = 1; i <= nums.length; i++) {
            if (!set.contains(i)) {
                result.add(i); // If the number is not in the set, add it to the result list
            }
        }
        
        return result;
        } 
    }
    