var
 a,m,j,i,n,g,k : integer;
 tan : array[1..110] of integer;
 kata : array[1..110] of string;
 b: boolean;
begin
 readln(n);
// writeln(n);
 for i:= 1 to n do
  read(tan[i]);
  readln;
 //for i:= 1 to n do
  //writeln(tan[i]);
 b:=true;
 for k:= 1 to n do
  begin
   g:=0;
   //writeln('k ',k);
   readln(kata[k]);
   //writeln(k,' ',kata[k]);
   //writeln(length(kata[k]));
   for j:= 1 to length(kata[k]) do
    begin
     if (kata[k][j]='a') or (kata[k][j]='i') or (kata[k][j]='u') or (kata[k][j]='e') or (kata[k][j]='o') or (kata[k][j]='y') then
       inc(g);
    end;
    //writeln(g);
   if tan[k]<>g then
    b:=false;
   //writeln(b);
 end;
 if b then
  writeln('YES')
 else
  writeln('NO');
end.
