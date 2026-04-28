#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


// Global Variables
int currentAdminID = -1,
currentPatientID = -1,
patientsCount = 2,
doctorsCount = 3,
appointmentsCount = 0,
adminsCount = 1;
const int maxPatientsCount = 50, maxDoctorsCount = 20, maxAppointmentsCount = 100, maxAdminsCount = 2;


// Structs
struct Date {
    string day;
    string month;
    string year;
};
struct Time {
    string hours;
    string minutes;
    string timePeriod;
};
struct Patient {
    int    patientID;
    string name;
    string password;
    string phoneNumber;
    int    age;
};
struct Doctor {
    int doctorID;
    string name;
    string specialization;
    int availableSlots;
    int consultationFee;
};
struct Appointment {
    int appointmentID;
    int patientID;
    int doctorID;
    Date appointmentDate;
    Time appointmentTime;
    string status;
    int totalCost;
};
struct Admin {
    int adminID;
    string name;
    string password;
};


// Arrays
Patient patients[maxPatientsCount];
Doctor doctors[maxDoctorsCount];
Appointment appointments[maxAppointmentsCount];
Admin admins[maxAdminsCount];


// Functions Declarations
void loadData();
void chooseAdminOrPatient(bool isRedirect);
void terminateTheProgram();
void viewDoctors(bool isRedirect);
void adminLogin();
void adminDashboard();
void addDoctor();
void removeDoctor();
void editConsultationFee();
void viewAllAppointments();
void markAppointmentAsCompleted();
void adminLogout();
void patientLoginOrSignUp();
void patientSignUp();
void patientLogin();
void patientDashboard();
void bookAppointment();
void cancelAppointment();
void viewAppointments();
void patientLogout();
void space();
void updateAppointmentStatus(Appointment* appointment, string newStatus);
void readValidInt(string prompt, int& value, int min, int max);
bool isArrayFull(int count, int maxSize);
bool hasDoctorTimeConflict(int doctorID, Date date, Time time);
bool hasPatientTimeConflict(int patientID, Date date, Time time);
bool isValidPassword(string password);
bool isValidPhoneNumber(string phone);
int calculateTotalCost(int doctorID);
int findPatientIndex(int id);
int findDoctorIndex(int id);
int findAppointmentIndex(int id);
string formatDate(Date date);
string formatTime(Time time);


// Main
int main() {
    loadData();
    chooseAdminOrPatient(false);
    return 0;
}


// Helper Function Definitions
void space() {
    cout << "\n" << string(40, '-') << "\n";
}
void updateAppointmentStatus(Appointment* appointment, string newStatus) {
    appointment->status = newStatus;
}
void readValidInt(string prompt, int& value, int min, int max) {
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
        else if (value < min || value > max) {
            cin.ignore();
            cout << "Please enter a number between " << min << " and " << max << ".\n";
        }
        else {
            cin.ignore();
            break;
        }
    }
}
bool isArrayFull(int count, int maxSize) {
    return count >= maxSize;
}
bool hasDoctorTimeConflict(int doctorID, Date date, Time time) {
    for (int i = 0; i < appointmentsCount; i++) {
        if (appointments[i].doctorID == doctorID &&
            appointments[i].status == "Booked" &&
            appointments[i].appointmentDate.day == date.day &&
            appointments[i].appointmentDate.month == date.month &&
            appointments[i].appointmentDate.year == date.year &&
            appointments[i].appointmentTime.hours == time.hours &&
            appointments[i].appointmentTime.minutes == time.minutes &&
            appointments[i].appointmentTime.timePeriod == time.timePeriod) {
            return true;
        }
    }
    return false;
}
bool hasPatientTimeConflict(int patientID, Date date, Time time) {
    for (int i = 0; i < appointmentsCount; i++) {
        if (appointments[i].patientID == patientID &&
            appointments[i].status == "Booked" &&
            appointments[i].appointmentDate.day == date.day &&
            appointments[i].appointmentDate.month == date.month &&
            appointments[i].appointmentDate.year == date.year &&
            appointments[i].appointmentTime.hours == time.hours &&
            appointments[i].appointmentTime.minutes == time.minutes &&
            appointments[i].appointmentTime.timePeriod == time.timePeriod) {
            return true;
        }
    }
    return false;
}
bool isValidPassword(string password) {
    return password.length() >= 6;
}
bool isValidPhoneNumber(string phone) {
    if (phone.empty()) return false;
    for (int i = 0; i < phone.length(); i++) {
        if (!isdigit(phone[i])) return false;
    }
    return true;
}
int calculateTotalCost(int doctorID) {
    int idx = findDoctorIndex(doctorID);
    if (idx == -1) return 0;
    return doctors[idx].consultationFee;
}
int findPatientIndex(int id) {
    for (int i = 0; i < patientsCount; i++) {
        if (patients[i].patientID == id) return i;
    }
    return -1;
}
int findDoctorIndex(int id) {
    for (int i = 0; i < doctorsCount; i++) {
        if (doctors[i].doctorID == id) return i;
    }
    return -1;
}
int findAppointmentIndex(int id) {
    for (int i = 0; i < appointmentsCount; i++) {
        if (appointments[i].appointmentID == id) return i;
    }
    return -1;
}
string formatDate(Date date) {
    return date.day + "/" + date.month + "/" + date.year;
}
string formatTime(Time time) {
    return time.hours + ":" + time.minutes + " " + time.timePeriod;
}


