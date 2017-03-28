var
 a,m,j,i,n,g,bes,kec : longint;
 s : array[1..200] of char;

 function max(x,y : integer) : integer;
 begin
  if x>=y then
   max:=x
  else
   max:=y;
 end;

begin
 readln(n);
 for i:= 1 to n do
  begin
   read(s[i]);
   if s[i]='x' then
    inc(kec)
   else
    inc(bes);
  end;
 a:=n div 2;
 a:=max(bes,kec)-a;
 i:=1;
 g:=a;
 if max(kec,bes)=kec then
  begin
   while g>0 do
    begin
     if s[i]='x' then
      begin
       s[i]:='X';
       dec(g);
      end;
     inc(i);
    end;
  end
 else
  begin
   while g>0 do
    begin
     if s[i]='X' then
      begin
       s[i]:='x';
       dec(g);
      end;
     inc(i);
    end;
  end;
 writeln(a);
 for i:= 1 to n do
  write(s[i]);
  writeln;
 end.



