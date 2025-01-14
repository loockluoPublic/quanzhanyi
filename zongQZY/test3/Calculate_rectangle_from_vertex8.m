function [PointTable_A_off8,PointTable_B_off8,XieMianPianYi,BianHao] = Calculate_rectangle_from_vertex8(side_faces_transformed1,side_faces_transformed2,side_faces_transformed3,side_faces_transformed4,side_faces_transformed5,side_faces_transformed6,side_faces_transformed7,side_faces_transformed8,P_bound1,P_bound2,PAB,phi,shenglunum,Ti,a,distanceThreshold)
%% 1、生成基底
%调用矩形拟合
[~,TrianglePoints4,~,~] = planefit4(side_faces_transformed1,side_faces_transformed3,side_faces_transformed5,side_faces_transformed7,P_bound1,P_bound2,distanceThreshold);
%调用矩形参数计算
[Pin,Pout,~,b,h,~,~,~] = Calculate_rectangle_from_vertex(TrianglePoints4);


x1 = Pin(1);
y1 = Pin(2);
z1 = Pin(3);
x2 = Pout(1);
y2 = Pout(2);
z2 = Pout(3);


%   u, v: 底面的两个正交基向量，其中 u 在竖直平面内

% 计算轴向向量并归一化
d = [x2 - x1, y2 - y1, z2 - z1];
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


%% 2、判断是否在斜面上

%计算八面参数
[PlaneParaOut8,TrianglePoints8,~,~] = planefit8(side_faces_transformed1,side_faces_transformed2,side_faces_transformed3,side_faces_transformed4,side_faces_transformed5,side_faces_transformed6,side_faces_transformed7,side_faces_transformed8,P_bound1,P_bound2,distanceThreshold);

%计算角度
PlanePara1 = PlaneParaOut8(1:3,1);
PlanePara2 = PlaneParaOut8(1:3,2);
PlanePara4 = PlaneParaOut8(1:3,4);
PlanePara5 = PlaneParaOut8(1:3,5);
PlanePara6 = PlaneParaOut8(1:3,6);
PlanePara8 = PlaneParaOut8(1:3,8);

theta1 = acos(dot(PlanePara1,PlanePara2)./norm(PlanePara1)./norm(PlanePara2));
theta2 = acos(dot(PlanePara4,PlanePara5)./norm(PlanePara4)./norm(PlanePara5));
theta3 = acos(dot(PlanePara5,PlanePara6)./norm(PlanePara5)./norm(PlanePara6));
theta4 = acos(dot(PlanePara1,PlanePara8)./norm(PlanePara1)./norm(PlanePara8));


%计算阈值
% 承接16顶点
PP16 = TrianglePoints8(:,[7,8,14,20,26,32,38,44,3,9,18,24,30,36,42,48]);

a1 = PP16(:,2);
b1 = PP16(:,7);
c1 = PP16(:,1);
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(c1,a1,b1);
d1 = [xN1,yN1,zN1]';
ab1 = norm(a1-b1)./2;
TiYuZhi1 = (ab1-norm(a1-d1))./ab1;


a2 = PP16(:,3);
b2 = PP16(:,6);
c2 = PP16(:,4);
[xN2,yN2,zN2] = foot_of_perpendicular_from_a_point_to_a_line(c2,a2,b2);
d2 = [xN2,yN2,zN2]';
ab2 = norm(a2-b2)./2;
TiYuZhi2 = (ab2-norm(a2-d2))./ab2;

a3 = PP16(:,3);
b3 = PP16(:,6);
c3 = PP16(:,5);
[xN3,yN3,zN3] = foot_of_perpendicular_from_a_point_to_a_line(c3,a3,b3);
d3 = [xN3,yN3,zN3]';
ab3 = norm(a3-b3)./2;
TiYuZhi3 = (ab3-norm(a3-d3))./ab3;

a4 = PP16(:,2);
b4 = PP16(:,7);
c4 = PP16(:,8);
[xN4,yN4,zN4] = foot_of_perpendicular_from_a_point_to_a_line(c4,a4,b4);
d4 = [xN4,yN4,zN4]';
ab4 = norm(a4-b4)./2;
TiYuZhi4 = (ab4-norm(a4-d4))./ab4;


%判断点是否在斜面上（利用阈值
temp = shenglunum./2;
XMFlagA = zeros(1,2*shenglunum);

for i = 1:2*shenglunum
    TiiA  = abs(Ti(i));
    if i <= temp
        if abs(TiiA) < abs(TiYuZhi4)
            XMFlagA(i) = 0;
        else
            XMFlagA(i) = 1;
        end
    elseif i <= 2*temp
        if abs(TiiA) < abs(TiYuZhi1)
            XMFlagA(i) = 0;
        else
            XMFlagA(i) = 1;
        end
    elseif i <= 3*temp
        if abs(TiiA) < abs(TiYuZhi2)
            XMFlagA(i) = 0;
        else
            XMFlagA(i) = 1;
        end
    else
        if abs(TiiA) < abs(TiYuZhi3)
            XMFlagA(i) = 0;
        else
            XMFlagA(i) = 1;
        end
    end
end

