//Implementation file for the Hospital Management System

#include "Hospital Management System.h"
#include <iostream>
#include <fstream>
#include <cstdio>

//Room Constructor
Room::Room():Contraceptives(50), Flue_relievers(50), Pain_killers(50), IV_fluids(50), Antibiotics(100), 
					Antihypertensives(25), Sedatives_and_anesthetics(75), Syringes_and_needles(25), Face_masks(400){}

//RegularPatient Constructor
RegularPatient::RegularPatient(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 		int time_of_appointment_Hour, int time_of_appointment_Min ): name(name), age(age), address(address), 
					diagnosis(diagnosis), amount_of_payment(amount_of_payment), time_of_appointment_Hour(time_of_appointment_Hour),
					time_of_appointment_Min(time_of_appointment_Min){}
					

//function payment() definition for RegularPatient
double RegularPatient::payment(double payment_rate, double amount_of_payment) {
	
	//returns the total amount of payment
	payment_rate = 1.00; //since RegularPatients will pay 100% of the amount
	return payment_rate * amount_of_payment;
}


//Hospital Employee Constructor
Employee::Employee(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min , string Employee_ID):RegularPatient(name, 
					age, address, diagnosis , amount_of_payment, time_of_appointment_Hour, time_of_appointment_Min ),Employee_ID(Employee_ID){}
		
				
//function payment() definition for Hospital Employee
double Employee::payment(double payment_rate, double amount_of_payment) {
	
	//returns the total amount of payment
	payment_rate = 0.6; //since RegularPatients will pay 60% of the amount
	return payment_rate * amount_of_payment;
}


//Gov_Employee constructor
Gov_Employee::Gov_Employee(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min, string occupation): RegularPatient(name, 
					age, address, diagnosis , amount_of_payment, time_of_appointment_Hour, time_of_appointment_Min),occupation(occupation){}
					

// function payment() definition for Gov_Employee
double Gov_Employee::payment(double payment_rate, double amount_of_payment){
	
	//returns the total amount of payment
	payment_rate = 0.7; //since RegularPatients will pay 70% of the amount
	return payment_rate * amount_of_payment;
}


//Senior_citizen Constructor
Senior_citizen::Senior_citizen(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min, string SrCitizen_ID):RegularPatient(name, 
					age, address, diagnosis , amount_of_payment, time_of_appointment_Hour, time_of_appointment_Min),SrCitizen_ID(SrCitizen_ID){}
					
					
//function payment() definition for Senior_citizen
double Senior_citizen::payment(double payment_rate, double amount_of_payment){
	
	//returns the total amount of payment
	payment_rate = 0.5; //since RegularPatients will pay 50% of the amount
	return payment_rate * amount_of_payment;
}

//getter functions
string	RegularPatient::getName(string name){
			return name;
		}
		
int		RegularPatient::getAge(int age){
			return age;
		}
		
string	RegularPatient::getAddress(string address){
			return address;
		}
		
string RegularPatient::getDiagnosis(string diagnosis){
			return diagnosis;
		}
		
double RegularPatient::getAmountOfPayment(double amount_of_payment){
			return amount_of_payment;
		}
		
string 	RegularPatient::getTimeofAppointment(int time_of_appointment_Hour, int time_of_appointment_Min){
	
			//coverts the hour int into string
			
			//variable to store time
			string Time;
			
			//char variables to store integers
			char Hour[2];
			char Min[2];
			
			string time;
			
			
			
		
			//sprintf() to turn int variables into char
			sprintf(Hour, "%d", time_of_appointment_Hour);
			sprintf(Min, "%d", time_of_appointment_Min);
			
			string HourInString(Hour);
			string MinInString(Min);
			
			
			
			//case 1: when user inputs values that are not correct
			if (time_of_appointment_Hour < 1 || time_of_appointment_Min < 1 || time_of_appointment_Hour > 24 || time_of_appointment_Min > 59 ){
							cout << "Invalid Input \n\n";
							exit(1);
								}
			
			//case 2: when time_of_appointment_Hour < 10
			else if (time_of_appointment_Hour < 10){
				
					if (time_of_appointment_Min < 10){
						
								time = "0" + HourInString + ":" + "0" + MinInString;
								
							}
					else {
								time = "0" + HourInString + ":" + MinInString;
						}		
			}
		
			//case 3:
			else {
					if (time_of_appointment_Min < 10){
								time = HourInString + ":" + "0" + MinInString;
							}
					else {
						time = HourInString + ":" + "0" + MinInString;
						}	
		}
		
		
		return time;
		}

