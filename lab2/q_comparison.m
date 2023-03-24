close all; clear;

% Load tests 
sims = {};
nx = 4;
nu = 1;
nq = 3;
states = {};
filenames = {'q_0_12_optimal', 'q_1_20_optimal', 'q_12_0_optimal'};

for i = 1:length(filenames)
    sim = load(strcat('simout/', filenames{i}, '.mat'));
    sims{i} = sim.opt_trajectory;
end

N = length(sims{1}(:,1));
for i = 1:nx+nu
    states{i} = zeros(N, nq);
end

for i = 1:nq
    for j = 1:nx+nu
        states{j}(:,i) = sims{i}(:,j);
    end
end

% Plotting
delta_t = 0.25;
t = 0:delta_t:delta_t*(N-1);
figure('Position', [0 0 1400 1600]);
ylabels = {'$u$', '$\lambda$', '$r$', '$p$', '$\dot{p}$'};
for i = 1:nx+nu
    subplot(nx+nu,1,i)
    hold on;
    for j = 1:nq
        if i == 1
            stairs(t, states{i}(:,j), 'LineWidth', 1.5)
        
        else
            plot(t, states{i}(:,j), '--o', 'LineWidth', 1);
        end
    end
    hold off;
    ylabel(ylabels{i}, 'Interpreter','latex', 'FontSize', 16);
    xlim([0 20]);
    grid;
end
xlabel('$t$', 'Interpreter', 'latex', 'FontSize', 16);
Lgnd = legend('$q = 0.12$','$q = 1.20$', '$q = 12.0$', 'Interpreter', 'latex', 'Fontsize', 12);
Lgnd.Position(1) = 0.01;
Lgnd.Position(2) = 0.5;

saveas(gcf, 'figures/lab2_q_compare_v3.svg');
