/**
 * Question Link: https://leetcode.com/problems/find-peak-element/
 * Primary idea: Classic Binary Search  
 *
 * Time Complexity: O(logn), Space Complexity: O(1)
 */

class FindPeakElement {
    func findPeakElement(_ nums: [Int]) -> Int {
        var left = 0, right = nums.count - 1, mid = 0
        
        while left < right {
            mid = (right - left) / 2 + left
            
            if nums[mid] > nums[mid + 1] {
                right = mid
            } else {
                left = mid + 1
            }
        }
        
        return left
    }
}