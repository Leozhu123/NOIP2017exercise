//Ĥ����չ��
//�������ݲ�����1.08s��ô��
var down,up:array [1..10000] of longint;
    pos_down,pos_up:longint;
	T,i,n,h,r,j,k:longint;
	boo:boolean;
	x,y,z:array [1..1005] of int64;
	map:array [1..1005,1..1005] of boolean;
	visited:array [1..1005] of boolean;
procedure dfs(now:longint);
var i:longint;
begin
  if visited[now] then exit;
  visited[now]:=true;
  for i:=1 to n do
    if not visited[i] and map[now,i] then dfs(i);
end;
procedure clean;
var i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to n do
	  map[i,j]:=false;
  for i:=1 to n do
  begin
    visited[i]:=false;
    //x[i]:=0;
    //y[i]:=0;
    //z[i]:=0;
   // down[i]:=0;
   // up[i]:=0;
  end;
  boo:=false;
  pos_up:=0;
  pos_down:=0;
end;
begin
  readln(T);
  for k:=1 to T do
  begin
    clean;
    readln(n,h,r);
	for i:=1 to n do
	begin
	  readln(x[i],y[i],z[i]);
	  if (z[i]-r<=0) and (z[i]>0) then begin inc(pos_down); down[pos_down]:=i; end;
	  if (z[i]+r>=h) and (z[i]<h) then begin inc(pos_up); up[pos_up]:=i; end;
    if (z[i]-r>=0) and (z[i]<0) then begin inc(pos_down); down[pos_down]:=i; end;
	  if (z[i]+r<=h) and (z[i]>h) then begin inc(pos_up); up[pos_up]:=i; end;
	end;
	for i:=1 to n do
      for j:=i+1 to n do
        if sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))<=2*r then begin map[i,j]:=true; map[j,i]:=true; end;
    for i:=1 to pos_down do
      dfs(down[i]);
	for i:=1 to pos_up do
      if visited[up[i]]=true then boo:=true;
    if boo then writeln('Yes') else writeln('No');
  end;
end.