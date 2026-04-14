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
	loadData();
	chooseAdminOrPatient(false);
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
void chooseAdminOrPatient(bool isRedirect) {

	int choice = 0;

	if (!isRedirect) {
		cout << "******************************************************" << endl;
		cout << "*           Welcome To The Online Clinic App         *" << endl;
		cout << "******************************************************" << endl;
	}

	do {

		cout << "\n";
		cout << "------------------------------------------" << endl;
		cout << "Choose an option to continue: " << endl;
		cout << "1. Admin" << endl;
		cout << "2. Patient" << endl;
		cout << "3. Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				adminLogin();
				break;
			case 2:
				patientLoginOrSignUp();
				break;
			case 3:
				terminateTheProgram();
				break;
			default:
				cout << "Invalid choice. Try again." << endl;
		}

	} while (choice != 1 && choice != 2 && choice != 3);

	
};
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

void patientLoginOrSignUp() {

	int choice = 0;

	do {

		cout << "\n";
		cout << "------------------------------------------" << endl;
		cout << "Do you want to log in or sign up?: " << endl;
		cout << "1. Login" << endl;
		cout << "2. Signup" << endl;
		cout << "3. Previous page" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			patientLogin();
			break;
		case 2:
			patientSignUp();
			break;
		case 3:
			chooseAdminOrPatient(true);
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
		}

	} while (choice != 1 && choice != 2 && choice != 3);

};
void patientSignUp() {

	cout << "\n";
	cout << "------------------------------------------" << endl;
	cout << "\tSign Up" << endl;

	// Patient id
	int patientId = patientsCount + 1;

	// Name
	string name = "";
	do {

		string input;
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, input);
		
		if (input == "") {
			cout << "Invalid input. Try again.";
		}
		else {
			name = input;
		}

	} while (name == "");

	// Password
	string password = "";
	do {

		string input;
		cout << "Enter your password: ";
		cin.ignore();
		getline(cin, input);

		if (input == "") {
			cout << "Invalid Input. Try again." << endl;
		}
		else if (input.size() < 6) {
			cout << "Password must be at least 6 characters" << endl;
		}
		else {
			password = input;
		}

	} while (password == "");

	// Phone number
	string phoneNumber = "";
	do {

		string input;
		cout << "Enter your phone number: ";
		cin.ignore();
		getline(cin, input);

		if (input == "") {
			cout << "Invalid Input. Try again." << endl;
		}
		else if (input.size() != 11) {
			cout << "Phone number must contain 11 digits" << endl;
		}
		else {
			phoneNumber = input;
		}

	} while (phoneNumber == "");

	// Age
	int age = -1;
	do {

		int input;
		cout << "Enter your age: ";
		cin >> input;

		if (input <= 0 || input > 120) {
			cout << "Invalid Input. Try again." << endl;
		}
		else if (input <= 0 || input > 120) {
			cout << "Invalid Age. choose from 1 to 120" << endl;
		}
		else {
			phoneNumber = input;
		}

	} while (age < 0);

};
void patientLogin() {};
void patientDashboard() {};
void bookAppointment() {

	viewDoctors(false); // عرض الدكاترة

	if (doctorsCount == 0) {
		cout << "No doctors available.\n";
		return;
	}

	int doctorID;
	cout << "Enter Doctor ID: ";
	cin >> doctorID;

	// البحث عن الدكتور
	int doctorIndex = -1;
	for (int i = 0; i < doctorsCount; i++) {
		if (doctors[i].doctorID == doctorID) {
			doctorIndex = i;
			break;
		}
	}

	if (doctorIndex == -1) {
		cout << "Invalid Doctor ID\n";
		return;
	}

	// التأكد من وجود Slots
	if (doctors[doctorIndex].availableSlots <= 0) {
		cout << "No available slots for this doctor.\n";
		return;
	}

	// أخذ التاريخ والوقت
	Date date;
	Time time;

	cout << "Enter Day: ";
	cin >> date.day;
	cout << "Enter Month: ";
	cin >> date.month;
	cout << "Enter Year: ";
	cin >> date.year;

	cout << "Enter Hours (1–12): ";
	cin >> time.hours;
	cout << "Enter Minutes (0–59): ";
	cin >> time.minutes;
	cout << "Enter Time Period (AM/PM): ";
	cin >> time.timePeriod;

	if (time.timePeriod != "AM" && time.timePeriod != "PM") {
		cout << "Invalid time period.\n";
		return;
	}

	// تضارب مواعيد للدكتور
	for (int i = 0; i < appointmentsCount; i++) {
		if (appointments[i].doctorID == doctorID &&
			appointments[i].appointmentDate.day == date.day &&
			appointments[i].appointmentDate.month == date.month &&
			appointments[i].appointmentDate.year == date.year &&
			appointments[i].appointmentTime.hours == time.hours &&
			appointments[i].appointmentTime.minutes == time.minutes &&
			appointments[i].appointmentTime.timePeriod == time.timePeriod &&
			appointments[i].status == "Booked")
		{
			cout << "Doctor already has an appointment at this time.\n";
			return;
		}
	}

	// تضارب مواعيد للمريض
	for (int i = 0; i < appointmentsCount; i++) {
		if (appointments[i].patientID == currentPatientID &&
			appointments[i].appointmentDate.day == date.day &&
			appointments[i].appointmentDate.month == date.month &&
			appointments[i].appointmentDate.year == date.year &&
			appointments[i].appointmentTime.hours == time.hours &&
			appointments[i].appointmentTime.minutes == time.minutes &&
			appointments[i].appointmentTime.timePeriod == time.timePeriod &&
			appointments[i].status == "Booked")
		{
			cout << "You already booked an appointment at this time.\n";
			return;
		}
	}

	// توليد ID unique
	int appointmentID = rand();
	bool exists = true;
	while (exists) {
		exists = false;
		for (int i = 0; i < appointmentsCount; i++) {
			if (appointments[i].appointmentID == appointmentID) {
				exists = true;
				appointmentID = rand();
				break;
			}
		}
	}

	// إضافة الموعد
	appointments[appointmentsCount].appointmentID = appointmentID;
	appointments[appointmentsCount].patientID = currentPatientID;
	appointments[appointmentsCount].doctorID = doctorID;
	appointments[appointmentsCount].appointmentDate = date;
	appointments[appointmentsCount].appointmentTime = time;
	appointments[appointmentsCount].status = "Booked";
	appointments[appointmentsCount].totalCost = doctors[doctorIndex].consultationFee;

	appointmentsCount++;

	// تقليل Slots للدكتور
	doctors[doctorIndex].availableSlots--;

	cout << "\nAppointment booked successfully!\n";
	cout << "Your Appointment ID is: " << appointmentID << endl;

	patientDashboard();
}
void cancelAppointment() {};
void viewAppointments() {};
void patientLogout() {};