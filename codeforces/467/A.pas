var
 a,m,j,i,n,g,k : longint;
begin
 readln(n);
 for i:= 1 to n do
  begin
   readln(j,k);
   if k-j>=2 then inc(g);
  end;
 writeln(g);
end.
