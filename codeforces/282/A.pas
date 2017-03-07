var
 a,m,j,i,n,g : longint;
 s : string;
 b : boolean;
begin
 readln(a);
 for i:= 1 to a do
  begin
   readln(s);
   if (s[1]='+') or (s[3]='+') then inc(g)
   else
   if (s[1]='-') or (s[3]='-') then dec(g);
  end;
 writeln(g);
end.