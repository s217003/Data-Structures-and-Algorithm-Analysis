#include "BinarySearchTree.h"
#include <iostream>

template <typename T>

void BST_sort(std::vector<T> &_data);
void Randomized_BST_sort(std::vector<T> &_data);

template <typename T>
void BST_sort(std::vector<T> &_data)
{
    BinarySearchTree <T> a;
    int l = _data.size();
    for(int i = 0; i < l; i++ ) {
        a.insert( _data[i] );
        std::cout << _data[i] <<" "<< std::endl;
    }
    a.printTree();
}

template <typename T>
void Randomized_BST_sort(vector<T> &_data)
{
    BinarySearchTree<T> b;
    int l = _data.size();
    random_shuffle(_data.begin(),_data.end());//乱序操作
    for(int i = 0; i < l; i++ ) {
	std::cout << _data[i] <<" "<< std::endl;
        b.insert(_data[i]);
    }
    b.printTree();
}

   
}
int main(int argc, char *argv[] )
{
    int n;
    std::cout << "_data 的长度:" << std::endl;//input the size of vector.
    std::cin >> n;
    std::vector <int> A(n);//input vector named A.
    Randomized_BST_sort(A);
    BST_sort(A);
    return 0;
}
