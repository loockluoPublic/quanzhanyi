function [PointTable_A,PointTable_B] = Calculat_A_and_B_Points(MTaon,Mcenter,Mradial,Bottom_round_center1,Bottom_round_center2,testP,numShengLu,phi)

MTaon = MTaon';
Mcenter = Mcenter';
Bottom_round_center1 = Bottom_round_center1';
Bottom_round_center2 = Bottom_round_center2';
phi = pi/2-phi;

% 计算45（phi）面的法向量D
A = [0,0,1];
B = MTaon;   
C = cross(A,B);
C = C./norm(C);

D = B+tan(phi)*C;
D = D./norm(D);
E = cross(cross(B,C),D);
E = E./norm(E);


% 圆心点
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(testP,Mcenter,Mcenter+MTaon);

% 面法向量第二个点（与圆心点构成45（phi）面的法向量）
Tao2 = [xN1,yN1,zN1] + D;

% 起始点 （测点半圆的中点）
QiShi = [xN1,yN1,zN1] + E;

% 构建旋转矩阵
theta = atan2(norm(cross([0, 0, 1], MTaon)), dot([0, 0, 1], MTaon));
v = cross([0, 0, 1],MTaon) / norm(cross([0, 0, 1], MTaon));
rot1 = myvrrotvec2mat([v, theta]);

Prot = zeros(3,5);
% 选择旋转点集合
Prot(1:3,1) = [xN1;yN1;zN1]; % 圆心点
Prot(1:3,2) = Tao2';  % 面法向量第二个点
Prot(1:3,3) = Bottom_round_center1'; % 圆底面点1
Prot(1:3,4) = Bottom_round_center2'; % 圆底面点2
Prot(1:3,5) = QiShi'; % 起始点 （测点半圆的中点）

% 旋转至【0，0，1】的点集合
P2D = Prot'*rot1;
% plotcylinder(P2D(3,:),P2D(4,:),'b',Mradial,0.2)

P2DT = P2D - repmat([P2D(1,1),P2D(1,2),0],size(P2D,1),1);

% 旋转、平移后 法向量
Tao3 = P2DT(2,:) - P2DT(1,:);

% 法平面参数 aa,bb,cc,dd 过点 P2DT(1,:) ，法向量Tao3
aa = Tao3(1);
bb = Tao3(2);
cc = Tao3(3);
dd = -(aa*P2DT(1,1)+bb*P2DT(1,2)+cc*P2DT(1,3));


% 起始角度
Ang1 = atan(P2DT(5,2)/P2DT(5,1));
A1x = Mradial*cos(Ang1);
A1y = Mradial*sin(Ang1);
A1z = -(dd+aa*A1x+bb*A1y)/cc;

