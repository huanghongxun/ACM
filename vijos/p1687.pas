type
        num = array[0..5000] of integer;
var
        n,tot,i:longint;
        fn:array[1..1000] of num;
        ans:num;
function        max(a,b:integer):integer;
begin
        if a > b then exit(a);
        exit(b);
end;
function        chen(a:num;b:integer):num;
var
        i,j:integer;
        temp:num;
begin
        fillchar(temp,sizeof(temp),0);
        j := 0;
        for i := 1 to a[0] do
        begin
                temp[i] := a[i]*b+j;
                j := temp[i] div 10;
                temp[i] := temp[i] mod 10;
        end;
        temp[0] := a[0];
        while j > 0 do
        begin
                inc(temp[0]);
                temp[temp[0]] := j mod 10;
                j := j div 10;
        end;
        exit(temp);
end;
function        jia(a,b:num):num;
var
        i,j:integer;
        temp:num;
begin
        fillchar(temp,sizeof(temp),0);
        j := 0;
        for i := 1 to max(a[0],b[0]) do
        begin
                temp[i] := a[i]+b[i]+j;
                j := temp[i] div 10;
                temp[i] := temp[i] mod 10;
        end;
        temp[0] := max(a[0],b[0]);
        while j > 0 do
        begin
                inc(temp[0]);
                temp[temp[0]] := j mod 10;
                j := j div 10;
        end;
        exit(temp);
end;
function        jian(a,b:num):num;
var
        i:integer;
        temp:num;
begin
        fillchar(temp,sizeof(temp),0);
        for i := 1 to max(a[0],b[0]) do
        begin
                temp[i] := a[i]-b[i];
                if temp[i] < 0 then
                begin
                        temp[i] := temp[i]+10;
                        a[i+1] := a[i+1]-1;
                end;
        end;
        temp[0] := max(a[0],b[0]);
        while temp[temp[0]] = 0 do dec(temp[0]);
        exit(temp);
end;
procedure       outp(a:num);
var
        i:integer;
begin
        if a[0] = 0 then write('0')
        else
        for i := a[0] downto 1 do       write(a[i]);
        writeln;
end;
begin
        readln(n);
        fillchar(fn,sizeof(fn),0);
        fn[n][0] := 1;
        fn[n][1] := 1;
        for i := n-1 downto 2 do
                fn[i] := chen(fn[i+1],i+1);
        fillchar(ans,sizeof(ans),0);
        for i := 2 to n do
        if i mod 2 = 1 then
                ans := jian(ans,fn[i])
        else
                ans := jia(ans,fn[i]);
        outp(ans);
end.