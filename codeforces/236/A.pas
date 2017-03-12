var
 a,m,j,i,n,g : longint;
 tab : array['a'..'z'] of integer;
 ch : char;
 s : string;
begin
 readln(s);
 for i := 1 to length(s) do
   inc(tab[s[i]]);
 for ch:= 'a' to 'z' do
   if tab[ch]>0 then inc(n);
 if n mod 2 = 0 then writeln('CHAT WITH HER!') else writeln('IGNORE HIM!');
end.

