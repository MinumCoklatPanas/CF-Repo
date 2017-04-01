var
 a,m,j,i,n,g,maxbaris,maxkolom,minbaris,minkolom : integer;
 tab : array[1..55,1..55] of char;
begin
 readln(n,m);
 for i:= 1 to n do
  begin
   for j:= 1 to m do
    begin
     read(tab[i,j]);
     if tab[i,j]='*' then
      begin
       inc(a);
       if a=1 then
        begin
         minbaris:=i;
         minkolom:=j;
        end;
       if i<minbaris then
        minbaris:=i;
       if j<minkolom then
        minkolom:=j;
       if i>maxbaris then
        maxbaris:=i;
       if j>maxkolom then
        maxkolom:=j;
      end;
     end;
    readln;
  end;
  //writeln(minbaris,' ',minkolom);
  //awriteln(maxbaris,' ',maxkolom);
 n:=(maxbaris-minbaris)+1;
 m:=(maxkolom-minkolom)+1;
 for i:= minbaris to maxbaris do
  begin
   for j:= minkolom to maxkolom do
    begin
     write(tab[i,j]);
    end;
   writeln;
  end;
end.

