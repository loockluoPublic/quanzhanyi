function [x,y,z] = angle2point(ANG,a,b,c,d,Mradial)
x = Mradial*cos(ANG);
y = Mradial*sin(ANG);
z = -(d+a*x+b*y)/c;
end