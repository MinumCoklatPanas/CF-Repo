var
 a,m,j,i,n,g : integer;
 matriks : array[1..10,1..10] of integer;
begin
 for i:= 1 to 5 do
  begin
   for j:= 1 to 5 do
    begin
     read(matriks[i,j]);
     if matriks[i,j]=1 then
      begin
       a:=i;
       g:=j;
      end;
    end;
    readln;
   end;
   a:=abs(a-3);
   g:=abs(g-3);
   writeln(a+g);
end.