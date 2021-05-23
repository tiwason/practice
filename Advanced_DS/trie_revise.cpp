#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct Trie_Node
{
    Trie_Node *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

Trie_Node *getNewNode()
{
    Trie_Node *node = new Trie_Node();
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(Trie_Node *root, string key)
{
    Trie_Node *crawl = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (crawl->children[index] == NULL)
            crawl->children[index] = getNewNode();

        crawl = crawl->children[index];
    }

    crawl->isEndOfWord = true;
}

bool search(Trie_Node *root, string key)
{
    Trie_Node *crawl = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (crawl->children[index] == NULL)
            return false;

        crawl = crawl->children[index];
    }

    return (crawl && crawl->isEndOfWord);
}

bool isEmpty(Trie_Node *node)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i])
            return false;
    }
    return true;
}

Trie_Node *deleteKey(Trie_Node *node, string key, int index)
{
    if (!node)
        return NULL;

    if (index == key.size() - 1)
    {
        node->isEndOfWord = false;
        if (isEmpty(node))
        {
            delete node;
            node = NULL;
        }
        return node;
    }

    int i = key[index] - 'a';
    node->children[i] = deleteKey(node->children[i], key, index++);
    if (isEmpty(node) && node->isEndOfWord == false)
    {
        delete node;
        node = NULL;
    }
    return node;
}

int main()
{
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int size = sizeof(keys) / sizeof(keys[0]);

    Trie_Node *root = getNewNode();

    for (int i = 0; i < size; i++)
        insert(root, keys[i]);

    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "their") ? cout << "Yes\n" : cout << "No\n";
    search(root, "thaw") ? cout << "Yes\n" : cout << "No\n";
}