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

%%  新平行函数
% % % num = 180;
% % % sp = linspace(0,2*pi,num);
% % % sz = linspace(0,2*pi,num);
% % % 
% % % OptErr = 99999;
% % % 
% % % OptPara = zeros(1,5);
% % % OptAllErr2 =  zeros(size(Points2,2),1);
% % % OptAllErr4 =  zeros(size(Points4,2),1);
% % % 
% % % for i = 1:num
% % %     for j = 1:num
% % %         [x0,y0,z0] = sph2cart(sp(i),sz(j),1);
% % %         v = [x0, y0, z0]./ sqrt( x0^2+y0^2+z0^2);
% % %         aaa = v(1);
% % %         bbb = v(2);
% % %         ccc = v(3);
% % %         fun2 = @(dd) sum(abs(aaa * Points2(1,:) + bbb * Points2(2,:) + ccc * Points2(3,:) + dd));
% % %         d_opt4 = fminsearch(fun2, 0);
% % % 
% % %         fun4 = @(dd) sum(abs(aaa * Points4(1,:) + bbb * Points4(2,:) + ccc * Points4(3,:) + dd));
% % %         d_opt4 = fminsearch(fun4, 0);
% % % 
% % % 
% % %         % 计算每个点到平面的距离
% % %         distancess2 = aaa * Points2(1,:) + bbb * Points2(2,:) + ccc * Points2(3,:) + d_opt4;
% % %         distancess4 = aaa * Points4(1,:) + bbb * Points4(2,:) + ccc * Points4(3,:) + d_opt4;
% % % 
% % %         disAll = sum(abs(distancess2))+sum(abs(distancess4));
% % % 
% % %         if disAll < OptErr
% % %             OptPara = [v,d_opt4,d_opt4];
% % %             OptAllErr2 = distancess2;
% % %             OptAllErr4 = distancess4;
% % %             OptErr = disAll;
% % %         end
% % % 
% % % 
% % %     end
% % % end
% % % 
% % % 
% % % % 选择一个基准向量，通常选择 [1, 0, 0] 或 [0, 1, 0]，避免与法向量平行
% % % if OptPara(1) ~= 0
% % %     % 如果法向量的 x 分量不为零，选择 [1, 0, 0] 作为基准
% % %     v1 = [1, 0, 0];
% % % else
% % %     % 否则，选择 [0, 1, 0] 作为基准
% % %     v1 = [0, 1, 0];
% % % end
% % % % 使用叉积计算垂直于法向量的第一个基底向量
% % % v1 = cross(OptPara(1:3), v1);
% % % % 归一化 v1
% % % v1 = v1 / norm(v1);
% % % % 第二个垂直基底向量可以通过叉积获得
% % % v2 = cross(OptPara(1:3), v1);
% % % % 归一化 v2
% % % v2 = v2 / norm(v2);
% % % 
% % % 
% % % OptErr = 99999;
% % % 
% % % OptPara2 = zeros(1,5);
% % % OptAllErr1 =  zeros(size(Points1,2),1);
% % % OptAllErr3 =  zeros(size(Points3,2),1);
% % % VV = [];
% % % thet = 0:0.01:2*pi;
% % % for ll = 1:length(thet)
% % % 
% % %     v = v1.*cos(thet(ll))+v2.*sin(thet(ll));
% % %     VV = [VV;v];
% % %     v=v./norm(v);
% % % 
% % %     aaa = v(1);
% % %     bbb = v(2);
% % %     ccc = v(3);
% % % 
% % %     fun1 = @(dd) sum(abs(aaa * Points1(1,:) + bbb * Points1(2,:) + ccc * Points1(3,:) + dd));
% % %     d_opt1 = fminsearch(fun1, 0);
% % % 
% % %     fun3 = @(dd) sum(abs(aaa * Points3(1,:) + bbb * Points3(2,:) + ccc * Points3(3,:) + dd));
% % %     d_opt3 = fminsearch(fun3, 0);
% % % 
% % % 
% % %     % 计算每个点到平面的距离
% % %     distancess1 = aaa * Points1(1,:) + bbb * Points1(2,:) + ccc * Points1(3,:) + d_opt1;
% % %     distancess3 = aaa * Points3(1,:) + bbb * Points3(2,:) + ccc * Points3(3,:) + d_opt3;
% % % 
% % %     disAll = sum(abs(distancess1))+sum(abs(distancess3));
% % % 
% % %     if disAll < OptErr
% % %         OptPara2 = [v,d_opt1,d_opt3];
% % %         OptAllErr1 = distancess1;
% % %         OptAllErr3 = distancess3;
% % %         OptErr = disAll;
% % %         ooo = ll;
% % %     end
% % % 
% % % end
% % % 
% % % 
% % % [n_fit1, d_fit1] = fit_perpendicular_plane(Points1', OptPara(1:4))
% % % 
% % % [n_fit3, d_fit3] = fit_perpendicular_plane(Points3', OptPara(1:4))
% % % 
% % % 
% % % 
% % % PlaneParaOut2(:,1) = OptPara2(1:4)';
% % % PlaneParaOut2(:,2) = OptPara(1:4)';
% % % PlaneParaOut2(:,3) = OptPara2([1,2,3,5])';
% % % PlaneParaOut2(:,4) = OptPara([1,2,3,5])';
% % % 
% % % 
% % % T1 = max(distancess1);
% % % T2 = max(distancess2);
% % % T3 = max(distancess3);
% % % T4 = max(distancess2);
% % % 
% % % MaxDis = [T1,T2,T3,T4];
% % % distancesFianal = [distancess1,distancess2,distancess3,distancess4];







%% 旧拟合

% % % 
% % % 
% % % 
% % % for i =1:4
% % %     Points = PointAll{i};
% % %     % 平面拟合
% % %     pointss = Points';
% % % 
% % %     Cnum = 1:length(pointss);
% % %     bestDist = 99999;  % 最优内点距离
% % % 
% % %     C = nchoosek(Cnum,3);
% % % 
% % %     for j = 1:length(C)
% % %         % 随机选择三个点
% % %         sampleIdx = C(j,:);
% % %         samplePoints = pointss(sampleIdx, :);
% % % 
% % %         % 计算平面模型
% % %         A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)];
% % %         coefficients = A \ samplePoints(:,3);
% % %         a = coefficients(1);
% % %         b = coefficients(2);
% % %         d = coefficients(3);
% % %         c=-1;
% % %         distances=abs([a,b,c,d]*[pointss,ones(size(pointss,1),1)]')/sqrt(a*a+b*b+c*c);
% % % 
% % % 
% % %         % 确定内点
% % %         inlierIdx = find(distances < distanceThreshold);
% % % 
% % % 
% % %         % 更新最优平面模型
% % %         if mean(distances) < bestDist
% % %             bestDist = mean(distances);
% % %             inlierIdxFinal{i} = inlierIdx;
% % %             distancesFianal1{i} = distances;
% % %         end
% % % 
% % %     end
% % %     % 重新计算最终平面模型，使用所有内点
% % % 
% % %     inlierPoints = pointss(inlierIdxFinal{i}, :);
% % % 
% % % 
% % %     x = inlierPoints(:,1);
% % %     y = inlierPoints(:,2);
% % %     z = inlierPoints(:,3);
% % % 
% % %     PIner = [x,y,z];
% % % 
% % %     threshold  = 2.5; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2.5度阈值
% % %     % Fit a plane through the points
% % %     [~, ~, V] = svd(PIner - mean(PIner, 1));
% % %     normal = V(:, 3); % Normal vector of the plane
% % % 
% % %     % Calculate angle between normal vector and z-axis
% % %     angle = acosd(abs(dot(normal, [0; 0; 1])));
% % %     angle = abs(90-angle);
% % % 
% % %     % Check if angle is below threshold
% % %     if angle < threshold
% % %         c = 0;
% % %         bb=polyfit(x,y,1);
% % %         % 拟合，其实是线性回归，但可以用来拟合平面
% % %         a = bb(1);
% % %         b = -1;
% % %         d = bb(2);
% % %     else
% % %         A = [inlierPoints(:,1), inlierPoints(:,2), ones(size(inlierPoints(:,1)))];
% % %         coefficients = A \ inlierPoints(:,3);
% % %         a = coefficients(1);
% % %         b = coefficients(2);
% % %         d = coefficients(3);
% % %         c=-1;
% % %     end
% % %     PlaneParaOut(:,i) = [a;b;c;d];
% % % end
% % % 
% % % %%%%%%%%% 测试 %%%%%%%%%%%%
% % % 
% % % PlaneParaOut(1,2) = 0;
% % % PlaneParaOut(2,2) = 0;
% % % % PlaneParaOut(3,2) = 1;
% % % PlaneParaOut(4,2) = mean(Points2(3,:));
% % % 
% % % 
% % % PlaneParaOut(1,4) = 0;
% % % PlaneParaOut(2,4) = 0;
% % % % PlaneParaOut(3,4) = 1;
% % % PlaneParaOut(4,4) = mean(Points4(3,:));
% % % 
% % % % PlaneParaOut(1,3) = PlaneParaOut(1,1) ;
% % % 
% % % 
% % % 
% % % 
% % % id1 = inlierIdxFinal{1};
% % % id2 = inlierIdxFinal{2};
% % % id3 = inlierIdxFinal{3};
% % % id4 = inlierIdxFinal{4};
% % % 
% % % tt1 = distancesFianal1{1};
% % % tt2 = distancesFianal1{2};
% % % tt3 = distancesFianal1{3};
% % % tt4 = distancesFianal1{4};
% % % 
% % % 
% % % 
% % % 
% % % 
% % % 
% % % T1 = max(tt1(id1));
% % % T2 = max(tt2(id2));
% % % T3 = max(tt3(id3));
% % % T4 = max(tt4(id4));
% % % 
% % % MaxDis = [T1,T2,T3,T4];
% % % distancesFianal = [distancesFianal1{1},distancesFianal1{2},distancesFianal1{3},distancesFianal1{4}];
% % % %%%%%%%%% 测试 %%%%%%%%%%%%
% % % 
% % % 
% % % 
% % % 
% % % 
% % % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % % % % % % % % 平面方程的系数输出
% % % % % % % % 
% % % % % % % % xfit = zeros(1,8);
% % % % % % % % yfit = zeros(1,8);
% % % % % % % % zfit = zeros(1,8);
% % % % % % % % 
% % % % % % % % %%%%%% 前2个面的交点 %%%%
% % % % % % % % % 计算交线
% % % % % % % % x_val = (max(x)+min(x))./2;
% % % % % % % % [P0,D] = CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,2),x_val);
% % % % % % % % % 找到边界，确定三角点
% % % % % % % % [PointTri] = GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint1,P0,D);
% % % % % % % % xfit(1) = PointTri(1,1);
% % % % % % % % yfit(1) = PointTri(2,1);
% % % % % % % % zfit(1) = PointTri(3,1);
% % % % % % % % 
% % % % % % % % [PointTri2] = GenerateTrianglePoints(PlaneParaOut(:,1),BoundPoint2,P0,D);
% % % % % % % % xfit(3) = PointTri2(1,1);
% % % % % % % % yfit(3) = PointTri2(2,1);
% % % % % % % % zfit(3) = PointTri2(3,1);
% % % % % % % % 
% % % % % % % % %%%%%% 第2、3个面的交点 %%%%
% % % % % % % % [P0,D] = CrossLine(PlaneParaOut(:,2),PlaneParaOut(:,3),x_val);
% % % % % % % % % 找到边界，确定三角点
% % % % % % % % [PointTri3] = GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint1,P0,D);
% % % % % % % % xfit(5) = PointTri3(1,1);
% % % % % % % % yfit(5) = PointTri3(2,1);
% % % % % % % % zfit(5) = PointTri3(3,1);
% % % % % % % % 
% % % % % % % % [PointTri4] = GenerateTrianglePoints(PlaneParaOut(:,3),BoundPoint2,P0,D);
% % % % % % % % xfit(6) = PointTri4(1,1);
% % % % % % % % yfit(6) = PointTri4(2,1);
% % % % % % % % zfit(6) = PointTri4(3,1);
% % % % % % % % 
% % % % % % % % %%%%%% 第3、4个面的交点 %%%%
% % % % % % % % [P0,D] = CrossLine(PlaneParaOut(:,3),PlaneParaOut(:,4),x_val);
% % % % % % % % [PointTri5] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D);
% % % % % % % % xfit(7) = PointTri5(1,1);
% % % % % % % % yfit(7) = PointTri5(2,1);
% % % % % % % % zfit(7) = PointTri5(3,1);
% % % % % % % % 
% % % % % % % % [PointTri6] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D);
% % % % % % % % xfit(8) = PointTri6(1,1);
% % % % % % % % yfit(8) = PointTri6(2,1);
% % % % % % % % zfit(8) = PointTri6(3,1);
% % % % % % % % 
% % % % % % % % %%%%%% 第1、4个面的交点 %%%%
% % % % % % % % [P0,D] = CrossLine(PlaneParaOut(:,1),PlaneParaOut(:,4),x_val);
% % % % % % % % [PointTri7] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint1,P0,D);
% % % % % % % % xfit(2) = PointTri7(1,1);
% % % % % % % % yfit(2) = PointTri7(2,1);
% % % % % % % % zfit(2) = PointTri7(3,1);
% % % % % % % % 
% % % % % % % % [PointTri8] = GenerateTrianglePoints(PlaneParaOut(:,4),BoundPoint2,P0,D);
% % % % % % % % xfit(4) = PointTri8(1,1);
% % % % % % % % yfit(4) = PointTri8(2,1);
% % % % % % % % zfit(4) = PointTri8(3,1);
% % % % % % % % 
% % % % % % % % BJD = [xfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
% % % % % % % %     yfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]]);...
% % % % % % % %     zfit([1:3,2:4,[1,3,5],[3,5,6],5:7,6:8,[2,4,7],[4,7,8]])];
% % % % % % % % 
% % % % % % % % 
% % % % % % % % % 取八个点
% % % % % % % % Pdd = BJD(:,[1:3,6,9,16:18]);
% % % % % % % % P1 = Pdd(:,1);
% % % % % % % % P2 = Pdd(:,2);
% % % % % % % % P3 = Pdd(:,3);
% % % % % % % % P4 = Pdd(:,4);
% % % % % % % % P5 = Pdd(:,5);
% % % % % % % % P6 = Pdd(:,6);
% % % % % % % % P7 = Pdd(:,7);
% % % % % % % % P8 = Pdd(:,8);
% % % % % % % % 
% % % % % % % % 
% % % % % % % % % 计算投影点
% % % % % % % % [xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P1,P3);
% % % % % % % % PP1 = [xN1;yN1;zN1];
% % % % % % % % 
% % % % % % % % [xN2,yN2,zN2] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P2,P4);
% % % % % % % % PP2 = [xN2;yN2;zN2];
% % % % % % % % 
% % % % % % % % [xN3,yN3,zN3] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P1,P3);
% % % % % % % % PP3 = [xN3;yN3;zN3];
% % % % % % % % 
% % % % % % % % [xN4,yN4,zN4] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P2,P4);
% % % % % % % % PP4 = [xN4;yN4;zN4];
% % % % % % % % 
% % % % % % % % [xN5,yN5,zN5] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P5,P6);
% % % % % % % % PP5 = [xN5;yN5;zN5];
% % % % % % % % 
% % % % % % % % [xN6,yN6,zN6] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P5,P6);
% % % % % % % % PP6 = [xN6;yN6;zN6];
% % % % % % % % 
% % % % % % % % [xN7,yN7,zN7] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,P7,P8);
% % % % % % % % PP7 = [xN7;yN7;zN7];
% % % % % % % % 
% % % % % % % % [xN8,yN8,zN8] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,P7,P8);
% % % % % % % % PP8 = [xN8;yN8;zN8];
% % % 
% % % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%% 强行令c=1
aaa = 0;
bbb = 0;
ccc = -1;
ddd2 = mean(Points2(3,:));
ddd4 = mean(Points4(3,:));

