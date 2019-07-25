
//约瑟夫环
//n个人围成一圈，第一个人从1开始报数，报m的将被杀掉，下一个人接着从1开始报。
//如此反复，最后剩下一个，求最后的胜利者。

#include <iostream>
int JosephCircle(int n,int m)
{
    // 关键在于找到新老排序的索引的关系
    // 旧的索引为old，变换后的索引为new，则old=(new+m-1)%n+1

    // 递归算法
    // return n == 1 ? n : (JosephCircle(n-1,m)+m-1)%n+1;

    // 循环算法
    int alivePerson(1);
    for(int i(2); i <= n; i++){
        alivePerson = (alivePerson+m-1)%i+1;
    }
    return alivePerson;
}

int main()
{
    std::cout << "Please input n and m: ";
    int n(0),m(0);
    std::cin >> n >> m;
    int livePerson;
    if(n > 0){
        livePerson = JosephCircle(n,m);
    }
    std::cout << "The one alive is number " << livePerson << std::endl;
    return 0;
}
