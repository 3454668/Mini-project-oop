#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define abstract class Person
class Person {
    
protected:
    int id;
    string name;
    string dateOfBirth; // Use string for date of birth
    string gender;
    string phoneNumber;
    string address;
    string email;

public:
    // Constructor
    Person(int _id, const string& _name, const string& _dateOfBirth, const string& _gender, const string& _phoneNumber, const string& _address, const string& _email)
        : id(_id), name(_name), dateOfBirth(_dateOfBirth), gender(_gender), phoneNumber(_phoneNumber), address(_address), email(_email) {}

    // Virtual destructor
    virtual ~Person() {}

    // Member functions to set and get id
    virtual void setId(int _id) { id = _id; }
    virtual int getId() const { return id; }

    // Member functions to set and get name
    virtual void setName(const string& _name) { name = _name; }
    virtual string getName() const { return name; }

    // Member functions to set and get date of birth
    virtual void setDateOfBirth(const string& _dateOfBirth) { dateOfBirth = _dateOfBirth; }
    virtual string getDateOfBirth() const { return dateOfBirth; }

    // Member functions to set and get gender
    virtual void setGender(const string& _gender) { gender = _gender; }
    virtual string getGender() const { return gender; }

    // Member functions to set and get phone number
    virtual void setPhoneNumber(const string& _phoneNumber) { phoneNumber = _phoneNumber; }
    virtual string getPhoneNumber() const { return phoneNumber; }

    // Member functions to set and get address
    virtual void setAddress(const string& _address) { address = _address; }
    virtual string getAddress() const { return address; }

    // Member functions to set and get email
    virtual void setEmail(const string& _email) { email = _email; }
    virtual string getEmail() const { return email; }
};

// Define concrete class Employee derived from Person
class Employee : public Person {
protected:
    int shiftHours;
    const double payPerHour;

public:
    Employee(int _id, const string& _name, const string& _dateOfBirth, const string& _gender, const string& _phoneNumber, const string& _address, const string& _email, int _shiftHours, double _payPerHour)
        : Person(_id, _name, _dateOfBirth, _gender, _phoneNumber, _address, _email), shiftHours(_shiftHours), payPerHour(_payPerHour) {}

    void setShiftHours(int _shiftHours) { shiftHours = _shiftHours; }
    int getShiftHours() const { return shiftHours; }

    double getPayPerHour() const { return payPerHour; }

    // Calculate total pay based on shift hours
    double calculatePay() const { return shiftHours * payPerHour; }
};

// Define Doctor class derived from Employee
class Doctor : public Employee {
private:
    string specialization;

public:
    Doctor(int _id, const string& _name, const string& _dateOfBirth, const string& _gender, const string& _phoneNumber, const string& _address, const string& _email, int _shiftHours, const string& _specialization)
        : Employee(_id, _name, _dateOfBirth, _gender, _phoneNumber, _address, _email, _shiftHours, 50.0), specialization(_specialization) {} // Pay per hour for doctor is 50

    void setSpecialization(const string& _specialization) { specialization = _specialization; }
    string getSpecialization() const { return specialization; }
};

// Define Nurse class derived from Employee
class Nurse : public Employee {
public:
    Nurse(int _id, const string& _name, const string& _dateOfBirth, const string& _gender, const string& _phoneNumber, const string& _address, const string& _email, int _shiftHours)
        : Employee(_id, _name, _dateOfBirth, _gender, _phoneNumber, _address, _email, _shiftHours, 30.0) {} // Pay per hour for nurse is 30
};

// Define Patient class
class Patient : public Person {
private:
    string medicalHistory;

public:
    Patient(int _id, const string& _name, const string& _dateOfBirth, const string& _gender, const string& _phoneNumber, const string& _address, const string& _email, const string& _medicalHistory)
        : Person(_id, _name, _dateOfBirth, _gender, _phoneNumber, _address, _email), medicalHistory(_medicalHistory) {}

    void setMedicalHistory(const string& _medicalHistory) { medicalHistory = _medicalHistory; }
    string getMedicalHistory() const { return medicalHistory; }
};

// Define LaboratoryManagement class
class LaboratoryManagement {
private:
    string patientId;
    string testType;
    string testDate;
    string result;

public:
    LaboratoryManagement(const string& _patientId, const string& _testType, const string& _testDate, const string& _result)
        : patientId(_patientId), testType(_testType), testDate(_testDate), result(_result) {}

    void setPatientId(const string& _patientId) { patientId = _patientId; }
    string getPatientId() const { return patientId; }

