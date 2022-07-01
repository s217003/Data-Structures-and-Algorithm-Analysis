#ifndef _QRICKSORT_H
#define _QRICKSORT_H

/**
* @brief Define a struct to complete the quicksort.
* 
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

/**
* @brief Do bubbling sort for a vector.
* 
*/
template <typename Compareble>
void BubblingSort( std::vector<Compareble> & A, int left, int right )
{
    int delta = right - left;
    for( int i = 0; i < delta; i++ )
        for( int j = left; j < right - i; j++ )
        {
            if( A[ j ] > A[ j + 1 ] )
                std::swap( A[ j ], A[ j + 1 ] );
        }
}

/**
* @brief Find the middle one among the three elements.(left, middle, right)
* 
*/
template <typename Compareble>
const Compareble & median3( std::vector<Compareble> & A, int left, int right )
{
    int center = ( left + right ) / 2;

    if( A[ center ] < A[ left ] )
        std::swap( A[ left ], A[ center ] );
    if( A[ right ] < A[ left ] )
        std::swap( A[ right ], A[ left ] );
    if( A[ right ] < A[ center ] )
        std::swap( A[ center ], A[ right ] );

    // Place pivot at position right - 1
    std::swap( A[ center ], A[ right - 1 ] );
    return A[ right - 1 ];
}

/**
* @brief A quicksort algorithm which choose pivot by median3.
* 
*/
template <typename Compareble>
void quick_sortmedian3( std::vector<Compareble> & A, int left, int right )
{
    // Use quicksort to sort the vector when the size is large.
    if( left + 10 <= right )
    {
        // Choose the pivot
        const Compareble & pivot = median3( A, left, right );

        // Begin partitioning
        int i = left, j = right - 1;
        while( 1 )
        {
            while( A[ ++i ] < pivot ) { }
            while( pivot < A[ --j ] ) { }
            if( i < j )
                std::swap( A[ i ], A[ j ] );
            else
                break;
        }

        std::swap( A[ i ], A[ right - 1 ] ); // Restore pivot
        
        // Sort for small and large parts.
        quick_sortmedian3( A, left, i - 1 );
        quick_sortmedian3( A, i + 1, right );
    }

    // Use Bubbling sort when the size is small.
    else
        BubblingSort( A, left, right );
}

/**
* @brief A quicksort algorithm which choose pivot randomly.
* 
*/
template <typename Compareble>
void quick_sortrandom( std::vector<Compareble> & A, int left, int right )
{
    // Use quicksort to sort the vector when the size is large.
    if( left + 10 <= right )
    {
        // Choose the pivot
        int index = ( rand() % ( right - left + 1)) + left;
        if( index != right )
            std::swap( A[ index ], A[ right ] );
        const Compareble & pivot = A[ right ];

        // Begin partitioning
        int i = left - 1, j = right;
        while( 1 )
        {
            while( A[ ++i ] < pivot ) { }
            while( pivot < A[ --j ] ) { }
            if( i < j )
                std::swap( A[ i ], A[ j ] );
            else
                break;
        }

        std::swap( A[ i ], A[ right ] ); // Restore pivot
        
        // Sort for small and large parts.
        quick_sortrandom( A, left, i - 1 );
        quick_sortrandom( A, i + 1, right );
    }

    // Use Bubbling sort when the size is small.
    else
        BubblingSort( A, left, right );
}

/**
* @brief A quicksort function which choose pivot by median3 and can be used outside the library.
* 
*/
template <typename Compareble>
void quicksortmedian3( std::vector<Compareble> & A )
{
    quick_sortmedian3( A, 0, A.size() - 1 );
}

/**
* @brief A quicksort function which choose pivot randomly and can be used outside the library.
* 
*/
template <typename Compareble>
void quicksortrandom( std::vector<Compareble> & A )
{
    quick_sortrandom( A, 0, A.size() - 1 );
}

#else
/// Do nothing.
#endif
