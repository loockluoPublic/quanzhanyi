function Point_out = generate_unit_circle_with_normal_vector(azimuth,elevation,num)
    r = 1;
    x0 = r.*cos(azimuth).*cos(elevation);
    y0 = r.*cos(azimuth).*sin(elevation);
    z0 = r.*sin(azimuth);
    
    % 定义法向量
    normal_vector = [x0, y0, z0];
    % 检查法向量是否是单位向量，如果不是则归一化
    if norm(normal_vector) ~= 1
        normal_vector = normal_vector / norm(normal_vector);
    end
    
    % 使用参数方程生成单位圆上的点
    theta = linspace(0, 2*pi,num+1);
    v = cross(normal_vector, [0, 0, 1]); % 找到与法向量垂直的一个向量
    if norm(v) < eps % 如果法向量与 [0, 0, 1] 平行，则选择另一个向量
        v = cross(normal_vector, [0, 1, 0]);
    end
    
    v = v / norm(v); % 归一化向量
    u = cross(v, normal_vector); % 创建另一个垂直向量
    
    % 单位圆的参数方程
    x_circle = cos(theta) * v(1) + sin(theta) * u(1);
    y_circle = cos(theta) * v(2) + sin(theta) * u(2);
    z_circle = cos(theta) * v(3) + sin(theta) * u(3);
    
    x_circle1 = x_circle(1:end-1);
    y_circle1 = y_circle(1:end-1);
    z_circle1 = z_circle(1:end-1);

    Point_out = [x_circle1;y_circle1;z_circle1];
    
end



