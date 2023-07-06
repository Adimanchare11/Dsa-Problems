#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data= data;
        children= new TrieNode *[26];
        for(int i=0; i<26; i++)
        {
            children[i]=NULL;
        }
        isTerminal= false;
    }

};
class Trie
{
    TrieNode* root;
    public:
    Trie()
    {
        root= new TrieNode('\0');
    }

    void insertWord(TrieNode*root, string word)
    {
        //base case

        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        //small calculation
        int index= word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            child= new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursive call
        insertWord(child,word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root,word);
    }

    bool search(TrieNode* parent, string word)
    {
        if(word.size()==0)
        {
            return parent->isTerminal;
        }

        if(parent->children[word[0]-'a']!=NULL)
        {
            return search(parent->children[word[0]-'a'], word.substr(1));
        }
        else{
            return false;
        }
    }
    bool search(string word)
    {
        if(word.size()==0)
        {
            return false;
        }
        return search(root,word);
    }

    void deleteWord(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }

    //small calculation
        TrieNode* child;
        int index= word[0]-'a';
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }

        else{
            //word not found
            return;
        }

        deleteWord(child, word.substr(1));

        //remove children if useless
        if(child->isTerminal==false)
        {
            for(int i=0; i<26; i++)
            {
                if(root->children[index]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }

    }

    void deleteWord(string word)
    {
        deleteWord(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        for(int i=0; i<vect.size(); i++)
        {
            while(vect[i]!="")
            {
               insertWord(vect[i]);
               vect[i]=vect[i].substr(1);
            }
        }
        return search(pattern);
    }

    // void search(TrieNode *parent, string pattern, string word) {
    //   if (pattern.size() == 0) {
    //     if (parent->isTerminal)
    //       cout << word << "\n";
    //     for (int i = 0; i < 26; i++)
    //       if (parent->children[i] != NULL)
    //         search(parent->children[i], pattern,
    //                word + (parent->children[i]->data));
    //   } else if (parent->children[pattern[0] - 'a'] != NULL)
    //     search(parent->children[pattern[0] - 'a'], pattern.substr(1),
    //            word + pattern[0]);
    // }

    // void autoComplete(vector<string> input, string pattern) {
    //     // Write your code here
    //     for (int i = 0; i < input.size(); i++)
    //       insertWord(input[i]);
    //     search(root, pattern, "");
    // }

};

int main(){
    
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("or");

    cout<<t.search("and")<<endl;
    t.deleteWord("and");
    cout<<t.search("and");
    Trie t;
    int n;
    cin >> n;

    // vector<string> vect;

    // for (int i = 0; i < n; ++i) {
    //     string word;
    //     cin >> word;
    //     vect.push_back(word);
    // }

    // string pattern;
    // cin >> pattern;

    // t.autoComplete(vect, pattern);
    

    return 0;
}