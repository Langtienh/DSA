var         n, m, k, i, j: longint;
	        kind, l, r: longint;
	        u1, u2, v1, v2: longint;
            x, y, c: array[0..100006] of longint;
            a, d, w, S: array[0..100006] of int64;
            res, S1, S2: int64;

begin
            read(n, m, k); c[0] := 0; d[0] := 0; S[0] := 0;
            for i:=1 to n do read(a[i]);
            for i:=1 to m do
                begin
                    read(kind, x[i], y[i], w[i]);
                    if kind = 2 then w[i] := -w[i];
                end;
            for i:=1 to k do
                begin
                    read(kind, l, r);
                    inc(c[l]); dec(c[r+1]);
                end;
            for i:=1 to m do
                begin
                    inc(c[i], c[i-1]);
                    inc(d[x[i]], c[i] * w[i]);
                    dec(d[y[i]+1], c[i]*w[i]);
                end;
            for i:=1 to n do
                begin
                    inc(d[i], d[i-1]);
                    inc(a[i], d[i]);
                    S[i] := S[i-1] + a[i];
                end;
            read(u1, v1, S1);
            read(u2, v2, S2);
            if abs(S[v1] - S[u1-1] - S1) < abs(S[v2] - S[u2-1] - S2) then write('SAN WIN')
            else if abs(S[v1] - S[u1-1] - S1) > abs(S[v2] - S[u2-1] - S2) then write('MI WIN')
            else write('HOA');
end.
    
