#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct Trie_Node
{
    struct Trie_Node* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

Trie_Node* getNewNode ()
{
    Trie_Node* node = new Trie_Node();
    for (int i=0; i<ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(Trie_Node* root, string key)
{
    Trie_Node* ptr = root;

    for (int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if (!ptr->children[index])
            ptr->children[index] = getNewNode();
        
        ptr = ptr->children[index];
    }

    ptr->isEndOfWord = true;
}

bool isEmpty(Trie_Node* node)
{
    for (int i=0; i<ALPHABET_SIZE; i++)
    {
        if (!node->children[i])
            return false;
    }

    return true;
}

Trie_Node* deleteKey(Trie_Node* root, string key, int index)
{

    if (!root)
        return NULL;

    if (index == key.size())
    {
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }
  
    int idx = key[index] - 'a';
    root->children[idx] = deleteKey(root->children[idx], key, index++);

    if (isEmpty(root) && root->isEndOfWord == false)
    {
        delete root;
        root = NULL;
    }

    return root;
}

bool search (Trie_Node* root, string key)
{
    Trie_Node* ptr = root;

    for (int i=0; i<key.size(); i++)
    {
        int index = key[i] - 'a';
        if (!ptr->children[index])
            return false;
        
        ptr = ptr->children[index];
    }

    return (ptr && ptr->isEndOfWord);
}

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int size  = sizeof(keys)/sizeof(keys[0]);

    Trie_Node* root = getNewNode();

    for (int i=0; i<size; i++)
        insert(root, keys[i]);

                       
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    search(root, "the")? cout << "Yes\n" :
                           cout << "No\n";
    search(root, "their")? cout << "Yes\n" :
                           cout << "No\n";
    search(root, "thaw")? cout << "Yes\n" :
                           cout << "No\n";
}