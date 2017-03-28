var
 a,m,j,i,n,g : longint;
 tab : array[0..9] of string;
 s1,s2 : string;
begin
 readln(s1);
 for i:= 0 to 9 do
  readln(tab[i]);
 for i:= 1 to 8 do
  begin
   s2:=copy(s1,1,10);
   delete(s1,1,10);
   for j:= 0 to 9 do
    begin
     if tab[j]=s2 then
      write(j);
    end;
  end;
writeln;
end.