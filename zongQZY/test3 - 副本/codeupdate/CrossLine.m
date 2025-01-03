function [P0,d] = CrossLine(PlanePara1,PlanePara2,x_val)



% 定义平面1的系数
a1 = PlanePara1(1);
b1 = PlanePara1(2);
c1 = PlanePara1(3);
d1 = PlanePara1(4);

% 定义平面2的系数
a2 = PlanePara2(1);
b2 = PlanePara2(2);
c2 = PlanePara2(3);
d2 = PlanePara2(4);


% 计算法向量的叉乘得到交线的方向向量
d = cross([a1, b1, c1], [a2, b2, c2]);

% 确定一个交点
 
% Create the system of equations
A = [b1, c1; b2, c2];
b = [-d1 - a1*x_val; -d2 - a2*x_val];

% Solve for y and z
yz = A\b;

% The point on the intersection line
P0 = [x_val, yz(1), yz(2)];




end
