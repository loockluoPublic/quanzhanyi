function [PlaneParaOut,TrianglePoints,MaxDis,distancesFianal] = planefit4(Points1,Points2,Points3,Points4,BoundPoint1,BoundPoint2,distanceThreshold)
% Points 输入点 3*n
% BoundPoint1 边界点1
% BoundPoint2 边界点2
% PlaneParaOut 平面参数4*n
% BJD 三角形点3*n（n 123，456，789这样取）

PointAll = {Points1,Points2,Points3,Points4};
coder.varsize('PlaneParaOut',[4 3000],[0 1]);
PlaneParaOut = zeros(4,4);
inlierIdxFinal = {1,2,3,4};
distancesFianal1 = {1,2,3,4};
for i =1:4
    Points = PointAll{i};
    % 平面拟合
    pointss = Points';

    Cnum = 1:length(pointss);
    bestDist = 99999;  % 最优内点距离

    C = nchoosek(Cnum,3);
    
    for j = 1:length(C)
        % 随机选择三个点
        sampleIdx = C(j,:);
        samplePoints = pointss(sampleIdx, :);

        % 计算平面模型
        A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)];
        coefficients = A \ samplePoints(:,3);
        a = coefficients(1);
        b = coefficients(2);
        d = coefficients(3);
        c=-1;
        distances=abs([a,b,c,d]*[pointss,ones(size(pointss,1),1)]')/sqrt(a*a+b*b+c*c);


        % 确定内点
        inlierIdx = find(distances < distanceThreshold);


        % 更新最优平面模型
        if mean(distances) < bestDist
            bestDist = mean(distances);
            inlierIdxFinal{i} = inlierIdx;
            distancesFianal1{i} = distances;
        end

    end
    % 重新计算最终平面模型，使用所有内点
    
    inlierPoints = pointss(inlierIdxFinal{i}, :);


    x = inlierPoints(:,1);
    y = inlierPoints(:,2);
    z = inlierPoints(:,3);

    PIner = [x,y,z];

    threshold  = 0.5;
    % Fit a plane through the points
    [~, ~, V] = svd(PIner - mean(PIner, 1));
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
        A = [inlierPoints(:,1), inlierPoints(:,2), ones(size(inlierPoints(:,1)))];
        coefficients = A \ inlierPoints(:,3);
        a = coefficients(1);
        b = coefficients(2);
        d = coefficients(3);
        c=-1;
    end
    PlaneParaOut(:,i) = [a;b;c;d];
end
id1 = inlierIdxFinal{1};
id2 = inlierIdxFinal{2};
id3 = inlierIdxFinal{3};
id4 = inlierIdxFinal{4};

tt1 = distancesFianal1{1};
tt2 = distancesFianal1{2};
tt3 = distancesFianal1{3};
tt4 = distancesFianal1{4};

T1 = max(tt1(id1));
T2 = max(tt2(id2));
T3 = max(tt3(id3));
T4 = max(tt4(id4));

MaxDis = [T1,T2,T3,T4];
distancesFianal = [distancesFianal1{1},distancesFianal1{2},distancesFianal1{3},distancesFianal1{4}];


% 平面方程的系数输出

xfit = zeros(1,8);
yfit = zeros(1,8);
zfit = zeros(1,8);

%%%%%% 前2个面的交点 %%%%
% 计算交线
x_val = (max(x)+min(x))./2;
[P0,D] = CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,2),x_val);
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

BJD = [xfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
    yfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
    zfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]])];


% 取八个点
Pdd = BJD(:,[1:3,6,9,16:18]);
P1 = Pdd(:,1);
P2 = Pdd(:,2);
P3 = Pdd(:,3);
P4 = Pdd(:,4);
P5 = Pdd(:,5);
P6 = Pdd(:,6);
P7 = Pdd(:,7);
P8 = Pdd(:,8);


% 计算投影点
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P1,P3);
PP1 = [xN1;yN1;zN1];

[xN2,yN2,zN2] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P2,P4);
PP2 = [xN2;yN2;zN2];

[xN3,yN3,zN3] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P1,P3);
PP3 = [xN3;yN3;zN3];

[xN4,yN4,zN4] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P2,P4);
PP4 = [xN4;yN4;zN4];

[xN5,yN5,zN5] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P5,P6);
PP5 = [xN5;yN5;zN5];

[xN6,yN6,zN6] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P5,P6);
PP6 = [xN6;yN6;zN6];

[xN7,yN7,zN7] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P7,P8);
PP7 = [xN7;yN7;zN7];

[xN8,yN8,zN8] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P7,P8);
PP8 = [xN8;yN8;zN8];

TrianglePoints = [PP1,PP2,PP3,PP2,PP3,PP4,PP1,PP3,PP5,PP3,PP5,PP6,PP5,PP6,PP7,PP6,PP7,PP8,PP2,PP4,PP7,PP4,PP7,PP8];

coder.varsize('TrianglePoints',[3 3000],[0 1]);


end