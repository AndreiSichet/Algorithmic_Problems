/*
Design Add and Search Word Data Structure:

Use a TRIE with DFS.

The Trie stores every word character by character.

For example:

    addWord("cat")
    addWord("car")

The Trie shares the prefix:

    c -> a

Then branches:

          c
          |
          a
         / \
        t   r
        |   |
       END END

Normal letters:

    Move to the child for that letter.

Dot '.':

    It can represent any letter.

    So we try every existing child.

Example:

    search("c.t")

First:

    c -> move to c

Then:

    '.' -> try every child

Then:

    t -> check if t exists

This creates a DFS tree:

                    c
                    |
                    .
                 /  |  \
                a   b   d
                |   |   |
                t   t   t

If any path produces a complete word,
return true.

We need isEnd because reaching a Trie node
does not necessarily mean a complete word exists.

Example:

    addWord("apple")

    search("app")

The path exists, but "app" was not inserted.

So we only return true when:

    index == word.size()

and:

    curr->isEnd == true

Backtracking is only needed for '.'.

For a normal character, there is only one
possible child.

For '.', there can be up to 26 possible children.

Time:

    addWord:
        O(L)

    search:
        O(26^L) worst case

In practice it is much faster because the Trie
only follows children that actually exist.

Space:

    O(N * L)

where N is the number of inserted words and
L is their average length.
*/

class WordDictionary {
private:
    struct Node {
        Node* children[26];
        bool isEnd;
        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    Node* root;
    bool backtrack(string& word, int index, Node* curr) {
        if (index == word.size()) {
            return curr->isEnd;
        }
        char c = word[index];
        if (c != '.') {
            int i = c - 'a';
            if (curr->children[i] == nullptr) {
                return false;
            }
            return backtrack(word, index + 1, curr->children[i]);
        }
        for (int i = 0; i < 26; i++) {
            if (curr->children[i] == nullptr) {
                continue;
            }
            if (backtrack(word, index + 1, curr->children[i])) {
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        // Mark the end of the word.
        curr->isEnd = true;
    }
    bool search(string word) {
        return backtrack(word, 0, root);
    }
};