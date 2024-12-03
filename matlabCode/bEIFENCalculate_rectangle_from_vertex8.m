function [PointTable_A_off8,PointTable_B_off8,XieMianPianYi] = Calculate_rectangle_from_vertex8(side_faces_transformed1,side_faces_transformed2,side_faces_transformed3,side_faces_transformed4,side_faces_transformed5,side_faces_transformed6,side_faces_transformed7,side_faces_transformed8,P_bound1,P_bound2,PAB,phi,shenglunum,Ti,a,distanceThreshold)

% 打印第一、八个平面xyz、P1、P2、PAB、phi、shenglushu、Ti,a,distanceThreshold

% fprintf('first face xyz: %f, %f, %f\n',side_faces_transformed1(1,1),side_faces_transformed1(2,1),side_faces_transformed1(3,1));
% fprintf('second face xyz: %f, %f, %f\n',side_faces_transformed2(1,1),side_faces_transformed2(2,1),side_faces_transformed2(3,1));
% fprintf('third face xyz: %f, %f, %f\n',side_faces_transformed3(1,1),side_faces_transformed3(2,1),side_faces_transformed3(3,1));
% fprintf('fourth face xyz: %f, %f, %f\n',side_faces_transformed4(1,1),side_faces_transformed4(2,1),side_faces_transformed4(3,1));
% fprintf('fifth face xyz: %f, %f, %f\n',side_faces_transformed5(1,1),side_faces_transformed5(2,1),side_faces_transformed5(3,1));
% fprintf('sixth face xyz: %f, %f, %f\n',side_faces_transformed6(1,1),side_faces_transformed6(2,1),side_faces_transformed6(3,1));
% fprintf('seventh face xyz: %f, %f, %f\n',side_faces_transformed7(1,1),side_faces_transformed7(2,1),side_faces_transformed7(3,1));
% fprintf('eighth face xyz: %f, %f, %f\n',side_faces_transformed8(1,1),side_faces_transformed8(2,1),side_faces_transformed8(3,1));
% 
% fprintf('P_bound1 xyz: %f, %f, %f\n',P_bound1(1),P_bound1(2),P_bound1(3));
% fprintf('P_bound2 xyz: %f, %f, %f\n',P_bound2(1),P_bound2(2),P_bound2(3));
% fprintf('PAB xyz: %f, %f, %f\n',PAB(1),PAB(2),PAB(3));
% 
% fprintf('phi: %f\n',phi);
% 
% fprintf('shenglushu: %f\n',shenglunum);
% fprintf('Ti: %f, %f, %f, %f\n',Ti(1),Ti(2),Ti(3),Ti(4));
% fprintf('a: %f, %f, %f, %f\n',a(1),a(2),a(3),a(4));
% fprintf('distanceThreshold: %f\n',distanceThreshold);

%%%%%%%%%%%%%%%%%%%%%%  计算八面参数  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
[PlaneParaOut8,TrianglePoints8,~,~] = planefit8(side_faces_transformed1,side_faces_transformed2,side_faces_transformed3,side_faces_transformed4,side_faces_transformed5,side_faces_transformed6,side_faces_transformed7,side_faces_transformed8,P_bound1,P_bound2,distanceThreshold);



%%%%%%%%%%%%%%%%%%%%%%  计算角度  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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




%%%%%%%%%%%%%%%%%%%%%%  计算阈值  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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



% a1 = PP16(:,1);
% b1 = PP16(:,8);
% c1 = PP16(:,2);
% d1 = PP16(:,7);
% TiYuZhi1 = norm(a1-b1)./norm(c1-d1);
% TiYuZhi4 = norm(a1-b1)./norm(c1-d1);
% 
% a1 = PP16(:,4);
% b1 = PP16(:,5);
% c1 = PP16(:,3);
% d1 = PP16(:,6);
% TiYuZhi2 = norm(a1-b1)./norm(c1-d1);
% TiYuZhi3 = norm(a1-b1)./norm(c1-d1);


%%%%%%%%%%%%%%%%%%%%%%  判断点是否在斜面上（利用阈值）  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
temp = shenglunum./2;
XMFlag = zeros(1,2*shenglunum);

