function Point_test = Generate_multi_layered_measurement_points(Point_out,num,laynum,P3,P4)
%% -----------------------平均轴向量、圆心-----------------------
x = Point_out(1,:)';
y = Point_out(2,:)';
z = Point_out(3,:)';

% [s1,s2,s3,xcenter,ycenter,zcenter] = Three_Points_Initial_Rough_Cylindrical_Judgment(xxx,yyy,zzz);
%%%%%%%%%%%%%%%%%%%%%
p1 = [x(1),y(1),z(1)];
p2 = [x(2),y(2),z(2)];
p3 = [x(3),y(3),z(3)];
pf= cross(p1-p2, p1-p3);

% 两条线段的重点，之后需要求中垂线
p12 = (p1 + p2)/2;
p23 = (p2 + p3)/2;

% 求两条线的中垂线
p12f = cross(pf, p1-p2);
p23f = cross(pf, p2-p3);

% 求在中垂线上投影的大小
ds = ( (p12(2)-p23(2))*p12f(1) - (p12(1)-p23(1))*p12f(2) ) / ( p23f(2)*p12f(1) - p12f(2)*p23f(1) );

% 得出距离
center = p23 + p23f .* ds;
% radius = sqrt((x(1)-p(1)).^2+(y(1)-p(2)).^2+(z(1)-p(3)).^2);
xcenter = center(1);
ycenter = center(2);
zcenter = center(3);
S = zeros(1,3);
pfnormal = pf./norm(pf);

S1 = pfnormal(1);
S2 = pfnormal(2);
S3 = pfnormal(3);
%%%%%%%%%%%%%%%%%%%%
S(1) = S1;
S(2) = S2;
S(3) = S3;
XCenterMean = xcenter;
YCenterMean = ycenter;
ZCenterMean = zcenter;
Smean = S;

%% -----------------------------计算参数-------------------------------
Dist = zeros(1,length(x));
for i = 1:length(x)
    dist = sqrt((x(i) - XCenterMean).^2+(y(i) - YCenterMean).^2+(z(i) - ZCenterMean).^2);
    Dist(i) = dist;
end

%%%%%%%%           圆柱参数          %%%%%%%%%%%
Radius = mean(Dist);
Tao = Smean / norm(Smean);
AxialPoint = [XCenterMean,YCenterMean,ZCenterMean]';


%%-------------------------管路确定范围（轴线端点）----------------------
P1 = AxialPoint;
P2 = AxialPoint + Tao';


[Nx1,Ny1,Nz1] = foot_of_perpendicular_from_a_point_to_a_line(P4,P1,P2);
[Nx2,Ny2,Nz2] = foot_of_perpendicular_from_a_point_to_a_line(P3,P1,P2);
Len = norm([Nx2,Ny2,Nz2] - [Nx1,Ny1,Nz1]);

%% -----------------------------生成抽样点-------------------------------
elevation = atan2(Tao(3),sqrt(Tao(1).^2 + Tao(2).^2));
azimuth = atan2(Tao(2),Tao(1));
Point_out1 = generate_unit_circle_with_normal_vector(elevation,azimuth,num);
Xgen = Point_out1(1,:);
Ygen = Point_out1(2,:);
Zgen = Point_out1(3,:);

%% ----------------------------移动到原点-------------------------------
Xlay0 =  Xgen * Radius + Nx1;
Ylay0 =  Ygen * Radius + Ny1;
Zlay0 =  Zgen * Radius + Nz1;


%% -----------------------------生成多层测点-------------------------------
% 阈值 
Threshold_low = 0.2;
Threshold_high = 0.8;

Layer = linspace(Threshold_low*Len,Threshold_high*Len,laynum);

Point_testx = zeros(laynum*num,1);
Point_testy = zeros(laynum*num,1);
Point_testz = zeros(laynum*num,1);

for i = 1:laynum
    tempx = Xlay0 - Layer(i)*Tao(1);
    tempy = Ylay0 - Layer(i)*Tao(2);
    tempz = Zlay0 - Layer(i)*Tao(3);
    Point_testx((i-1)*num+1:i*num) = tempx;
    Point_testy((i-1)*num+1:i*num) = tempy;
    Point_testz((i-1)*num+1:i*num) = tempz;
end


Point_test = [Point_testx';Point_testy';Point_testz'];

end

