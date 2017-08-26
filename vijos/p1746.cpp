#include <iostream>
using namespace std;
long a,b,c,t,q,n,m,i,j,k;
long map[305][305];
long v[305];
long f[305][305];

int main() {
    cin>>n>>m;
    for(i = 0; i < n; i++)
        cin>>v[i];
    memset(map, 127, sizeof(map));
    memset(f, 127, sizeof(f));
    for(i = 0; i < n; i++)
        map[i][i] = 0;
    for(i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        map[a][b] = min(map[a][b], c);
        map[b][a] = min(map[b][a], c);
    }
}
 for i:=1 to m do
  begin
   readln(a,b,c);
   if map[a,b]=-1 then
    begin
     map[a,b]:=c;
     map[b,a]:=c;
    end
   else
    begin
     map[a,b]:=min(map[a,b],c);
     map[b,a]:=map[a,b];
    end;
  end;

  for(k=0;k<n;k++)//第一次
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
         if map[i,k]+map[k,j]<map[i,j] then
          map[i,j]:=map[i,k]+map[k,j]

 for k:=1 to n do//第二次
  for i:=1 to n do
   for j:=1 to n do
    begin
     if (map[i,k]<>-1) and (map[k,j]<>-1) then
      if map[i,k]+map[k,j]+v[k]<f[i,j] then
       f[i,j]:=map[i,k]+map[k,j]+v[k];
    end;
 readln(t);
 for q:=1 to t do
  begin
   readln(a,b);
   if f[a,b]<2000000000 then
    writeln(f[a,b])
   else
    writeln(-1);
  end;
end.
