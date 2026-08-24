/*
Implement Trie:

A Trie stores strings character by character.

Each node contains:

    children:
        Pointers to the next characters.

    isEnd:
        true if a complete word ends at this node.

Example:

    Insert "apple":

        root
         |
         a
         |
         p
         |
         p
         |
         l
         |
         e
         |
        END

If we then insert "app", we reuse the existing:

    a -> p -> p

and simply mark the second p as an end:

         p
         |
        END
         |
         l
         |
         e
        END

This is why a Trie is useful for prefixes.

Insert:

    Start at root.

    For every character:
        If the child does not exist, create a new node.

        Move to that child.

    After the last character:
        Mark isEnd = true.

Search:

    Start at root.

    For every character:
        If the child does not exist, the word was never inserted.

        Otherwise move to the child.

    After the last character:
        Return isEnd.

Why do we need isEnd?

Consider:

    Insert "apple"

Then:

    search("app")

must return false.

The path:

    a -> p -> p

exists, but "app" itself was not inserted.

So we need isEnd to distinguish:

    "app"
    "apple"

startsWith:

    This is similar to search.

    We only need to successfully follow every character of the prefix.

    We do NOT need isEnd to be true.

Example:

    Insert "apple"

    startsWith("app") -> true

because the path:

    a -> p -> p

exists.

Time:

    insert(word)  = O(L)
    search(word)  = O(L)
    startsWith()  = O(L)

L is the length of the word or prefix.

Space:

    O(N * L)

where N is the number of inserted words.
*/

class PrefixTree {
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
public:
    PrefixTree() {
        root = new Node();
    }
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        // Mark the end of the complete word.
        curr->isEnd = true;
    }
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};