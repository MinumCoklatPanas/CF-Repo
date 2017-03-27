var
 a,m,j,i,n,g,tmp : longint;
 tab : array[1..4] of integer;
begin
 for i:= 1 to 3 do
  read(tab[i]);
 for i:= 1 to 3 do
  begin
   for j:= 1 to 2 do
    begin
     if tab[j]>tab[j+1] then
      begin
       //writeln('y');
       tmp:=tab[j];
       tab[j]:=tab[j+1];
       tab[j+1]:=tmp;
      end;
    end;
  end;
  //for i:= 1 to 3 do
   //write(tab[i],' ');
 m:=abs(tab[1]-tab[2])+abs(tab[2]-tab[3]);
 writeln(m);
end.