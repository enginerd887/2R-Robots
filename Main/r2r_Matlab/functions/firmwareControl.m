function matrix = firmwareControl(s, steplog, data)

matrix = [];
switch steplog
    case 'at1dX'
    	writeArray(s, data);
        while s.BytesAvailable == 0
            ;
        end
    case 'at1dXy'
            plot(fread(s,1),'r')
            fwrite(s,'s');
            while s.BytesAvailable == 0
                ;
            end
            matrix = readArray(s, 500, 1);
            figure
            plot(matrix)
end
end               