distancess2 = Points2(3,:)-ddd2;
distancess4 = Points4(3,:)-ddd4;


cccc = 0;
bb=polyfit([Points1(1,:)]',[Points1(2,:)]',1);
% 拟合，其实是线性回归，但可以用来拟合平面
aaaa1 = bb(1);
bbbb = -1;
dddd1 = bb(2);


v1 = [1,0,0];
v2 = [0,1,0];

OptErr =9999;
OptPara2 = zeros(1,5);
OptAllErr1 =  zeros(size(Points1,2),1);
OptAllErr3 =  zeros(size(Points3,2),1);

thet = 0:0.01:2*pi;
for ll = 1:length(thet)

    v = v1.*cos(thet(ll))+v2.*sin(thet(ll));

    v=v./norm(v);

    aaa = v(1);
    bbb = v(2);
    ccc = v(3);


    fun1 = @(dd) sum(abs(aaa * Points1(1,:) + bbb * Points1(2,:) + ccc * Points1(3,:) + dd));
    d_opt1 = fminsearch(fun1, 0);

    fun3 = @(dd) sum(abs(aaa * Points3(1,:) + bbb * Points3(2,:) + ccc * Points3(3,:) + dd));
    d_opt3 = fminsearch(fun3, 0);


    % 计算每个点到平面的距离
    distancess1 = aaa * Points1(1,:) + bbb * Points1(2,:) + ccc * Points1(3,:) + d_opt1;
    distancess3 = aaa * Points3(1,:) + bbb * Points3(2,:) + ccc * Points3(3,:) + d_opt3;

    disAll = sum(abs(distancess1))+sum(abs(distancess3));

    if disAll < OptErr
        OptPara2 = [v,d_opt1,d_opt3];
        OptAllErr1 = distancess1;
        OptAllErr3 = distancess3;
        OptErr = disAll;
        ooo = ll;
    end
