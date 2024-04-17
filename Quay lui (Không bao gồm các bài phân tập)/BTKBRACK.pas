var
        n: longint;

procedure Try(s:string;i:longint);
begin
        if (i>=0) and (length(s)<=n) then
        begin
                if (length(s)=n)and(i=0) then
                begin
                        writeln(s);
                end else
                begin
                        Try(s+'(',i+1);
                        Try(s+')',i-1);
                end;
        end;
end;

procedure Res();
var	i: longint;
	ans: int64;
begin
	ans := 1;
	for i:=n div 2 + 2 to n do ans := ans * i;
	for i:=1 to n div 2 do ans := ans div i;
	writeln(ans);
end;


begin
        readln(n);
        Res();
        Try('',0);
        readln;
end.
    
