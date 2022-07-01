# PriorityQueue

#### 介绍
1.  优先队列实现

#### 基本功能
1.  nsert(DataBase<Unique, Comparable>& _x):
    插入一个新数据_x, 数据集关于每个数据的data满足二叉堆性质；
2.  deleteMin(): 
    删除整个队列中data最小的元素；
3.  buildHeap(const std::vector<DataBase<Unique, Comparable> >&_input):  
    输入包含若干个数据的数组
4.  input:
    建立成一个关于data的优先队列；
5.  remove(Unique k): 
    查找键值k, 如果找到, 删除这个键值所在的数据元素, 并保持关于data的优先队列.  没有找到, 则不做任何事；
6.  modifyData(Unique k, Comparable d): 
    寻找键值为k的数据, 将其data做d值的增量, 这里d可正可负. 完成之后, 调整数据集, 使其仍然满足关于data的二叉堆；

#### 软件架构
1.  Makefile编译规则
    直接运行
    make
    产生可执行文件
    test
    用于测试程序;
2.  main.cpp主流程
    编译后产生
    test;
3.  PriorityQueue.h头文件
4.  report.md
    解释项目设计思路和测试说明;

#### 参与贡献

1.  ZL
