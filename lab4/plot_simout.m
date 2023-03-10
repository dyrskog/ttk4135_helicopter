export = 1;
comment = "High Q values (1000)";

Ts = 0.002; % Quarc sample time

% x = [travel, travel rate, pitch, pitch rate]

u_opt = simout(:,1);
x1_opt = simout(:,2);
x2_opt = simout(:,3);
x3_opt = simout(:,4);
x4_opt = simout(:,5);

u = simout(:,6);
x1 = simout(:,7);
x2 = simout(:,8);
x3 = simout(:,9);
x4 = simout(:,10);

t = 0:Ts:Ts*(length(u)-1);

figure('Position', [0 0 1400 960])

subplot(511)
title('q = 12.0', 'FontSize', 12)
hold on;
stairs(t,u)
stairs(t, u_opt),grid
hold off;
ylabel('u')
xlim([0 30])

subplot(512)
hold on;
plot(t,x1),grid
plot(t,x1_opt)
hold off;
ylabel('lambda')
xlim([0 30])

subplot(513)
hold on;
plot(t,x2),grid
plot(t,x2_opt);
hold off;
ylabel('r')
xlim([0 30])

subplot(514)
hold on;
plot(t,x3),grid
plot(t,x3_opt)
hold off;
ylabel('p')
xlim([0 30])

subplot(515)
hold on;
plot(t,x4),grid
plot(t,x4_opt);
xlabel('time (s)'),ylabel('pdot')
xlim([0 30])
hold off;

Lgnd = legend('Helicopter','Reference');
Lgnd.Position(1) = 0.01;
Lgnd.Position(2) = 0.5;

%% Export simout
if export
    numOfTests = dir(['simout/*.mat']);
    test_nr = num2str(numel(numOfTests) + 1);
    output.legend = "u_opt, [x_opt], u, [x]";
    output.simout = simout;
    output.Q_lqr = Q_lqr;
    output.R_lqr = R_lqr;
    output.N = N;
    output.q = P1;
    output.comment = comment;
    save(strcat(['simout/test',test_nr,'.mat']), 'output');
end
