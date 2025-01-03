function Cross_point = YuanZhuJiaoDian(Mcenter,MTaon,Mradial,Pin1,Pin2)

    % 定义圆柱参数
    % p0 = [x0, y0, z0];  % 圆柱轴线上的一点
    % v = [vx, vy, vz];   % 圆柱的轴线方向向量，必须为单位向量
    % r = radius;         % 圆柱的半径
    % 
    % % 定义直线上两点
    % P1 = [x1, y1, z1];
    % P2 = [x2, y2, z2];
    
    % 计算向量差
    dP = Pin2 - Pin1;
    
    % 计算系数 A, B, C
    A = dot(dP, dP) - (dot(dP, MTaon))^2;
    B = 2 * (dot(dP, Pin1 - Mcenter) - dot(dP, MTaon) * dot(Pin1 - Mcenter, MTaon));
    C = dot(Pin1 - Mcenter, Pin1 - Mcenter) - (dot(Pin1 - Mcenter, MTaon))^2 - Mradial^2;
    
    % 解二次方程 At^2 + Bt + C = 0
    t_vals = roots([A, B, C]);
    
    % 判断是否有实数解
    rt_vals = t_vals(imag(t_vals) == 0);
    Cross_point = zeros(length(rt_vals),3);
    if isempty(rt_vals)
        
    else
        % 计算交点
        
        for i = 1:length(rt_vals)
            intersection_point = Pin1 + rt_vals(i) * dP;
            Cross_point(i,:) = real(intersection_point);
%             disp(['Intersection Point ', num2str(i), ':']);
%             disp(intersection_point);
        end
    end




end