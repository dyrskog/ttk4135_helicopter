close all; clear;

% Load tests 
sims = {};
ouputs = {};
nx = 4;
nu = 1;
nq = 13;
states = {};


tests = {1};
N_tests = length(tests);


for i = 1:N_tests
    indx = tests{i}
    sim = load(strcat('simout/test', int2str(indx), '.mat'));
    sims{i} = sim.output.simout;
    outputs{i} = sim.output;
    disp(outputs{i}.Q_lqr(1,1));
end


% Trajectory w/o feedback
wofb = load('simout/q_12_0.mat');
wofb = wofb.simout;
wofb(:,2) = wofb(:,2) + pi;
i = i+1;
sims{i} = wofb

% Optimal trajectory q = 12
opt_trajectory = sims{1}(:,1:5);
i = i+1;
sims{i} = opt_trajectory;

N = min(cellfun('size',sims,1)); % Shortest simulation

for i = 1:nx+nu
    states{i} = zeros(N, N_tests+2);
end

for i = 1:N_tests+2
    if i <= N_tests
        sims{i} = sims{i}(1:N,6:10); % Make all simulations same length
    else
        sims{i} = sims{i}(1:N,:);
    end
    for j = 1:nx+nu
        states{j}(:,i) = sims{i}(:,j);
    end
end




% Plotting
delta_t = 0.002;
t = 0:delta_t:delta_t*(N-1);
figure('Position', [0 0 1400 1600]);
ylabels = {'$u$', '$\lambda$', '$r$', '$p$', '$\dot{p}$'};
for i = 1:nx+nu
    subplot(nx+nu,1,i)
    hold on;
    for j = 1:N_tests+2
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

% saveas(gcf, 'figures/lab2_q_compare_v3.svg');
