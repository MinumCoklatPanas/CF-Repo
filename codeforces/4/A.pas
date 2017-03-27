var
 n : integer;
 b : boolean;
begin
 readln(n);
 if n=2 then
  writeln('NO')
 else
  if n mod 2=0 then
   writeln('YES')
  else
   writeln('NO');
end.