
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




class PrefixTree {
public:
Trienode* root = new Trienode();
    PrefixTree() {   
    }
    
    void insert(string word) {
        Trienode* curr = root;
        for(char &ch : word){
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new Trienode(ch);
            }
            curr = curr->children[idx];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        Trienode* curr = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
               return false;
            }
            curr = curr->children[idx];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Trienode* curr = root;
        for(char &ch : prefix){
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
               return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};
