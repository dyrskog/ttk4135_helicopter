% TTK4135 - Helicopter lab
% Hints/template for problem 2.
% Updated spring 2018, Andreas L. Fl�ten

%% Initialization and model definition
init08; % Change this to the init file corresponding to your helicopter
global N;

A = [ 0   1       0         0             0         0;
      0   0     -K_2        0             0         0;
      0   0       0         1             0         0;
      0   0 -K_1*K_pp   -K_1*K_pd         0         0;
      0   0       0         0             0         1;
      0   0       0         0         -K_3*K_ep   -K_3*K_ed];


B = [ 0 0 0 K_1*K_pp  0     0;
      0 0 0   0       0 K_3*K_ep]';

% Discrete time system model. x = [lambda r p p_dot e e_dot]'
delta_t	= 0.25; % sampling time
A1 = eye(length(A)) + A*delta_t;
B1 = B*delta_t;

% Number of states and inputs
mx = size(A1,2); % Number of states (number of columns in A)
mu = size(B1,2); % Number of inputs(number of columns in B)

% Initial values
x1_0 = pi;                              % Lambda
x2_0 = 0;                               % r
x3_0 = 0;                               % p
x4_0 = 0;                               % p_dot
x5_0 = 0;                               % e
x6_0 = 0;                               % e_dot
x0 = [x1_0 x2_0 x3_0 x4_0 x5_0 x6_0]';           % Initial values

% Time horizon and initialization
N  = 15;                                  % Time horizon for states
M  = N;                                 % Time horizon for inputs
z  = zeros(N*mx+M*mu,1);                % Initialize z for the whole horizon
z0 = z;                                 % Initial value for optimization

z0(1) = pi;

% Bounds
ul 	    = [-pi/6; -inf];                   % Lower bound on control
uu 	    = [pi/6; inf];                   % Upper bound on control

xl      = -Inf*ones(mx,1);              % Lower bound on states (no bound)
xu      = Inf*ones(mx,1);               % Upper bound on states (no bound)
xl(3)   = ul(1);                           % Lower bound on state x3
xu(3)   = uu(1);                           % Upper bound on state x3

% Generate constraints on measurements and inputs
[vlb,vub]       = gen_constraints(N,M,xl,xu,ul,uu); % hint: gen_constraints
vlb(N*mx+M*mu)  = 0;                    % We want the last input to be zero
vub(N*mx+M*mu)  = 0;                    % We want the last input to be zero

% Generate the matrix Q and the vector c (objecitve function weights in the QP problem) 
Q1 = zeros(mx,mx);
Q1(1,1) = 1;                            % Weight on state x1
Q1(2,2) = 0;                            % Weight on state x2
Q1(3,3) = 0;                            % Weight on state x3
Q1(4,4) = 0;                            % Weight on state x4
Q1(5,5) = 0;
Q1(6,6) = 0;
P1 = 1;                                % Weight on input
P2 = 1;
P = diag([P1 P2]);
Q = gen_q(Q1,P,N,M);                                  % Generate Q, hint: gen_q

%% Generate system matrixes for linear model
Aeq = gen_aeq(A1,B1,N,mx,mu);             % Generate A, hint: gen_aeq
beq = [A1*x0; zeros(height(Aeq)-height(x0), 1)];             % Generate b

phi = @(z) z'*Q*z;

opts = optimoptions('fmincon', 'Algorithm', 'sqp', 'MaxFunctionEvaluations', 5e4, 'Display', 'iter');

z = fmincon(phi, z0, [], [], Aeq, beq, vlb, vub, @nonlcon, opts);

%% Extract control inputs and states
%u  = [z(N*mx+1:N*mx+M*mu);z(N*mx+M*mu)]; % Control input from solution
u1 = [z(N*mx+1:mu:N*mx+M*mu); z(N*mx+M*mu - 1)];
u2 = [z(N*mx+2:mu:N*mx+M*mu); z(N*mx+M*mu)];
x1 = [x0(1);z(1:mx:N*mx)];              % State x1 from solution
x2 = [x0(2);z(2:mx:N*mx)];              % State x2 from solution
x3 = [x0(3);z(3:mx:N*mx)];              % State x3 from solution
x4 = [x0(4);z(4:mx:N*mx)];              % State x4 from solution
x5 = [x0(5);z(5:mx:N*mx)];              % State x4 from solution
x6 = [x0(6);z(6:mx:N*mx)];              % State x4 from solution

num_variables = 5/delta_t;
zero_padding = zeros(num_variables,1);
unit_padding  = ones(num_variables,1);

u1  = [zero_padding; u1; zero_padding];
u2  = [zero_padding; u2; zero_padding];
x1  = [pi*unit_padding; x1; zero_padding];
x2  = [zero_padding; x2; zero_padding];
x3  = [zero_padding; x3; zero_padding];
x4  = [zero_padding; x4; zero_padding];
x5  = [zero_padding; x5; zero_padding];
x6  = [zero_padding; x6; zero_padding];

opt_trajectory = [u1 u2 x1 x2 x3 x4 x5 x6];

%% Plotting
t = 0:delta_t:delta_t*(length(u1)-1);

figure(3)
subplot(4,2,1),stairs(t,u1),grid,ylabel('u - pitch')
subplot(4,2,2),stairs(t,u2),grid,ylabel('u - elev')
subplot(4,2,3),plot(t,x1','-mo'),grid,ylabel('travel')
subplot(4,2,4),plot(t,x2,'-mo'),grid,ylabel('r')
subplot(4,2,5),plot(t,x3','-mo'),grid,ylabel('pitch')
subplot(4,2,6),plot(t,x4','-mo'),grid,ylabel('pdot')
subplot(4,2,7),plot(t,x5','-mo'),grid,xlabel('tid (s)'),ylabel('elevation')
subplot(4,2,8),plot(t,x6','-mo'),grid,xlabel('tid (s)'),ylabel('elev rate')

%% Simulink transfer
opt_u.time = t';
opt_u.signals.values = opt_trajectory; 

function [ c, ceq ] = nonlcon(z)
  global N
  mx = 6;
  alpha = 0.2;
  beta = 20;
  lambda_t = 2*pi/3;
  c = zeros(N,1);
  for k = 1:mx:N*mx
      lambda_k = z(k);
      e_k = z(k+4);
      c(k) = alpha*exp(-beta*(lambda_k - lambda_t)'*(lambda_k - lambda_t)) - e_k;
  end
  ceq = [];
end