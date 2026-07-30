class Solution {
public:
    int minimumPushes(string word) {
        // Hmare paas avaialable keys h 8 means 2,3,4,5,6,7,8,9 jinko hm press kr skte h to agar hm inhe map bhi krte h to best triak h ki hm 8 charcaters tk ko first place ope map kr skte h yani ki 8 distinct characters to one push me ho jayenge lekin fir agle 8 charcters ko hm one push me nhi  kr skte unhe 2 push chaiye honge 

        int n = word.length();
        int i=0;

        int pushes = 0;
        int push = 1;

        while(i<n){
            if(i != 0 && (i%8 == 0)){
                push++;
            }

            pushes+= push;
            i++;
        }

        return pushes;

    }
};