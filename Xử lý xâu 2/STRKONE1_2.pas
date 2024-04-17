var             f, bit: array[-1000006..1000006] of longint;
                k, n: longint;
                S: ansistring;

procedure       enter;
        var     i: longint;
        begin
                readln(k);
                readln(S); n:=length(S);
        end;

procedure       init;
        var     i: longint;
        begin
                for i:=-k to 0 do f[i]:=0;
                for i:=1 to n do
                        begin
                                f[i] := f[i-1];
                                if S[i] = '1' then inc(f[i]);
                        end;
        end;

procedure       process;
        var     i: longint;
                res: int64 = 0;
        begin
                bit[0] := 1;
                for i:=1 to n do
                     begin
                          if f[i] >=k then inc(res, bit[f[i]-k]);
                          inc(bit[f[i]]);
                     end;
                write(res);
        end;

begin
                enter;
                init;
                process;
end.
    
