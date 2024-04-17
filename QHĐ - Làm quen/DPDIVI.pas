const         maxn =  6000000;
var           
              a,d,ll: array[0..6007] of longint;
              n,l,m: longint;
Procedure     Nhap;
    Var       i: longint;
    Begin
              Readln(n,l);
              for i:=1 to n do
                  begin
                        read(a[i]);
                        d[i]:=d[i-1]+a[i];
                  end;
    End;
function      Max(b,c: longint): longint;
    Begin
              if b>c then exit(b) else exit(c);
    End;
function      Min(b,c: longint): longint;
    Begin
              if b>c then exit(c) else exit(b);
    End;
Procedure     Xuly;
    Var       i,j: longint;
    Begin
              ll[0]:=0;
              for i:=1 to n do
                    begin
                        ll[i]:=Maxn;
                        for j:=0 to i-1 do
                              begin
                                   if d[i]-d[j]<=l then
                                        ll[i]:=Min(ll[i],Max(ll[j],l-d[i]+d[j]));
                              end;
                    end;
    End;
Procedure     xuat;
    Begin
              Write(ll[n]);
    End;
BEGIN
              Nhap;
              Xuly;
              Xuat;
END.
    
