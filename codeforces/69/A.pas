var
 a,m,j,i,n,g,sumx,sumy,sumz : longint;
 tabX : array[1..200] of integer;
 tabY : array[1..200] of integer;
 tabZ : array[1..200] of integer;
begin
 readln(n);
 for i:= 1 to n do
  readln(tabX[i],tabY[i],tabZ[i]);
 for i:= 1 to n do
  begin
   sumx:=sumx+tabX[i];
   sumy:=sumy+tabY[i];
   sumz:=sumz+tabZ[i];
  end;
 if (sumx=0) and (sumy=0) and (sumz=0) then writeln('YES') else writeln('NO');
end.