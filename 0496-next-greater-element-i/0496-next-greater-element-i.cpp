class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        s.push(-1);
        vector<int> nextG(nums2.size(), -1);

        int n2 = nums2.size();
        for(int i=n2-1; i>=0; i--){
            int currElem = nums2[i];
            while(s.top() <= currElem && s.top() != -1){
                s.pop();
            } 
            nextG[i] = s.top();
            s.push(currElem);
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nextG[j]);
                }
            }
        }


        return ans;


    }
};