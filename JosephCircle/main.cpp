
//Լɪ��
//n����Χ��һȦ����һ���˴�1��ʼ��������m�Ľ���ɱ������һ���˽��Ŵ�1��ʼ����
//��˷��������ʣ��һ����������ʤ���ߡ�

#include <iostream>
int JosephCircle(int n,int m)
{
    // �ؼ������ҵ���������������Ĺ�ϵ
    // �ɵ�����Ϊold���任�������Ϊnew����old=(new+m-1)%n+1

    // �ݹ��㷨
    // return n == 1 ? n : (JosephCircle(n-1,m)+m-1)%n+1;

    // ѭ���㷨
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
