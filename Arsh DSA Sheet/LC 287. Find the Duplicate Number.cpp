
// Slow & Fast pointer approach - Floyd's tortoise and hare algorithm

/*
1. Detect the presence of cycle
2. Find the starting point of the cycle
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	
    	//initialize slow, fast pointer with head
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        /*
        1. Detect presence of cyle:
        the point where slow and fast pointer meet, 
        we will leave our slow pointer there
        */
        while(slow!=fast){
            slow = nums[slow];               // slow pointer moves one step at a time
            fast = nums[nums[fast]];         // fast pointer moves two steps at a time
        }
        
        /*
        2. Find the starting point of the cycle:
        Initialize slow2 from head, move slow from
        the point we left it off.
        The point where slow and slow2 meet will be 
        the starting of the cycle and "duplicate number"
        */
        int slow2 = 0;
        while(slow!=slow2){
            slow = nums[slow];              // both slow2 & slow move one step at a time
            slow2 = nums[slow2];
        }
        return slow;
    }
};
/* possible intuition: if there are n+1 boxes and we have n pencils to be placed inside them (one pencil in each box),
then one of the pencil will be repeated in one of the boxes - causing duplicates
*/


/*-----------------------------------*/
// Brute Force Solution - causes TLE
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