// Redirecting Function Definitions
void loadData() {

    // Data for the first run
    patients[0] = { 1001, "Ahmed Hassan",  "pass123",  "01012345678", 24 };
    patients[1] = { 1002, "Mona Samir",    "secure99", "01198765432", 31 };
    doctors[0] = { 5821, "Dr. Khaled Nour",  "Cardiology",  10, 300 };
    doctors[1] = { 9374, "Dr. Sara Mansour", "Dermatology",  6, 250 };
    doctors[2] = { 6610, "Dr. Tariq Farouk", "Orthopedics",  8, 400 };
    admins[0] = { 9999, "Admin", "admin123" };


    // Creating/Opening the file
    ifstream file("data.txt");
    if (!file.is_open()) return;


    // Filling patients data
    file >> patientsCount;
    file.ignore();
    for (int i = 0; i < patientsCount; i++) {
        file >> patients[i].patientID;
        file.ignore();
        getline(file, patients[i].name);
        getline(file, patients[i].password);
        getline(file, patients[i].phoneNumber);
        file >> patients[i].age;
        file.ignore();
    }


    // Filling doctors data
    file >> doctorsCount;
    file.ignore();
    for (int i = 0; i < doctorsCount; i++) {
        file >> doctors[i].doctorID;
        file.ignore();
        getline(file, doctors[i].name);
        getline(file, doctors[i].specialization);
        file >> doctors[i].availableSlots;
        file >> doctors[i].consultationFee;
        file.ignore();
    }


    // Filling appointments data
    file >> appointmentsCount;
    file.ignore();
    for (int i = 0; i < appointmentsCount; i++) {
        file >> appointments[i].appointmentID;
        file >> appointments[i].patientID;
        file >> appointments[i].doctorID;
        file.ignore();
        getline(file, appointments[i].appointmentDate.day);
        getline(file, appointments[i].appointmentDate.month);
        getline(file, appointments[i].appointmentDate.year);
        getline(file, appointments[i].appointmentTime.hours);
        getline(file, appointments[i].appointmentTime.minutes);
        getline(file, appointments[i].appointmentTime.timePeriod);
        getline(file, appointments[i].status);
        file >> appointments[i].totalCost;
        file.ignore();
    }


    // Filling admins data
    file >> adminsCount;
    file.ignore();
    for (int i = 0; i < adminsCount; i++) {
        file >> admins[i].adminID;
        file.ignore();
        getline(file, admins[i].name);
        getline(file, admins[i].password);
    }


    // Closing the file
    file.close();

}
void terminateTheProgram() {

    // Accessing the file
    ofstream file("data.txt");


    // Pasting patients data
    file << patientsCount << "\n";
    for (int i = 0; i < patientsCount; i++) {
        file << patients[i].patientID << "\n"
            << patients[i].name << "\n"
            << patients[i].password << "\n"
            << patients[i].phoneNumber << "\n"
            << patients[i].age << "\n";
    }


    // Pasting doctors data
    file << doctorsCount << "\n";
    for (int i = 0; i < doctorsCount; i++) {
        file << doctors[i].doctorID << "\n"
            << doctors[i].name << "\n"
            << doctors[i].specialization << "\n"
            << doctors[i].availableSlots << "\n"
            << doctors[i].consultationFee << "\n";
    }


    // Pasting appointments data
    file << appointmentsCount << "\n";
    for (int i = 0; i < appointmentsCount; i++) {
        file << appointments[i].appointmentID << "\n"
            << appointments[i].patientID << "\n"
            << appointments[i].doctorID << "\n"
            << appointments[i].appointmentDate.day << "\n"
            << appointments[i].appointmentDate.month << "\n"
            << appointments[i].appointmentDate.year << "\n"
            << appointments[i].appointmentTime.hours << "\n"
            << appointments[i].appointmentTime.minutes << "\n"
            << appointments[i].appointmentTime.timePeriod << "\n"
            << appointments[i].status << "\n"
            << appointments[i].totalCost << "\n";
    }


    // Pasting admins data
    file << adminsCount << "\n";
    for (int i = 0; i < adminsCount; i++) {
        file << admins[i].adminID << "\n"
            << admins[i].name << "\n"
            << admins[i].password << "\n";
    }


    // Closing the file
    file.close();
    cout << "\n*******************************************\n";
    cout << "      Thank you for using our app!          \n";
    cout << "*******************************************\n";

}
void chooseAdminOrPatient(bool isRedirect) {

    // Welcome message
    if (isRedirect) {
        space();
    }
    else {
        cout << "\n*******************************************\n";
        cout << "      CLINIC APPOINTMENT SYSTEM          \n";
        cout << "*******************************************\n";
    }


    // Taking user's input
    cout << "\n";
    cout << "What's your role?\n";
    cout << "1. Admin\n";
    cout << "2. Patient\n";
    cout << "3. Exit (save current program data)\n";
    int choice;
    readValidInt("Enter your choice: ", choice, 1, 3);
    space();


    // Taking actions based on input
    if (choice == 1) adminLogin();
    else if (choice == 2) patientLoginOrSignUp();
    else terminateTheProgram();

}
void viewDoctors(bool isRedirect) {

    if (isRedirect) {
        space();
        cout << "\n";
    }

    // Showing doctors list
    cout << "Doctors List:\n";
    cout << string(66, '-') << "\n";
    cout << left
        << setw(10) << "ID"
        << setw(22) << "Name"
        << setw(16) << "Specialization"
        << setw(8) << "Slots"
        << setw(10) << "Fee (EGP)"
        << "\n";
    cout << string(66, '-') << "\n";

    if (doctorsCount == 0) {
        cout << "No data yet.\n";
    }
    else {
        for (int i = 0; i < doctorsCount; i++) {
            cout << left
                << setw(10) << doctors[i].doctorID
                << setw(22) << doctors[i].name
                << setw(16) << doctors[i].specialization
                << setw(8) << doctors[i].availableSlots
                << setw(10) << doctors[i].consultationFee
                << "\n";
        }
    }
    cout << string(66, '-') << "\n";


    // Redirecting
    if (isRedirect) patientDashboard();

}


