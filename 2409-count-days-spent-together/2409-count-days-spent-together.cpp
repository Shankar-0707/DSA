class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        vector<int> daysContain = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        string arrivalString = "";
        string leavingString = "";

        for(int i=0; i<5; i++){
            if(arriveAlice[i] > arriveBob[i]){
                arrivalString+= arriveAlice;
                break;
            }
            if(arriveAlice[i] < arriveBob[i]){
                arrivalString+= arriveBob;
                break;
            }
        }

        if(arrivalString.length() == 0){
            // iska mtlb dono same din aaye the 
            arrivalString = arriveBob;
        }


        for(int i=0; i<5; i++){
            if(leaveAlice[i] > leaveBob[i]){
                leavingString = leaveBob;
                break;
            }
            if(leaveAlice[i] < leaveBob[i]){
                leavingString+= leaveAlice;
                break;
            }
        }

        if(leavingString.length() == 0){
            // iska mtlb dono same din aaye the 
            leavingString = leaveAlice;
        }

        // now we get the max arrival of them and min leaving of them merans intersection
        // extract month 
        int arrivalMonth = 0;
        int arrivalDate = 0;

        for(int i=0; i<2;i++){
            int dig = (arrivalString[i] - '0'); 
            arrivalMonth = arrivalMonth*10 + dig;
        }

        for(int i=3; i<5; i++){
            int dig = (arrivalString[i] - '0');
            arrivalDate = arrivalDate*10 + dig;
        }

        // extracting leaving cresentials 
        int leavingMonth = 0;
        int leavingDate = 0;

        for(int i=0; i<2;i++){
            int dig = (leavingString[i] - '0'); 
            leavingMonth = leavingMonth*10 + dig;
        }

        for(int i=3; i<5; i++){
            int dig = (leavingString[i] - '0');
            leavingDate = leavingDate*10 + dig;
        }


        /// now we have arrival month arrival date leaving month leaving date 
        if(leavingMonth < arrivalMonth) return 0;

        if(leavingMonth == arrivalMonth){
            if(leavingDate < arrivalDate) return 0;

            return (leavingDate - arrivalDate + 1);
        }

        // iska mtlb leaving mnth jyada h 
        int ans = 0;

        // current month ko include kro 
        ans += (daysContain[arrivalMonth-1] - arrivalDate + 1);

        ans+= (leavingDate);

        for(int month = arrivalMonth + 1 ; month < leavingMonth; month++){
            ans+= (daysContain[month-1]);
        }

        return ans;
    }
};