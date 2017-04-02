var
 a,m,j,i,n,g : longint;
 s: string;
 b: boolean;
 tab : array[1..1000] of longint;
begin
 readln(n);
 readln(s);
 a:=1;
 g:=1;
 i:=1;
 while i<=n do
  begin
   if s[i]='B' then
    begin
     b:=true;
     if s[i+1]='B' then
      inc(a)
     else
      begin
       tab[g]:=a;
       inc(g);
       a:=1;
      end;
   end;
   inc(i);
  end;
 writeln(g-1);
 for i:= 1 to g-1 do
  begin
   if i=g-1 then
    write(tab[i])
   else
    write(tab[i],' ');
  end;
  writeln;
end.
