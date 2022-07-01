#include<iostream>
#include"BalanceTree"
int main()
{
     AVLTree<double> tr;
     tr.insert(16);
     tr.insert(3);
     tr.insert(7);
     tr.insert(11);
     tr.insert(9);
     tr.insert(26);
     tr.insert(18);
     tr.insert(14);
     tr.insert(15);
     
     std::cout << "删除" <<std::endl;
     tr.remove(15);
     tr.remove(14);
     tr.remove(18); 
     tr.remove(26);
     tr.remove(3);
     tr.remove(9);
     tr.remove(7);
     tr.remove(11);
     tr.remove(16);
     std::cout << "\n" <<std::endl;
     return 0;
}
