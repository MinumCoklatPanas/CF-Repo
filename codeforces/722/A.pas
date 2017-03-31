var
 a,m,j,i,n,g : longint;
 s,s1,s2 : string;
 ch: char;
 b: boolean;
begin
 readln(n);
 readln(s);
 ch:=':';
 s1:=copy(s,1,2);
 s2:=copy(s,4,2);
 val(s1,a,g);
 val(s2,m,g);
 //writeln(a);
 if m>=60 then
  m:=m mod 60;
 j:=m;
 if n=12 then
  begin
   b:=true;
   while b do
    begin
     if a=0 then
      inc(a)
     else
      if a>12 then
       begin
        a:=a mod 10;
        if a=0 then
         a:=10;
       end;
      if a<>0 then
       b:=false;
   end;
  end
 else
  begin
   if a>=24 then
     a:= a mod 10;
  end;
 i:=a;
 str(a,s1);
 str(m,s2);
 if i<10 then
  s1:='0'+s1;
 if j<10 then
  s2:='0'+s2;
 writeln(s1,ch,s2);
end.
