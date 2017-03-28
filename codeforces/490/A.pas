var
 a,m,j,i,n,g,t1,t2,t3,k : longint;
 tab : array[1..5010] of integer;

 function min(x,y,z : longint) : longint;
 begin
  if x<=y then
  begin
   if x<=z then
    min:=x
   else
    min:=z;
  end
  else
   begin
   if y<=z then
    min:=y
   else
    min:=z;
   end;
end;

begin
 readln(a);
  for i:= 1 to a do
   begin
    read(tab[i]);
    if tab[i]=1 then
     inc(t1);
    if tab[i]=2 then
     inc(t2);
    if tab[i]=3 then
     inc(t3);
   end;
 writeln(min(t1,t2,t3));
 for i:= 1 to min(t1,t2,t3) do
  begin
   for j:= 1 to 3 do
    begin
     for k:= 1 to a do
      begin
       if tab[k]=j then
        begin
         if j=3 then
          write(k)
         else
          write(k,' ');
         tab[k]:=0;
         break;
        end;
      end;
     //writeln;
    end;
   writeln;
  end;
end.
