#include<bits/stdc++.h>
using namespace std;
//creating class trie
class TrieNode{
    public:
     char data;
     TrieNode* children[26];//26 character in alphabet
     bool isTerminal;
     //creating constructor
      TrieNode(char val){
        data=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
      }
};
class Trie{
    public:
    TrieNode* root;
    //constructor
    Trie(){
        // '\0' Null character
        root= new TrieNode('\0');
    }
    //insert
    //recursively

    void Insert(TrieNode* root,string word){
        //base case
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        //Assuming all capital letter
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //recursively call
        Insert(child,word.substr(1));
    }
    void Insertingword(string word){
        Insert(root,word);
    }
    bool searchw(TrieNode* root,string word){
        //base case
        if(word.size()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;
        //present
        if(root->children[index]!=NULL){
            child=root-.children[index];
        }
        else{
            //absent
            return false;
        }
        //recursion
        searchw(child,word.substr(1));
    }
    bool searchword(string word){
        return searchw(root,word);
    }
};
int main{
    // creating object of class
    Trie *t= new Trie();
    t->Insertingword("abcde")
}