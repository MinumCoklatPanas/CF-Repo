var
 a,m,j,i,n,g : longint;
 tab : array[0..9] of integer;
 b : boolean;
begin
 b := true;
 readln(n);
 //for a:= 0 to 9 do writeln(g,' ',tab[g]);
 for i:= n+1 to 9999 do
  begin
  m:=i;
  b:=true;
  //writeln(m);
   //for a:= 0 to 9 do writeln(a,' ',tab[a]);
   for g:= 0 to 9 do
   begin
    tab[g]:=0;
    //writeln(g,' ',tab[g]);
   end;
   while m>0 do
    begin
     //writeln(m);
     //writeln(m mod 10);
     inc(tab[m mod 10]);
     m:=m div 10;
    end;
   //for g:= 0 to 9 do
    //begin
     //writeln(g,' ',tab[g]);
    //end;
   //if not b  then for g:= 0 to 9 do tab[g]:=0;
   for j:= 0 to 9 do
    begin
     //writeln(j,' ',tab[j]);
     if tab[j]>=2 then
      begin
       //writeln(j,' disini');
       b:=false;
      end;
    end;
    //writeln(i,' ',b);
   if b then
    begin
     writeln(i);
     exit;
    end;
  end;
end.
