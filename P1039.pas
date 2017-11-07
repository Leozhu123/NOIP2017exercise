function gcd(a,b:longint):longint;
begin
  if a mod b <>0 then gcd:=gcd(b,a mod b)
                 else gcd:=b;
end;
var tm,n,i,ans,pans,j:longint;
begin
  readln(n);
  for tm:=1 to n do
  begin
  pans:=ans;
    ans:=0;
    for i:=1 to tm do
      for j:=1 to i-1 do
        ans:=ans+gcd(i,j);
    writeln(tm:5,ans:5,(ans-pans):5);
  end;
end.

