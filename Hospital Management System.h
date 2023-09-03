//Header File for Hospital Management System
//Made By: Bergancia, Chavez, Tuando, Calanuga, Molet

#include<string>
using namespace std;

//class for rooms of hospital
class Room{
	
	public:
		// amount of medical supplies
		int Contraceptives;
		int Flue_relievers;
		int Pain_killers;
		int IV_fluids;
		int Antibiotics;
		int Antihypertensives;
		int Sedatives_and_anesthetics;	
		int Syringes_and_needles;
		int Face_masks;	
		
		//default constructor
		Room();
		
};


//class for Regular Patients
class RegularPatient{
	
	private:
		//info of Regular Patient
		string name;
		int age;
		string address;
		string diagnosis;
		double amount_of_payment;
		double payment_rate;
		
		//time
		int time_of_appointment_Hour;
		int time_of_appointment_Min;
		
	public: 
		//constructor
		RegularPatient(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min );
		
		//funtion for getting payment 
		double payment(double payment_rate, double amount_of_payment);
		
		//getter functions
		string getName(string name);
		
		int getAge(int age);
		
		string getAddress(string address);
		
		string getDiagnosis(string diagnosis);
		
		double getAmountOfPayment(double amount_of_payment);
		
		string getTimeofAppointment(int time_of_appointment_Hour, int time_of_appointment_Min);	
	
};

//class for Employees of the hospital
//they will enjoy a 40% discount
class Employee : public  RegularPatient{
	
	private:
		//employee ID
		string Employee_ID;
		
	public: 
		//constructor
		Employee(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min , string Employee_ID);
			
		//funtion for getting payment 
		double payment(double payment_rate, double amount_of_payment);
		
		//getter function
		string getEmployeeID(string Employee_ID);
};


//class for Government Employees
//they will enjoy a 30% discount
class Gov_Employee : public  RegularPatient{
	
	private:
		//occupation of the patient
		string occupation;
		
	public: 
		//constructor
		Gov_Employee(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min , string occupation);
			
		//funtion for getting payment 
		double payment(double payment_rate, double amount_of_payment);
		
		string getOccupation(string occupation);
};


//class for Eldery 
//they will enjoy a 50% discount
class Senior_citizen : public  RegularPatient{
	
	private:
		//boolean variable for senior citizen ID
		string SrCitizen_ID;
		
	public:
		///constructor
		Senior_citizen(string name, int age, string address, string diagnosis ,double amount_of_payment,
			 int time_of_appointment_Hour, int time_of_appointment_Min , string SrCitizen_ID); 
			
		//funtion for getting payment 
		double payment(double payment_rate, double amount_of_payment);
		
		string getSrCitizenID(string SrCitizen_ID);
};


//bunker that stores medical supplies
struct bunker{
	//list of medicines and supplies
	int Contraceptives;
	int Flue_relievers;
	int Pain_killers;
	int IV_fluids;
	int Antibiotics;
	int Antihypertensives;
	int Sedatives_and_anesthetics;
	int Syringes_and_needles;
	int Face_masks;	
};


//funtion for displaying what the hospital management system is
void About_us();

//introduction of the Hospital Management System
void Intro();
 
 
//function for identidying patient type
//saves the information to an external txt file
void patientType(int PatientType);









