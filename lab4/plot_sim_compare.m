close all; clear;

% Load tests 
sims = {};
ouputs = {};
nx = 6;
nu = 2;
nq = 13;
states = {};


tests = {3};
N_tests = length(tests);

opt = load('simout/optimal_N15_q1.mat');
opt = opt.output;

opt2 = load('simout/optimal_N40_q1.mat');
opt2 = opt2.output;




t1 = 0:0.25:0.25*(length(opt)-1);
t2 = 0:0.25:0.25*(length(opt2)-1)

figure('Position', [0 0 1400 1600]);
ylabels = {'$u_1$', '$u_2$', '$\lambda$', '$r$', '$p$', '$\dot{p}$', '$e$', '$\dot{e}$'};
for i = 1:nx+nu
    subplot(nx+nu,1,i)
    hold on;

    % plot optimal
    if i < 3
        stairs(t1, opt(:,i), 'LineWidth', 1);
        stairs(t2, opt2(:,i), 'LineWidth', 1);
    else
        plot(t1, opt(:,i), 'LineWidth', 1);
        plot(t2, opt2(:,i), 'LineWidth', 1);
    end

    hold off;
    ylabel(ylabels{i}, 'Interpreter','latex', 'FontSize', 16);
    xlim([0 16]);
    grid;
end
xlabel('$t$', 'Interpreter', 'latex', 'FontSize', 16);
Lgnd = legend('N=15', 'N=40', '', 'Interpreter', 'latex', 'Fontsize', 12);
%Lgnd = legend('$q = 0.12$','$q = 1.20$', '$q = 12.0$', 'Interpreter', 'latex', 'Fontsize', 12);
Lgnd.Position(1) = 0.01;
Lgnd.Position(2) = 0.5;

testname = 'timehorizon_compare';
saveas(gcf, strcat('figures/lab4_', testname, '.svg'));