uses        math;

type        Data = Record
                val, pos: longint;
            end;

var         f: array[0..100006] of longint;
            p: array[0..100006] of Data;
            n: longint;

function    cmp(const A, B: Data): boolean;
begin
            exit((A.val < B.val)  or ((A.val = B.val) and (A.pos < B.pos)));
end;

procedure   swap(var A, B: Data);
var         tmp: Data;
begin
            tmp := A; A := B; B := tmp;
end;

procedure   QS(var arr: array of Data; l, r: longint);
var         i, j: longint;
            pivot: Data;
begin
            i := l; j := r;
            pivot := arr[l + random(r-l+1)];
            repeat
                while cmp(arr[i], pivot) do inc(i);
                while cmp(pivot, arr[j]) do dec(j);
                if i <= j then
                    begin
                        swap(arr[i], arr[j]);
                        inc(i); dec(j);
                    end;
            until i > j;
            if l < j then QS(arr, l, j);
            if i < r then QS(arr, i, r);
end;

procedure   enter();
var         i: longint;
begin
            read(n);
            for i:=1 to n do
                begin
                    read(p[i].val);
                    p[i].pos := i;
                end;
end;

procedure   process();
var         mmax, i: longint;
begin
            QS(p, 1, n);
            for i:=1 to n do f[i] := 1;
            for i:=1 to n-1 do
                if p[i].pos < p[i+1].pos then f[i+1] := f[i] + 1;
            mmax := f[1];
            for i:=2 to n do mmax := max(mmax, f[i]);
            write(n-mmax);
end;

begin
            enter();
            process();
end.
    
