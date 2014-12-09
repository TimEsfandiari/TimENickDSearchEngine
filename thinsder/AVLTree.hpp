//http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/
//Used AVLTree template from this website, and removed un needed functions.
#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T> class AVLTree
{
public:
    AVLTree()
    {
        this->root = NULL;
    }

    AVLTree(const AVLTree &rhs)
    {
        this->root = NULL;
        *this = rhs;
    }

    ~AVLTree()
    {
        makeEmpty();
    }

    //returns true if x is found in tree
    bool isFound(const T & x)
    {
        return isFound(x, root);
    }

    bool isEmpty() const
    {
        if(root == NULL)
            return true;
        else
            return false;
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(const T& x)
    {
        insert(x, root);
        //cout << "inserted a node" << endl;
    }

    T& find(const T& x)
    {
        return find(x, this->root);
    }

    void print(ostream& out) const
    {
        if(isEmpty() == true)
            cout << "List Empty" << endl;
        else
            print(out, root);
    }
private:
    struct AVLNode
    {
        public:
            T element;
            AVLNode *left;
            AVLNode *right;
            int height;

            AVLNode(const T & theElement, AVLNode *lt, AVLNode *rt, int h = 0):
            element(theElement), left(lt), right(rt), height(h) {}
    };

    AVLNode *root;

    int height(AVLNode *t) const
    {
        if(t == NULL)
            return -1;
        else
            return t->height;
    }

    int max(int lhs, int rhs) const
    {
        if(lhs > rhs)
            return lhs;
        else
            return rhs;
    }

    void insert(const T & x, AVLNode * & t)
    {
        if(t == NULL)
            t = new AVLNode(x, NULL,NULL);

        else if(x < t->element)
        {
            insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->element)
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        }

        else if(t->element < x )
        {
            insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->element)
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }
        }
        else
            t->element += x; //Works only for the IndexWord object

        t->height = max(height(t->left),height(t->right)) + 1;
    }

    T& find(const T & x, AVLNode* &root)
    {
        if ( root == NULL)
            throw logic_error("Element not found");
        else if( x == root->element)
            return root->element;
        else if( x < root->element )
            return find( x, root->left );
        else if( x > root->element )
            return find( x, root->right );
        else
            throw logic_error("Error in your code, fix it bro!!!");
    }

    bool isFound(const T & x, AVLNode* root)
    {
        if( root == NULL )
            return false;
        else if( x < root->element )
            return isFound( x, root->left );
        else if( root->element < x )
            return isFound( x, root->right );
        else
            return true;
    }

    void makeEmpty(AVLNode* &n)
    {
        if(n != NULL )
        {
            makeEmpty( n->left );
            makeEmpty( n->right );
            delete n;
        }
        n = NULL;
    }

    void rotateWithLeftChild(AVLNode* &k1)
    {
        AVLNode *temp = k1->left;
        k1->left = temp->right;
        temp->right = k1;
        k1->height = max(height(k1->left),height(k1->right)) + 1;
        temp->height = max(height(temp->left), k1->height) + 1;
        k1 = temp;
    }

    void rotateWithRightChild(AVLNode* &k4)
    {
        AVLNode* temp = k4->right;
        k4->right = temp->left;
        temp->left = k4;
        k4->height = max(height(k4->left),height(k4->right)) + 1;
        temp->height = max(height(temp->left), k4->height	) + 1;
        k4 = temp;
    }

    void doubleWithLeftChild(AVLNode* &k2)
    {
        rotateWithRightChild(k2->left);
        rotateWithLeftChild(k2);
    }

    void doubleWithRightChild(AVLNode* &k3)
    {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    void print(ostream& out, AVLNode* n) const
    {
        if(n != NULL)
        {
            print(out, n->left);
            out << n->element << endl;
            print(out, n->right);
        }
    }
};

#endif // AVLTREE_HPP
