var
 a,m,j,i,n,g : longint;
begin
 readln(n);
 for i:= 1 to n do begin
 m:=0;
  for j := 1 to 3 do begin
   read(a);
   if a= 1 then inc(m);
  end;
  if m>=2 then inc(g);
 end;
 writeln(g);
end.