    void setTestType(const string& _testType) { testType = _testType; }
    string getTestType() const { return testType; }

    void setTestDate(const string& _testDate) { testDate = _testDate; }
    string getTestDate() const { return testDate; }

    void setResult(const string& _result) { result = _result; }
    string getResult() const { return result; }
};


class EmergencyManagement {
private:
    string id;
    string patientId;
    string arrivalDate;
    string severity;
    string treatmentGiven;
    string doctorId;

public:
    EmergencyManagement(const string& _id, const string& _patientId, const string& _arrivalDate, const string& _severity, const string& _treatmentGiven, const string& _doctorId)
        : id(_id), patientId(_patientId), arrivalDate(_arrivalDate), severity(_severity), treatmentGiven(_treatmentGiven), doctorId(_doctorId) {}

    void setId(const string& _id) { id = _id; }
    string getId() const { return id; }

    void setPatientId(const string& _patientId) { patientId = _patientId; }
    string getPatientId() const { return patientId;}
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int id, shiftHours, choice;
    string name, dateOfBirth, gender, phoneNumber, address, email, medicalHistory, specialization;

    cout << "Welcome to HS Hospital" << endl;
    
    cout << "If you are a patient, enter 1" << endl;
    
    cout << "If you are a doctor, enter 2" << endl;
    
    cout << "If you are a nurse, enter 3" << endl;
    
    cout << "Your choice: ";
    
    cin >> choice;

