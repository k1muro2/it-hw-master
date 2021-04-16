Program homework;
    var a,b,c:integer;
begin
    Writeln ('>>> Введите стороны треугольника...');
        Readln (a,b,c);
    if (a+b>c) and (a+c>b) and (c+b>a) then 
        begin 
        if (a=b) and (a=c) and (b=c) then 
            writeln ('>>> Треугольник - равносторонний')
        else begin 
            if (a=b)or(a=c)or(b=c) then Writeln ('>>> Треугольник - равнобедренный!')
            else 
                Writeln ('>>> Треугольник - разносторонний!');
            end;
        end
    else
        writeln ('>>> Неудача! Треугольника с заданными сторонами не существует...');
end.