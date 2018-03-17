var
 dua : array[0..35] of Int64;
 tiga : array[0..25] of Int64;
 ans,num,l,r,hasil : Int64;
 i,j,a,k : longint;

function hitung(x : Int64) : Int64;
var
 tmp : Int64;
begin
tmp:=0;
while (x>0) do
 begin
  inc(tmp);
  x:=x div 2;
 end;
hitung:=tmp;
end;


begin
readln(l,r);
dua[0]:=1;
for i:=1 to 31 do
 begin
  dua[i]:=dua[i-1]*2;
 end;
tiga[0]:=1;
for i:=1 to 20 do
 begin
  tiga[i]:=tiga[i-1]*3;
 end;
tiga[25]:=1;
num:=hitung(r);
//writeln(num);
ans:=0;
for i:=0 to num-1 do
 begin
  for j:=0 to 20 do
   begin
     hasil:=dua[i]*tiga[j];
     //writeln(hasil,' ',i,' ',j);
     if (hasil>r) then break;
     if ((l<=hasil) and (hasil<=r)) then
      inc(ans);
   end;
 end;
writeln(ans);
//readln;
end.
