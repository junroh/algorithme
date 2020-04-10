// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
    struct TrieNode {
        TrieNode* node[256];
        bool isLeafNode;
    };

    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0;i<word.size();i++) {
            if(cur->node[word[i]]==nullptr) {
                TireNode* tmp = new TrieNode();
                //memset(tmp->node,sizeof(TrieNode)*256,0);
                //tmp->isLeafNode = false;
                cur->node[word[i]] = tmp;
            }
            cur = cur->node[word[i]];
        }
        cur->isLeafNode = true;
    }

    TrieNode* findlastNode(string word) {
        TrieNode* cur = root;
        for(int i=0;i<word.size();i++) {
            if(cur->node[word[i]]==nullptr) {
                return nullptr;
            }
            cur = cur->node[word[i]];
        }
        return cur;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = findlastNode(word);
        return node==nullptr?false:node->isLeafNode;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = findlastNode(prefix);
        return node!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
