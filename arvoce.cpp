#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void init(Node *&root)
{
    root = nullptr;
}

bool vazia(Node *&root)
{
    return (root == nullptr);
}

bool estaNaArvore(Node *root, int x)
{
    if (vazia(root))
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    return estaNaArvore(root->left, x) || estaNaArvore(root->right, x);
}

void insert(Node *&root, int x)
{
    if (vazia(root))
    {
        Node *ptr = new Node();
        ptr->data = x;
        ptr->left = nullptr;
        ptr->right = nullptr;
        root = ptr;
    }

    else
    {

        if (root->data > x)
        {
            insert(root->left, x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}

void remove(Node *&node, int x)
{
    if (vazia(node))
    {
        return;
    }

    if (node->data == x)
    {
        if (vazia(node->left) && vazia(node->right))
        {
            delete node;
            node = nullptr;
        }
        else if (vazia(node->left))
        {
            Node *ptr = node;
            node = node->right;
            delete ptr;
        }
        else if (vazia(node->right))
        {
            Node *ptr = node;
            node = node->left;
            delete ptr;
        }
        else
        {
            Node *ptr = node->left;
            while (!vazia(ptr->right))
            {
                ptr = ptr->right;
            }
            node->data = ptr->data;
            remove(node->left, ptr->data);
        }
    }
    else if (node->data > x)
    {
        remove(node->left, x);
    }
    else
    {
        remove(node->right, x);
    }
}

int soma(Node *&node)
{
    if (vazia(node))
    {
        return 0;
    }
    else
    {
        int esq = soma(node->left);
        int dir = soma(node->right);
        return node->data + esq + dir;
    }
}

int alturaArvore(Node *&node)
{
    if (vazia(node))
    {
        return 0;
    }
    else
    {
        int esq = alturaArvore(node->left);
        int dir = alturaArvore(node->right);
        return (esq > dir ? esq : dir) + 1;
    }
}

bool arvoresIguais(Node *&node1, Node *&node2)
{

    if (vazia(node1) && vazia(node2))
    {
        return true;
    }

    if (vazia(node1) || vazia(node2))
    {
        return false;
    }

    if (node1->data != node2->data)
    {
        return false;
    }

    return arvoresIguais(node1->left, node2->left) && arvoresIguais(node1->right, node2->right);
}

int main()
{
    Node *raiz = nullptr; // Inicialize raiz com nullptr
    Node *raiz2 = nullptr;

    init(raiz);
    insert(raiz, 10);
    insert(raiz, 9);
    insert(raiz, 8);
    insert(raiz, 11);
    insert(raiz, 12);

    init(raiz2);
    insert(raiz2, 10);
    insert(raiz2, 9);
    insert(raiz2, 8);
    insert(raiz2, 11);
    insert(raiz2, 12);

    cout << arvoresIguais(raiz, raiz2) << endl;
    cout << alturaArvore(raiz) << endl;
    cout << soma(raiz) << endl;
    cout << estaNaArvore(raiz, 1) << endl;
    return 0;
}