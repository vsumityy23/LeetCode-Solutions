class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        
        
   
        unordered_set <string>  st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;

        queue <string> q;

        q.push(beginWord);
        st.erase(beginWord);
        int time=0;

        while(!q.empty()){

            int k=q.size();
            time++;


            while(k--){

                string word=q.front();
                string wordcopy=word;
                q.pop();

                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<word.length();i++){
                        word[i]=ch;
                        if(st.find(word)!=st.end()){
                            q.push(word);
                            st.erase(word);
                        }
                        if(word==endWord){
                            return time+1;
                        }

                        word=wordcopy;
                    }
                }

            }
        }


    return 0;

    }
};