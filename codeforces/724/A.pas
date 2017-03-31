var
 a,m,j,i,n,g : longint;
 hari : array[1..7] of string;
 s1,s2 : string;
 b : boolean;
begin
 hari[1]:='monday';
 hari[2]:='tuesday';
 hari[3]:='wednesday';
 hari[4]:='thursday';
 hari[5]:='friday';
 hari[6]:='saturday';
 hari[7]:='sunday';
 readln(s1);
 readln(s2);
 b:=false;
 for i:= 1 to 7 do
  begin
   if hari[i]=s1 then
    begin
     m:=(i+2) mod 7;
      if m=0 then
       m:=7;
     n:=(i+3) mod 7;
      if n=0 then
       n:=7;
     if (hari[m]=s2) or (hari[n]=s2) or (s1=s2) then
      b:=true;
    end;
  end;
 if b then
  writeln('YES')
 else
  writeln('NO');
end.