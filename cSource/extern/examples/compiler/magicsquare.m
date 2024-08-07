function m = magicsquare(n)
%MAGICSQUARE generates a magic square matrix of the size specified
%    by the input parameter n.

% Copyright 2003-2021 The MathWorks, Inc.

if ischar(n)
    n=str2double(n);
end
m = magic(n);
disp(m)
