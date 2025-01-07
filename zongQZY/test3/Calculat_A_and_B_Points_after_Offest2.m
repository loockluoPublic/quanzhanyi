function [PointTable_A_off,PointTable_B_off,BianHao] = Calculat_A_and_B_Points_after_Offest2(Bottom_round_center1,Bottom_round_center2,MTaon,Mcenter,Mradial,PAB,phi,Ang,toff,roff)

%% 0、编号

Bottom_round_center1 = Bottom_round_center1';
Bottom_round_center2 = Bottom_round_center2';

numShengLu = floor(length(Ang)./2);


BianHao = zeros(2,numShengLu*2);
for i = 1:numShengLu
    BianHao(1,i) = 2*i-1;
    BianHao(1,numShengLu+i) = numShengLu*2-2*(i-1);
    BianHao(2,i) = 2*i-1;
    BianHao(2,numShengLu+i) = numShengLu*2-2*(i-1);
end

%% 1、基底建立
x1 = Bottom_round_center1(1);
y1 = Bottom_round_center1(2);
z1 = Bottom_round_center1(3);
x2 = Bottom_round_center2(1);
y2 = Bottom_round_center2(2);
z2 = Bottom_round_center2(3);


% 计算圆柱底面的基底向量，其中第一个基底向量在竖直面内且朝上
% 输入：
%   x1, y1, z1: 圆柱底面圆心
%   x2, y2, z2: 圆柱顶面圆心
% 输出：
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

%% 2、计算角度

% 角度处理
Angt = Ang(1:numShengLu);
AngR1 = [Angt,pi-Angt(end:-1:1)];

% 角度偏移

rAng = roff(1:numShengLu)./Mradial;
roffAng = [rAng,-rAng(end:-1:1)];

AngR = AngR1 + roffAng;

%% 3、生成圆周点
YuanZhouDian = zeros(3,numShengLu*2);
for i = 1:2*numShengLu
    YuanZhouDian(:,i) = (Bottom_round_center2+u.*Mradial*sin(AngR(i))+v.*Mradial.*cos(AngR(i)))';
end

%% 4、计算轴向移动


% 总体移动
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(PAB,Bottom_round_center1,Bottom_round_center2);
ztyd = sqrt((zN1-Bottom_round_center2(3)).^2+(yN1-Bottom_round_center2(2)).^2+(xN1-Bottom_round_center2(1)).^2);

% phi角移动
PhiDian = zeros(3,numShengLu*2);
disPhiDian = zeros(1,numShengLu*2);
for i = 1:2*numShengLu
    PhiDian(:,i) = v.*Mradial.*cos(AngR(i));
    if i <= numShengLu
        disPhiDian(i) = -sqrt((PhiDian(1,i)).^2+(PhiDian(2,i)).^2+(PhiDian(3,i)).^2)./tan(phi);
    else
        disPhiDian(i) = sqrt((PhiDian(1,i)).^2+(PhiDian(2,i)).^2+(PhiDian(3,i)).^2)./tan(phi);
    end
end


% 偏移移动 ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
PYYD = [toff(1:numShengLu),-toff(numShengLu:-1:1)];

PointTable_A_off = zeros(3,2*numShengLu);
PYallA = ztyd+disPhiDian+PYYD;
for i = 1:2*numShengLu
    PointTable_A_off(:,i) = YuanZhouDian(:,i) - d'.*PYallA(i);
end

PointTable_B_off = zeros(3,2*numShengLu);
PYallB = ztyd-disPhiDian-PYYD;
for i = 1:2*numShengLu
    PointTable_B_off(:,i) = YuanZhouDian(:,i) - d'.*PYallB(i);
end
PointTable_B_off = PointTable_B_off(:,end:-1:1);




end
