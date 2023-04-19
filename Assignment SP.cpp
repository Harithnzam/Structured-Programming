#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct account{

	string name;
	int id;
};

double priceCalc(double probRate, double rate){
	
	double priceCalc;
	priceCalc = probRate * rate;
	return priceCalc;
	
}
int main(){
	//file declaration
	ifstream in_reg;
	ofstream out_reg;
	ofstream out_rep;
	ifstream in_quest;
	ofstream out_ans;
	account reg; //struct
	//other variable declaration
	string fTime , response = " ", loginID , fileID , login = " ", problem, feedback, quest, answer[4];
	int rate, pbCode;
	float pbRate;
	bool rateFail, pbFail;
	string link = "start https://www.cognitoforms.com/UniversitiTeknologiPETRONASCGS/CSDUTPPostEventReport"; //declare registration link
	out_reg.open("C:\Registration.txt", fstream::app); //open Registration file
	
	cout << "Are you a first time user?\n";
	cout << "Enter 'Y' to register or any key to skip the registration process.\n";
	cin >> fTime;
	cout << endl;
	
	while(fTime == "Y"){ //first time registration
		
		cout << "Please enter your name: ";
		cin.ignore();
		getline(cin, reg.name);
		cout << "Please enter your ID number: ";
		cin >> reg.id;
		cout << endl;
		
		out_reg << reg.name << "\t" << reg.id << "\n";
		
		cout << "Registration complete.\n";
		cout << "Do you want to register another account or continue to login page.\n";
		cout << "Enter 'Y' to register another account or any key to go to login page: ";
		cin >> fTime;

	}
	out_reg.close();
	
	while(login != "Login"){ //login by user using ID
		
		in_reg.open("C:\Registration.txt"); //open Registration.txt
		
		cout << "Log in using your registered ID.\n";
		cin >> loginID;
	
		while(!in_reg.eof()){  //read until end of file
		
			in_reg >> fileID;
		
			if(loginID == fileID){
				
				login = "Login";
			}
				
		}
		if(login != "Login"){
			
			cout << "\nYou didn't register with this ID number yet.\n";
			
		}
		
		in_reg.close();
	}	
	
	cout << "\n----- Main Menu -----\n"; //display menu
	cout << "1: Bicycle registration\n2: Bicycle repair\n";
	cout << "Enter code to select option or 'X' to exit: ";
	cin >> response;
	cout << endl;
		
	while(response != "1" && response != "2" && response != "X"){ //error checking
			
		cout << "INVALID CODE!\n\n";
		cout << "----- Main Menu -----\n";
		cout << "1: Bicycle registration\n2: Bicycle repair\n";
		cout << "Enter code to select option or 'X' to exit: ";
		cin >> response;
		cout << endl;
			
	}
		
	while(response != "X"){
		
		float price = 0;
		
		out_rep.open("C:\Repair.txt", fstream::app); //write the problem from user into Repair.txt
		
		if(response == "1"){
			
			system(link.c_str()); //direct to registration link form
			
		}
		
		else if(response == "2"){ //prompt and get problem from the user
			
			cout << "\n----Problem-----\n1: Tyre\n2: Brake\n3: Body\n4: Others\n";
			cout << "Please enter code for your problem: ";
			cin >> pbCode;
			
			pbFail = cin.fail();
			cin.clear();
			cin.ignore();
			
			while(pbCode < 1 || pbCode > 4 || pbFail == true){ //error checking
				
				cout << "\nPlease enter valid code!";
				cout << "\n----Problem-----\n1: Tyre\n2: Brake\n3: Body\n4: Others\n";
				cout << "Please enter code for your problem: ";
				cin >> pbCode;
			
				pbFail = cin.fail();
				cin.clear();
				cin.ignore();
			}
			
			if(pbCode == 1){
				
				problem = "Tyres";
				pbRate = 2;
				
				
			}
			else if(pbCode == 2){
				
				problem = "Brake";
				pbRate = 1.5;
				
			}
			else if(pbCode == 3){
				
				problem = "Body";
				pbRate = 3.5;
				
			}
			else if(pbCode == 4){
				
				cout << "Please enter your problem: ";
				cin.ignore();
				getline(cin, problem);
				pbRate = 4.5;
			}
			
			cout << "In scale from 0 to 10, please rate your problem: "; //user rate their problem
			cin >> rate;
			rateFail = cin.fail(); //error checking
			cin.clear();
			cin.ignore();
			
			while(rate < 0 || rate > 10 || rateFail == true){
				
				cout << "Please enter rate between 0 to 10 only.\n";
				cout << "In scale from 0 to 10, please rate your problem: ";
				cin >> rate;
				rateFail = cin.fail();
				cin.clear();
				cin.ignore();
			
			}
			
			price = priceCalc(pbRate, rate); //calculate price
			
			cout << "\nID: " << loginID << endl;
			cout << "Problem: " << problem << endl;
			cout << "Total: RM " << fixed << setprecision(2) << price << endl;
			
			if(rate < 4){ //display the action will be taken
				
				cout << "We will send you help tomorrow.\n";
				
				
			}
			else if(rate < 7){
				
				cout << "We will send you help this evening.\n";
				
			}
			else{
				
				cout << "We will send you help immediately.\n";
			}
			
			out_rep << loginID << "\t" << problem << "\t" << rate << "\tRM "<< fixed << setprecision(2) << price << "\n";
			
		}
		
		out_rep.close();
		
		cout << "\n----- Main Menu -----\n"; //display menu after exit from any option either 1 or 2 
		cout << "1: Bicycle registration\n2: Bicycle repair\n";
		cout << "Enter code to select option or 'X' to exit: ";
		cin >> response;
		cout << endl;
		
		while(response != "1" && response != "2" && response != "X"){
			
			cout << "INVALID CODE!\n\n";
			cout << "----- Main Menu -----\n";
			cout << "1: Bicycle registration\n2: Bicycle repair\n";
			cout << "Enter code to select option or 'X' to exit: ";
			cin >> response;
			cout << endl;
			
		}
		
		
	}
	
	cout << "\nDo you want to give feedback for our application?\n";
	cout << "Enter 'Y' to continue to feedback question.\n";
	cin >> feedback;
	
	int i = 0;
	
	in_quest.open("C:\Question.txt"); //read questions from Question.txt
	
	if(feedback == "Y"){ //prompt and get feedback from user
		
		while(!in_quest.eof()){  //read Question.txt until end of file
			
			getline(in_quest, quest);
			cout << endl << i+1 << ": "<< quest << endl;
			cin.ignore();
			getline(cin, answer[i]);
			i++;
		}
		
		in_quest.close(); //close file
		
		out_ans.open("C:\AnswerFeedback.txt", fstream::app); //write feedback from user into AnswerFeedback.txt
		out_ans << loginID << endl;
	
		for(int j = 0; j < 4; j++){
		
			out_ans << answer[j] << endl;
		}
		
		out_ans.close(); //close file
		
	}
	
	return 0;
}
