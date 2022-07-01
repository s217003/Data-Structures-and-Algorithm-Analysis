#include<iostream>
#include<algorithm>
#include<vector>
template <typename Comparable>

class AVLTree
{
private:
    struct AvlNode
    {
	Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;
	
        AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
	    : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
	    : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };
    AvlNode * root = nullptr;

    /**
    * Return the height of node t or -1 if nullptr.
    */

    int height( AvlNode *t ) const
	{
	    return t == nullptr ? -1 : t->height;
	}

    /**
    * Internal method to insert into a subtree.
    * x is the item to insert.
    * t is the node that roots the subtree.
    * Set the new root of the subtree.
    */
    void insert( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
	    t = new AvlNode{ x, nullptr, nullptr };
	else if( x < t->element )
	    insert( x, t->left );
        else if( t->element < x )
	    insert( x, t->right );
        balance( t );
    }

    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance( AvlNode * & t )
    {
        if( t == nullptr )
	    return;
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
	    if( height( t->left->left ) >= height( t->left->right ) )
	        rotateWithLeftChild( t );
	    else
	        doubleWithLeftChild( t );
        else
	    if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
	        if( height( t->right->right ) >= height( t->right->left ) )
		    rotateWithRightChild( t );
	        else
		    doubleWithRightChild( t );
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    /**
    * Rotate binary tree node with left child.
    * For AVL trees, this is a single rotation for case 1.
    * Update heights, then set new root.
    */
    void rotateWithLeftChild( AvlNode * & k2 )
    {
	AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    /**
    * Double rotate binary tree node: first left child
    * with its right child; then node k3 with new left child.
    * For AVL trees, this is a double rotation for case 2.
    * Update heights, then set new root.
    */
    void doubleWithLeftChild( AvlNode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }

    /**
    * Internal method to remove from a subtree.
    * x is the item to remove.
    * t is the node that roots the subtree.
    * Set the new root of the subtree.
    */
    void remove( const Comparable & x, AvlNode * & t )
    {
	if( t == nullptr )
	    return;
    // Item not found; do nothing
        if( x < t->element )
	    remove( x, t->left );
        else if( t->element < x )
	    remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
	    t->element = findMin( t->right )->element;
	    remove( t->element, t->right );
        }
        else
        {
	    AvlNode *oldNode = t;
	    t = ( t->left != nullptr ) ? t->left : t->right;
	    delete oldNode;
        }
	balance( t );
    }

public:
    void insert(const Comparable & x)
    {
        insert(x,root);
    }
    void insert(Comparable && x)
    {
        insert(std::move(x),root);
    }
    void printout()
    {
        printout(root);
        std::cout << std::endl;
    }
    int height()
    {
        return height(root);
    }

};


template<typename Comparable>
class SplayTree
{
private:

    struct  SplayNode 
    {
        Comparable element;
        SplayNode* left;
        SplayNode* right;
        SplayNode* parents;
        int height;

        SplayNode ( const Comparable & theele, SplayNode * lt , SplayNode  * rt,  SplayNode* parents, int h = 0)
	    :element{ theele },left(lt),right(rt),height(h){}
        SplayNode ( Comparable && theele, SplayNode  * lt , SplayNode  * rt,  SplayNode* parents, int h = 0)
	    :element{ std::move(theele) },left(lt),right(rt),height(h){}
    };

    SplayNode  * root = nullptr;

    int height(SplayNode* t) const
    {
        return t == nullptr ? -1 : t->height;
    }

    void insert(const Comparable & x, SplayNode* & t)
    {
        if(t == nullptr)
        {
            t = new SplayNode(x,nullptr,nullptr,nullptr);
            t->height = 0;
        }
        else if(x < t->element)
        {
            insert(x,t->left);
            t->left->parents = t;
        }
        else if(x > t->element) 
        {
            insert(x,t->right);
            t->right->parents = t;
        }
        t->height = std::max(height(t->left),height(t->right))+1;
    }

    static const int ALLOWED_IMBALANCE = 1;

    SplayNode * findMin(SplayNode * t) const
    {
        if(t==nullptr)
            return nullptr;
        if(t->right == nullptr)
            return t;
        return findMax (t->right);
        
    }

   
    void remove(const Comparable & x, SplayNode* & t)
    {
        if(t == nullptr)
            return;
        
        if(x < t->element)
            remove(x,t->left);
        else if(t->element < x)
            remove(x,t->right);
        else if(t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right) -> element;
            remove(t->element,t->right);
        }
        else
        {
            SplayNode*oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    void printtree(SplayNode* t)
    {
        if(t == nullptr)
            return ;
        printtree(t->left);
        std::cout << t->element;
        RotatetoTop(t);
        printtree(t->right);
    };

public:

    void insert(const Comparable & x)
    {
        insert(x,root);
    }
    void insert(Comparable && x)
    {
        insert(std::move(x),root);
    }
    void printtree()
    {
        printtree(root);
        std::cout << std::endl;
    }
    int height()
    {
        return height(root);
    }

};
