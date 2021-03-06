#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
#include <fstream.h>

//STRUCT DEFINITION
struct iCareBlood
{
	char donorNames[50];
   char donorBloodType[50];
   char DonorZipCode[50];
	char telephone[50];
};



//FUNCTION PROTOTYPE
int donorSection(int n, iCareBlood donor[]);
void receiverSection(iCareBlood donor[999]);




//MAIN FUNCTION
void main()
{
	char DonororReceiver[10], respond1 ;
   int n = 0;
   iCareBlood donor[999];

	cout << "================================================================================";
	cout << "\n\t\t\tHELLO! WELCOME TO iCare Blood." << endl;
	cout << "\n================================================================================" << endl;

   do
   {

	cout << "Donor or Receiver - ";
   cin.getline(DonororReceiver,10);

   if (strcmp(DonororReceiver, "Donor")==0 || strcmp(DonororReceiver, "donor")==0)
   {
   	donorSection(n, donor);
   }

   else if (strcmp(DonororReceiver, "Receiver")==0 || strcmp(DonororReceiver, "receiver")==0)
   {
   	receiverSection(donor);
   }

   else if (strcmp(DonororReceiver, "Donor") && strcmp(DonororReceiver, "Donor") && strcmp(DonororReceiver, "Receiver") && strcmp(DonororReceiver, "receiver")!=0)
   {
   	do
   	{
   		cout << "Please enter again" << endl;
   		cin.getline(DonororReceiver,10);
         if (strcmp(DonororReceiver, "Donor")==0 || strcmp(DonororReceiver, "donor")==0)
   		{
   			donorSection(n, donor);
   		}

   		else if (strcmp(DonororReceiver, "Receiver")==0 || strcmp(DonororReceiver, "receiver")==0)
   		{
   			receiverSection(donor);
   		}
   	}while(strcmp(DonororReceiver, "Donor") && strcmp(DonororReceiver, "Donor") && strcmp(DonororReceiver, "Receiver") && strcmp(DonororReceiver, "receiver")!=0);
   }

   cout << "\nGo to main menu? (Y - Yes | N - No) - ";
   cin >> respond1;
   cout << "\n================================================================================" << endl;
   }while(respond1 == 'Y');

   getch();
}






//FUNCTION DONOR
int donorSection(int n, iCareBlood donor[])
{
   int i=0;
	char respond2;

   cout << "\n\n\t\t   --------------------------------------" << endl;
   cout << "\t\t\t\t    DONOR" << endl;
   cout << "\t\t   --------------------------------------" << endl;
   cout << "Thank you for your concern and interest in joining us. Your participation might save one's live. Kindly please enter your details as follow." << endl;

   ofstream outFile;
   outFile.open("fout.txt");
   outFile << "GENERAL REQUIREMENTS FOR BLOOD DONATION" << endl;
	outFile << "\n[Blood Donor Qualifications]" << endl;
	outFile << "Age				: 18 (16 and 17 year-olds can donate with a Minor Donor Permission Form signed by a parent or guardian)" << endl;
	outFile << "Weight			: At least 110 lbs" << endl;
	outFile << "Health			: General good health" << endl;
	outFile << "Identification	: Valid identification such as a driver?s license, DMV identification card, passport, etc." << endl;
	outFile << "\n[Do not donate if any of the following apply to you]" << endl;
	outFile << "HIV/AIDS			: You are a person with symptoms or laboratory evidence of HIV infection." << endl;
	outFile << "Cancer			: Hematological, ie: Hodgkin, Leukemia, Lymphomas." << endl;
	outFile << "Hepatitis		: A history of the disease after the age of 11, or a positive lab test for the virus." << endl;
	outFile << "Organ Failure	: Kidney, lung or liver failure." << endl;
	outFile << "Sexual History	: You have engaged in sex for money or drugs since 1977.";
   outFile.close();

   do
   {
   cout << "\nNAME       - ";
   cin.getline(donor[n].donorNames,50);
   cout << "ZIP CODE   - ";
   cin.getline(donor[n].DonorZipCode,50);
   cout << "TELEPHONE  - ";
   cin.getline(donor[n].telephone,50);
   cout << "BLOOD TYPE - ";
   cin.getline(donor[n].donorBloodType,50);
	cout << "\nThank you! Your donation details as followed has been stored." << endl;

   cout << "\n**************************" << endl;
   cout << " Name: " << donor[n].donorNames << endl;
   cout << " ZIP CODE: " << donor[n].DonorZipCode << endl;
   cout << " TELEPHONE: " << donor[n].telephone << endl;
   cout << " BLOOD TYPE: " << donor[n].donorBloodType << endl;
   cout << "**************************" << endl;

   i++;
   n = i;
   cout << "\nEnter another donator? (Y - Yes | N - No) - ";
   cin >> respond2;
   cout << "________________________________________________________________________________";
   cin.ignore();
   }while (respond2 == 'Y');

   return n;
}






//FUNCTION RECEIVER
void receiverSection(iCareBlood donor[999])
{
	char receiverBloodType[50], receiverZipCode[50];

	cout << "\n\n\t\t   --------------------------------------" << endl;
   cout << "\t\t\t\t  RECEIVER" << endl;
   cout << "\t\t   --------------------------------------" << endl;
   cout << "Thank you for using our services. We are here to help you find donor with your  type of blood. Kindly please enter details as follow." << endl << endl;


   int row, col;
   char blood[9][4] = {{"O- "},{"O+ "},{"A- "},{"A+ "},{"B- "},{"B+ "},{"AB-"},{"AB+"}};
   cout << "     O-  O+  A-  A+  B-  B+  AB- AB+"  <<endl;
   cout<< blood[0] << "  ";
   for(row = 1 ; row <= 8 ; row++)
   {
   	for(col = 1 ; col <= 8 ; col++)
      {
         if(col == 1)
         	cout << "/   ";
         else if(row == 8)
         	cout << "/   ";
         else if (row == col)
         	cout << "/   ";
         else if (row%2 == 0 && col < 3)
         	cout << "/   ";
         else if (col%2 == 1 && row == 7)
         	cout << "/   ";
         else if (row == 6 && col == 5)
         	cout << "/   ";
         else if (row == 4 && col == 3)
         	cout << "/   ";
      	else if(row < col)
         	cout << "X   " ;
         else
         	cout << "X   ";

      }
      cout << endl;
      cout << blood[row] << "  ";
   }


   cout << "\nBLOOD TYPE - ";
   cin >> receiverBloodType;
   cout << "ZIP CODE   - ";
   cin >> receiverZipCode;
   cout << endl << "NAME" << setw(20) << "TELEPHONE" << setw(20) << "ZIP CODE" << setw(20) << "BLOOD TYPE";
   for(int i=0; i<999; i++)
   {
   	if(strcmp(receiverZipCode, donor[i].DonorZipCode)==0)
      {
      	if(strcmp(receiverBloodType, donor[i].donorBloodType)==0)
         {
      		cout << endl << donor[i].donorNames << setw(20) << donor[i].telephone << setw(20) << donor[i].DonorZipCode << setw(20) << donor[i].donorBloodType << endl;
         }
      }
   }


}
