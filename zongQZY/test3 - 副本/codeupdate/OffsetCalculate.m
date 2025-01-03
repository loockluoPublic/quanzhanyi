function OffsetOut=OffsetCalculate(Mradial,phi,Ang,a)

temp = asin(Mradial.*sin(Ang)./(Mradial-a))-Ang;
roff = 2*pi.*Mradial./360*temp/pi*180;
toff = (Mradial.*cos(Ang)-(Mradial-a).*cos(temp+Ang))./tan(phi);

OffsetOut = [roff;toff];
OffsetOut(isnan(OffsetOut)) = 0;

end