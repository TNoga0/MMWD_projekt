close all;
clear all;

x=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51];
y=[1735950,
1976650,
1972700,
2449000,
2417700,
2490350,
2417700,
2490350,
2417700,
2490350,
2417700,
2381050,
2333000,
2381050,
2333000,
2381050,
2333000,
2381050,
2333000,
2381050,
2333000,
2381050,
2417700,
2490700,
2239650,
2338500,
2294150,
2345250,
2294150,
2345250,
2294150,
2345250,
2336150,
2356250,
2341150,
2356250,
2341150,
2356250,
2341150,
2356250,
2491300,
2491300,
2491300,
2491300,
2491300,
2491300,
2491300,
2491300,
2491300,
2491300,
2491300],

figure(1)
plot(x,y);
hold on;
grid on;
title('Nasza F Celu:');

%axis([0 2 -0.3 1.5]);
xlabel( 'Iteracja:' );
ylabel( 'F Celu:' );

