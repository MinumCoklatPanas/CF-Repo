var
 a,m,j,i,n,g,posi : longint;
 s,tempat,s1,ch : string;
 b : boolean;
begin
 tempat:='South';
 posi:=0;
 readln(n);
 ch:=' ';
 //readln(s1);
 //writeln(pos(ch,s1));
 b:=true;
  for i:= 1 to n do
   begin
    readln(a,s1);
    m:=pos(ch,s1);
    s:=copy(s1,m+1,length(s1)-m+1);
    //writeln(s);
    if b then
     begin
      if posi=0 then
       begin
        //writeln('#1');
        if (tempat=s) then
         begin
          posi:=posi+a;
          if posi=20000 then
           begin
            if tempat='South' then
             tempat:='North'
            else
             tempat:='South';
            posi:=0;
           end
          else
           if posi>20000 then
            b:=false;
          //writeln('posi sekarang ',posi);
          //writeln('tempat sekarang ',tempat);
         end
        else
         b:=false;
       end
      else
        begin
         //writeln('#2');
         if tempat=s then
          begin
           posi:=posi+a;
           if posi=20000 then
            begin
             if tempat='North' then
              tempat:='South'
             else
              tempat:='North';
              posi:=0;
            end
           else
            if (posi>20000) or (posi<0) then
             b:=false;
            //writeln('posi sekarang ',posi);
            //writeln('tempat sekarang ',tempat);
          end
         else
          if (tempat<>s) and ((s<>'West') and (s<>'East')) then
           begin
            posi:=posi-a;
            if (posi<0) then
             b:=false;
            //writeln('posi sekarang ',posi);
            //writeln('tempat sekarang ',tempat);;
           end;
    end;
   end;
  end;
  //writeln(b);
  if not b then
   writeln('NO')
  else
   if (tempat='South') and (posi=0) then
    writeln('YES')
   else
    writeln('NO');
end.
