close all
clear all
clc

%% Prep work:
% TTK4135 - Helicopter lab
% Hints/template for problem 2.
% Updated spring 2018, Andreas L. Fl�ten

%% Initialization and model definition
init08; 
template_problem_2;

%% discrete LQR - 10.3:
v = 100*[10 10 10 10]; % Different Q values
Q_lqr = diag(v); 
R_lqr = 1;

[K_lqr,S,e] = dlqr(A1,B1,Q_lqr,R_lqr);