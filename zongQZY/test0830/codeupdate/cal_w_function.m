%%��ѹ��������Ȩ��ϵ���ļ��㺯��
%t:�����߶ȣ�����
%g_k������ϵ��������
%N��������������
%k:��ͬ�㷨��kϵ��������
%w�������Ȩ��ϵ��������

function w = cal_w_function(t,g_k,N,k)

t_k = zeros(N-1,1);
w = zeros(N,1);
f = zeros(N,1);

    for i=1:N  
        count_tk = 1;
        for m=1:N
            if(m~=i)
            t_k(count_tk) =  t(m);
            count_tk = count_tk + 1;
            end
        end  

        for j=1:(N+1)/2
             f(j) = -sum(prod(nchoosek(t_k,(N+1-2*j)),2)); 
             w(i) = w(i) + g_k(j)*f(j);
        end

        mul = 1;
        for m=1:N
            if(m ~= i)
                mul = mul*(t(i) - t(m));
            end
        end
        w(i)=w(i)/((1-t(i)*t(i))^k * mul);    
    end
end