function [PointTable_A_off,PointTable_B_off] = Calculat_JuXing_A_and_B_Points_after_Offest(Tao,UPP,Pin,b,h,PAB,phi,shenglunum,Ti,toff)
%% 平移以及计算旋转矩阵
Pin = Pin';
UPP = UPP';
PAB = PAB';
% 平移 Pin
UPPmove = UPP-Pin;
PABmove = PAB-Pin;

% 构建旋转矩阵1,pt6转到z轴
theta1 = atan2(norm(cross([0, 0, 1], UPPmove)), dot([0, 0, 1], UPPmove));
v1 = cross([0, 0, 1],UPPmove) / norm(cross([0, 0, 1], UPPmove));
rot1 = myvrrotvec2mat([v1, theta1]);

% Tao旋转rot1
TaoRot1 = Tao'*rot1;

% 构建旋转矩阵2,taorot1转到x轴
theta2 = atan2(norm(cross([1, 0, 0], TaoRot1)), dot([1, 0, 0], TaoRot1));
v2 = cross([1, 0, 0],TaoRot1) / norm(cross([1, 0, 0], TaoRot1));
rot2 = myvrrotvec2mat([v2, theta2]);

% 总的旋转矩阵 ROT
ROT = rot1*rot2;

PABrot = PABmove*ROT;

%% 计算A点

% 在PABrot的基础上增量xyz
% x为b*tan(phi)
% y为b
% z为Ti*h
xbase = PABrot(1);
Px = ones(1,shenglunum);
Ax = [b./2*tan(phi).*Px,-b./2*tan(phi).*Px]+xbase;
Ay = [b./2.*Px,-b./2.*Px];
Az = Ti.*h./2;

%% 计算并偏移
Axoff = Ax + toff;
PointsArot = [Axoff;Ay;Az];
PointsBrot = [Axoff;-Ay;Az];
%% 旋转平移回去
PointsA = PointsArot'*pinv(ROT)+ repmat(Pin,2*shenglunum,1);
PointsB = PointsBrot'*pinv(ROT)+ repmat(Pin,2*shenglunum,1);
PointTable_A_off = PointsA';
PointTable_B_off = PointsB';

end