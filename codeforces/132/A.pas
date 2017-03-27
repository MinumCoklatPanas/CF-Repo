var
 a,m,j,i,n,g : longint;
 s1,s2 : string;

  function bit(x : integer) : string;
  var
   tmp : string;
   ch : char;
   k : integer;
  begin
   tmp:='';
   //writeln('masuk fungsi bit ',x);
   while x>0 do
    begin
    //writeln(x);
     if x mod 2=1 then
      tmp:=tmp+'1'
     else
      tmp:=tmp+'0';
     x:=x div 2;
    end;
   if length(tmp)<8 then
    for k:= 1 to 8-length(tmp) do
     tmp:=tmp+'0';
    bit:=tmp;
   //writeln('ini bitnya ',bit);
  end;

 function duapangkat(x : integer) : integer;
 var
  h,p : integer;
 begin
  p:=1;
  if x=0 then
   duapangkat:=1
  else
   begin
    for h := 1 to x do
     begin
      p:=p*2;
     end;
    duapangkat:=p;
   end;
 end;

 function convert(r : string) : integer;
 var
  l,t : integer;
 begin
 t:=0;
 //writeln('ini r ',r);
  for l:= length(r) downto 1 do
   begin
    if r[l]='1' then
     begin
     //writeln('ini l ',l);
     t:=t+duapangkat(length(r)-l);
     //writeln(convert);
     end;
   end;
   convert:=t;
   //writeln('hasil convertnya ',convert);
 end;
begin
 //writeln('ini bit ',bit(1));
 //writeln('ini convert');
 //writeln(convert(bit(1)));
 //writeln('ini dua pangkat ',duapangkat(5));
 readln(s1);
 n:=0;
 for i:= 1 to length(s1) do
  begin
   //writeln('i ', i);
   a:=convert(bit(ord(s1[i])));
   //writeln('a ',a);
   //writeln(n);
   n:=n-a;
   if n<0 then
    n:=n+256
   else
    n:=n mod 256;
   writeln(n);
   n:=a;
  end;
end.
end.
