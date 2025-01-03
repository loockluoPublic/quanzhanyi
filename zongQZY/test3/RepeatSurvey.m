function [SoundAngle,SoundLength] = RepeatSurvey(SoundPoint1,SoundPoint2,Bottom_round_center1,Bottom_round_center2)
    vec1 = Bottom_round_center2-Bottom_round_center1;
    vec2 = SoundPoint2 - SoundPoint1;
    SoundLength = norm(vec2);
    SoundAngle = acos(dot(vec1,vec2)./norm(vec2)./norm(vec1));
end
