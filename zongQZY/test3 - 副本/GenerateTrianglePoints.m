function [PointTri] = GenerateTrianglePoints(PlaneParaIn,BoundPoint1,P0,Direction)

xfit = zeros(1,2);
yfit = zeros(1,2);
zfit = zeros(1,2);

xx1 = BoundPoint1(1);
yy1 = BoundPoint1(2);
zz1 = BoundPoint1(3);
aa1 = Direction(1);
bb1 = Direction(2);
cc1 = Direction(3);
dd1 = -(aa1*xx1+bb1*yy1+cc1*zz1);
t1 = -(dd1+aa1*P0(1)+bb1*P0(2)+cc1*P0(3))./(aa1*Direction(1)+bb1*Direction(2)+cc1*Direction(3));
xfit(1) = P0(1)+Direction(1)*t1;
yfit(1) = P0(2)+Direction(2)*t1;
zfit(1) = P0(3)+Direction(3)*t1;




if PlaneParaIn(3)~=0
    dir1 = [0,0,-PlaneParaIn(4)/PlaneParaIn(3)] -[xfit(1),yfit(1),zfit(1)];
    v1 = cross(Direction, dir1);
    if norm(v1) < eps % 如果法向量与 [0, 0, 1] 平行，则选择另一个向量
        dir1 = [0, -PlaneParaIn(4)/PlaneParaIn(2), 0] - [xfit(1),yfit(1),zfit(1)];
        v1 = cross(Direction, dir1);
    end
else
    dir1 = [0, -PlaneParaIn(4)/PlaneParaIn(2), 0] - [xfit(1),yfit(1),zfit(1)];
    v1 = cross(Direction, dir1);
    if norm(v1) < eps % 如果法向量与 [0, 0, 1] 平行，则选择另一个向量
        dir1 = [-PlaneParaIn(4)/PlaneParaIn(1), 0, 0] - [xfit(1),yfit(1),zfit(1)];
        v1 = cross(Direction, dir1);
    end
end

w1 = cross(Direction, v1);
w1 = w1/norm(w1);

len = 2;
xfit(2) = xfit(1) -len.*w1(1);
yfit(2) = yfit(1) -len.*w1(2);
zfit(2) = zfit(1) -len.*w1(3);


PointTri = [xfit;yfit;zfit];

end