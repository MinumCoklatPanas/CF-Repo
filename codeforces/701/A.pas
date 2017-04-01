var
 a,m,j,i,n,g,min,max,k : longint;
 tab : array[1..110] of integer;
begin
 readln(n);
 for i:= 1 to n do
  begin
   read(tab[i]);
   if i=1 then
    begin
     min:=tab[1];
     g:=i;
    end
   else
    if tab[i]<min then
     begin
      min:=tab[i];
      g:=i;
     end;
   if tab[i]>=max then
    begin
     max:=tab[i];
     a:=i;
    end;
  end;
 m:=min+max;
 writeln(a,' ',g);
 tab[a]:=0;
 tab[g]:=0;
 for i:= 1 to (n div 2)-1 do
  begin
   for j:=1 to n do
    begin
     if tab[j]>0 then
      begin
       for k:= j+1 to n do
        begin
         if tab[k]+tab[j]=m then
          begin
           writeln(k,' ',j);
           tab[k]:=0;
           tab[j]:=0;
          end;
        end;
      end;
    end;
  end;
end.