    if (choice == 1) {
        // Input for Patient
        cout << "\nEnter Patient's ID: ";
        cin >> id;
        cout << "Enter Patient's Name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        cout << "Enter Patient's Date of Birth (YYYY-MM-DD): ";
        getline(cin, dateOfBirth);
        cout << "Enter Patient's Gender: ";
        getline(cin, gender);
        cout << "Enter Patient's Phone Number: ";
        getline(cin, phoneNumber);
        cout << "Enter Patient's Address: ";
        getline(cin, address);
        cout << "Enter Patient's Email: ";
        getline(cin, email);
        cout << "Enter Patient's Medical History: ";
        getline(cin, medicalHistory);
        Patient patient(id, name, dateOfBirth, gender, phoneNumber, address, email, medicalHistory);

        // Output patient details
        cout << "\nPatient's Details: " << endl;
        
        cout << "ID: " << patient.getId() << endl;
        
        cout << "Name: " << patient.getName() << endl;
        
        cout << "Date of Birth: " << patient.getDateOfBirth() << endl;
        
        cout << "Gender: " << patient.getGender() << endl;
        
        cout << "Phone Number: " << patient.getPhoneNumber() << endl;
        
        cout << "Address: " << patient.getAddress() << endl;
        
        cout << "Email: " << patient.getEmail() << endl;
        
        cout << "Medical History: " << patient.getMedicalHistory() << endl;

        // Department Selection
        cout << "\nDepartments:" << endl;
        cout << "1. Ophthalmologist" << endl;
        cout << "2. Orthopedic Doctor" << endl;
        cout << "3. Ear-Throat Doctor" << endl;
        cout << "4. Pediatrician" << endl;
        cout << "5. Dermatologist" << endl;
        cout << "6. Cardiologist" << endl;
        cout << "Choose the department for booking an appointment: ";
        int departmentChoice;
        cin >> departmentChoice;

        switch (departmentChoice) {
            case 1:
                cout << "Booking appointment for Ophthalmologist..." << endl;
                // Add booking logic for Ophthalmologist
                break;
            case 2:
                cout << "Booking appointment for Orthopedic Doctor..." << endl;
                // Add booking logic for Orthopedic Doctor
                break;
            case 3:
                cout << "Booking appointment for Ear-Throat Doctor..." << endl;
                // Add booking logic for Ear-Throat Doctor
                break;
            case 4:
                cout << "Booking appointment for Pediatrician..." << endl;
                // Add booking logic for Pediatrician
                break;
            case 5:
                cout << "Booking appointment for Dermatologist..." << endl;
                // Add booking logic for Dermatologist
                break;
            case 6:
                cout << "Booking appointment for Cardiologist..." << endl;
                // Add booking logic for Cardiologist
                break;
            default:
                cout << "Invalid department choice!" << endl;
                break;
        }

        // Room Booking
        cout << "\nDo you want to book a room in the hospital? (1 for Yes, 0 for No): ";
        int roomChoice;
        cin >> roomChoice;

        if (roomChoice == 1) {
            int roomNumber = rand() % 500 + 1; // Generate a random room number between 1 and 500
            cout << "Your room is booked. Room number: " << roomNumber << endl;
        } else {
            cout << "Room booking skipped." << endl;
        }

        // Laboratory Management
        cout << "\nEnter Lab Test Details:" << endl;
        cout << "Enter Patient ID: ";
        string patientId;
        cin >> patientId;
        cout << "Enter Test Type: ";
        string testType;
        cin.ignore(); // Ignore newline character
        getline(cin, testType);
        cout << "Enter Test Date (YYYY-MM-DD): ";
        string testDate;
        getline(cin, testDate);
        string testResult = (rand() % 2 == 0) ? "Negative" : "Positive"; // Randomly assign test result

        LaboratoryManagement lab(patientId, testType, testDate, testResult);

        // Output lab test details
        cout << "\nLab Test Details: " << endl;
        cout << "Patient ID: " << lab.getPatientId() << endl;
        cout << "Test Type: " << lab.getTestType() << endl;
        cout << "Test Date: " << lab.getTestDate() << endl;
        cout << "Result: " << lab.getResult() << endl;

    } else if (choice == 2) {
        // Input for Doctor
        cout << "\nEnter Doctor's ID: ";
        cin >> id;
        cout << "Enter Doctor's Name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        cout << "Enter Doctor's Date of Birth (YYYY-MM-DD): ";
        getline(cin, dateOfBirth);
        cout << "Enter Doctor's Gender: ";
        getline(cin, gender);
        cout << "Enter Doctor's Phone Number: ";
        getline(cin, phoneNumber);
        cout << "Enter Doctor's Address: ";
        getline(cin, address);
        cout << "Enter Doctor's Email: ";
        getline(cin, email);
        cout << "Enter Doctor's Shift Hours: ";
        cin >> shiftHours;
        cout << "Enter Doctor's Specialization: ";
        cin.ignore(); // Ignore newline character
        getline(cin, specialization);
        Doctor doc(id, name, dateOfBirth, gender, phoneNumber, address, email, shiftHours, specialization);

        // Output doctor details including calculated pay
        cout << "\nDoctor's Details: " << endl;
        
        cout << "ID: " << doc.getId() << endl;
        
        cout << "Name: " << doc.getName() << endl;
        
        cout << "Date of Birth: " << doc.getDateOfBirth() << endl;
        
        cout << "Gender: " << doc.getGender() << endl;
        
        cout << "Phone Number: " << doc.getPhoneNumber() << endl;
        
        cout << "Address: " << doc.getAddress() << endl;
        
        cout << "Email: " << doc.getEmail() << endl;
        
        cout << "Shift Hours: " << doc.getShiftHours() << endl;
        
        cout << "Specialization: " << doc.getSpecialization() << endl;
        
        cout << "Pay Per Hour: " << doc.getPayPerHour() << endl;
        
        cout << "Total Pay: " << doc.calculatePay() << endl;
        
    } else if (choice == 3) {
        // Input for Nurse
        cout << "\nEnter Nurse's ID: ";
        cin >> id;
        cout << "Enter Nurse's Name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        cout << "Enter Nurse's Date of Birth (YYYY-MM-DD): ";
        getline(cin, dateOfBirth);
        cout << "Enter Nurse's Gender: ";
        getline(cin, gender);
        cout << "Enter Nurse's Phone Number: ";
        getline(cin, phoneNumber);
        cout << "Enter Nurse's Address: ";
        getline(cin, address);
        cout << "Enter Nurse's Email: ";
        getline(cin, email);
        cout << "Enter Nurse's Shift Hours: ";
        cin >> shiftHours;
        Nurse nurse(id, name, dateOfBirth, gender, phoneNumber, address, email, shiftHours);

        // Output nurse details including calculated pay
        cout << "\nNurse's Details: " << endl;
        
        cout << "ID: " << nurse.getId() << endl;
        
        cout << "Name: " << nurse.getName() << endl;
        
        cout << "Date of Birth: " << nurse.getDateOfBirth() << endl;
        
        cout << "Gender: " << nurse.getGender() << endl;
        
        cout << "Phone Number: " << nurse.getPhoneNumber() << endl;
        
        cout << "Address: " << nurse.getAddress() << endl;
        
        cout << "Email: " << nurse.getEmail() << endl;
        
        cout << "Shift Hours: " << nurse.getShiftHours() << endl;
        
        cout << "Pay Per Hour: " << nurse.getPayPerHour() << endl;
        
        cout << "Total Pay: " << nurse.calculatePay() << endl;
        
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
    
}