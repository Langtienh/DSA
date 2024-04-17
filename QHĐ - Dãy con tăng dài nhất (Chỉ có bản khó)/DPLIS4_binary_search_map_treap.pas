uses        math;

const       fi = 'DPLIS4.inp'; fo = 'DPLIS4.out';

type        PNode = ^TreapNode;
            TreapNode = Record
                key, val, priority: longint;
                left, right: PNode;
            end;

var         map_treap: array[0..100006] of PNode;

function    new_node(key, val: longint): PNode;
var         P: PNode;
begin
            new(P);
            P^.val := val; P^.key := key;
            P^.left := nil; P^.right := nil;
            P^.priority := random(2000000007);
            exit(P);
end;

function    rotate_left(P : PNode): PNode; inline;
var         x, y: PNode;
begin
            x := P^.right; y := x^.left;
            x^.left := P;
            P^.right := y;
            exit(x);
end;

function    rotate_right(P: PNode): PNode; inline;
var         x, y: PNode;
begin
            x := P^.left; y := x^.right;
            x^.right := P;
            P^.left := y;
            exit(x);
end;

function    lower_bound(p: PNode; key: longint): PNode; inline;
var         tmp: PNode;
begin
            if p = nil then exit(p);
            if p^.key = key then exit(p);
            if key < p^.key then
                begin
                    tmp := lower_bound(p^.left, key);
                    if tmp = nil then exit(p) else exit(tmp);
                end
            else exit(lower_bound(p^.right, key));
end;

function    upper_bound(p: PNode; key: longint): PNode; inline;
var         tmp: PNode;
begin
            if p = nil then exit(p);
            if key < p^.key then
                begin
                    tmp := upper_bound(p^.left, key);
                    if tmp = nil then exit(p) else exit(tmp);
                end
            else exit(upper_bound(p^.right, key));
end;

function    insert(p: PNode; key, val: longint): PNode; inline;
begin
            if p = nil then exit(new_node(key, val));
            if key < p^.key then
                begin
                    p^.left := insert(p^.left, key, val);
                    if p^.left^.priority > p^.priority then p := rotate_right(p);
                end
            else if key > p^.key then begin
                    p^.right := insert(p^.right, key, val);
                    if p^.right^.priority > p^.priority then p := rotate_left(p);
                end;
            exit(p);
end;

function    remove(p: PNode; key: longint): PNode; inline;
var         tmp: PNode;
begin
            if p = nil then exit(p);
            if key < p^.key then p^.left := remove(p^.left, key)
            else if key > p^.key then p^.right := remove(p^.right, key)
            else if p^.left = nil then
                begin
                    tmp := p^.right;
                    dispose(p);
                    p := tmp;
                end
            else if p^.right = nil then
                begin
                    tmp := p^.left;
                    dispose(p);
                    p := tmp;
                end
            else if p^.left^.priority < p^.right^.priority then
                begin
                    p := rotate_left(p);
                    p^.left := remove(p^.left, key);
                end
            else begin
                    p := rotate_right(p);
                    p^.right := remove(p^.right, key);
                end;
            exit(p);
end;

procedure   add_node(block, x, y: longint); inline;
var         p: PNode;
            i: longint;
begin
            p := lower_bound(map_treap[block], x);
            while (p <> nil) and (p^.val >= y) do
                begin
                    i := p^.key;
                    map_treap[block] :=remove(map_treap[block], i);
                    p := upper_bound(map_treap[block], i);
                end;
            map_treap[block] := insert(map_treap[block], x, y);
end;

{function    less_or_equal(p: PNode; key: longint): PNode;  inline;
var         tmp : PNode;
begin
            if p = nil then exit(p);
            if p^.key = key then exit(p);
            if key > p^.key then
                begin
                    tmp := less_or_equal(p^.right, key);
                    if tmp = nil then exit(p) else exit(tmp);
                end
            else exit(less_or_equal(p^.left, key));
end;}

function    less_than(p: PNode; key: longint): PNode; inline;
var         tmp : PNode;
begin
            if p = nil then exit(p);
            if key > p^.key then
                begin
                    tmp := less_than(p^.right, key);
                    if tmp = nil then exit(p) else exit(tmp);
                end
            else exit(less_than(p^.left, key));
end;

function    find_node(block, key, val: longint): boolean; inline;
var         p: PNode;
begin
            p := less_than(map_treap[block], key);
            if p = nil then exit(false);
            if p^.val < val then exit(true);
            exit(false);
end;

procedure   process;
var         n, i, l, r, mid, x, y, res: longint;
begin
            read(n); res := 0;
            for i:=1 to n do map_treap[i] := nil;
            for i:=1 to n do
                begin
                    read(x, y);
                    l := 0; r := res;
                    while l < r do
                        begin
                            mid := (r+l+1) shr 1;
                            if find_node(mid, x, y) then l := mid
                            else r := mid-1;
                        end;
                    res := max(res, l+1);
                    add_node(l+1, x, y);
                end;
            write(res);
end;

begin
	    process;
end.
    
