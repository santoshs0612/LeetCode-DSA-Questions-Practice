class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(mp.find(beginWord)!=mp.end()){
            mp.erase(beginWord);
        }
        if(mp.find(endWord)==mp.end()){
            return 0;
        }
        while(!q.empty()){

            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord){
                return step;
            } 
            for(int i=0;i<word.length();i++){
                char prev= word[i];
                for(char ch='a';ch<='z';ch++){

                    word[i] = ch;

                    if(mp.find(word)!=mp.end()){
                        q.push({word,step+1});
                        mp.erase(word);
                    }
                }
                word[i] = prev;
            }

        }
        return 0;
        
    }
};