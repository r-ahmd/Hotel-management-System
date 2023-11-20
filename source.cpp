#include <bits/stdc++.h>
#include <queue>

using namespace std;

//Node for the linked list(Room)
struct RoomNode {
  int roomNumber;
  bool isBooked;
  RoomNode* next;

  RoomNode(int roomNum)
  {
    roomNumber=roomNum;
    isBooked=false;
    next=nullptr;
  }
};

//LL for managing rooms
class HotelRooms{
private:
  RoomNode* head;

public:
  HotelRooms()  //HotelRooms() : head(nullptr) {} //can be used
  {
    head=nullptr;
  }

  //add a room
  void addRoom(int roomNumber)
  {
    RoomNode* newNode = new RoomNode(roomNumber);
    newNode->next = head;
    head = newNode;
  }

  //book a room
  bool bookRoom()
  {
    RoomNode* temp = head;
    while (temp != nullptr)
    {
      if (!temp->isBooked)
      {
        temp->isBooked = true;
        cout<< "Room "<< temp->roomNumber <<" booked." <<endl;
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  //display room status
  void displayRooms()
  {
    RoomNode* temp = head;
    while (temp != nullptr) {
        cout<<"Room " <<temp->roomNumber << ": "<< (temp->isBooked ? "Booked." : "Available.") <<endl;
        temp = temp->next;
    }
  }

    ~HotelRooms() {    //Distractor 
      while (head != nullptr) {
        RoomNode* temp = head;
        head = head->next;
        delete temp;
      }
    }
};

queue<int> bookingQueue;

//add a booking request
void addBookingRequest(int customerId)
{
    bookingQueue.push(customerId);
    cout<< "Booking request added for customer "<< customerId << ".\n" <<endl;
}

int main() 
{
  HotelRooms hotel;
  hotel.addRoom(101);
  hotel.addRoom(102);
  hotel.addRoom(103);
  hotel.addRoom(104);
  hotel.addRoom(105);


  int customerId;
  cout<<"Enter customer ID to add to booking queue (0 to stop): ";
  while(cin >> customerId && customerId != 0) {
      bookingQueue.push(customerId);
      cout<< "Added customer "<< customerId << " to booking queue.\n" << endl;
      cout<< "Enter next customer ID (0 to stop): ";
  }

  while(!bookingQueue.empty())
  {
    cout<< "\nProcessing booking for customer " <<bookingQueue.front()<<".\n"<<endl;
    if(hotel.bookRoom())
      cout<< "Booking successful.\n" <<endl;
    else
      cout<< "No rooms available.\n"<<endl;
    bookingQueue.pop();
  }

  cout<<"\nRoom Status:\n" << endl;
  hotel.displayRooms();

  return 0;
}



//-----------By TechTitans----------
