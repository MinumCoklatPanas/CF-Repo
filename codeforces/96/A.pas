var
a,m,j,i,n,g : longint;
s : string;
b : boolean;
begin
 readln(s);
 a:=1;
 b:=true;
 for i:= 1 to length(s) do
  begin
   if s[i]<>s[i+1] then
    begin
     a:=1;
     continue
    end
   else
    begin
     inc(a);
     if a=7 then
      begin
       b:=false;
       break;
      end;
    end;
  end;
  if not b then writeln('YES') else writeln('NO');
end.