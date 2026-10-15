class Solution {
public:

    bool iscollide(int a1,int a2){
        if (a1>0 && a2<0){
            return true;
        }
        
        return false;

    }

    vector<int> asteroidCollision(vector<int>& arr) {

    int n=arr.size();
    stack<int> st;
    int push=true;

    for(int i=0;i<n;i++){

        push=true;

        while(!st.empty() && iscollide(st.top(),arr[i])){

            if(st.top()<abs(arr[i])){
                st.pop();
            }
            else if (st.top()==abs(arr[i])){
                st.pop();
                push=false;
                break;
            }else{
                push=false;
                break;
            }


        }

        if(push){
            st.push(arr[i]);
            
        }
        


    }


    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }


        reverse(ans.begin(),ans.end());
        return ans;
    }
   
};