class Solution {
public:
    int min(int a, int b){
        return a < b ? a : b;
    }

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> vec(1e5+1, 0);

        for(int i=0; i<n; i++){
            int diff = abs(nums1[i] - nums2[i]);
            vec[diff]++;
        }
        long long k = k1 + k2;
        int j = vec.size()-1;
        while(j>0 && k>0){
            if(vec[j] == 0){
                j--;
            }
            else{
                // hme maximum mil jaega 
                int countOps = min(vec[j], k);
                vec[j] -= countOps;
                vec[j-1]+= countOps;
                k-= countOps;
                j--;
            }
        }

        long long ans = 0;

        for(int i=0; i<vec.size(); i++){
            ans+= 1LL * i *i* vec[i];
        }

        return ans;

        // for(int i=0; i<n; i++){
        //     diff[i] = abs(nums1[i] - nums2[i]); 
        // }

        // long long k = 1LL *  k1 + k2; // total operations jo hm reduce kr skte h 
        // // as agar hm nums1 me +1 krenge to diff me -1 ki trah act hoga in nums2

        // priority_queue<int> pq;

        // for(auto num : diff){
        //     pq.push(num);
        // }

        // while(k > 0 && !pq.empty()){
        //     auto top = pq.top();
        //     pq.pop();

        //     if(top > 0){
        //         pq.push(top-1);
        //     }
        //     else{
        //         pq.push(0);
        //         break;
        //     }
        //     k--;
        // }

        // long long ans = 0;

        // while(!pq.empty()){
        //     ans+= 1LL * pq.top() * pq.top();
        //     pq.pop();
        // }

        // return ans;
    }
};