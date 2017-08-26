program p1454;
var
	n,i,rp,s,j,len,l: longint;
	t,rpcow: ansistring;
begin
	readln(n);
	rp:=0; len:=300;
	for i:= 1 to n do begin
		readln(t);
		if pos('reioxzsj',t)=0 then continue;
		s:=0; l:=length(t);
		for j:= 1 to l do begin
			if (j<l-1) and (t[j]+t[j+1]+t[j+2]='woc') or (t[j]='r') or (t[j]='p') then inc(s,5);
			if (j<l) and (t[j]+t[j+1]='pr') then inc(s,20);
		end;
		if (s>rp) or (s=rp) and (l<len) then begin
			rp:=s;
			rpcow:=t;
			len:=l;
		end;
	end;
	writeln(rpcow);
	writeln(rp);
end.