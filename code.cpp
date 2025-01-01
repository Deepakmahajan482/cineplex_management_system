
#include<iostream>
#include <string>
#include<fstream>
#include<windows.h>
using namespace std;

// class for movie adding 
class Movie {
public:
    string title;
    int duration;           // Duration in minutes
    double ticketPrice;
    int seat[10][10];
    
Movie(){}
    // Constructor to initialize movie details
    Movie(string t, int d, int price) {
        title = t;
        duration = d;
        ticketPrice = price;
         for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                seat[i][j] = 0;
     
    }
         }
    }

}s[4];


// payment method
void payment_method(){
       int option;
    string transactionID;
    cout<<endl;
    cout << "Choose Online Payment Method:\n";
    cout << "1. Paytm\n";
    cout << "2. Google Pay\n";
    cout << "3. PhonePe\n";
    cout << "Enter your choice: ";
    cin >> option;

    switch(option) {
        case 1:
            cout << "Enter your Paytm transaction ID: ";
            cin >> transactionID;
            cout << "Processing payment through Paytm with transaction ID: " << transactionID << endl;
            break;
        case 2:
            cout << "Enter your Google Pay transaction ID: ";
            cin >> transactionID;
            cout << "Processing payment through Google Pay with transaction ID: " << transactionID << endl;
            break;
        case 3:
            cout << "Enter your PhonePe transaction ID: ";
            cin >> transactionID;
            cout << "Processing payment through PhonePe with transaction ID: " << transactionID << endl;
            break;
        default:
            cout << "Invalid payment option!" << endl;
            return;
    }
Sleep(3000);
    cout << "Payment successful!" << endl;
}

// display front page 
void center (){
cout<<"\n\n\n\n\n\n";
}
void display(){
	system("CLS");
	center();
    cout<<"\t\t\t=============================================================================="<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                 WELCOME TO CINEPLEX MANAGEMENT                           ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;	
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t=============================================================================="<<endl;
	system("COLOR 73");
}

// user password
class User {
private:
   const string username="deepak";
   const  string password="12345";

public:
    bool login(const string &user, const string &pass) {
        if (user == username && pass == password) {
            return true;
        }
        return false;
    }
};



// to saving movies
void save() {
    ofstream out("save.bin", ios::trunc);
    for (int i = 0; i < 4; i++) {
        if (s[i].title != "null") {
            out<<i+1<<"\n";
            out <<"the title name is "<<s[i].title << "\n" <<"the duration is " <<s[i].duration << "\n" <<"the ticket price is "<< s[i].ticketPrice << "\n";
       
        }
           ofstream out((i)+"seat.bin");

    for(int k=0;k<10;k++){
        for(int j=0;j<10;j++){
            out<<s[i].seat[k][j]<<" ";
        }
        out<<"\n";
    }
    }
    out.close();
    cout << "Movies saved successfully.\n";
}


// for printing all movies
void print(){
    ifstream in("save.bin");
    string st;
    while(getline(in,st)){
        cout<<st<<endl;
    }
    in.close();
}


 // for adding movies
void screen(){
    
    string title1;
    int dura;
    int ticket;
 cout<<   "=============================================="<<endl;
    cout<<"||       Press 1 for Screen 1               ||"<<endl;
    cout<<"||       Press 2 for Screen 2               ||"<<endl;
    cout<<"||       Press 3 for Screen 3               ||"<<endl;
    cout<<"||       Press 4 for Screen 4               ||"<<endl;
    cout<<"=============================================="<<endl;
    int select_screen;
    cin>>select_screen;
    system("CLS");
    cin.ignore();
    cout << "Enter the movie title: ";
    getline(cin, title1);  // Read the entire title including spaces

    cout << "Enter the duration (in minutes): ";
    cin >> dura;  // Read the duration
    cout<<"Enter the price of ticket ";
    cin>>ticket;
    s[select_screen-1]=Movie(title1,dura,ticket);
save();
}


// for deleting movie
void deleting_screen(){
    center();
 cout<<   "=============================================="<<endl;
    cout<<"||       Press 1 for Screen 1               ||"<<endl;
    cout<<"||       Press 2 for Screen 2               ||"<<endl;
    cout<<"||       Press 3 for Screen 3               ||"<<endl;
    cout<<"||       Press 4 for Screen 4               ||"<<endl;
    cout<<"=============================================="<<endl;
    int select_screen;
    cin>>select_screen;
    s[select_screen-1]=Movie("null",0,0);
    save();
    cout<<"screen deleted done";
}


// storing seat ticket
void seat_saving(int screen){

    ofstream out((screen-1)+"seat.bin");

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            out<<s[screen-1].seat[i][j]<<" ";
        }
        out<<"\n";
    }
    out.close();
}
// printing seat ticket
void seat_printing(){
    for(int i=0;i<4;i++){
        cout<<"     SCREEN "<<i+1<<endl;
      ifstream in(i+"seat.bin");
      int seat[10][10];
 for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                in >> seat[i][j];
                cout<<seat[i][j]<<" ";
            }
            cout<<endl;
        }
         in.close();
    }
    
   
}


// feedback
void feedback(){
    int i=1;
    ofstream out("feedback.bin");
    string feed;
    cout<<"Enter your Feedback "<<endl;
    cin.ignore();
    getline(cin,feed);
out<<i<<".  ";
out<<feed<<"\n\n\n";
out.close();
    
    i++;
}

void print_feedback(){
    string st;
    ifstream in("feedback.bin");
    while(getline(in,st)){
        cout<<st<<endl;
    }
}

