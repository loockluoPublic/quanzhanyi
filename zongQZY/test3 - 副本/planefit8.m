function [PlaneParaOut,TrianglePoints,MaxDis,distancesFianal] = planefit8(Points1,Points2,Points3,Points4,Points5,Points6,Points7,Points8,P_bound1,P_bound2,distanceThreshold)
% Points 输入点 3*n
% BoundPoint1 边界点1
% BoundPoint2 边界点2
% PlaneParaOut 平面参数4*n
% PP 三角形点3*n（n 123，456，789这样取）

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
end