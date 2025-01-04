function [xN1,yN1,zN1] = foot_of_perpendicular_from_a_point_to_a_line(P_outer,P_lines1,P_lines2)
    
    % 三个点定义
    x1=P_outer(1);
    y1=P_outer(2);
    z1=P_outer(3);
    
    x2=P_lines1(1);
    y2=P_lines1(2);
    z2=P_lines1(3);
     
     
    x3=P_lines2(1);
    y3=P_lines2(2);
    z3=P_lines2(3);
    
    % 斜率计算
    K=-((x2-x1)*(x3-x2)+(y2-y1)*(y3-y2)+(z2-z1)*(z3-z2))/((x3-x2)^2+(y3-y2)^2+(z3-z2)^2);

    % P1点在轴线上的投影坐标
    xN1=K*(x3-x2)+x2;
    yN1=K*(y3-y2)+y2;
    zN1=K*(z3-z2)+z2;
end