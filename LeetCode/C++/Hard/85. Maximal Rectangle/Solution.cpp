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

    int maximalRectangle(vector<vector<char>>& matrix) {

        int ans =   INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>heights(m,0);

        for ( int i =0;i<n;i++){

            for (int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    heights[j]=0;
                }else{
                    heights[j]+=1;
                }
            }
            ans = max(ans,largestRectangleArea(heights));

        }
        return ans;
    }
};