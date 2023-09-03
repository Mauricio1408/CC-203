//Driver File For the Hospital Management System

#include "Hospital Management System.cpp"

int main(){
	
	//variable to keep the application running
	int keep_running = 1;
	
	//index of Hospital_rooms
	int room_number;
	
	//intro
	Intro();
	
	//there are 20 rooms
	Room Hospital_rooms[50];
	
	//structure for bunker
	bunker stocks = {5000, 5000, 10000, 10000, 20000, 5000, 10000, 5000, 20000 };
	
	cout << "\nThe Hospital has a total of 50 rooms starting from Room 1\n";
	cout << "Each room has their own supply of medical supplies, ready to be used\n";
	cout << "Whenever a medical supply has been used up, you can get some supplies at the bunker of the Hospital\n";
	
	cout << "\nChoose from the options below to navigate your way into the app\n\n";
	do{
			
	//variable that stores user choice
	//used in navigating through the application
	int user_choice; 
	
	// list of options
	cout << "\nOptions:\n\n";
	cout << "Option 1: About The Hospital Management System\n\n";
	cout << "Option 2: Enter a Patient\n\n";
	cout << "Option 3: Check Supplies\n\n";
	cout << "Option 4: Transfer Supplies\n\n";
	cout << "Option 5: Bunker Status\n\n";
	cout << "Option 6: View History\n\n";
	cout << "Press other keys to exit()\n";
	
	cout << "\nEnter Your Choice: ";
	cin >> user_choice;
	cout << endl;
	
	switch (user_choice){
		
		case 1:
			{
				
			//Outputs the description for the Hotel Management System
			About_us();
			break;
				
			}
			
		case 2:
			{
				
			//list of medical supplies
			//variables to store user inputs
			int ContraceptivesUsed;
			int Flue_relieversUsed;
			int Pain_killersUsed;
			int IV_fluidsUsed;
			int AntibioticsUsed;
			int AntihypertensivesUsed;
			int Sedatives_and_anestheticsUsed;
			int Syringes_and_needlesUsed;
			int Face_masksUsed;	
			
			//used to write the medical supplies used
			ofstream med_supply_;
			
			cout << "Enter Room Number: ";
			cin >> room_number;
			cout << endl;
			
			//to access the array of rooms correctly
			int index = room_number - 1;
			
			//variable used to distinguish the type of patient
			int PatientType;
			
			cout << "Hello there User!\n\n";
			cout << "Thank You for choosing us!\n";
			cout << "Please Select the appropriate details:\n\n";
			
			cout << "1: Regular Patient\n";
			cout << "2: Hospital Employee\n";
			cout << "3: Government Employee\n";
			cout << "4: Senior Citizen\n";
			
			cout << "\nEnter Patient Type: ";
			cin >> PatientType;
			
			//if medical supplies are not enough:
			if (Hospital_rooms[index].Contraceptives < 1 || Hospital_rooms[index].Flue_relievers < 1 || Hospital_rooms[index].Pain_killers < 1 || Hospital_rooms[index].IV_fluids < 1 
				|| Hospital_rooms[index].Antibiotics < 1 || Hospital_rooms[index].Antihypertensives  < 1 || Hospital_rooms[index].Sedatives_and_anesthetics < 1 || 
				Hospital_rooms[index].Syringes_and_needles < 1 || Hospital_rooms[index].Face_masks < 1 ){
					
				cout << "\n\nError: Medical supplies are not enough. Please get more from the bunker\n\n";	
				break;
					
				}
			
			
			//Saves the Patient's personal information onto a txt file
			patientType(PatientType);
			
			
			//ask the user for the number of medical supplies used
			cout << "\nEnter the number of medical supplies used: \n";
			
			cout << "\nNumber of Contraceptives: ";
			cin >> ContraceptivesUsed ;
			
			cout << "\nNumber of Flue Relievers: ";
			cin >> Flue_relieversUsed  ;
			
			cout << "\nNumber of Painkillers: ";
			cin >> Pain_killersUsed  ;
			
			cout << "\nNumber of IV Fluids: ";
			cin >> IV_fluidsUsed  ;
			
			cout << "\nNumber of Antibiotics: ";
			cin >> AntibioticsUsed ;
			
			cout << "\nNumber of Antihypertensives: ";
			cin >> AntihypertensivesUsed ;
			
			cout << "\nNumber of Sedatives and Anesthetics: ";
			cin >> Sedatives_and_anestheticsUsed ;
			
			cout << "\nNumber of Syringes and Needles: ";
			cin >> Syringes_and_needlesUsed  ;
			
			cout << "\nNumber of Facemasks: ";
			cin >> Face_masksUsed  ;
			cout <<endl << endl;
			
			//Reducing the number of medical supplies used
			Hospital_rooms[index].Contraceptives -= ContraceptivesUsed;
			Hospital_rooms[index].Flue_relievers -= Flue_relieversUsed;
			Hospital_rooms[index].Pain_killers -= Pain_killersUsed;
			Hospital_rooms[index].IV_fluids -= IV_fluidsUsed;
			Hospital_rooms[index].Antibiotics -= AntibioticsUsed;
			Hospital_rooms[index].Antihypertensives -= AntihypertensivesUsed;
			Hospital_rooms[index].Sedatives_and_anesthetics -= Sedatives_and_anestheticsUsed;
			Hospital_rooms[index].Syringes_and_needles -= Syringes_and_needlesUsed;
			Hospital_rooms[index].Face_masks -= Face_masksUsed;
		
			//Outputting the number of medical supplies used
			switch (PatientType){
				case 1:
					{
						
						//regular employee
						med_supply_.open("Regular Patients Log.txt", ios::app);
						
						if (med_supply_.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Regular Patients Log.txt'. \n";
						}
						
						med_supply_ << "\nNumber of Contraceptives: " << ContraceptivesUsed ;
						med_supply_ << "\nNumber of Flue Relievers: " << Flue_relieversUsed;
						med_supply_ << "\nNumber of Painkillers: "  << Pain_killersUsed;
						med_supply_ << "\nNumber of IV Fluids: " << IV_fluidsUsed;
						med_supply_ << "\nNumber of Antibiotics: " << AntibioticsUsed;
						med_supply_ << "\nNumber of Antihypertensives: " << AntihypertensivesUsed;
						med_supply_ << "\nNumber of Sedatives and Anesthetics: " << Sedatives_and_anestheticsUsed;
						med_supply_ << "\nNumber of Syringes and Needles: " << Syringes_and_needlesUsed;
						med_supply_ << "\nNumber of Facemasks: " << Face_masksUsed;
						
						med_supply_.close();
						
						break;
					}
					
				case 2:
					{
						
						//hospital employee
						med_supply_.open("Employee Log.txt", ios::app);
						
						if (med_supply_.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Employee Log.txt'. \n";
						}
						
						med_supply_ << "\nNumber of Contraceptives: " << ContraceptivesUsed ;
						med_supply_ << "\nNumber of Flue Relievers: " << Flue_relieversUsed;
						med_supply_ << "\nNumber of Painkillers: "  << Pain_killersUsed;
						med_supply_ << "\nNumber of IV Fluids: " << IV_fluidsUsed;
						med_supply_ << "\nNumber of Antibiotics: " << AntibioticsUsed;
						med_supply_ << "\nNumber of Antihypertensives: " << AntihypertensivesUsed;
						med_supply_ << "\nNumber of Sedatives and Anesthetics: " << Sedatives_and_anestheticsUsed;
						med_supply_ << "\nNumber of Syringes and Needles: " << Syringes_and_needlesUsed;
						med_supply_ << "\nNumber of Facemasks: " << Face_masksUsed;
						
						med_supply_.close();
						
						break;
						
					}
					
				case 3:
					{
						
						//gov employee
						med_supply_.open("Governent Employee Log.txt", ios::app);
						
						if (med_supply_.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Governent Employee Log.txt'. \n";
						}
						
						med_supply_ << "\nNumber of Contraceptives: " << ContraceptivesUsed ;
						med_supply_ << "\nNumber of Flue Relievers: " << Flue_relieversUsed;
						med_supply_ << "\nNumber of Painkillers: "  << Pain_killersUsed;
						med_supply_ << "\nNumber of IV Fluids: " << IV_fluidsUsed;
						med_supply_ << "\nNumber of Antibiotics: " << AntibioticsUsed;
						med_supply_ << "\nNumber of Antihypertensives: " << AntihypertensivesUsed;
						med_supply_ << "\nNumber of Sedatives and Anesthetics: " << Sedatives_and_anestheticsUsed;
						med_supply_ << "\nNumber of Syringes and Needles: " << Syringes_and_needlesUsed;
						med_supply_ << "\nNumber of Facemasks: " << Face_masksUsed;
						
						med_supply_.close();
						
						break;
					
					}
					
				case 4: 
				{
					
					//senior citizen
						med_supply_.open("Senior Citizen Log.txt", ios::app);
						
						if (med_supply_.fail()){
						cout << "Output file opening failed. \n";
						cout << "Please create a file and name it 'Senior Citizen Log.txt'. \n";
						}
						
						med_supply_ << "\nNumber of Contraceptives: " << ContraceptivesUsed ;
						med_supply_ << "\nNumber of Flue Relievers: " << Flue_relieversUsed;
						med_supply_ << "\nNumber of Painkillers: "  << Pain_killersUsed;
						med_supply_ << "\nNumber of IV Fluids: " << IV_fluidsUsed;
						med_supply_ << "\nNumber of Antibiotics: " << AntibioticsUsed;
						med_supply_ << "\nNumber of Antihypertensives: " << AntihypertensivesUsed;
						med_supply_ << "\nNumber of Sedatives and Anesthetics: " << Sedatives_and_anestheticsUsed;
						med_supply_ << "\nNumber of Syringes and Needles: " << Syringes_and_needlesUsed;
						med_supply_ << "\nNumber of Facemasks: " << Face_masksUsed;
						
						med_supply_.close();
						
						break;
					
				}
					
					
					
			}
			
			break;	
			}
			
		case 3:
			{
				
			//Outputs the medical supplies in a room
			cout << "Enter Room Number: ";
			cin >> room_number;
			
			//because arrays starts at 0:
			int index = room_number - 1;
			
			cout << "\n\nThe following are the resources left at room "<< room_number << ":" << endl << endl;
			
			cout <<	"Contraceptives: " 				<< Hospital_rooms[index].Contraceptives 			<< endl;
			cout <<	"Flue Relievers: " 				<< Hospital_rooms[index].Flue_relievers  			<< endl;
			cout <<	"Painkillers: " 				<< Hospital_rooms[index].Pain_killers  				<< endl;
			cout <<	"IV Fluids: " 					<< Hospital_rooms[index].IV_fluids  				<< endl;
			cout <<	"Antibiotics: " 				<< Hospital_rooms[index].Antibiotics  				<< endl;
			cout <<	"Antihypertensives: " 			<< Hospital_rooms[index].Antihypertensives  		<< endl;
			cout <<	"Sedatives and Anesthetic: " 	<< Hospital_rooms[index].Sedatives_and_anesthetics  << endl;
			cout <<	"Syringes and Needles: " 		<< Hospital_rooms[index].Syringes_and_needles  		<< endl;
			cout <<	"Facemasks: " 					<< Hospital_rooms[index].Face_masks  				<< endl << endl << endl;
			
			break;
			}
			
		case 4:
			{
			
			//Transfers the supplies from struct bunker to a room number
			cout << "\n\nTransfer medical supplies with ease!\n\n";
			
			//variables to store user inputs
			int ContraceptivesToTransfer;
			int Flue_relieversToTransfer;
			int Pain_killersToTransfer;
			int IV_fluidsToTransfer;
			int AntibioticsToTransfer;
			int AntihypertensivesToTransfer;
			int Sedatives_and_anestheticsToTransfer;
			int Syringes_and_needlesToTransfer;
			int Face_masksToTransfer;	
					

			cout << "Enter Room Number to transfer medical supplies: ";
			cin >> room_number;
			
			//because arrays starts at 0:
			int index = room_number - 1;
			
			//ask the user the amount of medical supplies to transfer
			cout << "\n\nNumber of Contraceptives: ";
			cin >> ContraceptivesToTransfer ;
			
			cout << "\nNumber of Flue Relievers: ";
			cin >> Flue_relieversToTransfer ;
			
			cout << "\nNumber of Painkillers: ";
			cin >> Pain_killersToTransfer ;
			
			cout << "\nNumber of IV Fluids: ";
			cin >> IV_fluidsToTransfer ;
			
			cout << "\nNumber of Antibiotics: ";
			cin >> AntibioticsToTransfer ;
			
			cout << "\nNumber of Antihypertensives: ";
			cin >> AntihypertensivesToTransfer ;
			
			cout << "\nNumber of Sedatives and Anesthetics: ";
			cin >> Sedatives_and_anestheticsToTransfer ;
			
			cout << "\nNumber of Syringes and Needles: ";
			cin >> Syringes_and_needlesToTransfer ;
			
			cout << "\nNumber of Facemasks: ";
			cin >> Face_masksToTransfer ;
			
			//transfering medical supplies
			stocks.Contraceptives -= ContraceptivesToTransfer;
			Hospital_rooms[index].Contraceptives += ContraceptivesToTransfer;
			
			stocks.Flue_relievers -= Flue_relieversToTransfer;
			Hospital_rooms[index].Flue_relievers += Flue_relieversToTransfer;
			
			stocks.Pain_killers -= Pain_killersToTransfer;
			Hospital_rooms[index].Pain_killers += Pain_killersToTransfer;
			
			stocks.IV_fluids -= IV_fluidsToTransfer;
			Hospital_rooms[index].IV_fluids += IV_fluidsToTransfer;
			
			stocks.Antibiotics -= AntibioticsToTransfer;
			Hospital_rooms[index].Antibiotics += AntibioticsToTransfer;
			
			stocks.Antihypertensives -= AntihypertensivesToTransfer;
			Hospital_rooms[index].Antihypertensives += AntihypertensivesToTransfer;
			
			stocks.Sedatives_and_anesthetics -= Sedatives_and_anestheticsToTransfer;
			Hospital_rooms[index].Sedatives_and_anesthetics += Sedatives_and_anestheticsToTransfer;
			
			stocks.Syringes_and_needles -= Syringes_and_needlesToTransfer;
			Hospital_rooms[index].Syringes_and_needles += Syringes_and_needlesToTransfer;
			
			stocks.Face_masks -= Face_masksToTransfer;
			Hospital_rooms[index].Face_masks += Face_masksToTransfer;
			
			
			cout << "\n\nTransfer Successful!\n\n";
			
			}
		
		case 5: 
		
		{
			
			//shows the user the status of the bunker
			cout << "\n\nBelow is the remaining stocks of the medical supplies: \n\n";
			
			cout <<	"Contraceptives: " 				<< stocks.Contraceptives 			<< endl;
			cout <<	"Flue Relievers: " 				<< stocks.Flue_relievers  			<< endl;
			cout <<	"Painkillers: " 				<< stocks.Pain_killers  			<< endl;
			cout <<	"IV Fluids: " 					<< stocks.IV_fluids  				<< endl;
			cout <<	"Antibiotics: " 				<< stocks.Antibiotics  				<< endl;
			cout <<	"Antihypertensives: " 			<< stocks.Antihypertensives  		<< endl;
			cout <<	"Sedatives and Anesthetic: " 	<< stocks.Sedatives_and_anesthetics << endl;
			cout <<	"Syringes and Needles: " 		<< stocks.Syringes_and_needles  	<< endl;
			cout <<	"Facemasks: " 					<< stocks.Face_masks  				<< endl << endl << endl;
			
		}
		
		case 6:
			{
			
			//shows the history of every patient in the Hospital Management System 
			int log_choice;
			ifstream log_view;
			char line;
			
			cout << "\n\nEnter which patient log you'd like to access: \n\n";
			
			cout << "1: Regular Patient\n";
			cout << "2: Hospital Employee\n";
			cout << "3: Government Employee\n";
			cout << "4: Senior Citizen\n\n";
			
			cout << "Enter choice: ";
			
			cin >> log_choice;
			
			switch(log_choice){
				case 1:
					
					log_view.open("Regular Patients Log.txt");
					
					if(log_view.fail()){
						cout << "Content file opening failed. \n";
						cout << "Please create a file and name it 'Regular Patients Log.txt' \n";
					}
					
					cout << "\nYou are now viewing the contents of Regular Patients Log.txt :\n\n";	
					
					while (!log_view.eof()){
						cout.put(line);
						log_view.get(line);	
						}
					log_view.close();
					
					break;
				
				case 2:
					
					log_view.open("Employee Log.txt");
					
					if(log_view.fail()){
						cout << "Content file opening failed. \n";
						cout << "Please create a file and name it 'Employee Log.txt' \n";
					}
					
					cout << "\nYou are now viewing the contents of Employee Log.txt :\n\n";	
					
					while (!log_view.eof()){
						cout.put(line);
						log_view.get(line);	
						}
					log_view.close();
					
					break;
					
				case 3:
					
					log_view.open("Governent Employee Log.txt");
					
					if(log_view.fail()){
						cout << "Content file opening failed. \n";
						cout << "Please create a file and name it 'Governent Employee Log.txt' \n";
					}
					
					cout << "\nYou are now viewing the contents of Governent Employee Log.txt :\n\n";	
					
					while (!log_view.eof()){
						cout.put(line);
						log_view.get(line);	
						}
					log_view.close();
					
					break;
					
				case 4:
					
					log_view.open("Senior Citizen Log.txt");
					
					if(log_view.fail()){
						cout << "Content file opening failed. \n";
						cout << "Please create a file and name it 'Senior Citizen Log.txt' \n";
					}
					
					cout << "\nYou are now viewing the contents of Senior Citizen Log.txt :\n\n";	
					
					while (!log_view.eof()){
						cout.put(line);
						log_view.get(line);	
						}
					log_view.close();
					
					break;
					
				default:
					
					cout << "\n\nInvalid Input. Try Again";
				
			}
			
		}
		
				default:
					cout << "\n\nThank You for using the Hospital Management System!";
					exit(1);
		}
			
		
	}while(keep_running == 1);
	
	
	return 0;	
}


