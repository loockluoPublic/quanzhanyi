classdef MyRectangle
%MYRECTANGLE Rectangle class

% Copyright 2021 The MathWorks, Inc.

    properties
        UpperLeft  (1,1) shapes.MyPosition
        LowerRight (1,1) shapes.MyPosition
    end
    methods
        function R = enlarge(R, n)
            arguments
                R (1,1) shapes.MyRectangle
                n (1,1) double {mustBeReal}
            end
            R.UpperLeft.X = R.UpperLeft.X - n;
            R.UpperLeft.Y = R.UpperLeft.Y - n;
            R.LowerRight.X = R.LowerRight.X + n;
            R.LowerRight.Y = R.LowerRight.Y + n;
        end
        function R = show(R)
            arguments
                R (1,1) shapes.MyRectangle
            end
            disp([R.UpperLeft.X R.UpperLeft.Y R.LowerRight.X R.LowerRight.Y]);
        end
    end
end
