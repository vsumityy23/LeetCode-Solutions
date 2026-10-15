class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        
        int n=nums2.size();
        vector<int> nge(n);

        for(int i=0;i<n;i++){
        
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                nge[st.top()]=nums2[i];
                st.pop();
            }
            st.push(i);

        }

        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }

        vector<int> ans(nums1.size());

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){

                if(nums1[i]==nums2[j]){
                    ans[i]=nge[j];
                }

            }
        }
        return ans;
    }
};