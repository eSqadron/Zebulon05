syms O_i A_i ai di
syms O1 O2 O3 a1 a2 a3 h1

H_n = [cos(O_i), -sin(O_i) * cos(A_i),  sin(O_i) * sin(A_i),  ai * cos(O_i);
       sin(O_i),  cos(O_i) * cos(A_i), -cos(O_i) * sin(A_i), ai * sin(O_i);
       0       ,  sin(A_i)           ,             cos(A_i), di;
       0       , 0                   , 0                   , 1;
       ]
   
   
H1 = subs(H_n, [O_i, A_i, ai, di], [O1, pi/2, a1, h1])
H2 = subs(H_n, [O_i, A_i, ai, di], [O2, 0, a2, 0])
H3 = subs(H_n, [O_i, A_i, ai, di], [O3, 0, a3, 0])

H1*H2*H3