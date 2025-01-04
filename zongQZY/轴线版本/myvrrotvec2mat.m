function m = myvrrotvec2mat(r)
epsilon = 1e-12;
s = sin(r(4));
c = cos(r(4));
t = 1 - c;

n = sl3dnormalize(r(1:3), epsilon);

x = n(1);
y = n(2);
z = n(3);
m = [ ...
    t*x*x + c,    t*x*y - s*z,  t*x*z + s*y; ...
    t*x*y + s*z,  t*y*y + c,    t*y*z - s*x; ...
    t*x*z - s*y,  t*y*z + s*x,  t*z*z + c ...
    ];
end

function vec_n = sl3dnormalize(vec, maxzero)
%SL3DNORMALIZE Normalize a vector.
%   Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the
%   input vector X. Input X can be vector of any size. If the modulus of
%   the input vector is <= MAXZERO, the output is set to zeros(size(X)).
%
%   Not to be called directly.

%   Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc.

norm_vec = norm(vec);
if (norm_vec <= maxzero)
    vec_n = zeros(size(vec));
else
    vec_n = vec ./ norm_vec;
end
end