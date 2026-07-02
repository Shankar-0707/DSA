class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();

        int i=0; 
        int j=0;

        while(i < n1 || j < n2){
            // remove leading zeroes until another revision
            while(i<n1 && version1[i] != '.' && version1[i] == '0'){
                i++;
            }

            int num1 = 0;
            while(i<n1 && version1[i] != '.'){
                int dig = version1[i] - '0';
                num1 = num1*10 + dig;
                i++;
            }

            i++;

            while(j<n2 && version2[j] != '.' && version2[j] == '0'){
                j++;
            }

            int num2 = 0;
            while(j<n2 && version2[j] != '.'){
                int dig = version2[j] - '0';
                num2 = num2*10 + dig;
                j++;
            }

            j++;

            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
        }

        return 0;
    }
};