end

PlaneParaOut(1:4,1) = [OptPara2(1);OptPara2(2);0;OptPara2(4)];

PlaneParaOut(1:4,2) = [0;0;-1;ddd2];

PlaneParaOut(1:4,3) = [OptPara2(1);OptPara2(2);0;OptPara2(5)];

PlaneParaOut(1:4,4) = [0;0;-1;ddd4];



T1 = max(distancess1);
T2 = max(distancess2);
T3 = max(distancess3);
T4 = max(distancess2);

MaxDis = [T1,T2,T3,T4];
distancesFianal = [distancess1,distancess2,distancess3,distancess4];

%% 
PlaneParaOutP = PlaneParaOut';


% 初始化一个矩阵存储叉乘结果
cross_vectors = zeros(4, 3);

% 计算每对相邻侧面法向量的叉乘
for i = 1:4
    if i < 4
        cross_vectors(i, :) = cross(PlaneParaOutP(i, 1:3), PlaneParaOutP(i+1, 1:3));
    else
        cross_vectors(i, :) = cross(PlaneParaOutP(i, 1:3), PlaneParaOutP(1, 1:3)); % 最后一个与第一个相邻
    end
    cross_vectors(i, :) = cross_vectors(i, :) / norm(cross_vectors(i, :)); % 归一化
