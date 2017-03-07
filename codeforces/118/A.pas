var
a,m,j,i,n,g : longint;
s : string;
begin
 readln(s);
 for i:= 1 to length(s) do
  begin
   if (s[i]='a') or (s[i]='A') or (s[i]='O') or (s[i]='o') or (s[i]='Y') or (s[i]='y') or (s[i]='E') or (s[i]='e') or (s[i]='U') or (s[i]='u') or (s[i]='I') or (s[i]='i') then
    continue
   else
     if (ord(s[i])>=65) and (ord(s[i])<=90) then
      begin
       write('.',lowercase(s[i]));
      end
   else
    write('.',s[i]);
  end;
  writeln;
end.



