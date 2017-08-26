type node=record
       d,f,fs,se,ss:longint;
   r:real;
   end;
var
  i,j,k,n,m,x0,x,y,z,ans,min:longint;
  sa,sb,s1,minb:longint;
  h:array[1..100000]of node;
  bi:real;
  input,output:text;
procedure init;
var mini,min2:longint;
begin
  readln(input,n);
  for i:=1 to n do begin h[i].f:=-1;h[i].se:=-1;end;
  for i:=1 to n do read(input,h[i].d);
  readln(input,x0);
  readln(input,m);
  for i:=1 to n-1 do
     begin
min:=1000000001;
    for j:=i+1 to n do
  begin
    if abs(h[i].d-h[j].d) then
       begin
     min:=abs(h[i].d-h[j].d);
 mini:=j;
   end;
    if abs(h[i].d-h[j].d)=min then
        if h[j].d
  end;
        h[i].f:=min;h[i].fs:=mini;
min:=1000000001;
for j:=i+1 to n do
   begin
    if (abs(h[i].d-h[j].d)<>h[i].fs) then
       begin
     min:=abs(h[i].d-h[j].d);
 mini:=j;
   end;
    if (abs(h[i].d-h[j].d)=min)and(j<>h[i].fs) then
        if h[j].d
  end;
h[i].se:=min;h[i].ss:=mini;
     end;
end;
procedure walk(s,xx:longint);
var flag:longint;
begin
  sa:=0;sb:=0;
  flag:=0;
  while s
     begin
   if flag mod 2 =1 then
      begin
     if h[s].f<>-1 then
   begin
     sa:=sa+h[s].f;
 if sa+sb>xx then begin sa:=sa-h[s].f;break;end;
     s:=h[s].fs;
     inc(flag);
   end else break;
  end
    else
    begin
     if h[s].ss<>-1 then
     begin
     sb:=sb+h[s].se;
     if sa+sb>xx then begin sb:=sb-h[s].se;break;end;
     s:=h[s].ss;
     inc(flag);
   end else break;
 end;
    end;
end;
 procedure main;
 begin
   bi:=1000000000;
   minb:=1;
   for i:=1 to n do
      begin
     walk(i,x0);
 if (sa<>0)and(sb/sa
   begin
     bi:=sb/sa;
 minb:=i;
   end;
  end;
   writeln(output,minb);
   for i:=1 to m do
      begin
    readln(input,s1,x);
walk(s1,x);
writeln(output,sb,' ',sa);
  end;
   close(output);
   close(input);
end;
 
begin
  init;
  main;
end.