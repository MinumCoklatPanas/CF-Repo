var
 a,m,j,i,n,g : longint;
 s1,s2 : string;
 tmp : char;
 b : boolean;

  procedure ubah(var ch : char);
  var
  d : integer;
  begin
   d:=ord(ch);
   d:=d-32;
   ch:=char(d);
  end;

begin
 readln(s1);
 readln(s2);
 b :=true;
 for i:= 1 to length(s1) do
  begin
   if (ord(s1[i])>=97) and (ord(s1[i])<=122) then
    begin
     tmp:=s1[i];
     ubah(tmp);
     s1[i]:=tmp;
    end;
    //writeln(ord(s2[i]));
   if(ord(s2[i])>=97) and (ord(s2[i])<=122) then
    begin
    //writeln('YES');
     tmp:= s2[i];
     //writeln(tmp,' sebelum');
     ubah(tmp);
     //writeln(tmp,' sesudah');
     s2[i]:=tmp;
    end;
  end;
 //writeln(s1);
 //writeln(s2);
 for i:= 1 to length(s1) do
  begin
  //writeln(s1[i],' ',s2[i],' ',i);
     if ord(s1[i]) > ord(s2[i]) then
      begin
       b:=true;
       writeln(1);
       break;
      end
     else
      if (ord(s1[i]) < ord(s2[i])) then
      begin
       b:=true;
       writeln(-1);
       break;
      end
     else
      b:=false;
  end;
  if not b then writeln(0);
  //writeln(s1);
  //writeln(s2);
end.

