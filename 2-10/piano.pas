const
  data:array[1..10]of string=('1','2','3','4','5','6','7','8','9','10');
var
  xx,l,tt,i,j,k1,l1,ans,t:longint;
  p:array[0..18]of longint;
  f:array[0..1000,0..52,0..52]of longint;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;
function pan(x,y:longint):boolean;
var
  jl:array[-4..60]of boolean;
  i:longint;
begin
  fillchar(jl,sizeof(jl),false);
  for i:=x-4 to x+4 do jl[i]:=true;
  for i:=y-4 to y+4 do jl[i]:=true;
  for i:=1 to xx do if not jl[p[i]] then exit(false);
  exit(true);
end;
begin
  assign(input,'piano.in');assign(output,'piano.out');
  reset(input);rewrite(output);
  readln(tt);
  fillchar(f,sizeof(f),50);
  for l:=1 to tt do
    begin
      read(xx);for i:=1 to xx do read(p[i]); readln;
      for i:=5 to 48 do for j:=i+1 to 48 do  f[0,i,j]:=1;
      for i:=5 to 48 do
        for j:=i+1 to 48 do
          if pan(i,j) then
             for k1:=5 to 48 do
               for l1:=5 to 48 do
                 f[l,i,j]:=min(f[l,i,j],f[l-1,k1,l1]+sqr(k1-i)+sqr(l1-j));
    end;
  ans:=maxlongint;
  for i:=5 to 48 do
    for j:=5 to 48 do
        ans:=min(ans,f[tt,i,j]);
  writeln(ans);
  close(input);close(output);
end.
