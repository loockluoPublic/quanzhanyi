function [Mcenter,MTaon,Mradial,Err_every,Bottom_round_center1,Bottom_round_center2] = Calculate_accurate_cylinders_from_multiple_measurement_points(points,P_bound1,P_bound2)
    points = points'; 
    num_points = size(points, 1);
    min_residual = Inf;
    best_axis_point = zeros(1,3);
    best_axis_direction = zeros(1,3);
    best_radius = 0;
    
    % 尝试所有可能的圆柱面参数组合
    for i = 1:num_points
        for j = i+1:num_points
            for k = j+1:num_points
                % 通过三个点确定圆柱面的轴线和半径
                [axis_point, axis_direction, radius] = fit_cylinder_from_three_points(points(i,:), points(j,:), points(k,:));
                
                % 计算拟合误差
                residual = calculate_residual(points, axis_point, axis_direction, radius);
                
                % 更新最佳拟合参数
                if residual < min_residual
                    min_residual = residual;
                    best_axis_point = axis_point;
                    best_axis_direction = axis_direction;
                    best_radius = radius;
                end
            end
        end
    end


Mcenter = best_axis_point; %圆心
MTaon = best_axis_direction;   %法向量
MTaon = MTaon./norm(MTaon);
Mradial = best_radius;   %半径


Mu1 = Mcenter;
len = 2;
Mu2 = Mu1 - len.*MTaon;
Mdis =zeros(1,size(points(:,1),1));
for h = 1:size(points(:,1),1)
    MOA = [points(h,1)-Mu1(1), points(h,2)-Mu1(2), points(h,3)-Mu1(3)];
    MAB = [Mu2(1)-Mu1(1), Mu2(2)-Mu1(2), Mu2(3)-Mu1(3)];
    MOAxAB = cross(MOA,MAB);
    Mdis(h) = norm(MOAxAB)./norm(MAB);
end
% 比较与半径的差值（圆度）
Err_every = Mdis - Mradial; % 单个点误差


Mradial = mean(Err_every) + Mradial;
Err_every = Err_every - mean(Err_every);


[xxN1,yyN1,zzN1] = foot_of_perpendicular_from_a_point_to_a_line(P_bound1,Mu1,Mu2);
[xxN2,yyN2,zzN2] = foot_of_perpendicular_from_a_point_to_a_line(P_bound2,Mu1,Mu2);

Bottom_round_center1 = [xxN1,yyN1,zzN1];
Bottom_round_center2 = [xxN2,yyN2,zzN2];

end

function [axis_point, axis_direction, radius] = fit_cylinder_from_three_points(p1, p2, p3)
    
    v1 = p2 - p1;
    v2 = p3 - p1;
    
    axis_direction = cross(v1, v2);
    axis_direction = axis_direction / norm(axis_direction);
    
    v3 = cross(axis_direction, v1);
    v4 = cross(axis_direction, v2);
    
    m1 = (p1 + p2) / 2;
    m2 = (p1 + p3) / 2;
    
    t = (dot(v4, m1 - m2) / dot(v4, v1)) / (dot(v3, v2) / dot(v3, v1) - dot(v4, v2) / dot(v4, v1));
    
    axis_point = m1 + t * v3;
    radius = norm(axis_point - p1);
end

function residual = calculate_residual(points, axis_point, axis_direction, radius)
    % 计算拟合误差
    num_points = size(points, 1);
    distances = zeros(num_points, 1);
    
    for i = 1:num_points
        % 计算每个点到圆柱面的距离
        p = points(i,:);
        distances(i) = norm(p - axis_point - dot(p - axis_point, axis_direction) * axis_direction) - radius;
    end
    
    % 拟合误差为距离的平方和
    residual = sum(distances.^2);
end