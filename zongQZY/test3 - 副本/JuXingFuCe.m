function [Distance,theta,LTPY,TiC,Wquanzhong3,Wquanzhong4]=JuXingFuCe(PointIn,shenglunum,Pin,Tao,h,PlaneParaOut4)


%% 计算距离
Distance = zeros(1,shenglunum);
for i = 1:shenglunum
    Distance(i) = norm(PointIn(:,2*i-1)-PointIn(:,2*i));
end

%% 计算声道角度

theta = zeros(1,shenglunum);


for i = 1:shenglunum
    shengdao1 = PointIn(:,2*i-1);
    shengdao2 = PointIn(:,2*i);

    SPXL = shengdao2 - shengdao1;
    theta(i) = acos(dot(Tao, SPXL) / (norm(Tao) * norm(SPXL)));  
end
theta = pi- theta;
% degtheta = rad2deg(theta);



%% 计算LT

DistanceYC = zeros(1,shenglunum);
for i = 1:shenglunum
    shengdao1 = PointIn(:,2*i-1);
    shengdao2 = PointIn(:,2*i);
    dir_vec = shengdao2 - shengdao1;

    % 计算方向向量
    a = PlaneParaOut4(1,1);
    b = PlaneParaOut4(2,1);
    c = PlaneParaOut4(3,1);
    d = PlaneParaOut4(4,1);
    % 将直线方程代入平面方程，求解参数 t
    xN5 = shengdao1(1);
    yN5 = shengdao1(2);
    zN5 = shengdao1(3);
    t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
    % 计算交点
    x_intersect1 = xN5 + t * dir_vec(1);
    y_intersect1 = yN5 + t * dir_vec(2);
    z_intersect1 = zN5 + t * dir_vec(3);
    temp3 = [x_intersect1;y_intersect1;z_intersect1];


    % 计算方向向量
    a = PlaneParaOut4(1,3);
    b = PlaneParaOut4(2,3);
    c = PlaneParaOut4(3,3);
    d = PlaneParaOut4(4,3);
    % 将直线方程代入平面方程，求解参数 t
    xN5 = shengdao1(1);
    yN5 = shengdao1(2);
    zN5 = shengdao1(3);
    t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
    % 计算交点
    x_intersect2 = xN5 + t * dir_vec(1);
    y_intersect2 = yN5 + t * dir_vec(2);
    z_intersect2 = zN5 + t * dir_vec(3);
    temp4 = [x_intersect2;y_intersect2;z_intersect2];

    DistanceYC(i) = norm(temp4-temp3);

end

LTPY = Distance - DistanceYC;



%% 相对高度计算
TiC = zeros(1,2*shenglunum);
for i = 1:2*shenglunum
    shengdao = PointIn(:,i);

    a = PlaneParaOut4(1,2);
    b = PlaneParaOut4(2,2);
    c = PlaneParaOut4(3,2);
    x = Pin(1);
    y = Pin(2);
    z = Pin(3);
    d =  -(a*x+b*y+c*z);
    xN5 = shengdao(1);
    yN5 = shengdao(2);
    zN5 = shengdao(3);
    dir_vec = [a,b,c];

    % 计算交点
    t = -(a*xN5 + b*yN5 + c*zN5 + d) / (a*dir_vec(1) + b*dir_vec(2) + c*dir_vec(3));
    x_intersect3 = xN5 + t * dir_vec(1);
    y_intersect3 = yN5 + t * dir_vec(2);
    z_intersect3 = zN5 + t * dir_vec(3);
    temp5 = [x_intersect3;y_intersect3;z_intersect3];
    
    % 计算高度
    TiC(i) = 2*norm(temp5 - shengdao)/h;

end

if mod(shenglunum,2)==1 %奇数
    temp6 = floor(shenglunum./2);
    TiC(1:2*temp6) = -TiC(1:2*temp6);
else %偶数
    temp6 = shenglunum./2;
    TiC(1:2*temp6) = -TiC(1:2*temp6);
end




%% 计算权重
% k1 = 0.5;
% k2 = 0.6;
k3 = 0;
k4 = 0.15;

% gk1 = [1.570796,0.392699,0.19635,0.122718,0.085903];
% gk2 = [1.513365,0.360325,0.174351,0.106311,0.072959];
gk3 = [2,2/3,2/5,2/7,2/9];
gk4 = [1.838286,0.556753,0.315143,0.215852,0.162469];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
gk = gk3;
k = k3;

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

    Wquanzhong3 = abs(repelem(w,2));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
gk = gk4;
k = k4;

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

    Wquanzhong4 = abs(repelem(w,2));

end
