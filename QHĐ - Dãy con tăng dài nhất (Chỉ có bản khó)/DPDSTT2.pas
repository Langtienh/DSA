uses        math;

type        arr_bit = array of longint;

var         f, prime, pos: array[0..1000006] of longint;
            bit: array[1..79006] of arr_bit;
            n, cnt, res, element: longint;

procedure   open_file;
begin
end;

procedure   close_file;
begin
end;

procedure   sieve;
var         i, j: longint;
begin
            cnt := 0;
            for i:=2 to 1000000 do
                begin
                    if f[i] = 0 then
                        begin
                            inc(cnt);
                            prime[cnt] := i;
                            pos[i] := cnt;
                            f[i] := i;
                        end;
                    j := 1;
                    while (j <= cnt) and (prime[j] <= f[i]) and (prime[j] * i <= 1000000) do
                        begin
                            f[prime[j]*i] := prime[j];
                            inc(j);
                        end;
                end;
end;

procedure   init;
var         i, j, tmp: longint;
begin
            res := 0;
            for i:=1 to cnt do
                begin
                    tmp := 1000000 div prime[i];
                    setLength(bit[i], tmp + 1);
                    for j:=0 to tmp do bit[i, j] := 0;
                end;
end;

procedure   update_bit(block, p, val: longint);
begin
            while p * prime[block] <= 1000000 do
                begin
                    bit[block, p] := max(val, bit[block, p]);
                    inc(p, p and (-p));
                end;
end;

function    query_bit(block, p: longint): longint;
var         ans : longint = 0;
begin
            while p > 0 do
                begin
                    ans := max(ans, bit[block, p]);
                    dec(p, p and (-p));
                end;
            exit(ans);
end;

procedure   update(a: longint);
var         a1, tmp, best, p: longint;
begin
            if a <= 1 then
                begin
                    res := max(res, 1);
                    exit;
                end;
            best := 0;
            a1 := a;
            while a > 1 do
                begin
                    tmp := f[a];
                    p := a1 div tmp;
                    best := max(best, query_bit(pos[tmp], p-1) + 1);
                    while a mod tmp = 0 do a := a div tmp;
                end;
            a := a1;
            res := max(res, best);
            while a > 1 do
                begin
                    tmp := f[a];
                    p := a1 div tmp;
                    update_bit(pos[tmp], p, best);
                    while a mod tmp = 0 do a := a div tmp;
                end;
end;

begin
            open_file;

            sieve;
            init;
            readln(n);
            while n > 0 do
                begin
                    read(element);
                    update(element);
                    dec(n);
                end;
            write(res);

            close_file;
end.
    
