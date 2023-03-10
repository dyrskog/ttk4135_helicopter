export = 1;
comment = "Time horizon increased yet again, N=100";

Ts = 0.002; % Quarc sample time

% x = [travel, travel rate, pitch, pitch rate]

u1_opt = simout(:,1);
u2_opt = simout(:,2);
x1_opt = simout(:,3);
x2_opt = simout(:,4);
x3_opt = simout(:,5);
x4_opt = simout(:,6);
x5_opt = simout(:,7);
x6_opt = simout(:,8);


u1 = simout(:,9);
u2 = simout(:,10);
x1 = simout(:,11);
x2 = simout(:,12);
x3 = simout(:,13);
x4 = simout(:,14);
x5 = simout(:,15);
x6 = simout(:,16);


t = 0:Ts:Ts*(length(u1)-1);

figure('Position', [0 0 1400 960])
subplot(4,2,1);
hold on;
stairs(t,u1);
stairs(t,u1_opt);
grid,ylabel('u - pitch');

subplot(4,2,2);
hold on;
stairs(t,u2);
stairs(t,u2_opt);
grid,ylabel('u - elev');

subplot(4,2,3);
hold on;
plot(t,x1');
plot(t,x1_opt');
grid,ylabel('travel');

subplot(4,2,4);
hold on;
plot(t,x2);
plot(t,x2_opt);
grid,ylabel('r')

subplot(4,2,5);
hold on;
plot(t,x3');
plot(t,x3_opt');
grid,ylabel('pitch');

subplot(4,2,6);
hold on;
plot(t,x4');
plot(t,x4_opt');
grid,ylabel('pdot')

subplot(4,2,7);
hold on;
plot(t,x5');
plot(t,x5_opt');
grid,xlabel('tid (s)'),ylabel('elevation')

subplot(4,2,8);
hold on;
plot(t,x6');
plot(t,x6_opt');
hold off;
grid,xlabel('tid (s)'),ylabel('elev rate')

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
    output.q = P;
    output.comment = comment;
    save(strcat(['simout/test',test_nr,'.mat']), 'output');
end
