class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack <int> st;
        int n = heights.size();
        int maxi=INT_MIN;

        for(int i = 0;i<n;i++){

            while(!st.empty() && heights[st.top()]>heights[i]){

                    int x  = st.top();
                    st.pop();
                    int nsl = -1;
                    if(!st.empty()){
                     nsl = st.top();
                    }
                    int nsr = i;

                    maxi = max( maxi, heights[x]*(nsr - nsl-1));
            }
             st.push(i);   
        }

         while(!st.empty()){

             int x  = st.top();
             st.pop();
            int nsl = -1;
            if(!st.empty()){
                nsl = st.top();
            }
            int nsr = n;

            maxi = max( maxi, heights[x]*(nsr - nsl-1));

         }   

         return maxi;
    }
};