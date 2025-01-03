function plotcylinder(u1,u2,color_a,r,alpha)
% 根据空间两点画圆柱
% u1,u2 ——空间两点
% color ——颜色
% r     ——半决
% alpha ——透明度

L=norm(u1-u2);
ROD=u2-u1;
[X,Y,Z]=cylinder(r,100);
x1=X*0;y1=Y*0;z1=Z*0;
Z=L*Z-L/2;
ROD_midpoint=(u1+u2)/2;
x=ROD_midpoint(1);
y=ROD_midpoint(2);
z=ROD_midpoint(3);
a=[1 0 0];b=[0 1 0];c=[0 0 1];
if(ROD(2)==0||ROD(1)==0)
    if(ROD(2)==0)    % 在XZ平面
       angel=acos(dot(ROD,c)/norm(ROD)/norm(c));
       if(ROD(1)<0)
           angel=-angel;  %%
       end
       A2=[cos(angel) 0 sin(angel);0 1 0; -sin(angel) 0 cos(angel)];  % 绕Y轴旋转
       for i=1:length(X(1,:))
          u=[X(1,i) Y(1,i) Z(1,i)]';
          u1=A2*u;
          x1(1,i)=u1(1);y1(1,i)=u1(2);z1(1,i)=u1(3);
          u=[X(1,i) Y(1,i) Z(2,i)]';
          u1=A2*u;
          x1(2,i)=u1(1);y1(2,i)=u1(2);z1(2,i)=u1(3);   
       end    
    end
    if(ROD(1)==0)   % 在YZ平面
       angel=acos(dot(ROD,c)/norm(ROD)/norm(c));
       angel=2*pi-angel;   % 此处maybe要增加类似上面的判定是否变为负数
       A1=[1 0 0;0 cos(angel) -sin(angel);0 sin(angel) cos(angel)];  % 绕X轴旋转
       for i=1:length(X(1,:))
          u=[X(1,i) Y(1,i) Z(1,i)]';
          u1=A1*u;
          x1(1,i)=u1(1);y1(1,i)=u1(2);z1(1,i)=u1(3);
          u=[X(1,i) Y(1,i) Z(2,i)]';
          u1=A1*u;
          x1(2,i)=u1(1);y1(2,i)=u1(2);z1(2,i)=u1(3);   
       end      
    end
else
     % 先绕Z轴旋转，在绕Y轴旋转
       angel=acos(dot(ROD,c)/norm(ROD)/norm(c));
       A2=[cos(angel) 0 sin(angel);0 1 0; -sin(angel) 0 cos(angel)];
       angel=acos(dot(ROD,a)/norm(ROD)/norm(a));
       if(ROD(2)<0)
           angel=2*pi-angel;
       end
       A3=[cos(angel) -sin(angel) 0;sin(angel) cos(angel) 0;0 0 1];
       A=A3*A2;
       for i=1:length(X(1,:))
          u=[X(1,i) Y(1,i) Z(1,i)]';
          u1=A*u;
          x1(1,i)=u1(1);y1(1,i)=u1(2);z1(1,i)=u1(3);
          u=[X(1,i) Y(1,i) Z(2,i)]';
          u1=A*u;
          x1(2,i)=u1(1);y1(2,i)=u1(2);z1(2,i)=u1(3);   
       end
end
fill3(x1(1,:)+x,y1(1,:)+y,z1(1,:)+z,color_a,'EdgeColor','none','FaceAlpha',alpha) %底面
hold on
fill3(x1(2,:)+x,y1(2,:)+y,z1(2,:)+z,color_a,'EdgeColor','none','FaceAlpha',alpha) %顶面
hold on
surf(x1+x,y1+y,z1+z,'facecolor',color_a,'edgecolor','none','FaceAlpha',alpha)    %圆柱表面
% axis equal
% xlabel('x')
% ylabel('y')
% zlabel('z')
set(gcf,'color','w')  %gcf是当前图窗的句柄，用图窗句柄可查询和修改图窗属性
end