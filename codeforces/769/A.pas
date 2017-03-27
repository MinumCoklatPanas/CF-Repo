var
 a,m,j,i,n,g,tmp : longint;
 tab : array[1..10] of integer;
begin
 readln(n);
 for i:= 1 to n do
   read(tab[i]);
 for i:= 1 to n do
  begin
   for j:= 1 to n-1 do
    begin
     if tab[j+1]<tab[j] then
      begin
       tmp:=tab[j];
       tab[j]:=tab[j+1];
       tab[j+1]:=tmp;
      end;
    end;
  end;
 if n mod 2 =1 then
  m:=(n+1) div 2
 else
  m:=(n div 2)+1;
 writeln(tab[m]);
 //for i:= 1 to n do
 //rite(tab[i],' ');
 //riteln;
end.
