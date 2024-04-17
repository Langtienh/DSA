const           mm=trunc(1e6);
var            
                f: array[0..100007] of longint;
                n,k: longint;
Procedure       Nhap;
    Begin
                readln(n,k);
    End;
Procedure       Xuly;
    Var         i: longint;
    Begin
                f[1]:=2;
                for i:=2 to k+1 do f[i]:=(f[i-1]+1) mod mm;
                for i:=k+2 to n do f[i]:=(f[i-1]+f[i-k-1]) mod mm;
    End;
Procedure       Xuat;
    Begin
                write(f[n]);
    End;
BEGIN
                Nhap;
                Xuly;
                Xuat;
END.
    