PointTable2DT_A = zeros(10,3);
AngAll =  zeros(10,1);
% 根据声路数画出测点
switch numShengLu
    case 1
        PointTable2DT_A = [A1x,A1y,A1z];
    case 2
        Ang2 = Ang1 - pi/6;
        Ang3 = Ang1 + pi/6;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z];
    case 3
        Ang2 = Ang1 - pi/4;
        Ang3 = Ang1 + pi/4;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A1x,A1y,A1z;A3x,A3y,A3z];
    case 4
        Ang2 = Ang1-0.3*pi;
        Ang3 = Ang1-0.1*pi;
        Ang4 = Ang1+0.1*pi;
        Ang5 = Ang1+0.3*pi;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z;A4x,A4y,A4z;A5x,A5y,A5z];
    case 5
        Ang2 = Ang1-1/3*pi;
        Ang3 = Ang1-1/6*pi;
        Ang4 = Ang1+1/6*pi;
        Ang5 = Ang1+1/3*pi;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z; A3x,A3y,A3z; A1x,A1y,A1z; A4x,A4y,A4z; A5x,A5y,A5z];
    case 6
        temp = 1/7*pi;
        Ang2 = Ang1-1/2*pi+temp;
        Ang3 = Ang1-1/2*pi+2*temp;
        Ang4 = Ang1-1/2*pi+3*temp;
        Ang5 = Ang1-1/2*pi+4*temp;
        Ang6 = Ang1-1/2*pi+5*temp;
        Ang7 = Ang1-1/2*pi+6*temp;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        [A6x,A6y,A6z] = angle2point(Ang6,aa,bb,cc,dd,Mradial);
        [A7x,A7y,A7z] = angle2point(Ang7,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z;A4x,A4y,A4z;A5x,A5y,A5z;A6x,A6y,A6z;A7x,A7y,A7z];
    case 7
        temp = 1/8*pi;
        Ang2 = Ang1-1/2*pi+temp;
        Ang3 = Ang1-1/2*pi+2*temp;
        Ang4 = Ang1-1/2*pi+3*temp;
        Ang5 = Ang1-1/2*pi+4*temp;
        Ang6 = Ang1-1/2*pi+5*temp;
        Ang7 = Ang1-1/2*pi+6*temp;
        Ang8 = Ang1-1/2*pi+7*temp;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        [A6x,A6y,A6z] = angle2point(Ang6,aa,bb,cc,dd,Mradial);
        [A7x,A7y,A7z] = angle2point(Ang7,aa,bb,cc,dd,Mradial);
        [A8x,A8y,A8z] = angle2point(Ang8,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z;A4x,A4y,A4z;A5x,A5y,A5z;A6x,A6y,A6z;A7x,A7y,A7z;A8x,A8y,A8z];
    case 8
        temp = 1/9*pi;
        Ang2 = Ang1-1/2*pi+temp;
        Ang3 = Ang1-1/2*pi+2*temp;
        Ang4 = Ang1-1/2*pi+3*temp;
        Ang5 = Ang1-1/2*pi+4*temp;
        Ang6 = Ang1-1/2*pi+5*temp;
        Ang7 = Ang1-1/2*pi+6*temp;
        Ang8 = Ang1-1/2*pi+7*temp;
        Ang9 = Ang1-1/2*pi+8*temp;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        [A6x,A6y,A6z] = angle2point(Ang6,aa,bb,cc,dd,Mradial);
        [A7x,A7y,A7z] = angle2point(Ang7,aa,bb,cc,dd,Mradial);
        [A8x,A8y,A8z] = angle2point(Ang8,aa,bb,cc,dd,Mradial);
        [A9x,A9y,A9z] = angle2point(Ang9,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z;A4x,A4y,A4z;A5x,A5y,A5z;A6x,A6y,A6z;A7x,A7y,A7z;A8x,A8y,A8z;A9x,A9y,A9z];
    case 9
        temp = 1/10*pi;
        Ang2 = Ang1-1/2*pi+temp;
        Ang3 = Ang1-1/2*pi+2*temp;
        Ang4 = Ang1-1/2*pi+3*temp;
        Ang5 = Ang1-1/2*pi+4*temp;
        Ang6 = Ang1-1/2*pi+5*temp;
        Ang7 = Ang1-1/2*pi+6*temp;
        Ang8 = Ang1-1/2*pi+7*temp;
        Ang9 = Ang1-1/2*pi+8*temp;
        Ang10 = Ang1-1/2*pi+9*temp;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        [A6x,A6y,A6z] = angle2point(Ang6,aa,bb,cc,dd,Mradial);
        [A7x,A7y,A7z] = angle2point(Ang7,aa,bb,cc,dd,Mradial);
        [A8x,A8y,A8z] = angle2point(Ang8,aa,bb,cc,dd,Mradial);
        [A9x,A9y,A9z] = angle2point(Ang9,aa,bb,cc,dd,Mradial);
        [A10x,A10y,A10z] = angle2point(Ang10,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z;A4x,A4y,A4z;A5x,A5y,A5z;A6x,A6y,A6z;A7x,A7y,A7z;A8x,A8y,A8z;A9x,A9y,A9z;A10x,A10y,A10z];
    case 10
         temp = 1/11*pi;
        Ang2 = Ang1-1/2*pi+temp;
        Ang3 = Ang1-1/2*pi+2*temp;
        Ang4 = Ang1-1/2*pi+3*temp;
        Ang5 = Ang1-1/2*pi+4*temp;
        Ang6 = Ang1-1/2*pi+5*temp;
        Ang7 = Ang1-1/2*pi+6*temp;
        Ang8 = Ang1-1/2*pi+7*temp;
        Ang9 = Ang1-1/2*pi+8*temp;
        Ang10 = Ang1-1/2*pi+9*temp;
        Ang11 = Ang1-1/2*pi+10*temp;
        [A2x,A2y,A2z] = angle2point(Ang2,aa,bb,cc,dd,Mradial);
        [A3x,A3y,A3z] = angle2point(Ang3,aa,bb,cc,dd,Mradial);
        [A4x,A4y,A4z] = angle2point(Ang4,aa,bb,cc,dd,Mradial);
        [A5x,A5y,A5z] = angle2point(Ang5,aa,bb,cc,dd,Mradial);
        [A6x,A6y,A6z] = angle2point(Ang6,aa,bb,cc,dd,Mradial);
        [A7x,A7y,A7z] = angle2point(Ang7,aa,bb,cc,dd,Mradial);
        [A8x,A8y,A8z] = angle2point(Ang8,aa,bb,cc,dd,Mradial);
        [A9x,A9y,A9z] = angle2point(Ang9,aa,bb,cc,dd,Mradial);
        [A10x,A10y,A10z] = angle2point(Ang10,aa,bb,cc,dd,Mradial);
        [A11x,A11y,A11z] = angle2point(Ang11,aa,bb,cc,dd,Mradial);
        PointTable2DT_A = [A2x,A2y,A2z;A3x,A3y,A3z;A4x,A4y,A4z;A5x,A5y,A5z;A6x,A6y,A6z;A7x,A7y,A7z;A8x,A8y,A8z;A9x,A9y,A9z;A10x,A10y,A10z;A11x,A11y,A11z];
    otherwise
        disp('other value')
end



Xcen2D = P2DT(1,1);
Ycen2D = P2DT(1,2);
Zcen2D = P2DT(1,3);
tempx = 2*Xcen2D - PointTable2DT_A(:,1);
tempy = 2*Ycen2D - PointTable2DT_A(:,2);
tempz = 2*Zcen2D - PointTable2DT_A(:,3);

%计算2D A面测点
PointTable2DT_A = [PointTable2DT_A;[tempx,tempy,tempz]];
PointTable2DT_A = [PointTable2DT_A(:,2),-PointTable2DT_A(:,1),PointTable2DT_A(:,3)];

%计算2D B面测点
tempBZ = 2*Zcen2D - PointTable2DT_A(:,3);
PointTable2DT_B = [PointTable2DT_A(:,1),PointTable2DT_A(:,2),tempBZ];



%2D AB面测点 转3D
PointTable_A1  = (PointTable2DT_A + repmat([P2D(1,1),P2D(1,2),0],size(PointTable2DT_A,1),1))*pinv(rot1);
PointTable_B1  = (PointTable2DT_B + repmat([P2D(1,1),P2D(1,2),0],size(PointTable2DT_B,1),1))*pinv(rot1);

PointTable_A1 = PointTable_A1';
PointTable_B1 = PointTable_B1';


PointTable_A = zeros(3,2*numShengLu);
PointTable_B = zeros(3,2*numShengLu);

PointTable_A = PointTable_A1;
PointTable_B = PointTable_B1;


end