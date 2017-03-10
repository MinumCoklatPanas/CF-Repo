var
 a,m,j,i,n,g : integer;
 tabel : array[1..4] of integer;
 s : ansistring;
begin
 readln(s);
 for i:= 1 to length(s) do
  begin
   if s[i]='1' then inc(tabel[1]);
   if s[i]='2' then inc(tabel[2]);
   if s[i]='3' then inc(tabel[3]);
  end;
 s:='';
 for i:= 1 to tabel[1] do
   s:=s+'1'+'+';
 for i:= 1 to tabel[2] do
  s:=s+'2'+'+';
 for i:= 1 to tabel[3] do
  s:=s+'3'+'+';
 delete(s,length(s),1);
 writeln(s);
end.