// booking seat
void booking(){
     string name;
    int numTickets;
    int totalAmount;
    int seatnumber;
    center();
   
cout<<   "=============================================="<<endl;
    cout<<"||       Press 1 for Screen 1               ||"<<endl;
    cout<<"||       Press 2 for Screen 2               ||"<<endl;
    cout<<"||       Press 3 for Screen 3               ||"<<endl;
    cout<<"||       Press 4 for Screen 4               ||"<<endl;
    cout<<"=============================================="<<endl;
    int select_screen;
    cin>>select_screen;
     //storing da9ta
    ofstream out((select_screen-1)+"booking_data.bin",ios::app);
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    // name storing
    out<<"the name is :"<<name<<"\n";
    cout << "Enter the number of tickets: ";
    cin >> numTickets;
    int l=0;
    //ticket storing
    out<<"ticket number is : ";
    for(int i=0;i<numTickets;i++){
        cout<<"enter the seat number ";
        cin>>seatnumber;
        int arr[2];
        int j=0;
        while(seatnumber!=0){
        arr[j]=seatnumber%10;
        seatnumber/=10;
        j++;
        }
        if(s[select_screen-1].seat[arr[1]][arr[0]]==0){
            s[select_screen-1].seat[arr[1]][arr[0]]=1;
            cout<<"Your seat number is reserved for you !"<<endl;
        out<<arr[1]<<arr[0]<<",";
        }
        else{
            cout<<"The seat is reserved please chnge the seat number ";
            l++;
        }

      

    }
     
    if(l!=0){
        cout<<"Please book the seat for "<<l<<" person because you choose the reserved seats";
    }
  
    totalAmount = numTickets * s[select_screen-1].ticketPrice;
    // total amount storing
      out<<"\nthe totalAmount is :"<<totalAmount<<"\n";
    cout << "\n--- Movie Ticket Booking Details ---\n";
    cout << "Name: " << name << endl;
    cout << "Movie: " << s[select_screen-1].title << endl;
    cout << "Number of tickets: " << numTickets << endl;
    cout << "Price per ticket: $" << s[select_screen-1].ticketPrice << endl;
    cout << "Total amount: $" << totalAmount << endl;
    cout << "------------------------------------" << endl;
    payment_method();
    out.close();
     seat_saving(select_screen);

}


// printing data
void printing_booking_data(){
    int s;
  cout<<   "=============================================="<<endl;
    cout<<"||       Press 1 for Screen 1               ||"<<endl;
    cout<<"||       Press 2 for Screen 2               ||"<<endl;
    cout<<"||       Press 3 for Screen 3               ||"<<endl;
    cout<<"||       Press 4 for Screen 4               ||"<<endl;
    cout<<"=============================================="<<endl;
    cin>> s;
   string st; 
    ifstream in((s-1)+"booking_data.bin");
    while(getline(in,st)){
        cout<<st<<endl;
    }
}

// admin interface
void admin_interface(){
    system("CLS");
    cout<<"===================================================================="<<endl;
    cout<<"||       Press 1 for insert  movie                                ||"<<endl;
    cout<<"||       Press 2 for delete  movie                                ||"<<endl;
    cout<<"||       Press 3 Availabity  of ticket                            ||"<<endl;
    cout<<"||       Press 4 for feedbacks                                    ||"<<endl;
    cout<<"||       Press 5 for Information                                  ||"<<endl;
    cout<<"||       Press 6 Exit                                             ||"<<endl;
    cout<<"===================================================================="<<endl;
    int admin_select;
    cin>>admin_select;
    switch(admin_select){
         case 1:screen();
        break;
        case 2:deleting_screen();
        break;
        case 3:seat_printing();
        break;
        case 4:print_feedback();
        break;
        case 5:printing_booking_data();
        break;
        case 6:exit(0);
        default:cout<<"please enter from above the options";    
    }
}  









// user interface
void userselection(){
cout<<"=============================================="<<endl;
cout<<"|     Press 1 for book ticket                |"<<endl;
cout<<"|     Press 2 for veiw screen                |"<<endl;
cout<<"|     Press 3 for veiw ticket                |"<<endl;
cout<<"|     Press 4 for giving feedback            |"<<endl;
cout<<"|     Press 5 Exit                           |"<<endl;
cout<<"=============================================="<<endl;
int select;
cin>>select;
switch(select){
    case 1: booking();
    break;
    case 2:print();
    break;
    case 3: seat_printing();
    Sleep(3000);
    break;
    case 4:feedback();
    break;
    case 5:
    exit(0);
    default: cout<<"Please enter the above options "<<endl;
}
}

// choosing interface from where we want to go
void choose(){
    User user;
string loginUser,loginPass;
	Sleep(3000);
system("CLS");
system("color 73");
	int choice;
	center();
    
	 cout<<"\t\t\t=============================================================================="<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                    PRESS 1 FOR ADMIN INTERFACE                           ||"<<endl;
	cout<<"\t\t\t||                    PRESS 2 FOR USER INTERFACE                            ||"<<endl;	
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t||                                                                          ||"<<endl;
	cout<<"\t\t\t=============================================================================="<<endl;
    cin>>choice;
 

  switch(choice){

	case 1:
	
		cout << "\nUser login:\n";
    cout << "Enter username: ";
    cin >> loginUser;
    cout << "Enter password: ";
    cin >> loginPass;

    if (user.login(loginUser, loginPass)) {
        cout << "Login successful!\n";
        admin_interface();
    } else {
        cout << "Invalid username or password.\n";
    }
	
	Sleep(3000);
	break;
	case 2: userselection();
	Sleep(3000);
	break;
	default:cout<<"please enter form the above 2 options ";
  }
}



int main(){
    display();
    while(1){
    choose(); 
    }
}
