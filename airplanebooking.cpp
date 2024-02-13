#include<bits/stdc++.h>
using namespace std;
int price_paid[100] = {0};
int seats_booked[100] = {0};
int flight_id[2] = {1,2};
int seats_remaining[2] = {50,50};
int price[2] = {5000,5000};
int customer_id = 0;
vector<int>flight1p;
vector<int>flight2p;
set<int>custid;

class Booking{
    public:
     
	int fid;
	
	
	
	
public:
     bool checkseats(int seatsreq,int id){
         int seats_available = seats_remaining[id-1];
         if(seats_available < seatsreq) return false;
         else return true;
         
        
    }
    void printdetails(int id,int seats,int customer_id){
        
        
        cout << "Customer ID " << customer_id <<"|"<< "  Booked Flight " << id<<"|" << "  Price Rs. " << 
        price[id-1]*seats <<"|"<< endl;
        
        price_paid[customer_id] = price[id-1]*seats;
        seats_booked[customer_id] = seats;
        price[id-1] += 200;
       
        displayflightdetails(id);
        
        
        
        
    }
    void book(int seats,int id){
        customer_id++;
        custid.insert(customer_id);
        if(id == 1) flight1p.push_back(customer_id);
        if(id == 2) flight2p.push_back(customer_id);
        seats_remaining[id-1] -= seats;
        cout << "Booked Succesfully!" << endl;
        printdetails(id,seats,customer_id);
    }
	void displayflightdetails(int id){
		cout << "Flight ID ----> " << id <<"|" <<" Seats remaining ----> " << seats_remaining[id-1]<<"|" << " Price ----> Rs. " << price[id-1] <<"|"<< endl;

	}
	void cancel(int cid,int fid){
	    int refund = price_paid[cid];
	    int sbooked = seats_booked[cid];
	    cout << sbooked << endl;
	    seats_remaining[fid-1] += sbooked;
	    price[fid-1] -= sbooked*200;
	    cout << "Refund amount Rs."  << refund << endl;
	    cout << "Booking cancelled succesfully!" << endl;
	    displayflightdetails(fid);
	    
	}
	void printfinaldetails(){
	    cout << "Flight ID----->1" << endl;
	    for(int i =1;i<=flight1p.size();i++){
	        cout << "Customer ID ---> " << i << "Tickets Booked---> " << seats_booked[i] << "Price---> " << price_paid[i] << endl;
	    }
	    cout << "Flight ID----->2" << endl;
	    for(int i =1;i<=flight2p.size();i++){
	        cout << "Customer ID ---> " << i << "Tickets Booked---> " << seats_booked[i] << "Price---> " << price_paid[i] << endl;
	    }
	}
	


};

int main(){
    int t = 10;
    while(t>0){
	cout << "Welcome to Zoho Airlines" << endl;
	cout << "1.Book  2. Cancel  3.Print" << endl;
	int in;
	cin >> in;
	Booking booking1;

	///booking condtition
	if(in == 1){
		cout << "Enter flight ID:" << endl;
		int id;
		cin >> id;
		
		booking1.displayflightdetails(id);
		cout << "Enter required number of seats:" << endl;
		int seatsreq;
		cin >> seatsreq;
		bool available = booking1.checkseats(seatsreq,id);
		if(available == true){
		    booking1.book(seatsreq,id);
		}
		else {
		    cout << "Sorry the requested number of seats are not available:[" << endl;
		}

	    }
	    if(in == 2){
	        cout << "Enter the Customer id and flight id" << endl;
	        int cid,fid;
	        cin >> cid ;
	        cin >> fid;
	        if((custid.find(cid) == custid.end()) and ((fid!=1) or (fid !=2))){
	            cout << "Enter valid details" << endl;
	        }
	        else{
	       
	        booking1.cancel(cid,fid);
	        }
	        
	    }
	    if(in==3){
	        
	        Booking booking1;
	        booking1.printfinaldetails();
	        
	    }
	    t--;
    }
	   

	return 0;



}


