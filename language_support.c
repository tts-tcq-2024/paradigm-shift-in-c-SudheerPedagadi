#include "language_support.h"

// Global variable for language setting (0: English, 1: German)
extern int language;

const char* translateMessage(const char* message) {
    if (language == 1) { // German
        if (strcmp(message, "Temperature out of range!") == 0) return "Temperatur außerhalb des Bereichs!";
        if (strcmp(message, "State of Charge out of range!") == 0) return "Ladezustand außerhalb des Bereichs!";
        if (strcmp(message, "Charge Rate out of range!") == 0) return "Ladegeschwindigkeit außerhalb des Bereichs!";
        if (strcmp(message, "Approaching discharge") == 0) return "Nähern sich der Entladung";
        if (strcmp(message, "Approaching charge-peak") == 0) return "Nähern sich dem Lade-Peak";
    }
    // Default to English
    return message;
}
