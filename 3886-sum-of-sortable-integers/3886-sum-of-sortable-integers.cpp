class Solution {
public:

    void computeLPS(vector<int>& pattern, vector<int>& lps){
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while(i < M){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool search(vector<int>& pattern, vector<int>& text){
        // KMP algorithm for finding pattern in a text -> linear
        int N = text.size();
        int M = pattern.size();

        vector<int> lps(M, 0);
        computeLPS(pattern, lps);

        int i = 0; // text
        int j = 0; // pattern

        while(i<N){
            if(pattern[j] == text[i]){
                i++;
                j++;
            }

            if(j == M){
                return true; // pattern mil gya h 
            }
            else if(i<N && pattern[j] != text[i]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return false;
    }

    bool isRotation(vector<int>& vec1, vector<int>& vec2){
        vector<int> vec3 = vec2;
        vec3.insert(vec3.end(), vec2.begin(), vec2.end());
        return search(vec1, vec3);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(nums.begin(), nums.end()); // O(nlogn)
        int ans = 0;

        for(int k = 1; k<=n; k++){
            if(n % k != 0) continue;
            else{
                bool valid = true;
                for(int start = 0; start < n; start+=k){
                    vector<int> vec1(nums.begin()+start, nums.begin()+start+k);
                    vector<int> vec2(sorted.begin()+start, sorted.begin()+start+k);

                    if(!isRotation(vec1, vec2)){
                        valid = false;
                        break;
                    }
                }

                if(valid){
                    ans+= k;
                }
            }
        }

        return ans;
    }
};