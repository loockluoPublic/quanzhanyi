function [PlaneParaOut,TrianglePoints,MaxDis,tt1,tt2,tt3,tt4,tt5,tt6,tt7,tt8,LenDaoJiao] = planefit8(Points1,Points2,Points3,Points4,Points5,Points6,Points7,Points8,P_bound1,P_bound2,distanceThreshold)
% Points 输入点 3*n
% BoundPoint1 边界点1
% BoundPoint2 边界点2
% PlaneParaOut 平面参数4*n
% PP 三角形点3*n（n 123，456，789这样取）



%%  增加判断面的点是否完善

[~,TrianglePoints4,~,~] = planefit4(Points1,Points3,Points5,Points7,P_bound1,P_bound2,distanceThreshold);
tempPP = TrianglePoints4(:,[1,2,3,6,9,12,15,18]);

Isempty = [size(Points2,2),size(Points4,2),size(Points6,2),size(Points8,2)];
offnum = 0.0001;
fprintf('Isempty FACE2468: %f, %f, %f, %f\n',Isempty(1),Isempty(2),Isempty(3),Isempty(4));
if Isempty(1) == 0
    TPP9 = tempPP(:,1) + offnum*(tempPP(:,2)-tempPP(:,1));
    TPP10 = tempPP(:,1) + offnum*(tempPP(:,5)-tempPP(:,1));
    normaltao = tempPP(:,1) - (TPP9+TPP10)./2;

    % 已知数据：平面法向量和平面上一点
    normaltao = normaltao / norm(normaltao); % 归一化法向量
    point_on_plane = TPP10; % 平面上一点
    
    % 生成平面上的随机点参数
    Tnum_points = 20; % 要生成的点数
    Trange = 1; % 点的分布范围
    
    % 找到平面内的两个非平行向量作为基向量
    % 随意选择一个非平行于法向量的向量
    Tv1 = [1; 0; 0];
    if abs(dot(normaltao, Tv1)) > 1e-6 % 如果v1与法向量平行，则换一个向量
    Tv1 = [0; 1; 0];
    end
    
    % 使用Gram-Schmidt正交化法找到两个平面内的正交向量
    Tu = Tv1 - dot(Tv1, normaltao) * normaltao; % 投影法向量到平面内
    Tu = Tu / norm(Tu); % 单位化
    
    Tv = cross(normaltao, Tu); % 第二个正交向量
    
    % 生成平面上的点
    Tpoints = zeros(3, Tnum_points);
    for i = 1:Tnum_points
        % 在范围内随机生成系数
        Ta = (rand - 0.5) * 2 * Trange;
        Tb = (rand - 0.5) * 2 * Trange;
        
        % 计算平面上的点：p = p0 + a*u + b*v
        Tpoints(:, i) = point_on_plane + Ta * Tu + Tb * Tv;
    end
Points2 = Tpoints;
end



if Isempty(2) == 0
    TPP9 = tempPP(:,5) + offnum*(tempPP(:,1)-tempPP(:,5));
    TPP10 = tempPP(:,5) + offnum*(tempPP(:,7)-tempPP(:,5));
    normaltao = tempPP(:,5) - (TPP9+TPP10)./2;

    % 已知数据：平面法向量和平面上一点
    normaltao = normaltao / norm(normaltao); % 归一化法向量
    point_on_plane = TPP9; % 平面上一点
    
    % 生成平面上的随机点参数
    Tnum_points = 20; % 要生成的点数
    Trange = 1; % 点的分布范围
    
    % 找到平面内的两个非平行向量作为基向量
    % 随意选择一个非平行于法向量的向量
    Tv1 = [1; 0; 0];
    if abs(dot(normaltao, Tv1)) > 1e-6 % 如果v1与法向量平行，则换一个向量
    Tv1 = [0; 1; 0];
    end
    
    % 使用Gram-Schmidt正交化法找到两个平面内的正交向量
    Tu = Tv1 - dot(Tv1, normaltao) * normaltao; % 投影法向量到平面内
    Tu = Tu / norm(Tu); % 单位化
    
    Tv = cross(normaltao, Tu); % 第二个正交向量
    
    % 生成平面上的点
    Tpoints = zeros(3, Tnum_points);
    for i = 1:Tnum_points
        % 在范围内随机生成系数
        Ta = (rand - 0.5) * 2 * Trange;
        Tb = (rand - 0.5) * 2 * Trange;
        
        % 计算平面上的点：p = p0 + a*u + b*v
        Tpoints(:, i) = point_on_plane + Ta * Tu + Tb * Tv;
    end
