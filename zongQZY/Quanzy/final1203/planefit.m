function [PlaneParaOut,TrianglePoints] = planefit(Points,PlaneParaIn,BoundPoint1,BoundPoint2)
% Points 输入点 3*n
% PlaneParaIn 输入平面参数 4*n (n可为0)
% BoundPoint1 边界点1
% BoundPoint2 边界点2
% PlaneParaOut 平面参数4*n
% TrianglePoints 三角形点3*n（n 123，456，789这样取）


op = size(PlaneParaIn,2);
% 平面拟合
x = Points(1,:)';
y = Points(2,:)';
z = Points(3,:)';

pointss = Points';

threshold  = 0.5;
% Fit a plane through the points
[~, ~, V] = svd(pointss - mean(pointss, 1));
normal = V(:, 3); % Normal vector of the plane

% Calculate angle between normal vector and z-axis
angle = acosd(abs(dot(normal, [0; 0; 1])));
angle = abs(90-angle);

% Check if angle is below threshold
if angle < threshold
    c = 0;
    bb=polyfit(x,y,1);
    % 拟合，其实是线性回归，但可以用来拟合平面
    a = bb(1);
    b = -1;
    d = bb(2);

else
    % 构建矩阵 A 和向量 b
    A = [x, y, ones(size(x))];

    % 使用最小二乘法拟合平面
    coefficients = A \ z;

    a = coefficients(1);
    b = coefficients(2);
    d = coefficients(3);
    c=-1;
end

PlaneParaOut = zeros(4,1);
TrianglePoints = zeros(3,6);
coder.varsize('TrianglePoints',[3 3000],[0 1]);

if op == 0
    % 平面方程的系数输出
    PlaneParaOut = [a;b;c;d];
    % 找到边界，确定三角点
    xfit = [min(x),min(x),max(x),max(x)];
    yfit = [max(y),min(y),min(y),max(y)];
    zfit = -(d + a * xfit + b * yfit)/c;
    TrianglePoints = [xfit([1:3,1,3,4]);yfit([1:3,1,3,4]);zfit([1:3,1,3,4])];

elseif op == 1
    % 平面方程的系数输出
    PlaneParaOut = [PlaneParaIn,[a;b;c;d]];
    % 计算交线
    xfit = zeros(1,6);
    yfit = zeros(1,6);
    zfit = zeros(1,6);
    x_val = (max(x)+min(x))./2;
    [P0,D] = CrossLine(PlaneParaIn,[a;b;c;d],x_val);

    % 找到边界，确定三角点
    [PointTri] = GenerateTrianglePoints(PlaneParaIn,BoundPoint1,P0,D);
    xfit(1) = PointTri(1,1);
    yfit(1) = PointTri(2,1);
    zfit(1) = PointTri(3,1);
    xfit(2) = PointTri(1,2);
    yfit(2) = PointTri(2,2);
    zfit(2) = PointTri(3,2);

    [PointTri2] = GenerateTrianglePoints(PlaneParaIn,BoundPoint2,P0,D);
    xfit(3) = PointTri2(1,1);
    yfit(3) = PointTri2(2,1);
    zfit(3) = PointTri2(3,1);
    xfit(4) = PointTri2(1,2);
    yfit(4) = PointTri2(2,2);
    zfit(4) = PointTri2(3,2);

    [PointTri3] = GenerateTrianglePoints([a,b,c,d],BoundPoint1,P0,D);
    xfit(5) = PointTri3(1,2);
    yfit(5) = PointTri3(2,2);
    zfit(5) = PointTri3(3,2);

    [PointTri4] = GenerateTrianglePoints([a,b,c,d],BoundPoint2,P0,D);
    xfit(6) = PointTri4(1,2);
    yfit(6) = PointTri4(2,2);
    zfit(6) = PointTri4(3,2);

    TrianglePoints = [xfit([1:3,2:4,[1,3,5],[3,5,6]]);...
        yfit([1:3,2:4,[1,3,5],[3,5,6]]);zfit([1:3,2:4,[1,3,5],[3,5,6]])];

