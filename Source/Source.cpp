#include <iostream>

using namespace std;

class Node
{
public:
    Node* alphabet[26] = { NULL, };
    bool finish = false;
};

class Trie
{
public:
    Node* root;
    Trie()
    {
        root = new Node();
    }
    void Insert(const char* content)
    {
        Node* currentNode = root;
        for (int i = 0; i < strlen(content); i++)
        {
            if (currentNode->alphabet[content[i] - 'a']==NULL)
            {
                currentNode->alphabet[content[i] - 'a'] = new Node;
                currentNode = currentNode->alphabet[content[i] - 'a'];
            }
            else
            {
                currentNode= currentNode->alphabet[content[i] - 'a'];
            }
        }

        currentNode->finish = true;
            
    }

    bool Find(const char* content)
    {
        Node* currentNode = root;

        for (int i = 0; i < strlen(content); i++)
        {
            if (currentNode->alphabet[content[i] - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                currentNode = currentNode->alphabet[content[i] - 'a'];
            }
 
        }
        if (currentNode->finish == true)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    void Delete(const char* content)
    {
        Node* currentNode = root;
        Node* nextNode = nullptr;

        for (int i = 0; i < strlen(content); i++)
        {
            if (currentNode->alphabet[content[i] - 'a'] == NULL)
            {
                return;
            }

            nextNode = currentNode->alphabet[content[i] - 'a']->alphabet[content[i + 1] - 'a'];

            delete currentNode->alphabet[content[i]-'a'];

            if (i == 0)
            { 
                root->alphabet[content[i] - 'a'] = nullptr;
            }

            currentNode = nextNode;
        }
    }

};



int main()
{
    Trie trie;

    trie.Insert("tree");

    cout << trie.Find("tree") << endl;

    trie.Delete("tree");

    cout << trie.Find("tree") << endl;
}

