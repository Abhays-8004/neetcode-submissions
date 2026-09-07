
class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool end;

    Trienode(char ch){
        this->data  = ch;
        end = false;
        for(int i = 0;i<26;i++){
            children[i]= NULL;
        }
    }
    Trienode(){
        
        this->end = false;
        for(int i = 0;i<26;i++){
            children[i]= NULL;
        }
    }

};


class WordDictionary {
public:
Trienode* root = new Trienode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trienode* curr = root;
        for(char &ch : word){
            if(ch == '.'){
                for(int i = 0;i<26;i++){
                    if(curr->children[i]!= NULL){
                        int idx = i;
                    }
                    

                }
            }
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new Trienode(ch);
            }
            curr = curr->children[idx];
        }

        curr->end = true;
    }
    
    bool search(string word) {
         return dfs(word,0,root);
    }

    bool dfs(string word,int j,Trienode* root){
        Trienode* curr = root;

        for(int i = j;i<word.size();i++){
            char ch = word[i];
            if(ch == '.'){
                for(Trienode* child:curr->children){
                    if(child != NULL && dfs(word,i+1,child)){
                        return true;
                    }
                }
                return false;
            }else{
                if(curr->children[ch-'a'] == NULL){
                    return false;
                }
                curr =  curr->children[ch-'a'];
            }
        }

        return curr->end;
    }
};
