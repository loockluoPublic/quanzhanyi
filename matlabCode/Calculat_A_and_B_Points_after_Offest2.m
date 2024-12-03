function [PointTable_A_off,PointTable_B_off,BianHao] = Calculat_A_and_B_Points_after_Offest2(Bottom_round_center1,Bottom_round_center2,MTaon,Mcenter,Mradial,PAB,phi,Ang,toff,roff)

numShengLu = length(Ang)./2;
MTaon = MTaon';
Mcenter = Mcenter';

phi = pi/2-phi;

% 计算phi面的法向量D
A = [0,0,1];
B = MTaon;
C = cross(A,B);
C = C./norm(C);

D = B+tan(phi)*C;
D = D./norm(D);

% 计算0度线向量E
E = cross(cross(B,C),D);
E = E./norm(E);
fprintf('E xyz: %f, %f, %f\n',E(1),E(2),E(3));


% 圆心点
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(PAB,Mcenter,Mcenter+MTaon);

% 面法向量第二个点（与圆心点构成phi面的法向量）
Tao2D = [xN1,yN1,zN1] + D;

% 起始点 （测点半圆的中点）
QiShi = [xN1,yN1,zN1] + E;

% 构建旋转矩阵
theta = atan2(norm(cross([0, 0, 1], MTaon)), dot([0, 0, 1], MTaon));
v = cross([0, 0, 1],MTaon) / norm(cross([0, 0, 1], MTaon));
rot1 = myvrrotvec2mat([v, theta]);


Prot = zeros(3,3);
% 选择旋转点集合
Prot(1:3,1) = [xN1;yN1;zN1]; % 圆心点
Prot(1:3,2) = Tao2D';  % 面法向量第二个点
Prot(1:3,3) = QiShi'; % 起始点 （测点半圆的中点，0度线）

% 旋转至【0，0，1】的点集合
P2D = Prot'*rot1;

P2DT = P2D - repmat([P2D(1,1),P2D(1,2),0],size(P2D,1),1);

% 旋转、平移后 法向量
Tao3 = P2DT(2,:) - P2DT(1,:);

% 法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3
aa = Tao3(1);
bb = Tao3(2);
cc = Tao3(3);
dd = -(aa*P2DT(1,1)+bb*P2DT(1,2)+cc*P2DT(1,3));


% 起始角度
AngOring = atan(P2DT(3,2)/P2DT(3,1));
% !!!!!!!后面的点以这个为基础

fprintf('AngOring: %f\n',AngOring);

% 第一步修正
Ang = Ang+roff./Mradial;
if E(3) < 0
Ang = Ang+pi;
end

% 第二步处理
AngProcess = zeros(1,length(Ang));
AngProcess(1:numShengLu) = AngOring - Ang(1:numShengLu);
AngProcess(1+numShengLu:2*numShengLu) = pi+AngOring+Ang(1+numShengLu:2*numShengLu);

% 调用计算坐标
x = Mradial*cos(AngProcess);
y = Mradial*sin(AngProcess);
z = -(dd+aa*x+bb*y)./cc;

