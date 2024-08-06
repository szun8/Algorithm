#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trie {
public:
    bool finish;
    bool nextCheck[26];
    Trie* next[26];

public:
    Trie() {
        finish = false;
        memset(nextCheck, false, sizeof(nextCheck));
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        if (word[0] == '\0') {
            finish = true;

        }
        else {
            int key = word[0] - 'a';
            if (next[key] == NULL) {
                next[key] = new Trie();
                nextCheck[key] = true;
            }
            string nextWord = word.substr(1);
            next[key]->insert(nextWord);
        }
    }

    bool search(string word) {
        if (word[0] == '\0') return false;
        int key = word[0] - 'a';

        if (!nextCheck[key]) {
            return false;
        }
        // 마지막 문자 라는 조건이 필요함
        if (word.size() == 1 && next[key]->finish) {
            return true;
        }

        string nextWord = word.substr(1);
        return next[key]->search(nextWord);
    }

    bool startsWith(string prefix) {
        int key = prefix[0] - 'a';
        if (prefix[0] == '\0') {
            return true;
        }

        if (next[key] == NULL) {
            return false;
        }

        string nextWord = prefix.substr(1);
        return next[key]->startsWith(nextWord);
    }
};