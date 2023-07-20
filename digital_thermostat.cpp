#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants for temperature range and control parameters
const float MIN_TEMPERATURE = 10.0;
const float MAX_TEMPERATURE = 30.0;
const float DEFAULT_DESIRED_TEMPERATURE = 20.0;
const float COOLING_THRESHOLD = 1.0;
const float HEATING_THRESHOLD = 1.0;


const float Kp = 0.5; 
const float Ki = 0.1; 
const float Kd = 0.2; 
const float dt = 1.0;

// Function to generate random temperature readings
float generateRandomTemperature() {
    return MIN_TEMPERATURE + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (MAX_TEMPERATURE - MIN_TEMPERATURE)));
}

// Function to update the state of the heating or cooling system using PID control
void updateHeatingCoolingStatePID(float currentTemperature, float desiredTemperature, bool& heatingSystemOn, bool& coolingSystemOn,
                                  float& integralSum, float& previousError) {
    float error = desiredTemperature - currentTemperature;
    integralSum += error * dt;
    float derivative = (error - previousError) / dt;

    float controlValue = Kp * error + Ki * integralSum + Kd * derivative;

    if (controlValue > 0) {
        heatingSystemOn = true;
        coolingSystemOn = false;
    } else {
        heatingSystemOn = false;
        coolingSystemOn = true;
    }

    previousError = error;
}

int main() {
    
    srand(static_cast<unsigned>(time(0)));

    float currentTemperature = DEFAULT_DESIRED_TEMPERATURE;
    float desiredTemperature = DEFAULT_DESIRED_TEMPERATURE;
    float integralSum = 0.0;
    float previousError = 0.0;
    bool heatingSystemOn = false;
    bool coolingSystemOn = false;

    cout << "Welcome to the Digital Thermostat System!\n";

    while (true) {
       
        cout << "Enter the desired temperature (between " << MIN_TEMPERATURE << " and " << MAX_TEMPERATURE << "): ";
        cin >> desiredTemperature;

        // Ensure the desired temperature is within the valid range
        desiredTemperature = max(MIN_TEMPERATURE, min(MAX_TEMPERATURE, desiredTemperature));

        
        currentTemperature = generateRandomTemperature();
        updateHeatingCoolingStatePID(currentTemperature, desiredTemperature, heatingSystemOn, coolingSystemOn, integralSum, previousError);

        // Display current status
        cout << "Current Temperature: " << currentTemperature << " C\n";
        cout << "Desired Temperature: " << desiredTemperature << " C\n";
        cout << "Heating System: " << (heatingSystemOn ? "ON" : "OFF") << "\n";
        cout << "Cooling System: " << (coolingSystemOn ? "ON" : "OFF") << "\n";

       
        for (int i = 0; i < 10000000; i++) {
            // Just adding some delay
        }

       
    }

    return 0;
}
