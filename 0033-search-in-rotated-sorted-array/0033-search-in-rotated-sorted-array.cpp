class Solution {
public:
int search(vector<int>& nums , int target) { 
    int len = nums.size();
    int start = 0; 
    int end = len-1;
    while (start<=end) { 
        int mid = start +(end-start)/2;
        if (nums[mid] == target) { 
            return mid;
        }
        //left array is sorted//
        if (nums[start] <= nums[mid]) {
            //check whether the target is there or not//
            if (target>=nums[start] && target < nums[mid]) {
                end = mid - 1;
            } else { 
                start = mid+1; //that means target = unsorted array//
                //Now unsorted array = sorted array + unsorted array (coz middle value in that array divides the further arrays)//
                //.. Repeat the same for that array as well//
            }
        } 
        
        //right array is sorted// 
        else { 
            if (target >  nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid-1; //array is in left unsorted array...//
            }
        }
    }
    return -1;
}
};