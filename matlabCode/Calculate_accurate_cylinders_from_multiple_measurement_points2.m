function [Mcenter,MTaon,Mradial,Err_every,Bottom_round_center1,Bottom_round_center2] = Calculate_accurate_cylinders_from_multiple_measurement_points2(points,P_bound1,P_bound2)

% points = points';
num = 180;
sp = linspace(0,2*pi,num);
sz = linspace(0,2*pi,num);

OptErr = 99999;
OptAngle = zeros(1,2);
OptPara = zeros(1,4);
OptAllErr =  zeros(size(points,2),1);

for i = 1:num
    for j = 1:num
        [x0,y0,z0] = sph2cart(sp(i),sz(j),1);
        theta = atan2(norm(cross([0, 0, 1], [x0, y0, z0])), dot([0, 0, 1], [x0, y0, z0]));
        v = cross([0, 0, 1], [x0, y0, z0]) / norm(cross([0, 0, 1], [x0, y0, z0]));

        rot1 = myvrrotvec2mat([v, theta]);

        P = points'*rot1;
        X = P(:,1);
        Y = P(:,2);
        [center, radius] = fitcircle([X'; Y']);
        err = hypot(X-center(1), Y-center(2))-radius;
        Merr = sqrt(mean(err.^2));
        if Merr < OptErr
            OptErr = Merr;
            OptPara = [center',radius,Merr];
            OptAllErr = err;
            OptAngle = [sp(i),sz(j)];
        end

    end
end

[x1,y1,z1] = sph2cart(OptAngle(1),OptAngle(2),1);


theta = atan2(norm(cross([0, 0, 1], [x1, y1, z1])), dot([0, 0, 1], [x1, y1, z1]));
v = cross([0, 0, 1], [x1, y1, z1]) / norm(cross([0, 0, 1], [x1, y1, z1]));
rot1 = myvrrotvec2mat([v, theta]);
rot2 = pinv(rot1);


Mcenter = [OptPara(1),OptPara(2),0] * rot2;


MTaon = [x1,y1,z1];

tempp = P_bound2-P_bound1;
op = sum(MTaon.*tempp);




Mradial = OptPara(3);


Err_every = OptAllErr';


Mu1 = Mcenter;
Mu2 = Mcenter + MTaon;


[xxN1,yyN1,zzN1] = foot_of_perpendicular_from_a_point_to_a_line(P_bound1,Mu1,Mu2);
[xxN2,yyN2,zzN2] = foot_of_perpendicular_from_a_point_to_a_line(P_bound2,Mu1,Mu2);

Bottom_round_center1 = [xxN1,yyN1,zzN1];
Bottom_round_center2 = [xxN2,yyN2,zzN2];

% ！  需求1  判断方向 ，改法向量方向


end

