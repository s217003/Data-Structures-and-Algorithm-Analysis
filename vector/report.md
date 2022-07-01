# Vector

#### 介绍
一个向量的实现文件！

#### 参与贡献

1. skx217003

#### 特技

1. 用以实现向量类的头文件。

#### SPARE_CAPACITY的作用

1. 为Vector的元素预留一定的多余空间。少量增加元素时不需要重新分配内存。

#### SPARE_CAPACITY对push_back的影响

1. 当增加元素少于SPARE_CAPACITY时，可以直接在向量中增加新的元素，无需调用reverse重新分配内存。

#### SPARE_CAPACITY的最优大小

1. size为1到N均匀分布，如果SPARE_CAPACIT取N，无需进行重新分配。
2. 若N较小时，重新分配内存的效率会大于储存SPARE_CAPACITY个元素的效率。此时SPARE_CAPACITY的最优大小为N。
3. 若N足够大时，储存SPARE_CAPACITY个元素的效率大于重新分配内存的效率。此时SPARE_CAPACITY的最优大小小于N。
