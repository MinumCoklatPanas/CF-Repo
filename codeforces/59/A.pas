var
 a,m,j,i,n,g,h1,h2 : longint;
 s : string;

 procedure ubah1(s : string);
 var
 tmp : integer;
 begin
  for tmp:= 1 to length(s) do
   begin
    if(ord(s[tmp])>=65) and (ord(s[tmp])<=90) then
     write(lowercase(s[tmp]))
    else
     write(s[tmp]);
   end;
   writeln;
 end;

 procedure ubah2(s : string);
 var
  tmp1 : integer;
 begin
 //writeln(length(s));
  for tmp1:= 1 to length(s) do
   begin
    if(ord(s[tmp1])>=97) and (ord(s[tmp1])<=122) then
     write(upcase(s[tmp1]))
    else
     write(s[tmp1]);
   end;
  writeln;
 end;

 begin
  //ubah1 ubbah ke huruf besar
  //ubah2 ubah ke huruf kecil
  //h1 huruf besar
  //h2 huruf kecil
  readln(s);
  for i:= 1 to length(s) do
   begin
    if (ord(s[i])>=65) and (ord(s[i])<=90) then inc(h1);
    if (ord(s[i])>=97) and (ord(s[i])<=122) then inc(h2);
   end;
  if h2>=h1 then ubah1(s) else ubah2(s);
end.