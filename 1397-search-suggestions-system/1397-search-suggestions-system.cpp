class Node{
    private:
        Node* link[26];
        bool flag =false;
    
    public:
        bool containsKey(char a){
            return link[a-'a']!=NULL;
        }
        Node* getKey(char ch){
            return link[ch-'a'];
        }
        void setKey(char ch,Node* node){
            link[ch-'a'] = node;
        }
        void setEnd(){
            flag= true;
            return;
        }
        bool isEnd(){
            return flag==true;
        }
};

class Trie{
    private:
        Node* root;

    public:
        Trie(){
            root= new Node();
        }
        void insert(string word){
            Node* temp = root;

            for(int i=0;i<word.length();i++){
                if(!temp->containsKey(word[i])){
                    temp->setKey(word[i],new Node());
                }
                temp = temp->getKey(word[i]);
            }
            temp->setEnd();
        }
        bool search(string word){
            Node* temp = root;

            for(int i=0;i<word.length();i++){
                if(!temp->containsKey(word[i])){
                    return false;
                }
                temp = temp->getKey(word[i]);
            }
           return temp->isEnd();
        }
        // search prefix 
        vector<string> prefixSearch(string &word){
            Node* temp = root;
            vector<string> ans;
            for(int i=0;i<word.length();i++){
                if(!temp->containsKey(word[i])){
                    return ans;
                }
                temp = temp->getKey(word[i]);
            }

            dfs(temp,word,ans);
           return ans;
        }
        void dfs(Node* node, string &current, vector<string> &ans){

            if(node->isEnd()==true){
                ans.push_back(current);
            }

            for(char ch = 'a';ch<='z';ch++){
                if(node->containsKey(ch)){
                    current.push_back(ch);
                    dfs(node->getKey(ch),current,ans);
                    current.pop_back();
                }
            }
        }
        Node* getRoot(){
            return root;
        }
};



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        Trie* trie = new Trie();

        // inserting all words into the trie

        for (int i=0;i<products.size();i++){
            trie->insert(products[i]);
        }

        vector<vector<string>> ans;
        string pre="";
        Node* rootNode = trie->getRoot();
        for(auto x:searchWord){

            pre+=x;
            vector<string> tempAns = trie->prefixSearch(pre);
            //system design 

            if(tempAns.size()>3){
                vector<string> temp;

                for(int i=0;i<3;i++){
                    temp.push_back(tempAns[i]);
                }
                ans.push_back(temp);
            }else{
                ans.push_back(tempAns);
            }
        }
        return ans;
    }
};