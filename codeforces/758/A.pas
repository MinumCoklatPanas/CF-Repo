var
 a,m,j,i,n,g,max,sum : longint;
 tab : array[1..200] of longint;
begin
 readln(n);
 for i:= 1 to n do
  begin
   read(tab[i]);
   if max<tab[i] then max:=tab[i];
  end;
 //writeln(max);
 for i:= 1 to n do
  begin
   tab[i]:=max-tab[i];
   sum:=sum+tab[i];
  end;
 writeln(sum);
end.