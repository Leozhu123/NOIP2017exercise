uses math;
const cost:array [1..10] of integer=(1,3,5,7,10,15,16,18,21,23);
var dp:array[0..10,0..100000] of longint;
    i,j,need:longint;
    v:array [1..10] of longint;
begin
  readln(need);
  for i:=1 to 10 do
    read(v[i]);
  for i:=1 to 10 do
    v[i]:=v[i]-cost[i];
  for i:=1 to 10 do
  begin
    for j:=1 to need do
    begin
      if j<i then dp[i,j]:=dp[i-1,j] else
      if dp[i-1,j]>dp[i,j-i]+v[i] then dp[i,j]:=dp[i-1,j] else dp[i,j]:=dp[i,j-i]+v[i];
    end;
  end;
  writeln(dp[10,need]);
end.
