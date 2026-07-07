class Solution {
public:

    // kadane
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = curr_sum;
        for (int i = 1; i < nums.size(); i++) {
            curr_sum = max(nums[i], curr_sum + nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum; 
    }
};


/*
        AI Lectures
        The core requirement: monotonicity
Sliding window works only when shrinking the window from the left is monotonically "safe" — meaning: once you've found a valid window ending at right, you know exactly how far to shrink from the left, and you'll never want to un-shrink later. This relies on some quantity behaving predictably as you add/remove elements — usually because all elements have a consistent sign or effect.
Concretely, ask yourself:

"If I remove the leftmost element from my window, does the window get monotonically 'better' or 'worse' in a way I can reason about — for every possible future, not just right now?"

If yes → sliding window. If the answer is "it depends on what comes later" → sliding window is the wrong tool.
When it works (classic patterns)
1. All non-negative numbers, sum/count constraint
cpp// Smallest subarray with sum >= target (nums all positive)
while (sum >= target) {
    sum -= nums[left++];
}
Why it works: every element you add only increases the sum, and every element you remove only decreases it. There's no ambiguity — shrinking is always "reduce sum," growing is always "increase sum." The relationship between window size and sum is monotonic.
2. Longest substring without repeating characters
cppwhile (seen.count(s[right])) {
    seen.erase(s[left]);
    left++;
}
Why it works: the "validity" condition (no duplicates) is monotonic in window size — if a window [l, r] is invalid, every wider window containing it is also invalid. Shrinking from the left can only help, never hurt.
3. At most K distinct characters, max consecutive 1s with K flips, etc.
Same idea — the constraint you're tracking only moves in one direction as the window grows or shrinks.
Why your Kadane's attempt broke
In max subarray sum, elements can be negative, so removing nums[left] from the window can either increase or decrease curr_sum depending on the sign of nums[left]. There's no consistent "shrinking helps" rule.
Your code's shrink condition was curr_sum < 0 — but that only checks the aggregate sum, not whether the specific left element is the problem. In the trace I did earlier, curr_sum = 3 (non-negative, so no shrink), but the window still contained a -3 that was actively hurting you. The algorithm had no way to detect "this particular leftmost element is bad" — because sliding window's whole mechanism is built around a global running quantity, not per-element blame.
This is the giveaway: when you need to know something about a specific element inside the window (not just an aggregate), sliding window is usually the wrong lens.
Quick diagnostic checklist
Ask these before reaching for two pointers:
QuestionSliding window OK?Are all elements non-negative (or same sign)?✅ likelyIs "window valid" monotonic in window size?✅ likelyDo you ever need to reconsider an element you already shrank past?❌ noCan removing the leftmost element make things worse sometimes and better other times?❌ noIs the real invariant "best value ending at position i" rather than "best window right now"?❌ think DP instead
The pattern that does fit max subarray: Kadane's
Kadane's works because it doesn't try to maintain a window at all — it's actually a 1D DP in disguise:
dp[i] = max(nums[i], dp[i-1] + nums[i])
"Best subarray ending at i" only depends on "best subarray ending at i-1," collapsed into a single running variable. No left pointer, no shrinking — because the moment you allow negative numbers, "should I drop the left element" isn't answerable without knowing the full history, which DP naturally tracks and sliding window doesn't.
Rule of thumb to carry forward

Sliding window = "the boundary of validity moves in one direction as I scan" (think: monotonic constraints, non-negative sums, character-set restrictions).
Kadane's / prefix-DP style = "the best answer at position i depends on the best answer at i-1, and signs can flip" (think: subarray sums with negatives, max product subarray, buy/sell stock).
Two pointers (different from window) = sorted arrays, pair-sum problems, partitioning — pointer movement is justified by sortedness, not window validity.≈≈


*/