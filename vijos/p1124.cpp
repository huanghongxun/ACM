#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
using namespace __gnu_cxx; 
string start,end;
vector<string> w1,w2;
int bfs()
{
    map<string,int> l;
    l[start]=0;
    queue<string> q;
    q.push(start);
    while(!q.empty())
    {
        string n=q.front();
        for(int i=0;i!=w1.size();++i)
        {
            int k=0;
            while(k<n.size())
            {
                int p=n.find(w1[i].c_str(),k);
                k+=w1[i].size();
                if(p==string::npos) break;
                string n1;
                for(int j=0;j<p;++j)
                  n1.push_back(n[j]);
                for(int j=0;j<w2[i].size();++j)
                  n1.push_back(w2[i][j]);
                for(int j=p+w1[i].size();j<n.size();++j)
                  n1.push_back(n[j]);
                if(l.count(n1)) continue;
                else
                  l.insert(pair<string,int>(n1,l[n]+1));
                if(n1==end) return l[n1];
                if(l[n1]>10) return -1;
                q.push(n1);
            }
        }
        q.pop();
    }
    return -1;
}
int main(int argc, char** argv) {
    cin>>start>>end;
    string t1,t2;
    while(cin>>t1>>t2)
    { 
        w1.push_back(t1);
        w2.push_back(t2);
    }
    int q=bfs();
    if(q==-1) cout<<"NO ANSWER!"<<endl;
    else cout<<q<<endl;
    return 0;
}