#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include <iostream>
using namespace std;



template <typename Comparable>
class BinarySearchTree
{    
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    BinarySearchTree(BinarySearchTree && rhs);
    ~BinarySearchTree();

    const Comparable & findMin() const;
    const Comparable & findMax() const;
    bool contains(const Comparable & x) const;
    bool isEmpty() const;                      //判空
    void printTree(ostream & out = cout) const;

    void makeEmpty();
    void insert(const Comparable & x);
    void insert(Comparable && x);
    void remove(const Comparable & x);

    BinarySearchTree & operator=(const BinarySearchTree & rhs);
    BinarySearchTree & operator=(BinarySearchTree && rhs);

private:    
    struct BinaryNode
    {
	Comparable element; // 结点对应的值
	BinaryNode *left;   // 指向左孩子
	BinaryNode *right;  // 指向右孩子
	
	BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
	    :element{theElement}, left{lt}, right{rt} {}

	BinaryNode(Comparable && theElement, BinaryNode *lt, BinaryNode *rt)
	    :element{std::move(theElement)}, left{lt}, right{rt} {}
    };
    
    BinaryNode *root;

    void insert(const Comparable & x, BinaryNode * & t);
    void insert(Comparable && x,BinaryNode * & t);
    void remove(const Comparable & x, BinaryNode * & t);
    BinaryNode * findMin(BinaryNode *t) const;
    BinaryNode * findMax(BinaryNode *t) const;
    bool contains(const Comparable & x, BinaryNode *t) const;
    void makeEmpty(BinaryNode * & t);
    void printTree(BinaryNode *t, ostream & out) const;
    BinaryNode * clone(BinaryNode *t) const;
};

/**
 *returns ture if x is found in the tree.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x) const
{
    return contains(x,root);
}

/**
 *Insert x into the tree; duplicates are ignored.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
    return insert(x,root);
}

/**
 *remove x from the tree. nothing is done if x is not found.                 
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
    return remove(x,root);
}

/**
 * internal method to test if an item is in a subtree.  
 * x is item to search for.
 * t is the node that roots the subtree.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode *t) const
{
    if(t==nullptr)
        return false;
    else if(x < t->element)
        return contains(x,x->left);
    else if(t->element < x)
        return contains(x,x->right);
    else
        return true; //match
}

/**
 *internal method to insert into a subtree
 *x is the item to insert.
 *t is the node that roots the subtree.
 *set the new root of the subtree.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x,BinaryNode * & t)
{
    if( t== nullptr)
        t = new BinaryNode(x,nullptr,nullptr);
    else if(x<t->element)
        insert(x,t->left);
    else if(x>t->element)
        insert(x,t->right);
    else
        ; //duplicate; do nothing
}

/**
 * internal method to insert into a subtree.
 * x is the item to insert by moving.
 * t is the node that roots the subtree.
 * set the new root of the subtree.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::insert( Comparable && x,BinaryNode * & t)
{
    if( t== nullptr)
        t = new BinaryNode(std::move(x),nullptr,nullptr);
    else if(x<t->element)
        insert(std::move(x),t->left);
    else if(x>t->element)
        insert(std::move(x),t->right);
    else
        ; //duplicate; do nothing
}

/**
 *internal method to remove from a subtree.
 *x is the item to remove.
 *t is the node that roots the subtree.
 *set the new root of the subtree.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinaryNode * & t)
{
    if(t == nullptr)
        return;//item not found; do nothing
    if(x < t->element)
        remove(x,t->left);
    else if(x > t->element)
        remove(x,t->right);
    else if(t->left != nullptr && t->right != nullptr) //two children
    {
        t->element = findMin(t->right)->element;
        remove(t->element,t->right);
    }
    else
    {
        BinaryNode * oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
    }
}

/**
 *destructor for the tree 
 */
template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    makeEmpty();
}

/**
 *internal method to make subtree empty. 
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t)
{
    if( t != nullptr )
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

/**
 *copy constructor
 */
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree & rhs):root(nullptr)
{
    root = clone(rhs.root);
}

/**
 *internal method to clone subtree. 
 */
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::clone(BinarySearchTree<Comparable>::BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode(t->element,clone(t->left),clone(t->right));
}

/**
 *print the tree of the object.               
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(std::ostream & out) const
{
    printTree(root,out);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode *t,std::ostream & out) const
{
    if( t == nullptr)
        return;
    printTree(t->left,out);
    out << t->element;
    printTree(t->right,out);
    return;
}

#endif
