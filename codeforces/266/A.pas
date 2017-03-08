var
 a,m,j,i,n,g : longint;
 s : string;
begin
 readln(a);
 readln(s);
 i:=1;
 while i<=length(s) do
  begin
   while s[i+1]=s[i] do
    begin
     delete(s,pos(s[i+1],s),1);
     inc(g);
    end;
   inc(i);
  end;
 writeln(g);
end.
