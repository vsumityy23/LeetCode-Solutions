class Solution {
public:
    int climbStairs(int n) {

        if(n==1) return 1;
        if (n==2) return 2;


        //base case 
        int last=2;
        int secondlast=1;
        int ans;

        for(int i=2;i<n;i++){
            ans=last+secondlast;
            secondlast=last;
            last=ans;
        }

        return ans;

    }
};

     