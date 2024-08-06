#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// class Trie {
// public:
//     bool finish;
//     bool nextCheck[26];
//     Trie* next[26];

// public:
//     Trie() {
//         finish = false;
        
//         memset(nextCheck, false, sizeof(nextCheck));
//         memset(next, 0, sizeof(next));
//     }

//     void insert(string word) {
//         if (word[0] == '\0') {
//             finish = true;
//         }
//         else {
//             int key = word[0] - 'a';
//             if (next[key] == NULL) {
//                 next[key] = new Trie();
//                 nextCheck[key] = true;
//             }
//             string nextWord = word.substr(1);
//             next[key]->insert(nextWord);
//         }
//     }

//     bool search(string word) {
//         if (word[0] == '\0') return false;
//         int key = word[0] - 'a';

//         if (!nextCheck[key]) {
//             return false;
//         }
//         // 마지막 문자 라는 조건이 필요함
//         if (word.size() == 1 && next[key]->finish) {
//             return true;
//         }

//         string nextWord = word.substr(1);
//         return next[key]->search(nextWord);
//     }

//     bool startsWith(string prefix) {
//         int key = prefix[0] - 'a';
//         if (prefix[0] == '\0') {
//             return true;
//         }

//         if (next[key] == NULL) {
//             return false;
//         }

//         string nextWord = prefix.substr(1);
//         return next[key]->startsWith(nextWord);
//     }
// };

// class WordFilter {
// public:
//     unordered_map<string, vector<int> > prefixs;   // 접두사 목록
//     unordered_map<string, vector<int> > suffixs;   // 접미사 목록

// public:
//     WordFilter(vector<string>& words) {
//         for (int i = 0; i < words.size(); i++) {
//             // 접두사 목록 추가 a, ap, app, appl, apple : 0
//             for(int j=1; j < words[i].size()+1; j++){
//                 prefixs[words[i].substr(0,j)].push_back(i);
//             }

//             // 접미사 목록 추가 apple, appl, app, ap, a : 0
//             for(int j=words[i].size()-1; j >= 0; j--){
//                 suffixs[words[i].substr(j)].push_back(i);
//             }
//         }
//     }

//     int f(string pref, string suff) {
        
//         if(prefixs[pref].empty()) return -1;
//         vector<int>& prefIdx = prefixs[pref];

//         if(suffixs[suff].empty()) return -1;
//         vector<int>& suffIdx = suffixs[suff];

//         int i = prefIdx.size()-1, j = suffIdx.size()-1;

//         while (i >= 0 && j>= 0){
//             if(prefIdx[i] == suffIdx[j]) return prefIdx[i]; // 맞지 않았으므로 큰 곳이 줄여줘야함
//             else if(prefIdx[i] > suffIdx[j]) i--;   // 1 , 0
//             else j--;
//         }
//         return -1;
//     }
// };

class Trie{
    public: 
    Trie* root;
    Trie* child[27];
    int lastIndex;

    Trie(){
        root= NULL;
        for(int i=0; i<27; i++)   child[i]= NULL;
        lastIndex= -1;
    }
};

void build(int index, Trie* root, string &s){
    for(int i=0; i<s.size(); i++){
        int ch= (s[i]== '#')? 26: s[i]-'a';
        if(!root->child[ch])    root->child[ch]= new Trie();
        root= root->child[ch];
        root->lastIndex= index;
    }
}

int search(Trie* root, string &s){
    for(int i=0; i<s.size(); i++){
        int ch= (s[i]== '#')? 26: s[i]-'a';
        if(!root->child[ch])    return -1;
        root= root->child[ch];
    }
    return root->lastIndex;
}

class WordFilter {
    Trie* root;
public:
    WordFilter(vector<string>& words) {
        root= new Trie();
        for(int i=0; i<words.size(); i++){
            string s= words[i], t, rev= s;
            reverse(rev.begin(), rev.end());
            for(int j=0; j<s.size(); j++){
                t+= s[j];
                string te= t+"#"+rev;
                build(i, root, te);
            }
        }
    }
    
    int f(string pref, string suff) {
        reverse(suff.begin(), suff.end());
        string s= pref+"#"+suff;
        return search(root, s);
    }
};

int main() {
    vector<string> words;
    words.push_back("apple");   //0
    // words.push_back("app");     //1
    // words.push_back("ale");     //2 -> return

    WordFilter* obj = new WordFilter(words);
    int param_1 = obj->f("a", "e");
    return 0;
}