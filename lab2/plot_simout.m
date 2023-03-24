close all; clear;

testname = 'q_12_0';
titlestring = '$q = 12.0$';

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

ylabels = {'$u$', '$\lambda$', '$r$', '$p$', '$\dot{p}$'};

figure('Position', [0 0 1400 1600]);

for i = 1:5
    subplot(5,1,i);
    
    hold on
    for j = 1:2
        if i == 1
            plot(t, simout(:,i), 'b', 'LineWidth', 1);
            stairs(t_opt, opt(:,i), 'r', 'Linewidth', 1);
            title(titlestring, 'Interpreter', 'latex', 'FontSize', 16);
        elseif i == 2
            plot(t, simout(:,i)+pi, 'b', 'Linewidth', 1);
            plot(t_opt, opt(:,i), 'r--o', 'LineWidth', 1);
        else
            plot(t, simout(:,i), 'b', 'LineWidth', 1);
            plot(t_opt, opt(:,i), 'r--o', 'LineWidth', 1);
        end
    end
    hold off
    xlim([0 18]);
    ylabel(ylabels{i}, 'Interpreter','latex', 'FontSize', 16);
    grid;
end
xlabel('$t$', 'Interpreter', 'latex', 'FontSize', 16);
Lgnd = legend('Helicopter','Reference', 'FontSize', 10);
Lgnd.Position(1) = 0.01;
Lgnd.Position(2) = 0.5;



saveas(gcf, strcat('figures/lab2_', testname, '.svg'));