end

% 使所有方向一致
reference_vector = cross_vectors(1, :);  % 选择第一个向量作为参考
for i = 2:4
    if dot(reference_vector, cross_vectors(i, :)) < 0  % 如果方向相反
        cross_vectors(i, :) = -cross_vectors(i, :);    % 翻转方向
    end
end


% 计算平均方向向量，并归一化
n = mean(cross_vectors, 1);


% 计算顶面方程的 d 值
d_top = -dot(n, BoundPoint1);

% 计算底面方程的 d 值
d_bottom = -dot(n, BoundPoint2);

% 初始化顶点矩阵
PP = zeros(8, 3);

% 计算顶面和底面的4个顶点
for i = 1:4
    % 顶面顶点
    if i < 4
        PlaneParaOut1 = PlaneParaOutP(i, :);
        PlaneParaOut2 = PlaneParaOutP(i + 1, :);
    else
        PlaneParaOut1 = PlaneParaOutP(i, :);
        PlaneParaOut2 = PlaneParaOutP(1, :);
    end
    
    % 求顶面和两个相邻侧面的交线
    A = [PlaneParaOut1(1:3); PlaneParaOut2(1:3); n];
    B_top = [-PlaneParaOut1(4); -PlaneParaOut2(4); -d_top];
    PP(i, :) = A\B_top;

    % 求底面和两个相邻侧面的交线
    B_bottom = [-PlaneParaOut1(4); -PlaneParaOut2(4); -d_bottom];
    PP(i + 4, :) = A\B_bottom;
