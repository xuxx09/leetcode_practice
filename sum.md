### 1. Two Sum
```
// O(n*n) solution
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++){
            for (int j = i + 1; j < nums.length; j ++) {
                if(nums[j] == target - nums[i]) {
                    return new int[]{i, j};
                }
            }
        }
        throw new IllegalArgumentException("no solution");
    }
}
```

```
// O(n) solution
class Solution {
    public int[] twoSum(int[] nums, int target) {
       Map<Integer, Integer> map = array2Map(nums);
        for(int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement) && map.get(complement) != i) {
                return new int[]{i, map.get(complement)};
            }
        }
        throw new IllegalArgumentException("no solution");
    }
    
    private Map<Integer, Integer> array2Map(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i< nums.length; i++) {
            map.put(nums[i], i);
        }
        return map;
    }
}
```
