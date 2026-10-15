class Solution {
public:
    int sumSubarrayMins(vector<int>& heights) {

        stack <int> st;
        int n = heights.size();
        int sum=0;
        const int mod = 1e9 + 7;

        for(int i = 0;i<n;i++){

            while(!st.empty() && heights[st.top()]>heights[i]){

                    int x  = st.top();
                    st.pop();
                    int nsl = -1;
                    if(!st.empty()){
                     nsl = st.top();
                    }
                    int nsr = i;
                     
                    sum = (sum+(nsr-x)*(x-nsl)*heights[x])%mod;
                   
            }
             st.push(i);   
        }

         while(!st.empty()){

             long long x  = st.top();
             st.pop();
            long long nsl = -1;
            if(!st.empty()){
                nsl = st.top();
            }
            int nsr = n;

            sum = (sum+(nsr-x)*(x-nsl)*heights[x])%mod;

         }   

         return sum;
        
    }
};