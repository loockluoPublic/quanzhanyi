function [Distance,theta,LTPY,TiC,Wquanzhong1,Wquanzhong2]=YuanXingFuCe(PointIn,shenglunum,Mcenter,MTaon,Mradial,phi)

%% 距离计算
Distance = zeros(1,shenglunum);
for i = 1:shenglunum
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
theta(theta>pi./2) = pi- theta(theta>pi./2);
% rad2deg(theta)



%% 相对高度计算


TiC = zeros(1,shenglunum);

for i = 1:shenglunum
    shengdao1 = PointIn(:,2*i-1);
    shengdao2 = PointIn(:,2*i);

    MidP = (shengdao1+shengdao2)./2;
    Pt1 = Mcenter;
    Pt2 = Mcenter+MTaon;


    [xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(MidP,Pt1,Pt2);
    temp = [xN1;yN1;zN1];
    TiC(i) = norm(MidP-temp)./Mradial;
end

% alphaA = asin(TiC);
TiC(1:floor(shenglunum./2)) = - TiC(1:floor(shenglunum./2));

%% 计算LT
% % % LTPY = zeros(1,shenglunum);
% % % for i = 1:shenglunum
% % %     shengdao1 = PointIn(:,2*i-1);
% % %     shengdao2 = PointIn(:,2*i);
% % %     Cross_point = YuanZhuJiaoDian(Mcenter,MTaon,Mradial,shengdao1',shengdao2');
% % % 
% % %     LT1 = norm(shengdao1'-Cross_point(2,:));
% % %     LT2 = norm(shengdao1'-Cross_point(1,:));
% % % 
% % %     if LT1<LT2
% % %         LTF = norm(shengdao1'-Cross_point(2,:));
% % %         LTR = norm(shengdao2'-Cross_point(1,:));
% % %         LThalf = min([LTF,LTR]);
% % %     else
% % %         LTF = norm(shengdao2'-Cross_point(2,:));
% % %         LTR = norm(shengdao1'-Cross_point(1,:));
% % %         LThalf = min([LTF,LTR]);
% % %     end
% % %     LTPY(i) = LThalf.*2;
% % % 
% % % end

LTPY = zeros(1,shenglunum);
for i =  1:shenglunum
    TempT = TiC(i);
    TempA = theta(i);
    DisL = 2*sqrt(1 - TempT.^2).*Mradial;
    DisX = DisL./sin(TempA);
    LTPY(1,i) = (Distance(i)-DisX);
end



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


TiYiCe = TiC;


% fprintf('%f,%f,%f,%f',TiYiCe(1),TiYiCe(2),TiYiCe(3),TiYiCe(4));


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

    Wquanzhong1 = w;




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


TiYiCe2 = TiC;


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

    Wquanzhong2 = w;


end
