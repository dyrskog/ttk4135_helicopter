close all; clear;

% Load tests 
sims = {};
ouputs = {};
nx = 4;
nu = 1;
nq = 13;
states = {};


tests = {1, 3, 11};
N_tests = length(tests);


for i = 1:N_tests
    indx = tests{i}
    sim = load(strcat('simout/test', int2str(indx), '.mat'));
    sims{i} = sim.output.simout;
    outputs{i} = sim.output;
    disp(outputs{i}.Q_lqr(1,1));
end



% Plotting
delta_t = 0.002;
t = 0:delta_t:delta_t*(N-1);
figure('Position', [0 0 1400 1600]);
ylabels = {'$u$', '$\lambda$', '$r$', '$p$', '$\dot{p}$'};
for i = 1:nx+nu
    subplot(nx+nu,1,i)
    hold on;
    for j = 1:N_tests
        if i == 1
            stairs(t, states{i}(:,j), 'LineWidth', 1.5)
        
        else
            plot(t, states{i}(:,j), 'LineWidth', 1.5);
        end
    end
    hold off;
    ylabel(ylabels{i}, 'Interpreter','latex', 'FontSize', 16);
    xlim([0 17]);
    grid;
end
xlabel('$t$', 'Interpreter', 'latex', 'FontSize', 16);
Lgnd = legend('Feedback', 'Open loop', 'Optimal', 'Interpreter', 'latex', 'Fontsize', 12);
%Lgnd = legend('$q = 0.12$','$q = 1.20$', '$q = 12.0$', 'Interpreter', 'latex', 'Fontsize', 12);
Lgnd.Position(1) = 0.01;
Lgnd.Position(2) = 0.5;