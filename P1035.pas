var n,k:integer;
    s:double;
begin
  readln(k);
  s:=0;
  while s<=k do
  begin
  inc(n);
    s:=s+1/n;
  end;
  writeln(n);
end.
