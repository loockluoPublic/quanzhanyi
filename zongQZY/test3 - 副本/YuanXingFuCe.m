function [Distance,theta,LTPY,TiC,Wquanzhong1,Wquanzhong2]=YuanXingFuCe(PointIn,shenglunum,Mcenter,MTaon,Mradial,phi)

%% 距离计算
Distance = zeros(1,shenglunum);
for i = 1:shenglunum
    shengdao = PointIn(:,[i,2*shenglunum+1-i]);
    Distance(i) = norm(PointIn(:,2*i-1)-PointIn(:,2*i));
end



%% 计算声道角度
% 计算水平方向向量
theta = zeros(1,shenglunum);
for i = 1:shenglunum
    shengdao1 = PointIn(:,2*i-1);
    shengdao2 = PointIn(:,2*i);

    SPXL = shengdao2 - shengdao1;
    theta(i) = acos(dot(MTaon, SPXL) / (norm(MTaon) * norm(SPXL)));  
end

% rad2deg(theta)


%% 计算LT
DistanceYC = zeros(1,shenglunum);



for i = 1:shenglunum
    shengdao1 = PointIn(:,2*i-1);
    shengdao2 = PointIn(:,2*i);
    Cross_point = YuanZhuJiaoDian(Mcenter,MTaon,Mradial,shengdao1',shengdao2');
    DistanceYC(i) = norm(Cross_point(1,:)- Cross_point(2,:));

end

LTPY = Distance - DistanceYC;

%% 相对高度计算

%%%%%%%%%%%%%%%%%%%%%%%%%%%%水平方向计算%%%%%%%%%%%%%%%%%%
% 起始点
A = [0,0,1];
B = MTaon;
C = cross(A,B);
C = C./norm(C);

D = B+tan(phi)*C;
D = D./norm(D);
E = cross(cross(B,C),D);
E = E./norm(E);




% 圆心点
[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(MTaon,Mcenter,Mcenter+MTaon);

% 起始点 （测点半圆的中点）
QiShi = [xN1,yN1,zN1] + E;
QiShi = cross(QiShi,B);


Pz1 = Mcenter;
Pz2 = Mcenter+MTaon;

[xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(QiShi,Pz1,Pz2);
zxQS = [xN1,yN1,zN1];

dirQS = QiShi-zxQS;
dirQS = dirQS./norm(dirQS);


alphaA = zeros(1,2*shenglunum);
for i = 1:2*shenglunum
    shengdao = PointIn(:,i);
    [xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(shengdao,Pz1,Pz2);
    zxP = [xN1,yN1,zN1];
    dirP = shengdao' - zxP;
    dirP = dirP./norm(dirP);
    alphaA(i) = acos(dot(dirP, dirQS) / (norm(dirP) * norm(dirQS)));
end

TiC = sin(alphaA);

if mod(shenglunum,2)==1 %奇数
    temp6 = floor(shenglunum./2);
    TiC(1:2*temp6) = -TiC(1:2*temp6);
else %偶数
    temp6 = shenglunum./2;
     TiC(1:2*temp6) = -TiC(1:2*temp6);
end




DegAlpha = rad2deg(alphaA);
DegAlpha(DegAlpha>90) = 180 - DegAlpha(DegAlpha>90);



%% 计算权重 1
k1 = 0.5;
k2 = 0.6;
k3 = 0;
k4 = 0.15;

gk1 = [1.570796,0.392699,0.19635,0.122718,0.085903];
gk2 = [1.513365,0.360325,0.174351,0.106311,0.072959];
gk3 = [2,2/3,2/5,2/7,2/9];
gk4 = [1.838286,0.556753,0.315143,0.215852,0.162469];

gk = gk1;
k = k1;


TiYiCe = TiC(1:2:2*shenglunum);


if mod(shenglunum,2)==1 %奇数
    temp6 = floor(shenglunum./2);
    TiYiCe(temp6+1) = 0;
end

t_k = zeros(shenglunum-1,1);
w = zeros(shenglunum,1);
f = zeros(shenglunum,1);

    for i=1:shenglunum  
        count_tk = 1;
        for m=1:shenglunum
            if(m~=i)
            t_k(count_tk) =  TiYiCe(m);
            count_tk = count_tk + 1;
            end
        end  

        for j=1:(shenglunum+1)/2
             f(j) = -sum(prod(nchoosek(t_k,(shenglunum+1-2*j)),2)); 
             w(i) = w(i) + gk(j)*f(j);
        end

        mul = 1;
        for m=1:shenglunum
            if(m ~= i)
                mul = mul*(TiYiCe(i) - TiYiCe(m));
            end
        end
        w(i)=w(i)/((1-TiYiCe(i)*TiYiCe(i))^k * mul);    
    end

    Wquanzhong1 = abs(repelem(w,2));




%% 计算权重 2
k1 = 0.5;
k2 = 0.6;
k3 = 0;
k4 = 0.15;

gk1 = [1.570796,0.392699,0.19635,0.122718,0.085903];
gk2 = [1.513365,0.360325,0.174351,0.106311,0.072959];
gk3 = [2,2/3,2/5,2/7,2/9];
gk4 = [1.838286,0.556753,0.315143,0.215852,0.162469];

gk = gk2;
k = k2;


TiYiCe2 = TiC(1:2:2*shenglunum);


if mod(shenglunum,2)==1 %奇数
    temp6 = floor(shenglunum./2);
    TiYiCe2(temp6+1) = 0;
end

t_k = zeros(shenglunum-1,1);
w = zeros(shenglunum,1);
f = zeros(shenglunum,1);

    for i=1:shenglunum  
        count_tk = 1;
        for m=1:shenglunum
            if(m~=i)
            t_k(count_tk) =  TiYiCe2(m);
            count_tk = count_tk + 1;
            end
        end  

        for j=1:(shenglunum+1)/2
             f(j) = -sum(prod(nchoosek(t_k,(shenglunum+1-2*j)),2)); 
             w(i) = w(i) + gk(j)*f(j);
        end

        mul = 1;
        for m=1:shenglunum
            if(m ~= i)
                mul = mul*(TiYiCe2(i) - TiYiCe2(m));
            end
        end
        w(i)=w(i)/((1-TiYiCe2(i)*TiYiCe2(i))^k * mul);    
    end

    Wquanzhong2 = abs(repelem(w,2));


end