string Employee::getEmployeeID(string Employee_ID){
			return Employee_ID;
}

string Gov_Employee::getOccupation(string occupation){
			return occupation;
}

string Senior_citizen::getSrCitizenID(string SrCitizen_ID){
			return SrCitizen_ID;
}


//function for determining the type of patient
//saves the information onto a txt file
void patientType( int PatientType){
			
			//personal infos
			string name;
			int age;
			string address;
			string diagnosis;
			double amount_of_payment;
			int time_of_appointment_Hour;
			int time_of_appointment_Min;
			double payment_rate;
			
//			int flag = 0;
			cin.ignore();	
			cout << "\nName: ";
			getline(cin, name);
			
			cout << "\nAge: ";
			cin >> age;
			
			cin.ignore();
			cout << "\nAddress: ";
			getline(cin,address);
			
			cout << "\nDiagnosis: ";
			getline(cin,diagnosis);
			
			cout << "\nAmount of Payment: ";
			cin >> amount_of_payment;
			
			cout << "\nTime of appointment: (24-hour format, seperated by space) ";
			cin >> time_of_appointment_Hour >>  time_of_appointment_Min ;
			
			//check to see if time input is correct
			if (time_of_appointment_Hour < 0 || time_of_appointment_Hour > 24 || time_of_appointment_Min < 0 || time_of_appointment_Min > 59 ){
				
				cout << "\n\nInvalid Input. Try again\n\n";
//				exit(1);
				
			}
			
			switch (PatientType){
				
				//Regular Patient
				case 1:
					{
						
					RegularPatient _patient(name, age, address, diagnosis, amount_of_payment, time_of_appointment_Hour, time_of_appointment_Min );
					
					cout << "\n\nThe Information below will be saved:\n\n";
					cout << _patient.getName(name) 								<< endl;
					cout << _patient.getAge(age)						 		<< endl;
					cout << _patient.getAddress(address)						<< endl;
					cout << _patient.getDiagnosis(diagnosis) 					<< endl;
					cout << _patient.getAmountOfPayment(amount_of_payment)		<< endl;
					cout << _patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min)<< endl;
					
					double total_payment = _patient.payment(payment_rate,  amount_of_payment);
					
					cout << "\nRegular Patients will pay 100% of the amount\n";
					cout << "\nSince you are a regular patient, your total will be: ";
					cout << total_payment;
				
					//ofstream variable
					ofstream outputFile;
				
					outputFile.open("Regular Patients Log.txt", ios::app);
					
					if (outputFile.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Regular Patients Log.txt'. ";
					
					}
						
						outputFile << "\n\nRegular Patient\n\n"; 
						
						outputFile << "Name: " 					<< _patient.getName(name) <<endl <<endl;
						outputFile << "Age: "  					<< _patient.getAge(age) <<endl <<endl;
						outputFile << "Address: " 				<< _patient.getAddress(address) <<endl <<endl;
						outputFile << "Diagnosis: " 			<< _patient.getDiagnosis(diagnosis) <<endl <<endl;
						outputFile << "Amount of Payment: " 	<< _patient.getAmountOfPayment(amount_of_payment) <<endl <<endl;
						outputFile << "Time of appointment: " 	<< _patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) << endl << endl;
						outputFile << "Total Payment: " 		<< total_payment ;
						
						cout << "\n\nSaved to 'Regular Patients Log.txt'"  << endl;
						
						outputFile.close();	
				
					break;
					}
					
					
				// hospital employee
				case 2:
					
					{
					//Hospital ID
					string Emp_Id;
					
					cin.ignore();
					cout << "\nEnter Employee ID: ";
					getline(cin,Emp_Id );
					
					Employee __patient(name, age, address, diagnosis, amount_of_payment,time_of_appointment_Hour, time_of_appointment_Min, Emp_Id );
					
					cout << "\n\nThe Information below will be saved:\n\n";
					cout << __patient.getName(name) << endl;
					cout << __patient.getAge(age) << endl;
					cout << __patient.getAddress(address) << endl;
					cout << __patient.getDiagnosis(diagnosis) << endl;
					cout << __patient.getAmountOfPayment(amount_of_payment) << endl;
					cout << __patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) << endl;
					cout << __patient.getEmployeeID(Emp_Id) << endl;
					
					double HsptlEmp_total_payment = __patient.payment(payment_rate,  amount_of_payment);
					
					cout << "\nHospital Employees will pay 60% of the amount\n";
					cout << "\nSince you are a part of the hospital, your total will be: ";
					cout << HsptlEmp_total_payment;

					//ofstream variable
					ofstream outputFile;
					
					outputFile.open("Employee Log.txt", ios::app);
					
					if (outputFile.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Employee Log.txt'. \n";
						}
						
						outputFile << "\n\nHospital Employee\n\n"; 
						
						outputFile << "Name: " 					<< __patient.getName(name) <<endl <<endl;
						outputFile << "Age: "  					<< __patient.getAge(age) <<endl <<endl;
						outputFile << "Address: " 				<< __patient.getAddress(address) <<endl <<endl;
						outputFile << "Diagnosis: " 			<< __patient.getDiagnosis(diagnosis) <<endl <<endl;
						outputFile << "Amount of Payment: " 	<< __patient.getAmountOfPayment(amount_of_payment) <<endl <<endl;
						outputFile << "Time of appointment: " 	<< __patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) <<endl <<endl;
						outputFile << "Total Payment: " 		<< HsptlEmp_total_payment <<endl <<endl;
						outputFile << "Employee ID: "			<< __patient.getEmployeeID(Emp_Id) <<endl <<endl;
						
						outputFile.close();
						
						cout << "\n\nSaved to 'Employee Log.txt'" <<endl;
				
					break;
						
					}
					
						
				case 3:
					
					{
					//Occupation
					string Occupation_of_Patient;
					
					cin.ignore();
					cout << "Enter Occupation: ";
					getline(cin, Occupation_of_Patient);
					
					Gov_Employee ___patient(name, age, address, diagnosis, amount_of_payment, time_of_appointment_Hour, time_of_appointment_Min, Occupation_of_Patient );
					
					cout << "\n\nThe Information below will be saved:\n\n";
					cout << ___patient.getName(name) << endl;
					cout << ___patient.getAge(age) << endl;
					cout << ___patient.getAddress(address) << endl;
					cout << ___patient.getDiagnosis(diagnosis) << endl;
					cout << ___patient.getAmountOfPayment(amount_of_payment) << endl;
					cout << ___patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) << endl;
					cout << ___patient.getOccupation(Occupation_of_Patient) << endl;
					
					double Gov_employee_TotalPayment = ___patient.payment(payment_rate,  amount_of_payment);
					
					cout << "\nGovernment employees will pay 70% of the amount\n";
					cout << "\nSince you are a Government employee, your total will be: ";
					cout << Gov_employee_TotalPayment;
				
					//ofstream variable
					ofstream outputFile;
					
					outputFile.open("Governent Employee Log.txt", ios::app);
					
		
					if (outputFile.fail()){
						
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Governent Employee Log.txt'. \n";
					
						}
						
						outputFile << "\n\nGovernment Employee\n\n"; 
						
						outputFile << "Name: " 					<< ___patient.getName(name) <<endl <<endl;
						outputFile << "Age: "  					<< ___patient.getAge(age) <<endl <<endl;
						outputFile << "Address: " 				<< ___patient.getAddress(address) <<endl <<endl;
						outputFile << "Diagnosis: " 			<< ___patient.getDiagnosis(diagnosis) <<endl <<endl;
						outputFile << "Amount of Payment: " 	<< ___patient.getAmountOfPayment(amount_of_payment) <<endl <<endl;
						outputFile << "Time of appointment: " 	<< ___patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) <<endl <<endl;
						outputFile << "Total Payment: " 		<< Gov_employee_TotalPayment <<endl <<endl;
						outputFile << "Occupation"				<< ___patient.getOccupation(Occupation_of_Patient) << endl <<endl;
						
						outputFile.close();
						
						cout << "\n\nSaved to 'Governent Employee Log.txt'"<<endl;
			
					break;	
						
					}
					
				
				case 4:
					
					{
					//Senior Citizen ID
					string Sr_Citizen_ID;
					
					cin.ignore();
					cout << "Enter Senior Citizen ID: ";
					getline(cin,Sr_Citizen_ID );
					
					Senior_citizen ____patient(name, age, address, diagnosis, amount_of_payment,time_of_appointment_Hour, time_of_appointment_Min, Sr_Citizen_ID );
					
					cout << "\n\nThe Information below will be saved:\n\n";
					cout << ____patient.getName(name) << endl;
					cout << ____patient.getAge(age) << endl;
					cout << ____patient.getAddress(address) << endl;
					cout << ____patient.getDiagnosis(diagnosis) << endl;
					cout << ____patient.getAmountOfPayment(amount_of_payment) << endl;
					cout << ____patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) << endl;
					cout << ____patient.getSrCitizenID(Sr_Citizen_ID) << endl;
					
					double SeniorCitizen_TotalPayment = ____patient.payment(payment_rate,  amount_of_payment);
					
					cout << "\nSenior Citizens will pay 50% of the amount\n";
					cout << "\nSince you are a Senior Citizen, your total will be: ";
					cout << SeniorCitizen_TotalPayment;
				
					//ofstream variable
					ofstream outputFile;
					
					outputFile.open("Senior Citizen Log.txt", ios::app);
					
					if (outputFile.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Senior Citizen Log.txt'. \n";
					}
						
						outputFile << "\n\nSenior Citizen\n\n"; 
						
						outputFile << "Name: " 					<< ____patient.getName(name) <<endl;
						outputFile << "Age: "  					<< ____patient.getAge(age) <<endl;
						outputFile << "Address: " 				<< ____patient.getAddress(address) <<endl;
						outputFile << "Diagnosis: " 			<< ____patient.getDiagnosis(diagnosis) <<endl;
						outputFile << "Amount of Payment: " 	<< ____patient.getAmountOfPayment(amount_of_payment) <<endl;
						outputFile << "Time of appointment: " 	<< ____patient.getTimeofAppointment(time_of_appointment_Hour, time_of_appointment_Min) <<endl;
						outputFile << "Total Payment: " 		<< SeniorCitizen_TotalPayment <<endl;
						outputFile << "Senior Citizen ID: " 	<< ____patient.getSrCitizenID(Sr_Citizen_ID) << endl;
						
						outputFile.close();
						
						cout << "\n\nSaved to 'Senior Citizen Log.txt' " <<endl; 
				
					break;
					}

		
				default:
					
					cout << "\n\nInvalid Input\n\n ";
					break;
		
			}}



