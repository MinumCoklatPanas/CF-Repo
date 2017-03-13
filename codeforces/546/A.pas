var
 a,m,j,i,n,g,sum,k : longint;
begin
 readln(a,m,k);
 for i:=1 to k do
  sum:=sum+i;
 //writeln(sum);
 g:=a*sum;
 g:=g-m;
 if g<0 then writeln(0) else writeln(g);
end.