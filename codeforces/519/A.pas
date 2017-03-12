var
 a,m,j,i,n,g : longint;
 tab1 : array['a'..'z'] of longint;
 tab2 : array['A'..'Z'] of longint;
 tab3 : array[1..8,1..8] of char;
 ch : char;
begin
 for i:= 1 to 8 do
  begin
   for j:= 1 to 8 do
    begin
     read(tab3[i,j]);
     if tab3[i,j]='.' then
      continue
     else
      if (ord(tab3[i,j])>=97) and (ord(tab3[i,j])<=122) then
       inc(tab1[tab3[i,j]])
      else
       if (ord(tab3[i,j])>=65) and (ord(tab3[i,j])<=90) then
        inc(tab2[tab3[i,j]]);
    end;
   readln;
  end;
  n:= tab1['q']*9+tab1['r']*5+tab1['b']*3+tab1['n']*3+tab1['p'];
  g:= tab2['Q']*9+tab2['R']*5+tab2['B']*3+tab2['N']*3+tab2['P'];
  if n>g then
   writeln('Black')
  else
   if n<g then
    writeln('White')
   else
    writeln('Draw');
end.