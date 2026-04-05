#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// Global Variables
int currentAdminID = -1,
currentPatientID = -1,
patientsCount = 2,
doctorsCount = 3,
appointmentsCount = 0,
adminsCount = 1;


// Functions Declarations
void loadData();
void chooseAdminOrPatient();
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

void patientSignUp();
void patientLogin();
void patientDashboard();
void bookAppointment();
void cancelAppointment();
void viewAppointments();
void patientLogout();


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
	int patientID;
	string name;
	string password;
	string phoneNumber;
	int age;
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
Patient patients[50];
Doctor doctors[20];
Appointment appointments[100];
Admin admins[2];


// Main function
int main() {
	srand(time(NULL));
	loadData();
	chooseAdminOrPatient();
	viewDoctors(false);
}


// Functions definition
void loadData() {

	// Defining the file
	ifstream data("data.txt");
	if (!data.is_open()) return;

	// Loading counts
	data >> patientsCount;
	data >> doctorsCount;
	data >> appointmentsCount;
	data >> adminsCount;
	data.ignore();

	// Loading arrays
	for (int i = 0; i < patientsCount; i++) {
		data >> patients[i].patientID;
		data.ignore();
		getline(data, patients[i].name);
		getline(data, patients[i].password);
		getline(data, patients[i].phoneNumber);
		data >> patients[i].age;
		data.ignore();
	}
	for (int i = 0; i < doctorsCount; i++) {
		data >> doctors[i].doctorID;
		data.ignore();
		getline(data, doctors[i].name);
		getline(data, doctors[i].specialization);
		data >> doctors[i].availableSlots;
		data >> doctors[i].consultationFee;
		data.ignore();
	}
	for (int i = 0; i < appointmentsCount; i++) {
		data >> appointments[i].appointmentID;
		data >> appointments[i].patientID;
		data >> appointments[i].doctorID;
		data.ignore();
		getline(data, appointments[i].appointmentDate.day);
		getline(data, appointments[i].appointmentDate.month);
		getline(data, appointments[i].appointmentDate.year);
		getline(data, appointments[i].appointmentTime.hours);
		getline(data, appointments[i].appointmentTime.minutes);
		getline(data, appointments[i].appointmentTime.timePeriod);
		getline(data, appointments[i].status);
		data >> appointments[i].totalCost;
		data.ignore();
	}
	for (int i = 0; i < adminsCount; i++) {
		data >> admins[i].adminID;
		data.ignore();
		getline(data, admins[i].name);
		getline(data, admins[i].password);
	}

	// Closing the file
	data.close();

};
void chooseAdminOrPatient() {};
void terminateTheProgram() {

	// Opening the file
	ofstream data("data.txt");

	// Saving counts
	data << patientsCount << "\n";
	data << doctorsCount << "\n";
	data << appointmentsCount << "\n";
	data << adminsCount << "\n";

	// Saving arrays
	for (int i = 0; i < patientsCount; i++) {
		data << patients[i].patientID << "\n";
		data << patients[i].name << "\n";
		data << patients[i].password << "\n";
		data << patients[i].phoneNumber << "\n";
		data << patients[i].age << "\n";
	}
	for (int i = 0; i < doctorsCount; i++) {
		data << doctors[i].doctorID << "\n";
		data << doctors[i].name << "\n";
		data << doctors[i].specialization << "\n";
		data << doctors[i].availableSlots << "\n";
		data << doctors[i].consultationFee << "\n";
	}
	for (int i = 0; i < appointmentsCount; i++) {
		data << appointments[i].appointmentID << "\n";
		data << appointments[i].patientID << "\n";
		data << appointments[i].doctorID << "\n";
		data << appointments[i].appointmentDate.day << "\n";
		data << appointments[i].appointmentDate.month << "\n";
		data << appointments[i].appointmentDate.year << "\n";
		data << appointments[i].appointmentTime.hours << "\n";
		data << appointments[i].appointmentTime.minutes << "\n";
		data << appointments[i].appointmentTime.timePeriod << "\n";
		data << appointments[i].status << "\n";
		data << appointments[i].totalCost << "\n";
	}
	for (int i = 0; i < adminsCount; i++) {
		data << admins[i].adminID << "\n";
		data << admins[i].name << "\n";
		data << admins[i].password << "\n";
	}

	// Closing the file
	data.close();

};

void viewDoctors(bool isRedirect) {

	cout << "------------------------------------------" << endl;
	if (doctorsCount == 0) {
		cout << "No data yet." << endl;
		cout << "------------------------------------------" << endl;
		return;
	}

	for (int i = 0; i < doctorsCount; i++) {
		cout << "Doctor #" << i + 1 << endl;
		cout << "ID              : " << doctors[i].doctorID << endl;
		cout << "Name            : " << doctors[i].name << endl;
		cout << "Specialization  : " << doctors[i].specialization << endl;
		cout << "Available Slots : " << doctors[i].availableSlots << endl;
		cout << "Consultation Fee: " << doctors[i].consultationFee << " EGP" << endl;
		cout << "------------------------------------------" << endl;
	}

	if (isRedirect) {
		patientDashboard();
	}

};

void adminLogin() {};
void adminDashboard() {};
void addDoctor() {};
void removeDoctor() {};
void editConsultationFee() {};
void viewAllAppointments() {};
void markAppointmentAsCompleted() {};
void adminLogout() {};

void patientSignUp() {};
void patientLogin() {};
void patientDashboard() {};
void bookAppointment() {};
void cancelAppointment() {};
void viewAppointments() {};
void patientLogout() {};