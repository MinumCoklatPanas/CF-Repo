var
 a,m,j,i,n,g,k,o,p : longint;
begin
 readln(a,m,j);
 g:=2;
 k:=2;
 o:=a;
 p:=m;
 while (o<>p) and (a<=j) and (m<=j) do
  begin
   //writeln(o,' ',p);
   if o<p then
    begin
     o:=a*g;
     inc(g);
    end
   else
    if o>p then
     begin
      p:=m*k;
      inc(k);
     end;
  end;
  //writeln(o,' ',p);
 if o<>p then i:=0
 else
 i:=j div o;
 writeln(i);
end.
