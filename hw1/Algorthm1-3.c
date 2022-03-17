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
typedef set<int> Set;//把set<int> 等效成Set，把set<int> 轉化成Set型別
map<Set, int> IDcache;//定義map，是Set型別到int的對映，即一個集合，一個ID
vector<Set> Setcache;//定義不定長陣列，不定長陣列的每個元素是Set型別
//即這是一個不定長的集合的陣列
//查詢給定的集合x的ID，如果找不到，分配一個新的ID
int ID(Set x)
{
    if(IDcache.count(x))
    {
        return IDcache[x];//在map裡count（查詢）集合x,如果找到返回這個集合的ID
    }
    Setcache.push_back(x);//找不到的話向不定長的集合陣列新增新的集合
    IDcache[x] = Setcache.size()-1;
    return IDcache[x];//返回這個集合的ID，即不定長集合陣列的大小-1

}

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int main()
{
    int i,n,m;

        stack<int> s;//定義一個棧s，這個棧裡存放的是每個集合的ID
        //每個集合都可以表示成所包含元素的ID的集合
        cin >> m;
        for(i = 0;i < m;i++)
        {
            string op;//讀入每一條操作
            cin >> op;
            if(op.compare("PUSH") == 0)
            {
                s.push(ID(Set()));//PUSH空集入棧，Set()就表示這是空集
            }
            else if(op.compare("DUP") == 0)
            {
                s.push(s.top());//DUP，把當前的棧頂元素入棧
            }
            else {//其他的操作
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();//出棧兩個集合，存放到x1x2中
                Set x;//定義一個集合變數x，用來處理中間值
                if(op.compare("UNION") == 0)
                {
                    set_union (ALL(x1), ALL(x2), INS(x));//把集合x1和集合x2的並集存放到x中
                    //估計集合的儲存像連結串列那樣，所有用x.begin(),x.end()把這個集合的所有元素遍歷
                    //inserter(x,x.begin())是從x.begin()開始插入
                }
                if(op.compare("INTERSECT") == 0)
                {
                    set_intersection (ALL(x1), ALL(x2), INS(x));//把集合x1，x2的交集存到x裡
                }
                if(op.compare("ADD") == 0) //把集合x1插入到x2中
                {
                    x = x2;
                    x.insert(ID(x1));
                     /*
                     set不儲存重複的元素，
                     所以insert的元素如果set中已有，
                     則不會重複新增
                     */
                }
                s.push(ID(x));//把集合x的ID入棧

            }
            cout << Setcache[s.top()].size() << endl;//輸出對應ID的不定長集合陣列的大小
        }



    return 0;
}
