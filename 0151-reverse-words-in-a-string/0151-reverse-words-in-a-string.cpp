class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        // first step puri string hi reverser krdo 
        reverse(s.begin(), s.end());

        // remove initial whitespaces
        int i=0;
        while(i<n && s[i] == ' '){
            i++;
        }

        // ab ek ek word ko reverse kreneg vapas excluding any number of spaces
        while(i<n){
            int j=i;
            while(j<n && s[j] != ' '){
                j++;
            }

            // ab yha j pkka ya to end me hoga ya to ek white space pe hoga yani ki ek valid word h usse phle 
            reverse(s.begin()+i, s.begin()+j); // vo word reverse ho gya h 
            i = j;

            while(i<n && s[i] == ' ') i++;
        }

        // yha tk sare qwords reverse ho chuke h bs ab spaces handle krne h 

        i=0;
        int j=0;

        while(i<n){
            while(i<n && s[i] == ' '){
                i++;
            }
            while(i<n && s[i] != ' '){
                s[j++] = s[i++];
            }

            while(i<n && s[i] == ' '){
                i++;
            }
            // ab yha j ek epacse ho gya h or i bhi to hme i ko ek bdhadena 
            if(i<n) {
                s[j++] = ' ';
            }

            
        }
        s.resize(j);
        return s;
    }
};