# Digital Thermostat System using PID Control

The Digital Thermostat System is a simple simulation of a thermostat that uses Proportional-Integral-Derivative (PID) control to maintain the desired temperature. The system continuously reads the current temperature, takes input from the user for the desired temperature, and adjusts the heating or cooling system accordingly to reach and maintain the desired temperature.

## Table of Contents

1\. [Introduction](#introduction)

2\. [Requirements](#requirements)

3\. [Usage](#usage)

4\. [Constants and Control Parameters](#constants-and-control-parameters)

5\. [PID Control](#pid-control)

6\. [Random Temperature Generation](#random-temperature-generation)

7\. [User Interaction](#user-interaction)

8\. [Delay](#delay)

9\. [Conclusion](#conclusion)

## Introduction

This project aims to provide a basic implementation of a digital thermostat system using C++. The system operates in a loop, allowing users to set their desired temperature and observe how the system regulates the actual temperature to match the desired one. The PID control algorithm is used to efficiently control the heating and cooling systems and minimize temperature deviations.

## Requirements

To run this project, you need:

- A C++ compiler that supports C++11 or later.

- Standard C++ libraries.

- A terminal or command prompt to run the compiled executable.

## Usage

1\. Clone or download the project's source code from the repository.

2\. Compile the code using a C++ compiler.

3\. Run the compiled executable.

4\. The program will prompt you to enter the desired temperature. Input a temperature value between the specified minimum and maximum temperature range.

5\. Observe the system's behavior as it continuously updates the current temperature and adjusts the heating or cooling system using PID control.

## Constants and Control Parameters

The project uses several constants and control parameters to determine its behavior:

- `MIN_TEMPERATURE` and `MAX_TEMPERATURE`: Define the minimum and maximum temperature range that the system can maintain.

- `DEFAULT_DESIRED_TEMPERATURE`: Sets the initial desired temperature to 20.0 degrees Celsius.

- `COOLING_THRESHOLD` and `HEATING_THRESHOLD`: Define the thresholds for cooling and heating control. If the error is greater than these thresholds, the corresponding system will be turned on.

## PID Control

PID control is a widely used control algorithm in various applications, including temperature regulation. The PID control parameters used in this project are:

- `Kp`: Proportional gain - A coefficient for the proportional control term.

- `Ki`: Integral gain - A coefficient for the integral control term.

- `Kd`: Derivative gain - A coefficient for the derivative control term.

- `dt`: Time step for the derivative term - Used to calculate the derivative of the error.

The PID control algorithm calculates the control value based on the error (difference between desired and current temperature), integral of the error, and derivative of the error. The control value is then used to determine whether the heating or cooling system needs to be turned on.

## Random Temperature Generation

The function `generateRandomTemperature()` is used to simulate random temperature readings within the specified temperature range. This function utilizes the `rand()` function and adjusts the generated value to fall within the valid temperature range.

## User Interaction

The program interacts with the user by prompting them to input the desired temperature. The user can enter a temperature value, and the program ensures that the desired temperature is within the valid range.

## Delay

A delay loop is included after displaying the current status to slow down the program's execution and provide better readability. The delay does not affect the thermostat's functionality and is solely for demonstration purposes.

## Conclusion

The Digital Thermostat System demonstrates a basic implementation of PID control for temperature regulation. It simulates a thermostat system that continuously updates the current temperature and uses PID control to maintain the desired temperature. Users can interact with the system by setting their desired temperature and observing how the heating and cooling systems respond to reach and maintain the desired temperature. The project can serve as a starting point for more sophisticated thermostat control systems in real-world applications.