Points4 = Tpoints;
end



if Isempty(3) == 0
    TPP9 = tempPP(:,7) + offnum*(tempPP(:,5)-tempPP(:,7));
    TPP10 = tempPP(:,7) + offnum*(tempPP(:,2)-tempPP(:,7));
    normaltao = tempPP(:,7) - (TPP9+TPP10)./2;

    % 已知数据：平面法向量和平面上一点
    normaltao = normaltao / norm(normaltao); % 归一化法向量
    point_on_plane = TPP9; % 平面上一点
    
    % 生成平面上的随机点参数
    Tnum_points = 20; % 要生成的点数
    Trange = 1; % 点的分布范围
    
    % 找到平面内的两个非平行向量作为基向量
    % 随意选择一个非平行于法向量的向量
    Tv1 = [1; 0; 0];
    if abs(dot(normaltao, Tv1)) > 1e-6 % 如果v1与法向量平行，则换一个向量
    Tv1 = [0; 1; 0];
    end
    
    % 使用Gram-Schmidt正交化法找到两个平面内的正交向量
    Tu = Tv1 - dot(Tv1, normaltao) * normaltao; % 投影法向量到平面内
    Tu = Tu / norm(Tu); % 单位化
    
    Tv = cross(normaltao, Tu); % 第二个正交向量
    
    % 生成平面上的点
    Tpoints = zeros(3, Tnum_points);
    for i = 1:Tnum_points
        % 在范围内随机生成系数
        Ta = (rand - 0.5) * 2 * Trange;
        Tb = (rand - 0.5) * 2 * Trange;
        
        % 计算平面上的点：p = p0 + a*u + b*v
        Tpoints(:, i) = point_on_plane + Ta * Tu + Tb * Tv;
    end
Points6 = Tpoints;
end


if Isempty(4) == 0
    TPP9 = tempPP(:,2) + offnum*(tempPP(:,1)-tempPP(:,2));
    TPP10 = tempPP(:,2) + offnum*(tempPP(:,7)-tempPP(:,2));
    normaltao = tempPP(:,2) - (TPP9+TPP10)./2;

    % 已知数据：平面法向量和平面上一点
    normaltao = normaltao / norm(normaltao); % 归一化法向量
    point_on_plane = TPP9; % 平面上一点
    
    % 生成平面上的随机点参数
    Tnum_points = 20; % 要生成的点数
    Trange = 1; % 点的分布范围
    
    % 找到平面内的两个非平行向量作为基向量
    % 随意选择一个非平行于法向量的向量
    Tv1 = [1; 0; 0];
    if abs(dot(normaltao, Tv1)) > 1e-6 % 如果v1与法向量平行，则换一个向量
    Tv1 = [0; 1; 0];
    end
    
    % 使用Gram-Schmidt正交化法找到两个平面内的正交向量
    Tu = Tv1 - dot(Tv1, normaltao) * normaltao; % 投影法向量到平面内
    Tu = Tu / norm(Tu); % 单位化
    
    Tv = cross(normaltao, Tu); % 第二个正交向量
    
    % 生成平面上的点
    Tpoints = zeros(3, Tnum_points);
    for i = 1:Tnum_points
        % 在范围内随机生成系数
        Ta = (rand - 0.5) * 2 * Trange;
        Tb = (rand - 0.5) * 2 * Trange;
        
        % 计算平面上的点：p = p0 + a*u + b*v
        Tpoints(:, i) = point_on_plane + Ta * Tu + Tb * Tv;
    end
Points8 = Tpoints;
end




PointAll = {Points1,Points2,Points3,Points4,Points5,Points6,Points7,Points8};
coder.varsize('PlaneParaOut',[4 3000],[0 1]);
PlaneParaOut = zeros(4,8);
inlierIdxFinal = {1,2,3,4,5,6,7,8};
distancesFianal1 = {1,2,3,4,5,6,7,8};
for i =1:8
    Points = PointAll{i};
    % 平面拟合
    pointss = Points';

    Cnum = 1:length(pointss);
    bestDist = 99999;  % 最优内点距离

    C = nchoosek(Cnum,3);
    
    for j = 1:1
        % 随机选择三个点
        sampleIdx = C(j,:);
        % samplePoints = pointss(sampleIdx, :);
        samplePoints = pointss(:, :);
        % 计算平面模型
        % A = [samplePoints(:,1), samplePoints(:,2), ones(3,1)];
        A = [samplePoints(:,1), samplePoints(:,2), ones(length(pointss),1)];


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

    threshold  =2;
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




