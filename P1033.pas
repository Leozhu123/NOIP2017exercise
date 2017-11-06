const g=10
var h,s1,v,l,k:double;
    n,i,ans:integer;
begin
  readln(h,s1,v,l,k,n);
  for i:=1 to n do
	begin
		if (sqrt(2*h/g)*v>=(s1-i-0.0001)) and (sqrt(((h-k)*2)/g)*v<=(s1-i+l+0.0001)) then inc(ans);
	end;
	writeln(ans);
end.
