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
};



int main()
{
    
}

