#include <algorithm>

template <typename Object>
class Vector
{
 public:
    explicit Vector( int initSize = 0 ) : theSize{ initSize },
	theCapacity{ initSize + SPARE_CAPACITY }
	{ objects = new Object[ theCapacity ]; }//The constructor allows the user to specify an initial size, which defaults to zero. 

    Vector( const Vector & rhs ) : theSize{ rhs.theSize },
	    theCapacity{ rhs.theCapacity }, objects{ nullptr }
    {
	objects = new Object[ theCapacity ];
	for( int k = 0; k < theSize; ++k )
	    objects[ k ] = rhs.objects[ k ];
    }//The copy constructor makes a new Vector and can then be used by a casual implementation of operator= that uses the standard idiom of swapping in a copy. 

    Vector & operator= ( const Vector & rhs )
	{
	    Vector copy = rhs;
	    std::swap( *this, copy );
	    return *this;
        }

    ~Vector( )
    { delete [ ] objects; }
    
    Vector( Vector && rhs ) : theSize{ rhs.theSize },
	theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
	rhs.objects = nullptr;
	rhs.theSize = 0;
	rhs.theCapacity = 0;
    }

    Vector & operator= ( Vector && rhs )
    {
	std::swap( theSize, rhs.theSize );
	std::swap( theCapacity, rhs.theCapacity );
	std::swap( objects, rhs.objects );
	
	return *this;
    }//the implementation of the move constructor and move operator.

    void resize( int newSize )
    {
	if( newSize > theCapacity )
	    reserve( newSize * 2 );
	theSize = newSize;
    }//The resize routine

    void reserve( int newCapacity )
    {
	if( newCapacity < theSize )
	    return;//The reserve routine can also be used to shrink the underlying array, but only if the speciﬁed new capacity is at least as large as the size. If it isn’t, the reserve request is ignored.reserve也可用于收缩底层阵列，但前提是指定的新容量至少大小相同。如果不是，则忽略。

	Object *newArray = new Object[ newCapacity ];//Allocation of a new array.
	for( int k = 0; k < theSize; ++k )
	    newArray[ k ] = std::move( objects[ k ] );//Moving the old contents.

	theCapacity = newCapacity;
	std::swap( objects, newArray );
	delete [ ] newArray;//The reclaiming of the old array.
    }//The reserve routine to expanding capacity.
    
    Object & operator[]( int index )
	{ return objects[ index ]; }
    const Object & operator[]( int index ) const
	{ return objects[ index ]; }//The two versions of operator[] are trivial.运算符[]的两个版本非常简单.

    bool empty( ) const
	{ return size( ) == 0; }//空
    int size( ) const
	{ return theSize; }//大小
    int capacity( ) const
	{ return theCapacity; }//容量

    void push_back( const Object & x )
	{
	    if( theSize == theCapacity )
		reserve( 2 * theCapacity + 1 );
	    objects[ theSize++ ] = x;
	}

    void push_back( Object && x )
	{
	    if( theSize == theCapacity )
		reserve( 2 * theCapacity + 1 );
	    objects[ theSize++ ] = std::move( x );
	}

    void pop_back( )
	{
	    --theSize;
	}

    const Object & back ( ) const
	{
	    return objects[ theSize - 1 ];
	}

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin( )
	{ return &objects[ 0 ]; }
    const_iterator begin( ) const
	{ return &objects[ 0 ]; }
    iterator end( )
	{ return &objects[ size( ) ]; }
    const_iterator end( ) const
	{ return &objects[ size( ) ]; }//The declaration of the iterator and const_iterator nested types.迭代器和const_迭代器嵌套类型的声明以及两个begin和两个end方法。
    
    static const int SPARE_CAPACITY = 16;
    
 private:
    int theSize;//the Vector stores the size as its data members.
    int theCapacity;//the Vector stores the capacity(容量) as its data members.
    Object * objects;//the Vector stores the primitive array(基元数组) as its data members.
};