// Admin Functions
void adminLogin() {

    // Function Text
    cout << "\n\t\t(Admin Login)\n\n";


    // ID
    int id;
    readValidInt("Enter Admin ID (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) { chooseAdminOrPatient(true); return; }


    // Password
    cout << "Enter Password: ";
    string password;
    getline(cin, password);


    // Evaluating the ID and password
    int idx = -1;
    for (int i = 0; i < adminsCount; i++) {
        if (admins[i].adminID == id) { idx = i; break; }
    }
    if (idx == -1 || admins[idx].password != password) {
        cout << "Invalid credentials. Try again.\n";
        adminLogin();
        return;
    }


    // Setting current admin ID and redirecting
    currentAdminID = id;
    adminDashboard();

}
void adminDashboard() {
    
    // Function text
    space();
    cout << "\n\t\t(Admin Dashboard)\n\n";
    cout << "1. Add Doctor\n";
    cout << "2. Remove Doctor\n";
    cout << "3. Edit Consultation Fee\n";
    cout << "4. View All Appointments\n";
    cout << "5. Mark Appointment as Completed\n";
    cout << "6. Logout\n";


    // Taking user input
    int choice;
    readValidInt("Enter your choice: ", choice, 1, 6);
    if (choice == 1) addDoctor();
    else if (choice == 2) removeDoctor();
    else if (choice == 3) editConsultationFee();
    else if (choice == 4) viewAllAppointments();
    else if (choice == 5) markAppointmentAsCompleted();
    else adminLogout();

}
void addDoctor() {
    
    // Function text
    space();
    cout << "\n";
    cout << "\n\t\t(Add Doctor)\n\n";


    // Checking if the array is full
    if (isArrayFull(doctorsCount, maxDoctorsCount)) {
        cout << "Doctors list is full (20/20). Cannot add more.\n";
        adminDashboard();
        return;
    }


    // ID
    int id;
    readValidInt("Enter Doctor ID (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) { adminDashboard(); return; }
    // Checking if the ID exists
    if (findDoctorIndex(id) != -1) {
        cout << "A doctor with this ID already exists.\n";
        addDoctor();
        return;
    }


    // Name
    cout << "Enter Name: ";
    string name;
    getline(cin, name);
    // Checking if the name is empty
    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        addDoctor();
        return;
    }


    // Specialization
    cout << "Enter Specialization: ";
    string spec;
    getline(cin, spec);
    // Checking if the specialization is empty
    if (spec.empty()) {
        cout << "Specialization cannot be empty.\n";
        addDoctor();
        return;
    }


    // Available slots and fees
    int slots, fee;
    readValidInt("Enter Available Slots: ", slots, 1, 9999);
    readValidInt("Enter Consultation Fee (EGP): ", fee, 1, 999999);


    // Adding the doctor
    doctors[doctorsCount] = { id, name, spec, slots, fee };
    doctorsCount++;


    // Success message and redirection
    cout << "\nDoctor added successfully!\n";
    adminDashboard();

}
void removeDoctor() {
    
    // Function text
    space();
    cout << "\n\t\t(Remove Doctor)\n\n";


    // Viewing doctors
    viewDoctors(false);
    if (doctorsCount == 0) {
        adminDashboard();
        return;
    }


    // ID
    int id;
    readValidInt("Enter Doctor ID to remove (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) { adminDashboard(); return; }


    // Finding the doctor with the input ID
    int idx = findDoctorIndex(id);
    if (idx == -1) {
        cout << "Doctor not found.\n";
        removeDoctor();
        return;
    }


    // Are you sure message
    cout << "Are you sure you want to remove " << doctors[idx].name << "? (y/n): ";
    char confirm;
    cin >> confirm;
    cin.ignore();
    if (confirm != 'y' && confirm != 'Y') {
        adminDashboard();
        return;
    }


    // Canceling all booked appointments for this doctor
    for (int i = 0; i < appointmentsCount; i++) {
        if (appointments[i].doctorID == id && appointments[i].status == "Booked") {
            updateAppointmentStatus(&appointments[i], "Cancelled");
        }
    }


    // Shift array left to fill the gap
    for (int i = idx; i < doctorsCount - 1; i++) {
        doctors[i] = doctors[i + 1];
    }
    doctorsCount--;


    // Success message and redirecting
    cout << "\nDoctor removed successfully!\n";
    adminDashboard();

}
void editConsultationFee() {

    // Function text
    space();
    cout << "\n\t\t(Edit Consultation Fee)\n\n";


    // Viewing doctors
    viewDoctors(false);
    if (doctorsCount == 0) {
        adminDashboard();
        return;
    }


    // ID
    int id;
    readValidInt("Enter Doctor ID (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) { adminDashboard(); return; }


    // Finding the doctor with the input ID
    int idx = findDoctorIndex(id);
    if (idx == -1) {
        cout << "Doctor not found.\n";
        editConsultationFee();
        return;
    }


    // Setting new consultation fee
    int newFee;
    readValidInt("Enter new Consultation Fee (EGP): ", newFee, 1, 999999);
    doctors[idx].consultationFee = newFee;


    // Success message and redirection
    cout << "\nConsultation fee updated successfully!\n";
    adminDashboard();

}
void viewAllAppointments() {

    // Viewing appointments
    space();
    cout << "\n\t\t(Appointments List)\n\n";
    cout << string(82, '-') << "\n";
    cout << left
        << setw(8) << "Appt. ID"
        << setw(12) << "Patient ID"
        << setw(12) << "Doctor ID"
        << setw(14) << "Date"
        << setw(12) << "Time"
        << setw(14) << "Status"
        << setw(10) << "Cost (EGP)"
        << "\n";
    cout << string(82, '-') << "\n";

    if (appointmentsCount == 0) {
        cout << "No data yet.\n";
    }
    else {
        for (int i = 0; i < appointmentsCount; i++) {
            cout << left
                << setw(8) << appointments[i].appointmentID
                << setw(12) << appointments[i].patientID
                << setw(12) << appointments[i].doctorID
                << setw(14) << formatDate(appointments[i].appointmentDate)
                << setw(12) << formatTime(appointments[i].appointmentTime)
                << setw(14) << appointments[i].status
                << setw(10) << appointments[i].totalCost
                << "\n";
        }
    }
    cout << string(82, '-') << "\n";
    adminDashboard();

}
void markAppointmentAsCompleted() {
    
    // Text
    space();
    cout << "\n\t\t(Mark Appointment as Completed)\n\n";
    cout << "\nAppointments List:\n";


    // Display only booked appointments
    cout << string(72, '-') << "\n";
    cout << left
        << setw(8) << "Appt ID"
        << setw(12) << "Patient ID"
        << setw(12) << "Doctor ID"
        << setw(14) << "Date"
        << setw(12) << "Time"
        << setw(14) << "Status"
        << "\n";
    cout << string(72, '-') << "\n";

    bool hasBooked = false;
    for (int i = 0; i < appointmentsCount; i++) {
        if (appointments[i].status == "Booked") {
            hasBooked = true;
            cout << left
                << setw(8) << appointments[i].appointmentID
                << setw(12) << appointments[i].patientID
                << setw(12) << appointments[i].doctorID
                << setw(14) << formatDate(appointments[i].appointmentDate)
                << setw(12) << formatTime(appointments[i].appointmentTime)
                << setw(14) << appointments[i].status
                << "\n";
        }
    }


    // Checking if any booked appointments exist
    if (!hasBooked) {
        cout << "No data yet.\n";
        cout << string(72, '-') << "\n";
        adminDashboard();
        return;
    }
    cout << string(72, '-') << "\n";


    // Appointment ID
    int id;
    readValidInt("Enter Appointment ID: ", id, 0, 999999);
    if (id == 0) { adminDashboard(); return; }


    // Checking if the appointment exists
    int idx = findAppointmentIndex(id);
    if (idx == -1) {
        cout << "Appointment not found.\n";
        markAppointmentAsCompleted();
        return;
    }


    // Checking if the appointment is already booked
    if (appointments[idx].status != "Booked") {
        cout << "Only Booked appointments can be marked as completed.\n";
        markAppointmentAsCompleted();
        return;
    }


    // Updating appointment status
    updateAppointmentStatus(&appointments[idx], "Completed");
    cout << "\nAppointment marked as completed!\n";
    adminDashboard();

}
void adminLogout() {
    currentAdminID = -1;
    cout << "\nLogged out successfully!\n";
    chooseAdminOrPatient(true);
}


// Patient Functions
void patientLoginOrSignUp() {

    // Function text
    cout << "\n\t\t(Patient Portal)\n";
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "0. Go back\n";


    // Input choice
    int choice;
    readValidInt("Enter your choice: ", choice, 0, 2);


    // Redirecting
    if (choice == 1) patientLogin();
    else if (choice == 2) patientSignUp();
    else chooseAdminOrPatient(true);

}
void patientSignUp() {
    

    // Function text
    space();
    cout << "\n\t\t(Sign Up)\n\n";


    // Checking if the patients array if full
    if (isArrayFull(patientsCount, maxPatientsCount)) {
        cout << "Patient registration is currently unavailable (50/50).\n";
        patientLoginOrSignUp();
        return;
    }


    // ID
    int id;
    readValidInt("Enter Patient ID (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) { patientLoginOrSignUp(); return; }


    // Checking if the ID is unique
    if (findPatientIndex(id) != -1) {
        cout << "This ID is already taken. Please choose a different ID.\n";
        patientSignUp();
        return;
    }


    // Name
    cout << "Enter Name: ";
    string name;
    getline(cin, name);


    // Checking if the name is empty
    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        patientSignUp();
        return;
    }


    // Password
    cout << "Enter Password (min 6 characters): ";
    string password;
    getline(cin, password);


    // Checking password validity
    if (!isValidPassword(password)) {
        cout << "Password must be at least 6 characters.\n";
        patientSignUp();
        return;
    }


    // Phone number
    cout << "Enter Phone Number: ";
    string phone;
    getline(cin, phone);


    // Checking phone number validity
    if (!isValidPhoneNumber(phone)) {
        cout << "Phone number must contain digits only.\n";
        patientSignUp();
        return;
    }


    // Age
    int age;
    readValidInt("Enter Age: ", age, 1, 120);


    // Adding the patient
    patients[patientsCount] = { id, name, password, phone, age };
    patientsCount++;


    // Success message and redirecting
    cout << "\nAccount created successfully! Please log in.\n";
    patientLogin();

}
void patientLogin() {

    // Function text
    space();
    cout << "\n\t\t(Login)\n\n";


    // ID
    int id;
    readValidInt("Enter Patient ID (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) {
        space();
        patientLoginOrSignUp();
        return;
    }


    // Password
    cout << "Enter Password: ";
    string password;
    getline(cin, password);


    // Check if the patient exists and the password is correct
    int idx = findPatientIndex(id);
    if (idx == -1 || patients[idx].password != password) {
        cout << "Invalid credentials. Try again.\n";
        patientLogin();
        return;
    }


    // Setting current patient ID and redirecting
    currentPatientID = id;
    patientDashboard();

}
void patientDashboard() {

    // Space
    space();

    // Finding patient's index
    int idx = findPatientIndex(currentPatientID);


    // Welcome message
    cout << "\nWelcome, " << patients[idx].name << "! Choose an option to proceed:\n";
    cout << "1. Book Appointment\n";
    cout << "2. Cancel Appointment\n";
    cout << "3. View My Appointments\n";
    cout << "4. View Doctors\n";
    cout << "5. Logout\n";


    // User's choice
    int choice;
    readValidInt("Enter your choice: ", choice, 1, 5);


    // Redirecting
    if (choice == 1) bookAppointment();
    else if (choice == 2) cancelAppointment();
    else if (choice == 3) viewAppointments();
    else if (choice == 4) viewDoctors(true);
    else patientLogout();

}
void bookAppointment() {
    
    // Space
    space();
    cout << "\n\t\t(Book Appointment)\n\n";


    // Checking if the array is full
    if (isArrayFull(appointmentsCount, maxAppointmentsCount)) {
        cout << "Appointments list is full (100/100).\n";
        patientDashboard();
        return;
    }


    // Viewing doctors
    viewDoctors(false);


    // Checking if there are no doctors
    if (doctorsCount == 0) {
        patientDashboard();
        return;
    }


    // ID
    int doctorID;
    readValidInt("Enter Doctor ID (Enter 0 to go back): ", doctorID, 0, 999999);
    if (doctorID == 0) { patientDashboard(); return; }


    // Check if the doctor exists
    int dIdx = findDoctorIndex(doctorID);
    if (dIdx == -1) {
        cout << "Doctor not found.\n";
        bookAppointment();
        return;
    }


    // Checking if the doctors has available slots
    if (doctors[dIdx].availableSlots <= 0) {
        cout << "This doctor has no available slots.\n";
        bookAppointment();
        return;
    }


    // Date input
    int day, month, year;
    readValidInt("Enter Day   (1-31): ", day, 1, 31);
    readValidInt("Enter Month (1-12): ", month, 1, 12);
    readValidInt("Enter Year (2026+): ", year, 2026, 2100);
    Date date;
    date.day = to_string(day);
    date.month = to_string(month);
    date.year = to_string(year);


    // Time input
    int hours, minutes;
    readValidInt("Enter Hours   (1-12): ", hours, 1, 12);
    readValidInt("Enter Minutes (0-59): ", minutes, 0, 59);
    Time time;
    time.hours = to_string(hours);
    time.minutes = (minutes < 10 ? "0" : "") + to_string(minutes);
    // Period
    string period;
    while (true) {
        cout << "Enter AM or PM: ";
        getline(cin, period);
        if (period == "AM" || period == "am") { period = "AM"; break; }
        if (period == "PM" || period == "pm") { period = "PM"; break; }
        cout << "Invalid. Please enter AM or PM.\n";
    }
    time.timePeriod = period;


    // Checking if the doctor has an appoitment at this given date and time
    if (hasDoctorTimeConflict(doctorID, date, time)) {
        cout << "This doctor already has a booking at this date and time.\n";
        bookAppointment();
        return;
    }


    // Checking if the patient has an appoitment at this given date and time
    if (hasPatientTimeConflict(currentPatientID, date, time)) {
        cout << "You already have a booking at this date and time.\n";
        bookAppointment();
        return;
    }


    // Creating the appointment
    int newID = appointmentsCount + 1;
    appointments[appointmentsCount] = {
        newID,
        currentPatientID,
        doctorID,
        date,
        time,
        "Booked",
        calculateTotalCost(doctorID)
    };
    appointmentsCount++;
    doctors[dIdx].availableSlots--;


    // Success message and redirection
    cout << "\nAppointment booked successfully! Your Appointment ID is: " << newID << "\n";
    patientDashboard();

}
void cancelAppointment() {

    // Space
    space();
    cout << "\n\t\t(Cancel Appointment)\n\n";
    

    // Display this patient's appointments
    cout << "Appointments List:\n";
    cout << string(70, '-') << "\n";
    cout << left
        << setw(8) << "Appt ID"
        << setw(12) << "Doctor ID"
        << setw(14) << "Date"
        << setw(12) << "Time"
        << setw(14) << "Status"
        << setw(10) << "Cost"
        << "\n";
    cout << string(70, '-') << "\n";

    bool hasAny = false;
    for (int i = 0; i < appointmentsCount; i++) {
        if (
            (appointments[i].patientID == currentPatientID) &&
            (appointments[i].status == "Booked")
            ) {
            hasAny = true;
            cout << left
                << setw(8) << appointments[i].appointmentID
                << setw(12) << appointments[i].doctorID
                << setw(14) << formatDate(appointments[i].appointmentDate)
                << setw(12) << formatTime(appointments[i].appointmentTime)
                << setw(14) << appointments[i].status
                << setw(10) << appointments[i].totalCost
                << "\n";
        }
    }

    if (!hasAny) {
        cout << "No data yet.\n";
        cout << string(70, '-') << "\n";
        patientDashboard();
        return;
    }
    cout << string(70, '-') << "\n";


    // ID
    int id;
    readValidInt("Enter Appointment ID to cancel (Enter 0 to go back): ", id, 0, 999999);
    if (id == 0) { patientDashboard(); return; }


    // Checking if the appointment exists
    int idx = findAppointmentIndex(id);
    if (idx == -1) {
        cout << "Appointment not found.\n";
        cancelAppointment();
        return;
    }


    // Checking if the current patient's is the same as the appointment's patient id
    if (appointments[idx].patientID != currentPatientID) {
        cout << "You can only cancel your own appointments.\n";
        cancelAppointment();
        return;
    }


    // Checking if the appointment is not already canceled
    if (appointments[idx].status != "Booked") {
        cout << "Only Booked appointments can be cancelled.\n";
        cancelAppointment();
        return;
    }


    // Updating appointment's status
    updateAppointmentStatus(&appointments[idx], "Cancelled");


    // Increasing doctor's avaiable slots
    int dIdx = findDoctorIndex(appointments[idx].doctorID);
    if (dIdx != -1) doctors[dIdx].availableSlots++;


    // Success message and redirection
    cout << "\nAppointment cancelled successfully!\n";
    patientDashboard();

}
void viewAppointments() {

    // Space
    space();


    // Appointments List
    cout << "\n\t\t(Appointments List)\n\n";
    cout << string(70, '-') << "\n";
    cout << left
        << setw(8) << "Appt ID"
        << setw(12) << "Doctor ID"
        << setw(14) << "Date"
        << setw(12) << "Time"
        << setw(14) << "Status"
        << setw(10) << "Cost"
        << "\n";
    cout << string(70, '-') << "\n";

    bool hasAny = false;
    for (int i = 0; i < appointmentsCount; i++) {
        if (appointments[i].patientID == currentPatientID) {
            hasAny = true;
            cout << left
                << setw(8) << appointments[i].appointmentID
                << setw(12) << appointments[i].doctorID
                << setw(14) << formatDate(appointments[i].appointmentDate)
                << setw(12) << formatTime(appointments[i].appointmentTime)
                << setw(14) << appointments[i].status
                << setw(10) << appointments[i].totalCost
                << "\n";
        }
    }

    if (!hasAny) cout << "No data yet.\n";

    cout << string(70, '-') << "\n";


    // Redirection
    patientDashboard();

}
void patientLogout() {
    currentPatientID = -1;
    cout << "\nLogged out successfully!\n";
    chooseAdminOrPatient(true);
}