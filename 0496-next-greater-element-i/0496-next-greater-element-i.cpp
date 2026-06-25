class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        s.push(-1);
        vector<int> nextG(nums2.size(), -1);
        unordered_map<int,int> greater;

        int n2 = nums2.size();
        for(int i=n2-1; i>=0; i--){
            int currElem = nums2[i];
            while(s.top() <= currElem && s.top() != -1){
                s.pop();
            } 
            nextG[i] = s.top();
            greater[nums2[i]] = nextG[i];
            s.push(currElem);
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(greater[nums1[i]]);
        }

        return ans;
    }
};