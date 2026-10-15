class Solution {
public:

    string removeKdigits(string num, int k) {

        int n = num.length();
        if(k>=n) return "0";
        
        string  ans="";
        stack <char> st;

        for(int i=0;i<n;i++){

            while( k>0 && !st.empty() &&  (st.top()-'0')>(num[i]-'0') ){
                
                st.pop();
                k--;
            }

            st.push(num[i]); 

        }

        while(k!=0){
            k--;
            st.pop();
        }


while(!st.empty()){
    ans += st.top();
    st.pop();
}

reverse(ans.begin(), ans.end());

       
        int i=0;
        int m=ans.size();
        while(i<m && ans[i]=='0'){
            i++;
        }

         if(ans=="" || i==m) return "0";
    
        return ans.substr(i);        
    }
};