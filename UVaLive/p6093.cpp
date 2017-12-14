#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
const int N = 100102, M = 22;
typedef pair<int, int> node;

struct treat {
    int tim,ind;
    treat(int _tim,int _ind):tim(_tim),ind(_ind){}
    treat(){}
    bool operator <(const treat& a)const
    {
        return tim > a.tim;
    }
};

struct Patient {
    int id,pro,arrtim;
    Patient(int _id,int _pro,int _arrtim):id(_id),pro(_pro),arrtim(_arrtim){}
    Patient(){}
    bool operator <(const Patient& a)const
    {
        if(a.pro == pro)
            return arrtim > a.arrtim;
        return pro < a.pro;
    }
};

vector<node> pat[506];
int arrive[506],treated[506];

int main() {
    int n,Tim,a,b,Pcnt,cs = 1;
    int i,j;
    while(scanf("%d%d",&n,&Tim)!=EOF && (n || Tim)) {
        priority_queue<treat> T;
        priority_queue<Patient> P;
        vector<node> ans;
        Pcnt = 0;
        while(scanf("%d",&arrive[Pcnt]) && arrive[Pcnt] != -1)
        {
            pat[Pcnt].clear();
            while(scanf("%d%d",&a,&b) && (a+b))  //property,duration
                pat[Pcnt].push_back(node(a,b));
            Pcnt++;
        }
        while(!T.empty()) T.pop();
        while(!P.empty()) P.pop();
        for(i=0;i<n;i++)   //n个医生准备
            T.push(treat(Tim,-1));
        for(i=0;i<Pcnt;i++)
            T.push(treat(arrive[i],i)); //编号i
        int doctor = 0;
        memset(treated,-1,sizeof(treated));
        int pcnt = 0;
        while(pcnt < Pcnt)
        {
            int nowt = T.top().tim;
            while(!T.empty() && T.top().tim == nowt)
            {
                if(T.top().ind == -1)  //空闲doctor
                    doctor++;
                else
                {
                    int pid = T.top().ind;
                    treated[pid]++;
                    if(treated[pid] >= pat[pid].size()) //全部疗程完成
                    {
                        ans.push_back(node(nowt,arrive[pid]));
                        pcnt++;
                    }
                    else
                        P.push(Patient(pid,pat[pid][treated[pid]].x,arrive[pid]));
                }
                T.pop();
            }
            while(!P.empty() && doctor)
            {
                int k = P.top().id;
                T.push(treat(nowt+pat[k][treated[k]].y,-1)); //此时空闲
                T.push(treat(nowt+pat[k][treated[k]].y,k)); //或者继续诊断此病人
                P.pop();
                doctor--;
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        printf("Case %d:\n",cs++);
        for(i=0;i<ans.size();i++)
            printf("Patient %d released at clock = %d\n",ans[i].y,ans[i].x);
    }
    return 0;
}