end


PP1 = PP(1,:)';
PP2 = PP(4,:)';
PP3 = PP(5,:)';
PP4 = PP(8,:)';
PP5 = PP(2,:)';
PP6 = PP(6,:)';
PP7 = PP(3,:)';
PP8 = PP(7,:)';


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % 平面1的参数 (A1x + B1y + C1z + D1 = 0)
% A1 = PlaneParaOutP(1,1); B1 = PlaneParaOutP(1,2); C1 =PlaneParaOutP(1,3); D1 = PlaneParaOutP(1,4);
% % 平面2的参数 (A2x + B2y + C2z + D2 = 0)
% A2 = PlaneParaOutP(2,1); B2 = PlaneParaOutP(2,2); C2 =PlaneParaOutP(2,3); D2 = PlaneParaOutP(2,4);
% % 选择一个自由变量 (假设为 x)
% syms x y z
% % 方程1和方程2
% eq1 = A1*x + B1*y + C1*z + D1 == 0;
% eq2 = A2*x + B2*y + C2*z + D2 == 0;
% % 解方程组
% sol = solve([eq1, eq2], [y, z]);
% % 提取解
% y_sol = sol.y;
% z_sol = sol.z;
% % 设定 x 的范围
% x_vals = linspace(-5, 5, 100);
% y_vals = double(subs(y_sol, x, x_vals));
% z_vals = double(subs(z_sol, x, x_vals));
% PL1 = [x_vals(1),y_vals(1),z_vals(1)];
% PL2 = [x_vals(end),y_vals(end),z_vals(end)];
% [xn1,yn1,zn1] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2);
% PPP1 = [xn1,yn1,zn1];
% [xn2,yn2,zn2] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2);
% PPP3 = [xn2,yn2,zn2];
% 
% 
% % 平面1的参数 (A1x + B1y + C1z + D1 = 0)
% A1 = PlaneParaOutP(2,1); B1 = PlaneParaOutP(2,2); C1 =PlaneParaOutP(2,3); D1 = PlaneParaOutP(2,4);
% % 平面2的参数 (A2x + B2y + C2z + D2 = 0)
% A2 = PlaneParaOutP(3,1); B2 = PlaneParaOutP(3,2); C2 =PlaneParaOutP(3,3); D2 = PlaneParaOutP(3,4);
% % 选择一个自由变量 (假设为 x)
% syms x y z
% % 方程1和方程2
% eq1 = A1*x + B1*y + C1*z + D1 == 0;
% eq2 = A2*x + B2*y + C2*z + D2 == 0;
% % 解方程组
% sol = solve([eq1, eq2], [y, z]);
% % 提取解
% y_sol = sol.y;
% z_sol = sol.z;
% % 设定 x 的范围
% x_vals = linspace(-5, 5, 100);
% y_vals = double(subs(y_sol, x, x_vals));
% z_vals = double(subs(z_sol, x, x_vals));
% PL1 = [x_vals(1),y_vals(1),z_vals(1)];
% PL2 = [x_vals(end),y_vals(end),z_vals(end)];
% [xn3,yn3,zn3] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2);
% PPP5 = [xn3,yn3,zn3];
% [xn4,yn4,zn4] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2);
% PPP6 = [xn4,yn4,zn4];
% 
% 
% % 平面1的参数 (A1x + B1y + C1z + D1 = 0)
% A1 = PlaneParaOutP(3,1); B1 = PlaneParaOutP(3,2); C1 =PlaneParaOutP(3,3); D1 = PlaneParaOutP(3,4);
% % 平面2的参数 (A2x + B2y + C2z + D2 = 0)
% A2 = PlaneParaOutP(4,1); B2 = PlaneParaOutP(4,2); C2 =PlaneParaOutP(4,3); D2 = PlaneParaOutP(4,4);
% % 选择一个自由变量 (假设为 x)
% syms x y z
% % 方程1和方程2
% eq1 = A1*x + B1*y + C1*z + D1 == 0;
% eq2 = A2*x + B2*y + C2*z + D2 == 0;
% % 解方程组
% sol = solve([eq1, eq2], [y, z]);
% % 提取解
% y_sol = sol.y;
% z_sol = sol.z;
% % 设定 x 的范围
% x_vals = linspace(-5, 5, 100);
% y_vals = double(subs(y_sol, x, x_vals));
% z_vals = double(subs(z_sol, x, x_vals));
% PL1 = [x_vals(1),y_vals(1),z_vals(1)];
% PL2 = [x_vals(end),y_vals(end),z_vals(end)];
% [xn3,yn3,zn3] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2);
% PPP7 = [xn3,yn3,zn3];
% [xn4,yn4,zn4] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2);
% PPP8 = [xn4,yn4,zn4];
% 
% 
% % 平面1的参数 (A1x + B1y + C1z + D1 = 0)
% A1 = PlaneParaOutP(4,1); B1 = PlaneParaOutP(4,2); C1 =PlaneParaOutP(4,3); D1 = PlaneParaOutP(4,4);
% % 平面2的参数 (A2x + B2y + C2z + D2 = 0)
% A2 = PlaneParaOutP(1,1); B2 = PlaneParaOutP(1,2); C2 =PlaneParaOutP(1,3); D2 = PlaneParaOutP(1,4);
% % 选择一个自由变量 (假设为 x)
% syms x y z
% % 方程1和方程2
% eq1 = A1*x + B1*y + C1*z + D1 == 0;
% eq2 = A2*x + B2*y + C2*z + D2 == 0;
% % 解方程组
% sol = solve([eq1, eq2], [y, z]);
% % 提取解
% y_sol = sol.y;
% z_sol = sol.z;
% % 设定 x 的范围
% x_vals = linspace(-5, 5, 100);
% y_vals = double(subs(y_sol, x, x_vals));
% z_vals = double(subs(z_sol, x, x_vals));
% PL1 = [x_vals(1),y_vals(1),z_vals(1)];
% PL2 = [x_vals(end),y_vals(end),z_vals(end)];
% [xn3,yn3,zn3] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint1,PL1,PL2);
% PPP2 = [xn3,yn3,zn3];
% [xn4,yn4,zn4] = foot_of_perpendicular_from_a_point_to_a_line(BoundPoint2,PL1,PL2);
% PPP4 = [xn4,yn4,zn4];
% 
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% temp1 = [PP1,PP2,PP3,PP4,PP5,PP6,PP7,PP8]';
% temp2 = [PPP1;PPP2;PPP3;PPP4;PPP5;PPP6;PPP7;PPP8];





% TrianglePoints = [PPP1;PPP2;PPP3;PPP2;PPP3;PPP4;PPP1;PPP3;PPP5;PPP3;PPP5;PPP6;PPP5;PPP6;PPP7;PPP6;PPP7;PPP8;PPP2;PPP4;PPP7;PPP4;PPP7;PPP8]';
TrianglePoints = [PP1,PP2,PP3,PP2,PP3,PP4,PP1,PP3,PP5,PP3,PP5,PP6,PP5,PP6,PP7,PP6,PP7,PP8,PP2,PP4,PP7,PP4,PP7,PP8];

coder.varsize('TrianglePoints',[3 3000],[0 1]);


end