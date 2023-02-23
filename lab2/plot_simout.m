close all; clear;

testname = 'q_12_0';

lab = load(strcat('simout/', testname, '.mat'));
simout = lab.simout;
opt = load(strcat('simout/', testname, '_optimal.mat'));
opt = opt.opt_trajectory;

Ts = 0.002; % Quarc sample time
sim_Ts = 0.25; % Optimal simulation sample time

% x = [travel, travel rate, pitch, pitch rate]

u = simout(:,1);
x1 = simout(:,2);
x2 = simout(:,3);
x3 = simout(:,4);
x4 = simout(:,5);

u_opt = opt(:,1);
x1_opt = opt(:,2);
x2_opt = opt(:,3);
x3_opt = opt(:,4);
x4_opt = opt(:,5);

t = 0:Ts:Ts*(length(u)-1);
t_opt = 0:sim_Ts:sim_Ts*(length(u_opt)-1);


figure('Position', [0 0 1400 960])

subplot(511)
title('q = 12.0', 'FontSize', 12)
hold on;
stairs(t,u)
stairs(t_opt, u_opt),grid
hold off;
ylabel('u')
xlim([0 20])

subplot(512)
hold on;
plot(t,x1+pi),grid
plot(t_opt,x1_opt)
hold off;
ylabel('lambda')
xlim([0 20])

subplot(513)
hold on;
plot(t,x2),grid
plot(t_opt,x2_opt);
hold off;
ylabel('r')
xlim([0 20])

subplot(514)
hold on;
plot(t,x3),grid
plot(t_opt,x3_opt)
hold off;
ylabel('p')
xlim([0 20])

subplot(515)
hold on;
plot(t,x4),grid
plot(t_opt,x4_opt);
xlabel('time (s)'),ylabel('pdot')
xlim([0 20])
hold off;

Lgnd = legend('Helicopter','Reference');
Lgnd.Position(1) = 0.01;
Lgnd.Position(2) = 0.5;
