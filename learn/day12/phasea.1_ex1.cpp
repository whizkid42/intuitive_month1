#include <iostream>

bool tryReadSensor(const int readings[], int size, int maxRetries) {
    int attempts = 0;
    for (int i = 0; i < size && attempts < maxRetries; ++i) {
        ++attempts;
        if (readings[i] >= 0) { 
            return true;
        } 
    }
    return false;
}

int main() {
    const int sensorReadings[] = { -1, -1, 2, -1, 2 }; // Simulated sensor readings
    bool ok = tryReadSensor(sensorReadings, 5, 3);
    return ok ? 0 : 1;
}