for i = 1:2*shenglunum
    Tii  = abs(Ti(i));
    if i <= temp
        if abs(Tii) < abs(TiYuZhi4)
            XMFlag(i) = 0;
        else
            XMFlag(i) = 1;
        end
    elseif i <= 2*temp
        if abs(Tii) < abs(TiYuZhi1)
            XMFlag(i) = 0;
        else
            XMFlag(i) = 1;
        end
    elseif i <= 3*temp
        if abs(Tii) < abs(TiYuZhi2)
            XMFlag(i) = 0;
        else
            XMFlag(i) = 1;
        end
    else
        if abs(Tii) < abs(TiYuZhi3)
            XMFlag(i) = 0;
        else
            XMFlag(i) = 1;
        end
    end
end

Ti2 = zeros(1,2*shenglunum);
XieMianPianYi = zeros(1,2*shenglunum);
%%%%%%%%%%%%%%%%%%%%%%  对斜面上的点进行偏移（修正Ti）  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for j = 1:2*shenglunum
    if j <= temp
        if XMFlag(j) == 1 %斜面上
            Ti2(j) = Ti(j) + a(j) *sin(theta3);
            XieMianPianYi(j) = a(j) *tan(theta3);
        else
            Ti2(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    elseif j <= 2*temp
        if XMFlag(j) == 1 %斜面上
            Ti2(j) = Ti(j) - a(j) *sin(theta2);
            XieMianPianYi(j) = a(j) *tan(theta2);
        else
            Ti2(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    elseif j <= 3*temp
        if XMFlag(j) == 1 %斜面上
            Ti2(j) = Ti(j) - a(j) *sin(theta1);
            XieMianPianYi(j) = a(j) *tan(theta1);
        else
            Ti2(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    else
        if XMFlag(j) == 1 %斜面上
            Ti2(j) = Ti(j) + a(j) *sin(theta4);
            XieMianPianYi(j) = a(j) *tan(theta4);
        else
            Ti2(j) = Ti(j);
            XieMianPianYi(j) = 0;
        end
    end
end



%%%%%%%%%%%%%%%%%%%%%%  调用矩形拟合  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
[~,TrianglePoints4,~,~] = planefit4(side_faces_transformed1,side_faces_transformed3,side_faces_transformed5,side_faces_transformed7,P_bound1,P_bound2,distanceThreshold);

%%%%%%%%%%%%%%%%%%%%%%  调用矩形参数计算  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
[Pin,Pout,UPP,b,h,~,Tao,~] = Calculate_rectangle_from_vertex(TrianglePoints4);

%%%%%%%%%%%%%%%%%%%%%%  矩形安装点计算  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
toff = [-a(1:shenglunum)./tan(phi),a(shenglunum+1:2*shenglunum)./tan(phi)];
[PointTable_A_off4,PointTable_B_off4] = Calculat_JuXing_A_and_B_Points_after_Offest(Tao,UPP,Pin,b,h,PAB,phi,shenglunum,Ti2,toff);

%%%%%%%%%%%%%%%%%%%%%%  计算交点  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Pin2Pup = (UPP-Pin)./norm(UPP-Pin); %  单位上方向
[xN6,yN6,zN6] = foot_of_perpendicular_from_a_point_to_a_line(PAB,Pin,Pout);
PabLine = [xN6;yN6;zN6];






PointTable_A_off8 = zeros(size(PointTable_A_off4));
for k = 1:2*shenglunum
    if k <= temp
        if XMFlag(k) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(k)./2;
            dir_vec = PointTable_A_off4(:,k) - up2;

            % 计算方向向量
            a = PlaneParaOut8(1,8);
            b = PlaneParaOut8(2,8);
            c = PlaneParaOut8(3,8);
            d = PlaneParaOut8(4,8);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_A_off4(1,k);
            yN5 = PointTable_A_off4(2,k);
            zN5 = PointTable_A_off4(3,k);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_A_off8(:,k) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_A_off8(:,k) = PointTable_A_off4(:,k);
        end
    elseif k <= 2*temp
        if XMFlag(k) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(k)./2;
            dir_vec = PointTable_A_off4(:,k) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,2);
            b = PlaneParaOut8(2,2);
            c = PlaneParaOut8(3,2);
            d = PlaneParaOut8(4,2);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_A_off4(1,k);
            yN5 = PointTable_A_off4(2,k);
            zN5 = PointTable_A_off4(3,k);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_A_off8(:,k) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_A_off8(:,k) = PointTable_A_off4(:,k);
        end
    elseif k <= 3*temp
        if XMFlag(k) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(k)./2;
            dir_vec = PointTable_A_off4(:,k) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,4);
            b = PlaneParaOut8(2,4);
            c = PlaneParaOut8(3,4);
            d = PlaneParaOut8(4,4);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_A_off4(1,k);
            yN5 = PointTable_A_off4(2,k);
            zN5 = PointTable_A_off4(3,k);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_A_off8(:,k) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_A_off8(:,k) = PointTable_A_off4(:,k);
        end
    else
        if XMFlag(k) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(k)./2;
            dir_vec = PointTable_A_off4(:,k) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,6);
            b = PlaneParaOut8(2,6);
            c = PlaneParaOut8(3,6);
            d = PlaneParaOut8(4,6);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_A_off4(1,k);
            yN5 = PointTable_A_off4(2,k);
            zN5 = PointTable_A_off4(3,k);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_A_off8(:,k) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_A_off8(:,k) = PointTable_A_off4(:,k);
        end
    end
