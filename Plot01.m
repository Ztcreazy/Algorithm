clear;close all;clc

fig = uifigure('Position', [100 100 300 150]);
startLabel = uilabel(fig, 'Position', [50 100 100 22], 'Text', 'Start Time:');
startField = uieditfield(fig, 'numeric', 'Position', [150 100 100 22]);
endLabel = uilabel(fig, 'Position', [50 50 100 22], 'Text', 'End Time:');
endField = uieditfield(fig, 'numeric', 'Position', [150 50 100 22]);
button = uibutton(fig, 'Position', [100 10 100 22], 'Text', 'Plot', 'ButtonPushedFcn', @(btn,event) plotData(startField.Value, endField.Value));

function plotData(startTime, endTime)
    t = linspace(startTime, endTime, 1000);
    % lambda
    lambda = @(t) 5*sin(2*pi*t);

    % h(t)
    h = @(t) 3*pi*exp(-lambda(t));

    % Plot h(t) 
    for i = 1:length(t)
        plot(t(1:i), h(t(1:i)));
        title('Plot of h(t) as a function of time');
        xlabel('Time (s)');
        ylabel('h(t)');
        grid on
        drawnow;
    end
end