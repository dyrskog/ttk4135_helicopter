close all; clear;

% Load tests 
sims = {};
ouputs = {};
nx = 6;
nu = 2;
nq = 13;
states = {};


tests = {1,3,6};
N_tests = length(tests);


for i = 1:N_tests
    indx = tests{i};
    sim = load(strcat('simout/test', int2str(indx), '.mat'));
    sims{i} = sim.output.simout;
    outputs{i} = sim.output;
    disp(sim.output.comment);
end

N = min(cellfun('size',sims,1)); % Shortest simulation

for i = 1:nx+nu
    states{i} = zeros(N, N_tests);
end

% simout: [u_opt(1:2), xopt(3:8), u(9:10), x(11:16)]
for i = 1:N_tests
    for j = 1:nx+nu
        states{j}(:,i) = sims{i}(1:N,j);
    end
end


% Plotting
delta_t = 0.002;
t = 0:delta_t:delta_t*(N-1);
figure('Position', [0 0 1400 1600]);
ylabels = {'$u_1$', '$u_2$', '$\lambda$', '$r$', '$p$', '$\dot{p}$', '$e$', '$\dot{e}$'};
for i = 1:nx+nu
    subplot(nx+nu,1,i)
    hold on;
    for j = 1:N_tests
        if i < 3
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