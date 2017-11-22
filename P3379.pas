type
  point=^node;
  node=record
    data:longint;
    next:point;
  end;
  rmq_d=record
    dee,poss:longint;
  end;
var
  nod:point;
  map:array [1..500000] of point;
  visited:array [1..500000] of boolean;
  id,deapth,appear:array [1..1000000] of longint;
  rmq:array [1..1000000,0..30] of rmq_d;
  pos,n,m,root,log_n,len,x,y:longint;
  i:longint;
procedure dfs(now,deep:longint);
var tmp:point;
begin
  if appear[now]=0 then appear[now]:=pos;
  id[pos]:=now;
  deapth[pos]:=deep;
  visited[now]:=true;
  inc(pos);
  tmp:=(map[now]^).next;
  while (tmp<>nil)  do
  begin
    if (not visited[tmp^.data]) then
    begin
      dfs(tmp^.data,deep+1);
      id[pos]:=now;
      deapth[pos]:=deep;
      inc(pos);
    end;
    tmp:=tmp^.next;
  end;
end;
procedure rmq_init;
var i,j:longint;
begin
  for i:=1 to len do
  begin
    rmq[i,0].dee:=deapth[i];
    rmq[i,0].poss:=i;
  end;
  for j:=1 to log_n do
    for i:=1 to len do
    if i+1<<(j-1)>len then break else
    begin
      if rmq[i,j-1].dee<=rmq[i+1<<(j-1),j-1].dee then
      begin
        rmq[i,j].dee:=rmq[i,j-1].dee;
        rmq[i,j].poss:=rmq[i,j-1].poss;
      end else
      begin
        rmq[i,j].dee:=rmq[i+1<<(j-1),j-1].dee;
        rmq[i,j].poss:=rmq[i+1<<(j-1),j-1].poss;
      end;
    end;
end;
function rmq_search(rl,rr:longint):longint;
var k,l,r:longint;
begin
  if rl>rr then begin l:=rr; r:=rl; end else begin l:=rl; r:=rr; end;
  k:=trunc(ln(r-l+1)/ln(2));
  if rmq[l,k].dee<rmq[(r-(1<<k))+1,k].dee
    then exit(rmq[l,k].poss)
    else exit(rmq[(r-(1<<k))+1,k].poss);
end;
begin
  readln(n,m,root);
  for i:=1 to n do
  begin
    new(map[i]);
    map[i]^.next:=nil;
  end;
  for i:=1 to n-1 do
  begin
    new(nod);
    readln(x,y);
    nod^.data:=y;
    nod^.next:=map[x]^.next;
    map[x]^.next:=nod;
    new(nod);
    nod^.data:=x;
    nod^.next:=map[y]^.next;
    map[y]^.next:=nod;
  end;

  log_n:=trunc(ln(n)/ln(2))+1;
  pos:=1;

  dfs(root,1);

  len:=pos-1;
  rmq_init;

  for i:=1 to m do
  begin
    readln(x,y);
    writeln(id[rmq_search(appear[x],appear[y])]);
  end;

end.