end




PointTable_B_off8 = zeros(size(PointTable_B_off4));
for l = 1:2*shenglunum
    if l <= temp
        if XMFlag(l) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(l)./2;
            dir_vec = PointTable_B_off4(:,l) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,6);
            b = PlaneParaOut8(2,6);
            c = PlaneParaOut8(3,6);
            d = PlaneParaOut8(4,6);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_B_off4(1,l);
            yN5 = PointTable_B_off4(2,l);
            zN5 = PointTable_B_off4(3,l);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_B_off8(:,l) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_B_off8(:,l) = PointTable_B_off4(:,l);
        end
    elseif l <= 2*temp
        if XMFlag(l) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(l)./2;
            dir_vec = PointTable_B_off4(:,l) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,4);
            b = PlaneParaOut8(2,4);
            c = PlaneParaOut8(3,4);
            d = PlaneParaOut8(4,4);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_B_off4(1,l);
            yN5 = PointTable_B_off4(2,l);
            zN5 = PointTable_B_off4(3,l);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_B_off8(:,l) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_B_off8(:,l) = PointTable_B_off4(:,l);
        end
    elseif l <= 3*temp
        if XMFlag(l) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(l)./2;
            dir_vec = PointTable_B_off4(:,l) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,2);
            b = PlaneParaOut8(2,2);
            c = PlaneParaOut8(3,2);
            d = PlaneParaOut8(4,2);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_B_off4(1,l);
            yN5 = PointTable_B_off4(2,l);
            zN5 = PointTable_B_off4(3,l);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_B_off8(:,l) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_B_off8(:,l) = PointTable_B_off4(:,l);
        end
    else
        if XMFlag(l) == 1 %斜面上
            up2 =  PabLine + Pin2Pup.*h.*Ti2(l)./2;
            dir_vec = PointTable_B_off4(:,l) - up2;
            % 计算方向向量
            a = PlaneParaOut8(1,8);
            b = PlaneParaOut8(2,8);
            c = PlaneParaOut8(3,8);
            d = PlaneParaOut8(4,8);
            % 将直线方程代入平面方程，求解参数 t
            xN5 = PointTable_B_off4(1,l);
            yN5 = PointTable_B_off4(2,l);
            zN5 = PointTable_B_off4(3,l);
            t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
            % 计算交点
            x_intersect = xN5 + t * dir_vec(1);
            y_intersect = yN5 + t * dir_vec(2);
            z_intersect = zN5 + t * dir_vec(3);
            % 输出交点
            PointTable_B_off8(:,l) = [x_intersect; y_intersect; z_intersect];
        else
            PointTable_B_off8(:,l) = PointTable_B_off4(:,l);
        end
    end
end




end
