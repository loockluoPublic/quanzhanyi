function Point_out = generate_unit_circle_with_normal_vector2(PointIn,num,laynum,PUp,PDown)

P1 = PointIn(:,1);
P2 = PointIn(:,2);
P3 = PointIn(:,3);

% 1. 计算法向量
v1 = P2 - P1;
v2 = P3 - P1;
normal = cross(v1, v2);  % 叉乘
normal = normal / norm(normal);  % 单位化

% 2. 计算中点
M1 = (P1 + P2) / 2;
M2 = (P1 + P3) / 2;

% 3. 计算垂直向量
n1 = cross(v1, normal);
n2 = cross(v2, normal);

% 4. 求解圆心
A = [n1, -n2];
b = M2-M1;
ttt =  A \ b;
center = M1 + ttt(1)*n1;


% 5. 计算半径
r = norm(P1 - center);





x0 = normal(1);
y0 = normal(2);
z0 = normal(3);




Pl1 = center';
Pl2 = Pl1 + [x0,y0,z0];


[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(PUp,Pl1,Pl2);
[xN2,yN2,zN2] = foot_of_perpendicular_from_a_point_to_a_line(PDown,Pl1,Pl2);


deltx = zeros(1,laynum);
delty = zeros(1,laynum);
deltz = zeros(1,laynum);

for i = 1:laynum
    lamuda = i/(laynum+1-i);
    deltx(i) =  (xN1+lamuda*xN2)/(1+lamuda);
    delty(i) =  (yN1+lamuda*yN2)/(1+lamuda);
    deltz(i) =  (zN1+lamuda*zN2)/(1+lamuda);
end



% 计算轴向向量并归一化
d = [xN2 - xN1, yN2 - yN1, zN2 - zN1];
d = d / norm(d);

% 选择竖直平面内的向量 e
if abs(d(1)) > abs(d(2))  % 如果轴向向量大致沿 X 轴
    e = [0, 1, 0];  % 选择 y 方向的单位向量
else  % 否则，如果轴向向量大致沿 Y 轴
    e = [1, 0, 0];  % 选择 x 方向的单位向量
end

% 计算第一个基向量 u，使其位于竖直面内
u = cross(d, e);  % 计算与 d 和 e 正交的向量
u = u / norm(u);  % 归一化


% 确保 u 的方向朝上
if u(3) <= 0
    u = -u;  % 如果 u 的方向与轴方向相反，反转 u
end

% 计算第二个基向量 v，使其与 d 和 u 正交
v = cross(d, u);  % 计算第二个正交向量
v = -v / norm(v);  % 归一化


u = u*r;
v = v*r;

theta = linspace(-1*pi/6,7/6*pi,num);


% 单位圆的参数方程
x_circle = cos(theta) * v(1) + sin(theta) * u(1);
y_circle = cos(theta) * v(2) + sin(theta) * u(2);
z_circle = cos(theta) * v(3) + sin(theta) * u(3);

Point_out = zeros(3,num*laynum);
for j = 1:laynum
    x_circle1 = x_circle + deltx(j);
    y_circle1 = y_circle + delty(j);
    z_circle1 = z_circle + deltz(j);
    Point_out(:,(j-1)*num+1:j*num) = [x_circle1;y_circle1;z_circle1];
end

end