//Description of the Hospitll Management System
void About_us(){
	
	string paragraph1 = "MGMM Hospital is a Healthcare Facility that specialized Medical and Nursing Care as well as Medical Supplies to Patients.";
	string paragraph2 = "It is licensed by the Department of Health and accredited by the Philippine Hospital Association and Philippines Health Insurance Corporation. ";
	string paragraph3 = "The Hospital was established on November 12,2022 as a small clinic by Mr. Mauricio Manuel Bergancia, Mr. Michael Rey Tuando, Ms. Mherlie Joy Chavez, Ms. Gillie Calanuga and Ms. Jonessa Marie Molet, Students from West Visayas State University. ";
	string paragraph4 = "As the following years goes by (name) Hospital promise to arise a bigger and better Hospital that served and continue to serve many people in the Country.";

	cout << endl << paragraph1 <<endl;
	cout << endl << paragraph2 <<endl;
	cout << endl << paragraph3 <<endl;
	cout << endl << paragraph4 <<endl;
	
	return ;
}


//introz
void Intro(){
	string content1 = "The Hospital Management System is a comprehensive software solution designed to streamline and optimize the day-to-day operations of healthcare facilities.";
	string content2 = "It offers a user-friendly interface and powerful functionalities, simplifying administrative tasks, enhancing patient care, and improving overall efficiency. ";
	
	cout << endl << content1 <<endl;
	cout << endl << content2 <<endl;
	
	return;
}