%% 3、修正Ti
Ti2A = zeros(1,2*shenglunum);
XieMianPianYi = zeros(1,2*shenglunum);
%%%%%%%%%%%%%%%%%%%%%%  对斜面上的点进行偏移（修正Ti）  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for j = 1:2*shenglunum
    if j <= temp
        if XMFlagA(j) == 1 %斜面上
            Ti2A(j) = Ti(j) + a(j) *sin(theta4);
            XieMianPianYi(j) = a(j) *tan(theta4);
        else
            Ti2A(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    elseif j <= 2*temp
        if XMFlagA(j) == 1 %斜面上
            Ti2A(j) = Ti(j) - a(j) *sin(theta1);
            XieMianPianYi(j) = a(j) *tan(theta1);
        else
            Ti2A(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    elseif j <= 3*temp
        if XMFlagA(j) == 1 %斜面上
            Ti2A(j) = Ti(j) - a(j) *sin(theta2);
            XieMianPianYi(j) = a(j) *tan(theta2);
        else
            Ti2A(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    else
        if XMFlagA(j) == 1 %斜面上
            Ti2A(j) = Ti(j) + a(j) *sin(theta3);
            XieMianPianYi(j) = a(j) *tan(theta3);
        else
            Ti2A(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    end
end


%% 4、径向移动


deltTih = zeros(1,2*shenglunum);
deltTib = zeros(1,2*shenglunum);
for k = 1:2*shenglunum
    if k <= temp
        if XMFlagA(k) == 1 %斜面上
            deltTih(k) = abs(Ti2A(k)-TiYuZhi4).*h./2;
            deltTib(k) = deltTih(k)./tan(pi./2-theta4);
        else
            deltTih(k) = 0;
        end
    elseif k <= 2*temp
        if XMFlagA(k) == 1 %斜面上
            deltTih(k) = abs(Ti2A(k)-TiYuZhi1).*h./2;
            deltTib(k) = deltTih(k)./tan(pi./2-theta1);
        else
            deltTih(k) = 0;
        end
    elseif k <= 3*temp
        if XMFlagA(k) == 1 %斜面上
            deltTih(k) = abs(Ti2A(k)-TiYuZhi2).*h./2;
            deltTib(k) = deltTih(k)./tan(pi./2-theta2);
        else
            deltTih(k) = 0;
        end
    else
        if XMFlagA(k) == 1 %斜面上
            deltTih(k) = abs(Ti2A(k)-TiYuZhi3).*h./2;
            deltTib(k) = deltTih(k)./tan(pi./2-theta3);
        else
            deltTih(k) = 0;
        end
    end
end

deltTib = abs(deltTib);
%% 5、面上一周的点计算

ZhouDian = zeros(3,2*shenglunum);
for j = 1:shenglunum
    ZhouDian(:,j) = Pout + u'.*Ti2A(j).*h./2 + v'.*(b./2-deltTib(j));
end

for k = 1+shenglunum:2*shenglunum
    ZhouDian(:,k) = Pout + u'.*Ti2A(k).*h./2 - v'.*(b./2-deltTib(k));
end


%% 6、计算轴线移动l

%整体移动
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(PAB,Pin,Pout);
ztyd = sqrt((zN1-Pout(3)).^2+(yN1-Pout(2)).^2+(xN1-Pout(1)).^2);


% 距离*cos(phi) 无正负 全为正
PhiPy = zeros(1,2*shenglunum);
for i = 1:2*shenglunum
    tdb = deltTib(i);
    if tdb == 0
        PhiPy(i) = b./2./tan(phi);
    else
        PhiPy(i) = (b./2-tdb)./tan(phi);
    end
end

%% 7、偏移

% A测点
PYA = zeros(1,2*shenglunum);
for i = 1:shenglunum
    PYA(1:shenglunum) = ztyd + PhiPy(1:shenglunum)  - a(1:shenglunum)./tan(phi);
end

for i = 1+shenglunum:2*shenglunum
    PYA(1+shenglunum:2*shenglunum) = ztyd - PhiPy(1+shenglunum:2*shenglunum)  + a(1+shenglunum:2*shenglunum)./tan(phi);
end

PointTable_B_off8 = ZhouDian - d'.*PYA;

% B测点
PYB = zeros(1,2*shenglunum);
for i = 1:shenglunum
    PYB(1:shenglunum) = ztyd - PhiPy(1:shenglunum)  + a(1:shenglunum)./tan(phi);
end

for i = 1+shenglunum:2*shenglunum
    PYB(1+shenglunum:2*shenglunum) = ztyd + PhiPy(1+shenglunum:2*shenglunum)  - a(1+shenglunum:2*shenglunum)./tan(phi);
end
PointTable_A_off8 = ZhouDian - d'.*PYB;

%% 8、编号
BianHao = zeros(2,2*shenglunum);
for i = 1:shenglunum
    BianHao(1,i) = 2*i-1;
    BianHao(2,i) = 2*i;
end

for i = 1+shenglunum:2*shenglunum
    BianHao(1,i) = (2*shenglunum+1-i)*2;
    BianHao(2,i) = (2*shenglunum+1-i)*2-1;
end




    
end
