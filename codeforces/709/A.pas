var
 a,m,j,i,n,g,k,l : longint;
begin
 readln(a,m,g);
 for i:= 1 to a do
  begin
   read(j);
    if j<=m then
     begin
      k:=k+j;
      //writeln(k);
      if k>g then
       begin
        k:=0;
        inc(l);
       end;
      n:=j;
     end;
   end;
  writeln(l);
end.