PointTable2DT_A = ones(length(Ang),3);
PointTable2DT_A = [x',y',z'];

for iii = 1:size(PointTable2DT_A,1)
    if PointTable2DT_A(iii,3)>P2DT(1,3)
        PointTable2DT_A(iii,3) = PointTable2DT_A(iii,3)-toff(iii);
    else
        PointTable2DT_A(iii,3) = PointTable2DT_A(iii,3)+toff(iii);
    end
end

% 2D A面点
PointTable2DT_A = [PointTable2DT_A(:,2),-PointTable2DT_A(:,1),PointTable2DT_A(:,3)];

%2D B面点
Zcen2D = P2DT(1,3);
tempBZ = 2*Zcen2D - PointTable2DT_A(:,3);
PointTable2DT_B = [PointTable2DT_A(:,1),PointTable2DT_A(:,2),tempBZ];

%2D A面测点 转3D
PointTable_A1  = (PointTable2DT_A + repmat([P2D(1,1),P2D(1,2),0],size(PointTable2DT_A,1),1))*pinv(rot1);
PointTable_B1  = (PointTable2DT_B + repmat([P2D(1,1),P2D(1,2),0],size(PointTable2DT_B,1),1))*pinv(rot1);

PointTable_A_off = zeros(3,length(Ang));
PointTable_A_off = PointTable_A1';

PointTable_B_off = zeros(3,length(Ang));
PointTable_B_off = PointTable_B1';


Psy1 = Bottom_round_center1;
Pxy2 = Bottom_round_center2;
Pup3 = Bottom_round_center1 + [1, 0, 0];
Pup4 = Bottom_round_center2 + [1, 0, 0];
DirZX = Psy1 - Pxy2; % 向上游
Dirup = [1,0,0];
distance = ones(1,numShengLu);
rightflag = -1*ones(1,2*numShengLu);



for jj = 1:numShengLu*2
% 计算方向
    PA1 = PointTable_A_off(:,jj)';  % 右侧
    [aaa,bbb,ccc] = foot_of_perpendicular_from_a_point_to_a_line(PA1,Psy1,Pxy2);
    FPA1 = [aaa,bbb,ccc];
    DirA1 = FPA1 - PA1;  % 指向垂足
    % 计算夹角
    DirPD1 = cross(DirA1,Dirup);
    thetaA1 = rad2deg(acos(dot(DirZX, DirPD1) / (norm(DirZX) * norm(DirPD1))));     % 夹角（弧度）

    % 判断左右
    if thetaA1 > 90
        rightflag(jj) = 0;
    else
        rightflag(jj) = 1;
    end


    % 计算平面方程

    Dirtemp1 = cross(DirZX,Dirup); %A1-4一侧，右侧向量
    Dirn = cross(Dirtemp1,DirZX);
    Dirn = Dirn./norm(Dirn);  % 平面法向量
    
    A = Dirn(1);
    B = Dirn(2);
    C = Dirn(3);
    D = -(A * Psy1(1) + B * Psy1(2) + C * Psy1(3));
    
    % 计算点到平面的距离
    numerator = A * PA1(1) + B * PA1(2) + C * PA1(3) + D; % 平面方程左侧的值
    denominator = sqrt(A^2 + B^2 + C^2); % 法向量的模长
    distance(jj) = numerator / denominator; % 距离公式

end

RightPoint = []; % 编号、点（x，y，z）、距离
LeftPoint = [];


for kk = 1:numShengLu*2
    if rightflag(kk) == 1
        RightPoint = [RightPoint;[kk,PointTable_A_off(:,kk)',distance(kk)]];

    else
        LeftPoint = [LeftPoint;[kk,PointTable_A_off(:,kk)',distance(kk)]];

    end



end

RightPoint = sortrows(RightPoint,5);
LeftPoint = sortrows(LeftPoint,5);

BianHaoTemp = zeros(2*numShengLu,1);
BianHao1 = zeros(1,2*numShengLu);
for  hhh = 1:numShengLu

BianHaoTemp(hhh*2-1:hhh*2,1) = [RightPoint(hhh,1),LeftPoint(hhh,1)];
TTemp = [BianHaoTemp,(1:2*numShengLu)'];
TTTemp = sortrows(TTemp,1);

BianHao1 = TTTemp(:,2)';

end



rightflag = -1*ones(1,2*numShengLu);
for jj = 1:numShengLu*2
% 计算方向
    PA1 = PointTable_B_off(:,jj)';  
    [aaa,bbb,ccc] = foot_of_perpendicular_from_a_point_to_a_line(PA1,Psy1,Pxy2);
    FPA1 = [aaa,bbb,ccc];
    DirA1 = FPA1 - PA1;  % 指向垂足
    % 计算夹角
    DirPD1 = cross(DirA1,Dirup);
    thetaA1 = rad2deg(acos(dot(DirZX, DirPD1) / (norm(DirZX) * norm(DirPD1))));     % 夹角（弧度）
    
    % 判断左右
    if thetaA1 > 90
        rightflag(jj) = 0;
    else
        rightflag(jj) = 1;
    end


    % 计算平面方程

    Dirtemp1 = cross(DirZX,Dirup); %A1-4一侧，右侧向量
    Dirn = cross(Dirtemp1,DirZX);
    Dirn = Dirn./norm(Dirn);  % 平面法向量
    
    A = Dirn(1);
    B = Dirn(2);
    C = Dirn(3);
    D = -(A * Psy1(1) + B * Psy1(2) + C * Psy1(3));
    
    % 计算点到平面的距离
    numerator = A * PA1(1) + B * PA1(2) + C * PA1(3) + D; % 平面方程左侧的值
    denominator = sqrt(A^2 + B^2 + C^2); % 法向量的模长
    distance(jj) = numerator / denominator; % 距离公式

end

RightPoint = []; % 编号、点（x，y，z）、距离
LeftPoint = [];
for kk = 1:numShengLu*2
    if rightflag(kk) ==1
        RightPoint = [RightPoint;[kk,PointTable_B_off(:,kk)',distance(kk)]];
    else
        LeftPoint = [LeftPoint;[kk,PointTable_B_off(:,kk)',distance(kk)]];
    end



end

RightPoint = sortrows(RightPoint,5);
LeftPoint = sortrows(LeftPoint,5);



BianHaoTemp = zeros(2*numShengLu,1);
BianHao2 = zeros(1,2*numShengLu);
for  hhh = 1:numShengLu

    BianHaoTemp(hhh*2-1:hhh*2,1) = [LeftPoint(hhh,1),RightPoint(hhh,1)];
    TTemp = [BianHaoTemp,(1:2*numShengLu)'];
    TTTemp = sortrows(TTemp,1);
    
    BianHao2 = TTTemp(:,2)';

end

BianHao = [BianHao1;BianHao2];

end