%%%%%%%%% 测试 %%%%%%%%%%%%

PlaneParaOut(1,3) = 0;
PlaneParaOut(2,3) = 0;
PlaneParaOut(4,3) = mean(Points3(3,:));


PlaneParaOut(1,7) = 0;
PlaneParaOut(2,7) = 0;
PlaneParaOut(4,7) = mean(Points7(3,:));


PlaneParaOut(1:2,1) = (PlaneParaOut(1:2,1)+PlaneParaOut(1:2,5))./2 ;
PlaneParaOut(1:2,5) = PlaneParaOut(1:2,1) ;
%%%%%%%%% 测试 %%%%%%%%%%%%






% %%%%%%%%% 约束 %%%%%%%%%%%%
% 
% % 左、右面竖直
% PlaneParaOut(3,1) = 0;
% PlaneParaOut(3,5) = 0;
% % 左右面平行
% PlaneParaOut(1:2,1) = (PlaneParaOut(1:2,1)+PlaneParaOut(1:2,5))./2 ;
% PlaneParaOut(1:2,5) = PlaneParaOut(1:2,1) ;
% 
% %%%%%%%% 约束只能前后倾斜  %%%%%%%%%
%     t1 = PlaneParaOut(1,5);
%     t2 = PlaneParaOut(2,5);
% 
%     % 输入:
%     % points: n×3 矩阵，每行 (xi, yi, zi)
%     % t1, t2: 约束参数
% 
%     X = Points3(1,:)';  % 提取 x 坐标
%     Y = Points3(2,:)';  % 提取 y 坐标
%     Z = Points3(3,:)';  % 提取 z 坐标
% 
%     % 构造设计矩阵 A 和观测向量 b
%     A = [X, Y, ones(size(X))]; % A矩阵对应于 ax + by + d = z
%     b = Z; % 目标值
% 
%     % 约束矩阵
%     C = [t1, t2, 0]; % a*t1 + b*t2 + 0*d = 0
% 
%     % 使用约束最小二乘求解
%     n = size(A, 2);
%     M = [A'*A, C'; C, 0];  % 扩展矩阵
%     rhs = [A'*b; 0];  % 右端项
%     solution = M \ rhs; % 求解
% 
%     % 提取参数 a, b, d
%     a = solution(1);
%     b = solution(2);
%     d = solution(3);
% 
%     % 输出参数
%     params = [a, b, d];
%     PlaneParaOut(:,3) = [a; b;-1 ;d];
% 
%  
%     % 输入:
%     % points: n×3 矩阵，每行 (xi, yi, zi)
%     % t1, t2: 约束参数
% 
%     X = Points7(1,:)';  % 提取 x 坐标
%     Y = Points7(2,:)';  % 提取 y 坐标
%     Z = Points7(3,:)';  % 提取 z 坐标
% 
%     % 构造设计矩阵 A 和观测向量 b
%     A = [X, Y, ones(size(X))]; % A矩阵对应于 ax + by + d = z
%     b = Z; % 目标值
% 
%     % 约束矩阵
%     C = [t1, t2, 0]; % a*t1 + b*t2 + 0*d = 0
% 
%     % 使用约束最小二乘求解
%     n = size(A, 2);
%     M = [A'*A, C'; C, 0];  % 扩展矩阵
%     rhs = [A'*b; 0];  % 右端项
%     solution = M \ rhs; % 求解
% 
%     % 提取参数 a, b, d
%     a = solution(1);
%     b = solution(2);
%     d = solution(3);
% 
%     % 输出参数
%     params = [a, b, d];
%     PlaneParaOut(:,7) = [a; b;-1 ;d];
% 
% 
% PlaneParaOut(1:2,3) = (PlaneParaOut(1:2,3)+PlaneParaOut(1:2,7))./2 ;
% PlaneParaOut(1:2,7) = PlaneParaOut(1:2,3) ;
% %%%%%%%%%%% 约束只能前后倾斜  %%%%%%%%%%%%







id1 = inlierIdxFinal{1};
id2 = inlierIdxFinal{2};
id3 = inlierIdxFinal{3};
id4 = inlierIdxFinal{4};
id5 = inlierIdxFinal{5};
id6 = inlierIdxFinal{6};
id7 = inlierIdxFinal{7};
id8 = inlierIdxFinal{8};

tt1 = distancesFianal1{1};
tt2 = distancesFianal1{2};
tt3 = distancesFianal1{3};
tt4 = distancesFianal1{4};
tt5 = distancesFianal1{5};
tt6 = distancesFianal1{6};
tt7 = distancesFianal1{7};
tt8 = distancesFianal1{8};

T1 = max(tt1(id1));
T2 = max(tt2(id2));
T3 = max(tt3(id3));
T4 = max(tt4(id4));
T5 = max(tt5(id5));
T6 = max(tt6(id6));
T7 = max(tt7(id7));
T8 = max(tt8(id8));

MaxDis = [T1,T2,T3,T4,T5,T6,T7,T8];
distancesFianal = [tt1,tt2,tt3,tt4,tt5,tt6,tt7,tt8];


PlaneParaOutP = PlaneParaOut';

% 初始化一个矩阵存储叉乘结果
cross_vectors = zeros(8, 3);

% 计算每对相邻侧面法向量的叉乘
for i = 1:8
    if i < 8
        cross_vectors(i, :) = cross(PlaneParaOutP(i, 1:3), PlaneParaOutP(i+1, 1:3));
    else
        cross_vectors(i, :) = cross(PlaneParaOutP(i, 1:3), PlaneParaOutP(1, 1:3)); % 最后一个与第一个相邻
    end
    cross_vectors(i, :) = cross_vectors(i, :) / norm(cross_vectors(i, :)); % 归一化
end

% 使所有方向一致
reference_vector = cross_vectors(1, :);  % 选择第一个向量作为参考
for i = 2:8
    if dot(reference_vector, cross_vectors(i, :)) < 0  % 如果方向相反
        cross_vectors(i, :) = -cross_vectors(i, :);    % 翻转方向
    end
end


% 计算平均方向向量，并归一化
n = mean(cross_vectors, 1);


% 计算顶面方程的 d 值
d_top = -dot(n, P_bound1);

% 计算底面方程的 d 值
d_bottom = -dot(n, P_bound2);

% 初始化顶点矩阵
PP = zeros(16, 3);

% 计算顶面和底面的8个顶点
for i = 1:8
    % 顶面顶点
    if i < 8
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
    PP(i + 8, :) = A\B_bottom;
end

PP = PP';

TrianglePoints = PP(:,[1,8,9,8,9,16,1,2,10,1,9,10,2,3,10,3,10,11,3,4,11,4,11,12,4,5,12,5,12,13,5,6,13,6,13,14,6,7,14,7,14,15,7,8,15,8,15,16]);
coder.varsize('TrianglePoints',[3 3000],[0 1]);




%% 倒角计算
LenDaoJiao = zeros(1,8);
PPP4OUT = TrianglePoints4(:,[1,2,3,6,9,12,15,18]);
L1 = norm(PPP4OUT(:,1) - PP(:,1));
L2 = norm(PPP4OUT(:,1) - PP(:,2));
L3 = norm(PPP4OUT(:,5) - PP(:,3));
L4 = norm(PPP4OUT(:,5) - PP(:,4));
L5 = norm(PPP4OUT(:,7) - PP(:,5));
L6 = norm(PPP4OUT(:,7) - PP(:,6));
L7 = norm(PPP4OUT(:,2) - PP(:,7));
L8 = norm(PPP4OUT(:,2) - PP(:,8));



RETL1 = norm(PPP4OUT(:,1) - PPP4OUT(:,2));
RETL2 = norm(PPP4OUT(:,1) - PPP4OUT(:,5));
RETL3 = norm(PPP4OUT(:,5) - PPP4OUT(:,7));
RETL4 = norm(PPP4OUT(:,7) - PPP4OUT(:,2));



if L1 < 0.05*RETL1
    L1 = 0;
end

if L2 < 0.05*RETL2
    L2 = 0;
end

if L3 < 0.05*RETL2
    L3 = 0;
end

if L4 < 0.05*RETL3
    L4 = 0;
end

if L5 < 0.05*RETL3
    L5 = 0;
end


if L6 < 0.05*RETL4
    L6 = 0;
end

if L7 < 0.05*RETL4
    L7 = 0;
end

if L8 < 0.05*RETL1
    L8 = 0;
end
LenDaoJiao = [L1,L2,L3,L4,L5,L6,L7,L8];





end