function r = calculatearea(rect)
%CALCULATE Calculate the area of a rectangle

% Copyright 2021 The MathWorks, Inc.

arguments
    rect (1,1) shapes.MyRectangle
end

    r = (rect.LowerRight.Y - rect.UpperLeft.Y) * (rect.LowerRight.X - rect.UpperLeft.X);
end