function Ang = ShengLuJiaoJiSuan(numShengLu)

switch numShengLu
    case 1
        Ang1 = pi/2;
        Ang = [Ang1,Ang1];
    case 2
        Ang1 = pi/2 - pi/6;
        Ang2 = pi/2 + pi/6;
        Ang = [Ang2,Ang1,Ang1,Ang2];


    case 3
        
        Ang1 = pi/2 - pi/4;
        Ang2 = pi/2;
        Ang3 = pi/2 + pi/4;
        Ang = [Ang3,Ang2,Ang1,Ang1,Ang2,Ang3];

    case 4
        Ang1 = pi/2-0.3*pi;
        Ang2 = pi/2-0.1*pi;
        Ang3 = pi/2+0.1*pi;
        Ang4 = pi/2+0.3*pi;
        Ang = [Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4];

    case 5

        Ang1 = pi/2-1/3*pi;
        Ang2 = pi/2-1/6*pi;
        Ang3 = pi/2;
        Ang4 = pi/2+1/6*pi;
        Ang5 = pi/2+1/3*pi;
        Ang = [Ang5,Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4,Ang5];

    case 6
        temp = 1/7*pi;
        Ang1 = pi/2-1/2*pi+temp;
        Ang2 = pi/2-1/2*pi+2*temp;
        Ang3 = pi/2-1/2*pi+3*temp;
        Ang4 = pi/2-1/2*pi+4*temp;
        Ang5 = pi/2-1/2*pi+5*temp;
        Ang6 = pi/2-1/2*pi+6*temp;
        Ang = [Ang6,Ang5,Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4,Ang5,Ang6];
        
    case 7
        temp = 1/8*pi;
        Ang1 = pi/2-1/2*pi+temp;
        Ang2 = pi/2-1/2*pi+2*temp;
        Ang3 = pi/2-1/2*pi+3*temp;
        Ang4 = pi/2-1/2*pi+4*temp;
        Ang5 = pi/2-1/2*pi+5*temp;
        Ang6 = pi/2-1/2*pi+6*temp;
        Ang7 = pi/2-1/2*pi+7*temp;
        Ang = [Ang7,Ang6,Ang5,Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4,Ang5,Ang6,Ang7];

    case 8
        temp = 1/9*pi;
        Ang1 = pi/2-1/2*pi+temp;
        Ang2 = pi/2-1/2*pi+2*temp;
        Ang3 = pi/2-1/2*pi+3*temp;
        Ang4 = pi/2-1/2*pi+4*temp;
        Ang5 = pi/2-1/2*pi+5*temp;
        Ang6 = pi/2-1/2*pi+6*temp;
        Ang7 = pi/2-1/2*pi+7*temp;
        Ang8 = pi/2-1/2*pi+8*temp;
        Ang = [Ang8,Ang7,Ang6,Ang5,Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4,Ang5,Ang6,Ang7,Ang8];

    case 9
        temp = 1/10*pi;
        Ang1 = pi/2-1/2*pi+temp;
        Ang2 = pi/2-1/2*pi+2*temp;
        Ang3 = pi/2-1/2*pi+3*temp;
        Ang4 = pi/2-1/2*pi+4*temp;
        Ang5 = pi/2-1/2*pi+5*temp;
        Ang6 = pi/2-1/2*pi+6*temp;
        Ang7 = pi/2-1/2*pi+7*temp;
        Ang8 = pi/2-1/2*pi+8*temp;
        Ang9 = pi/2-1/2*pi+9*temp;
        Ang = [Ang9,Ang8,Ang7,Ang6,Ang5,Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4,Ang5,Ang6,Ang7,Ang8,Ang9];
 
    case 10
        temp = 1/11*pi;
        Ang1 = pi/2-1/2*pi+temp;
        Ang2 = pi/2-1/2*pi+2*temp;
        Ang3 = pi/2-1/2*pi+3*temp;
        Ang4 = pi/2-1/2*pi+4*temp;
        Ang5 = pi/2-1/2*pi+5*temp;
        Ang6 = pi/2-1/2*pi+6*temp;
        Ang7 = pi/2-1/2*pi+7*temp;
        Ang8 = pi/2-1/2*pi+8*temp;
        Ang9 = pi/2-1/2*pi+9*temp;
        Ang10 = pi/2-1/2*pi+10*temp;
        Ang = [Ang10,Ang9,Ang8,Ang7,Ang6,Ang5,Ang4,Ang3,Ang2,Ang1,Ang1,Ang2,Ang3,Ang4,Ang5,Ang6,Ang7,Ang8,Ang9,Ang10];

    otherwise
        disp('other value')
end
Ang = Ang-pi/2;


end