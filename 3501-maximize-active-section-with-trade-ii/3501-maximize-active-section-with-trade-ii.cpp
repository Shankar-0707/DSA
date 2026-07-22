void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]){
    if( l == r ){
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r-l)/2;
    buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
    buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
}

int* constructSt(int arr[], int n){
    int* segmentTree = new int[4*n];
    buildSegmentTree(0,0, n-1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]){
    if(l > end || r < start){
        return INT_MIN;
    }

    if(l >= start && r <= end){
        return segmentTree[i];
    }

    int mid = l + (r-l)/2;
    return max(querySegmentTree(start, end, 2*i+1, l, mid, segmentTree), querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b){
    return querySegmentTree(a, b, 0,0,n-1, st);
}


class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activeCount = count(s.begin(), s.end(), '1'); // to count the active ones in whole s

        vector<int> blockStart;
        vector<int> blockEnd;

        int i=0;
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i] == '0'){
                    i++;
                }
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
            }
            else{
                i++;
            }
        }

        int m = blockStart.size();

        if(m < 2){
            return vector<int>(queries.size(), activeCount);
            // kyoki agar 0 ka block ek ya usse km 0 hua to activeCount hi hmara answer hoga hr query ke liye 
        }

        vector<int> blockSize(m);
        for(int i=0; i<m; i++){
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        // ab hme pairSum bnana hoga 
        // pairSum[i] = blockSize[i] + blockSize[i+1];

        vector<int> pairSum(m-1);
        for(int i=0; i<m-1; i++){
            pairSum[i] = blockSize[i] + blockSize[i+1];
        }

        // constructr krenge ab segment Tree is pairSum ka 
        int *st = constructSt(pairSum.data(), m-1); // pairSum.data() isiliye kra kyoki hmne paisSum ko ek vector bnaya tha or constructTree ke paramneter me ek static array h 
        // to .data() krne se vo error nhi dega hmara data pass ho jaega 

        vector<int> result;

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            // first block in this range
            int low = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd);
            
            // Last Block in this range
            int high = upper_bound(begin(blockStart), end(blockStart), r) - begin(blockStart) - 1;
            int maxPairSum = 0;
            if(low < high){
                // we do this check beacse we want atleast 2 block for checking maxPairSum
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1;
                int lastLen = min(blockEnd[high], r) - blockStart[high] + 1;

                if(high - low == 1){
                    // sirf 2 hi pairs the mtlb 
                    maxPairSum = firstLen + lastLen;
                }
                else{
                    int pair1 = firstLen + blockSize[low+1];
                    int pair2 = blockSize[high-1] + lastLen;
                    int RMQMaxPairSum = RMQ(st, m-1, low+1, high-2);
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            } 

            result.push_back(maxPairSum + activeCount);
        }

        return result;
    }
};