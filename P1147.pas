var M,i,j,sum:longint;
    boo:boolean;
begin
  readln(M);
  for i:=1 to (M div 2+1) do
  begin
    sum:=i;
    for j:=i+1 to M do
    begin
      sum:=sum+j;
    //  writeln(i:5,j:5,sum:5);
      if sum=M then writeln(i,' ',j);
      if sum>M then  break;
    end;
  end;
end.