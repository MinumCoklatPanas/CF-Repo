var
 s : ansistring;
 i : longint;
begin
 readln(s);
 if (ord(s[1])>=97) and (ord(s[1])<=122) then
  begin
   s[1]:=chr(ord(s[1])-32);
   writeln(s);
  end
 else
  writeln(s);
end.
