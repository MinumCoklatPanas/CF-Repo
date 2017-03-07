var
 a,m,j,i,n,g : longint;
 tab : array[1..100] of longint;
 b : boolean;
begin
 readln(a,n);
 b:=true;
 for i:= 1 to a do
  begin
   read(tab[i]);
   if tab[i]=0 then inc(g);
  end;
  //writeln(g);
  //writeln(tab[n]);
  //writeln(a-g);
  if tab[n]= 0 then n:=a-g
  else
   while b do
    begin
     if tab[n]=tab[n+1] then
      inc(n)
     else
      b:=false;
    end;
  writeln(n);
 end.