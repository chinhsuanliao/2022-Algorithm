#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<set>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef set<int> Set;//��set<int> ���Ħ�Set�A��set<int> ��Ʀ�Set���O
map<Set, int> IDcache;//�w�qmap�A�OSet���O��int����M�A�Y�@�Ӷ��X�A�@��ID
vector<Set> Setcache;//�w�q���w���}�C�A���w���}�C���C�Ӥ����OSet���O
//�Y�o�O�@�Ӥ��w�������X���}�C
//�d�ߵ��w�����Xx��ID�A�p�G�䤣��A���t�@�ӷs��ID
int ID(Set x)
{
    if(IDcache.count(x))
    {
        return IDcache[x];//�bmap��count�]�d�ߡ^���Xx,�p�G����^�o�Ӷ��X��ID
    }
    Setcache.push_back(x);//�䤣�쪺�ܦV���w�������X�}�C�s�W�s�����X
    IDcache[x] = Setcache.size()-1;
    return IDcache[x];//��^�o�Ӷ��X��ID�A�Y���w�����X�}�C���j�p-1

}

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int main()
{
    int i,n,m;

        stack<int> s;//�w�q�@�Ӵ�s�A�o�Ӵ̸̦s�񪺬O�C�Ӷ��X��ID
        //�C�Ӷ��X���i�H��ܦ��ҥ]�t������ID�����X
        cin >> m;
        for(i = 0;i < m;i++)
        {
            string op;//Ū�J�C�@���ާ@
            cin >> op;
            if(op.compare("PUSH") == 0)
            {
                s.push(ID(Set()));//PUSH�Ŷ��J�̡ASet()�N��ܳo�O�Ŷ�
            }
            else if(op.compare("DUP") == 0)
            {
                s.push(s.top());//DUP�A���e���̳������J��
            }
            else {//��L���ާ@
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();//�X�̨�Ӷ��X�A�s���x1x2��
                Set x;//�w�q�@�Ӷ��X�ܼ�x�A�ΨӳB�z������
                if(op.compare("UNION") == 0)
                {
                    set_union (ALL(x1), ALL(x2), INS(x));//�ⶰ�Xx1�M���Xx2���ö��s���x��
                    //���p���X���x�s���s����C���ˡA�Ҧ���x.begin(),x.end()��o�Ӷ��X���Ҧ������M��
                    //inserter(x,x.begin())�O�qx.begin()�}�l���J
                }
                if(op.compare("INTERSECT") == 0)
                {
                    set_intersection (ALL(x1), ALL(x2), INS(x));//�ⶰ�Xx1�Ax2���涰�s��x��
                }
                if(op.compare("ADD") == 0) //�ⶰ�Xx1���J��x2��
                {
                    x = x2;
                    x.insert(ID(x1));
                     /*
                     set���x�s���ƪ������A
                     �ҥHinsert�������p�Gset���w���A
                     �h���|���Ʒs�W
                     */
                }
                s.push(ID(x));//�ⶰ�Xx��ID�J��

            }
            cout << Setcache[s.top()].size() << endl;//��X����ID�����w�����X�}�C���j�p
        }



    return 0;
}
