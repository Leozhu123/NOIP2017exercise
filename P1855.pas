uses math;
var  dp:array [-2..105,-2..205,-2..205] of int64;
     n,Md,Td,i,j,k:longint;
     m,t:array [1..300] of int64;
begin
  readln(n,Md,Td);
  for i:=1 to n do
    readln(t[i],m[i]);
  for i:=1 to n do
    for j:=1 to Md do
      for k:=1 to Td do
      begin
        if (j<m[i]) or (k<t[i]) then dp[i,j,k]:=dp[i-1,j,k]
        else dp[i,j,k]:=max(dp[i-1,j,k],dp[i-1,j-m[i],k-t[i]]+1);
      end;
  writeln(dp[n,Md,Td]);
end.
