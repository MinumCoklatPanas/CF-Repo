var
 a,m,j,i,n,g : longint;
 s : string;
begin
 readln(a);
 for i := 1 to a do
  begin
   readln(s);
   if length(s)>10 then
    begin
    m:=length(s);
     write(s[1],length(s)-2,s[m]);
    end else
    begin
     write(s);
    end;
    writeln;
  end;
end.