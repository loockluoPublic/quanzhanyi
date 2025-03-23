function [Pin,Pout,UPP,b,h,w,Tao,PP] = Calculate_rectangle_from_vertex(TrianglePoints4)
% TrianglePoints4 前一个函数的输出三角点坐标
% P_bound1 边界点1
% P_bound2 边界点2
% Pin  边界点1的中心
% Pout 边界点2的中心
% UPP  边界1上中点
% b    进口面宽
% h    进口面高
% w    管道长度
% Tao  单位轴线
% PP   8个顶点


% 取八个点
Pdd = TrianglePoints4(:,[1:3,6,9,12,17,18]);
PP1 = Pdd(:,1);
PP2 = Pdd(:,2);
PP3 = Pdd(:,3);
PP4 = Pdd(:,4);
PP5 = Pdd(:,5);
PP6 = Pdd(:,6);
PP7 = Pdd(:,7);
PP8 = Pdd(:,8);

% 计算轴线
Tao1 = (PP3-PP1)./norm(PP3-PP1);
Tao2 = (PP4-PP2)./norm(PP4-PP2);
Tao3 = (PP6-PP5)./norm(PP6-PP5);
Tao4 = (PP8-PP7)./norm(PP6-PP5);
Tao = (Tao1+Tao2+Tao3+Tao4)./4;



% 计算进口中心
temp1 = (PP2+PP5)./2;
temp2 = (PP1+PP7)./2;
Pin = (temp1+temp2)./2;

% 计算出口中心
temp3 = (PP3+PP8)./2;
temp4 = (PP4+PP6)./2;
Pout = (temp3+temp4)./2;

% 计算上顶点
UPP = (PP5+PP1)./2;

% 计算长宽高
b1 = sqrt((PP1(1)-PP5(1)).^2+(PP1(2)-PP5(2)).^2+(PP1(3)-PP5(3)).^2);
h = sqrt((PP1(1)-PP2(1)).^2+(PP1(2)-PP2(2)).^2+(PP1(3)-PP2(3)).^2);
w = sqrt((PP1(1)-PP3(1)).^2+(PP1(2)-PP3(2)).^2+(PP1(3)-PP3(3)).^2);


b2 = sqrt((PP3(1)-PP6(1)).^2+(PP3(2)-PP6(2)).^2+(PP3(3)-PP6(3)).^2);


b3 = sqrt((PP4(1)-PP8(1)).^2+(PP4(2)-PP8(2)).^2+(PP4(3)-PP8(3)).^2);

b4 = sqrt((PP2(1)-PP7(1)).^2+(PP2(2)-PP7(2)).^2+(PP2(3)-PP7(3)).^2);

b = mean([b1,b2,b3,b4]);

h2 = sqrt((PP6(1)-PP8(1)).^2+(PP6(2)-PP8(2)).^2+(PP6(3)-PP8(3)).^2);

h3 = sqrt((PP3(1)-PP4(1)).^2+(PP3(2)-PP4(2)).^2+(PP3(3)-PP4(3)).^2);

h4 = sqrt((PP5(1)-PP7(1)).^2+(PP5(2)-PP7(2)).^2+(PP5(3)-PP7(3)).^2);


PP = [PP1,PP2,PP3,PP4,PP5,PP6,PP7,PP8]';   % 8个顶点


end