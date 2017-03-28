var
 m,j,i,n,g : longint;
 ah : char;
begin
 readln(n,m);
  for i:= 1 to n do
   begin
    for j:= 1 to 2*m-1 do
     begin
      //writeln(i,' ',j);
      read(ah);
      //writeln(ah);
      if (ah='C') or (ah='M') or (ah='Y') then
       inc(g);
     end;
     readln;
   end;
 if g>=1 then
  writeln('#Color')
 else
  writeln('#Black&White');
end.