elseif op == 2
    % 平面方程的系数输出
    PlaneParaOut = [PlaneParaIn,[a;b;c;d]];

    %%%%%% 前2个面的交点 %%%%
    % 计算交线
    xfit = zeros(1,8);
    yfit = zeros(1,8);
    zfit = zeros(1,8);
    
    x_val = (max(x)+min(x))./2;
    [P0,D] = CrossLine(PlaneParaIn(:,1),PlaneParaIn(:,2),x_val);
    % 找到边界，确定三角点
    [PointTri] = GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint1,P0,D);
    xfit(1) = PointTri(1,1);
    yfit(1) = PointTri(2,1);
    zfit(1) = PointTri(3,1);
    xfit(2) = PointTri(1,2);
    yfit(2) = PointTri(2,2);
    zfit(2) = PointTri(3,2);

    [PointTri2] = GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint2,P0,D);
    xfit(3) = PointTri2(1,1);
    yfit(3) = PointTri2(2,1);
    zfit(3) = PointTri2(3,1);
    xfit(4) = PointTri2(1,2);
    yfit(4) = PointTri2(2,2);
    zfit(4) = PointTri2(3,2);

    %%%%%% 第2、3个面的交点 %%%%
    [P0,D] = CrossLine(PlaneParaOut(:,2),PlaneParaOut(:,3),x_val);
    % 找到边界，确定三角点
    [PointTri3] = GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint1,P0,D);
    xfit(5) = PointTri3(1,1);
    yfit(5) = PointTri3(2,1);
    zfit(5) = PointTri3(3,1);
    xfit(7) = PointTri3(1,2);
    yfit(7) = PointTri3(2,2);
    zfit(7) = PointTri3(3,2);

    [PointTri4] = GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint2,P0,D);
    xfit(6) = PointTri4(1,1);
    yfit(6) = PointTri4(2,1);
    zfit(6) = PointTri4(3,1);
    xfit(8) = PointTri4(1,2);
    yfit(8) = PointTri4(2,2);
    zfit(8) = PointTri4(3,2);


    TrianglePoints = [xfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8]);...
        yfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8]);zfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8])];

elseif op == 3
    % 平面方程的系数输出
    PlaneParaOut = [PlaneParaIn,[a;b;c;d]];
    xfit = zeros(1,8);
    yfit = zeros(1,8);
    zfit = zeros(1,8);
    
    %%%%%% 前2个面的交点 %%%%
    % 计算交线
    x_val = (max(x)+min(x))./2;
    [P0,D] = CrossLine(PlaneParaIn(:,1),PlaneParaIn(:,2),x_val);
    % 找到边界，确定三角点
    [PointTri] = GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint1,P0,D);
    xfit(1) = PointTri(1,1);
    yfit(1) = PointTri(2,1);
    zfit(1) = PointTri(3,1);

    [PointTri2] = GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint2,P0,D);
    xfit(3) = PointTri2(1,1);
    yfit(3) = PointTri2(2,1);
    zfit(3) = PointTri2(3,1);

    %%%%%% 第2、3个面的交点 %%%%
    [P0,D] = CrossLine(PlaneParaOut(:,2),PlaneParaOut(:,3),x_val);
    % 找到边界，确定三角点
    [PointTri3] = GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint1,P0,D);
    xfit(5) = PointTri3(1,1);
    yfit(5) = PointTri3(2,1);
    zfit(5) = PointTri3(3,1);

    [PointTri4] = GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint2,P0,D);
    xfit(6) = PointTri4(1,1);
    yfit(6) = PointTri4(2,1);
    zfit(6) = PointTri4(3,1);

    %%%%%% 第3、4个面的交点 %%%%
    [P0,D] = CrossLine(PlaneParaOut(:,3),PlaneParaOut(:,4),x_val);
    [PointTri5] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D);
    xfit(7) = PointTri5(1,1);
    yfit(7) = PointTri5(2,1);
    zfit(7) = PointTri5(3,1);

    [PointTri6] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D);
    xfit(8) = PointTri6(1,1);
    yfit(8) = PointTri6(2,1);
    zfit(8) = PointTri6(3,1);
    
    %%%%%% 第1、4个面的交点 %%%%
    [P0,D] = CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,4),x_val);
    [PointTri7] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D);
    xfit(2) = PointTri7(1,1);
    yfit(2) = PointTri7(2,1);
    zfit(2) = PointTri7(3,1);

    [PointTri8] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D);
    xfit(4) = PointTri8(1,1);
    yfit(4) = PointTri8(2,1);
    zfit(4) = PointTri8(3,1);

   TrianglePoints = [xfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
        yfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);zfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]])];
end

end