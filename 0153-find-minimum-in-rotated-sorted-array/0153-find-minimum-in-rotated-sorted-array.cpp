class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // Edge Case Single elemenet 
        if(n == 1) return  nums[0];

        // case 1 No rortation happens 
        if(nums[0] < nums[n-1]) return nums[0];

        // Now rotation happens 
        int s = 0;
        int e = n-1;
        
        while( s < e){
            int mid = s + (e-s)/2;

            if(nums[mid] > nums[e]){
                // pkka right me answer hoga
                s = mid+1;
            }
            else{
                // ho skta h ki mid ek answer ho 
                e = mid;
            }
        }

        // yha per ek hi element hoga 
        return nums[s];
    }
};