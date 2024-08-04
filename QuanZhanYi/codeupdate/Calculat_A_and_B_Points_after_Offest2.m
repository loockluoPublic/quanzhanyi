function PointTable_A_off = Calculat_A_and_B_Points_after_Offest2(MTaon,Mcenter,Mradial,PAB,phi,Ang,toff,roff)

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

% 第一步修正
Ang = Ang+roff./Mradial;

% 第二步处理
AngProcess = [];
AngProcess(1:numShengLu) = AngOring - Ang(1:numShengLu);
AngProcess(1+numShengLu:2*numShengLu) = pi+AngOring+Ang(1+numShengLu:2*numShengLu);

% 调用计算坐标
[x,y,z] = angle2point(AngProcess,aa,bb,cc,dd,Mradial);

PointTable2DT_A = ones(length(Ang),3);
PointTable2DT_A = [x',y',z'];

for iii = 1:size(PointTable2DT_A,1)
    if PointTable2DT_A(iii,3)>P2DT(1,3)
        PointTable2DT_A(iii,3) = PointTable2DT_A(iii,3)-toff(iii);
    end

    if PointTable2DT_A(iii,3)<P2DT(1,3)
        PointTable2DT_A(iii,3) = PointTable2DT_A(iii,3)+toff(iii);
    end
end


PointTable2DT_A = [PointTable2DT_A(:,2),-PointTable2DT_A(:,1),PointTable2DT_A(:,3)];

%2D A面测点 转3D
PointTable_A1  = (PointTable2DT_A + repmat([P2D(1,1),P2D(1,2),0],size(PointTable2DT_A,1),1))*pinv(rot1);

PointTable_A_off = PointTable_A1';

end
