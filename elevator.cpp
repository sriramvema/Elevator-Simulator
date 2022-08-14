// UMBC - CMSC 341 - Spring 2022 - Proj1
// Author: Sriram Vema
// Date: 3/8/2022
// Section:5
// File: elevator.cpp
// Description: Elevator file that holds elevator class functions
#include "elevator.h"

Elevator::Elevator(){
    m_ground = nullptr; // Default constructor sets ground and top pointers to nullptr
    m_top = m_ground;
}

Elevator::~Elevator(){
    clear(); // Calls clear to delete the linked list
}

void Elevator::clear(){
    Floor* curr = m_ground;
    if (m_ground != nullptr) {
        while (curr->m_next != nullptr) {
            curr = curr->m_next;      // Iterates through the linked list and deletes the previous node
            delete curr->m_previous;
            curr->m_previous = nullptr;
        }
        delete curr; // Deletes the last remaining node
        m_ground = nullptr; // Sets ground and top back to default nullptr
        m_top = nullptr;
    }
}

bool Elevator::insertAtHead(int floor, string passenger){
    Floor* newFloor = new Floor(floor, passenger);  // Creates the floor to be added
    if (m_ground == nullptr) {
        m_ground = newFloor;  // If the list is empty then adds it as the head
        m_top = m_ground;
        return true;
    } else {
        if (floor == (m_ground->m_floorNum - 1)) {
            newFloor->m_next = m_ground;    // Checks if the floor is one less than the current head before adding
            m_ground->m_previous = newFloor;
            m_ground = newFloor; 
            return true;          
        } else {
            delete newFloor;
            return false;
        }
    }
    delete newFloor;
    return false;
}

bool Elevator::insertAtTail(int floor, string passenger){
    Floor* newFloor = new Floor(floor, passenger);  
    if (m_ground == nullptr && floor > 0) {
        m_ground = newFloor; // If the list is empty then adds it as the head
        m_top = m_ground;
        return true;
    } else {
        if (floor == (m_top->m_floorNum + 1) && floor > 0) {  // checks to see if the floor is one greater than the current tail before adding
            m_top->m_next = newFloor;
            newFloor->m_previous = m_top;
            m_top = newFloor;  
            return true;          
        } else {
            delete newFloor;
            return false;
        }

    }
    delete newFloor;
    return false;
}

bool Elevator::removeFloor(int floor){
    if (checkFloor(floor)) { // checks to see if the floor exists
        Floor* curr;
        int topDif = m_top->m_floorNum - floor;        // integers to compare the distance from the ground and tail
        int groundDif = floor - m_ground->m_floorNum;
        if (m_ground == m_top) {
            curr = m_ground;
            m_ground = nullptr;
            m_top = nullptr;
            delete curr;
            return true;
        }
        if (m_top->m_floorNum == floor) { // if the floor is the tail then it deletes the tail and sets it as the previous node
            curr = m_top;
            m_top = curr->m_previous;
            m_top->m_next = nullptr;
            delete curr;
            return true;
        } else if (m_ground->m_floorNum == floor) { // if the floor is the head then it sets the head as the next node and deletes the floor
                curr = m_ground;
                m_ground = curr->m_next;
                m_ground->m_previous = nullptr;
                delete curr;
                return true;
        } else if (groundDif < topDif) { // checks to see which distance is shorter to the floor from the head or tail and iterates that way
            curr = m_ground;
            while (curr->m_floorNum != floor) {
                curr = curr->m_next;
            }
            curr->m_next->m_previous = curr->m_previous;  // Removes the node from the linked list first and then deletes it
            curr->m_previous->m_next = curr->m_next;  
            delete curr;
            return true;          
        } else {
            curr = m_top;
            while (curr->m_floorNum != floor) {
                curr = curr->m_previous;
            }
            curr->m_next->m_previous = curr->m_previous;
            curr->m_previous->m_next = curr->m_next;
            delete curr;
            return true;
        }
    } else {
        return false;
    }
}
bool Elevator::insertFloor(int floor){
    int topDif, groundDif;
    Floor* insertedFloor = new Floor(floor, "");
    try{
        checkFloor(floor);  // If the floor is out of range it deletes the floor that was just created to prevent a memory leak
    } catch(out_of_range) {
        delete insertedFloor;
    }
    if (m_ground == nullptr) { // if the list is empty then it fills the head with the floor
        insertAtHead(floor);
        delete insertedFloor;
        return true;
    } else if (checkFloor(floor) == false) {  // checks to see if the floor exists
        Floor* curr;
        groundDif = floor - m_ground->m_floorNum;
        topDif = m_top->m_floorNum - floor;
        if ( groundDif < topDif || groundDif == topDif) {      // Decides which way to iterate from
            curr = m_ground;
            while (curr != nullptr && curr->m_next->m_floorNum < floor) {
                curr = curr->m_next;
            }
        } else {
            curr = m_top;
            while (curr != nullptr && curr->m_floorNum > floor) {
                curr = curr->m_previous;
            }
        }
        insertedFloor->m_next = curr->m_next;    // Finds the spot in which the floor would fit in the linked list and adds it there
        curr->m_next->m_previous = insertedFloor;
        curr->m_next = insertedFloor;
        insertedFloor->m_previous = curr;
        return true;
    } else {
        delete insertedFloor;
        return false;
    }
    delete insertedFloor;
    return false;
}

bool Elevator::checkFloor(int floor){
    if (floor < m_ground->m_floorNum || floor > m_top->m_floorNum) {  // Throws out of range exception if the floor is out of range
        throw std::out_of_range("FLOOR NUMBER OUT OF RANGE");
        return false;
    }
    if (m_ground != nullptr) {
        if (floor < m_ground->m_floorNum || floor > m_top->m_floorNum) {  // Iterates through the linked list to find the floor number
            return false;
        } else if (m_ground != nullptr) {
            Floor* curr = m_ground;
            while (curr != nullptr) {
                if (curr->m_floorNum == floor) {
                    return true;
                } else{
                    curr = curr->m_next;
                }
            }
        }
    }
    return false;
}
bool Elevator::move(int origin, int destination){
    if (checkFloor(origin) && checkFloor(destination)) { // checks if the floors exist
        Floor* start;
        Floor* switched;
        if (origin > destination) {  // Decides which way to iterate from
            start = m_top;
            while (start->m_floorNum != origin && start->m_previous != nullptr) {
                start = start->m_previous;
            }
            if (start->m_floorNum == origin) {
                switched = start;
                while (switched->m_floorNum != destination && switched->m_previous != nullptr) {
                    switched = switched->m_previous;
                }
                if (switched->m_passenger.empty() && switched->m_floorNum == destination) { // checks if anyone is at the destination before moving
                    switched->m_passenger = start->m_passenger;
                    start->m_passenger = "";
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }

        } else if (origin < destination){
            start = m_ground;
            while (start->m_floorNum != origin && start->m_next != nullptr) {
                start = start->m_next;
            }
            if (start->m_floorNum == origin) {
                switched = start;
                while (switched->m_floorNum != destination && switched->m_next != nullptr) {
                    switched = switched->m_next;
                }  
                if (switched->m_passenger.empty() && switched->m_floorNum == destination) {
                    switched->m_passenger = start->m_passenger;
                    start->m_passenger = "";
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }        
    } else {
        return false;
    }
}

string Elevator::exit(int floor, string passenger){
    if (checkFloor(floor) == true) {
        Floor* curr = m_ground;
        while(curr->m_floorNum != floor) { // iterates to the floor
            curr = curr->m_next;
        }
        if (curr->m_passenger == passenger) {
            curr->m_passenger = ""; // emptys the elevator
            return passenger;
        } else {
            return "";
        }   
    } else {
        if (floor < m_ground->m_floorNum || floor > m_top->m_floorNum) { // Throws an exception if the floor is out of range
            throw std::out_of_range("FLOOR NUMBER OUT OF RANGE");
        }
        return "";
    }
}

bool Elevator::enter(int floor, string passenger){
    if (checkFloor(floor) == true) {  // Checks if the floor exists
        Floor* curr = m_ground;
        while(curr->m_floorNum != floor) {
            curr = curr->m_next;  // iterates to the floor 
        }
        if (curr->m_passenger.empty()) {
            curr->m_passenger = passenger; // Adds the passenger
            return true;
        } else {
            return false;
        }
    } else {
        if (floor < m_ground->m_floorNum || floor > m_top->m_floorNum) {
            throw std::out_of_range("FLOOR NUMBER OUT OF RANGE");
        }
        return false;
    }
}

Elevator::Elevator(const Elevator & rhs){
    Floor* curr = rhs.m_ground;
    if (rhs.m_ground != nullptr) {
        Floor* groundLevel = new Floor(rhs.m_ground->m_floorNum);
        Floor* topLevel = new Floor(rhs.m_top->m_floorNum);
        if (rhs.m_ground->m_floorNum != rhs.m_top->m_floorNum) {
            m_ground = groundLevel;
            m_top = topLevel;
            m_ground->m_next = m_top;       // Sets the ground and top for the new elevator
            m_top->m_previous = m_ground; 
            if (rhs.m_ground->m_next != rhs.m_top) {
                while (curr != nullptr) {   // iterates through rhs and adds the data to linked list
                    insertFloor(curr->m_floorNum);
                    curr = curr->m_next;
                }
                curr = rhs.m_ground;
                while (curr != nullptr) {
                    if (curr->m_passenger.empty() == false) {  // If rhs has any passengers they will also be copied in
                        enter(curr->m_floorNum, curr->m_passenger);
                    }
                    curr = curr->m_next;
                }
            }         
        } else {
            m_ground = groundLevel;
            m_top = m_ground;           
        }
    } else {
        m_ground = nullptr;
        m_top = nullptr;
    }
}

const Elevator & Elevator::operator=(const Elevator & rhs){
    clear(); // clears the linked list before copying
    if (this != &rhs) {
        Floor* curr = rhs.m_ground;
        Floor* groundLevel = new Floor(rhs.m_ground->m_floorNum);
        Floor* topLevel = new Floor(rhs.m_top->m_floorNum);
        if (rhs.m_ground->m_floorNum != rhs.m_top->m_floorNum) {
            m_ground = groundLevel;
            m_top = topLevel;
            m_ground->m_next = m_top;
            m_top->m_previous = m_ground; 
            if (rhs.m_ground->m_next != rhs.m_top) {
                while (curr != nullptr) {
                    insertFloor(curr->m_floorNum);
                    curr = curr->m_next;
                }
                curr = rhs.m_ground;
                while (curr != nullptr) {
                    if (curr->m_passenger.empty() == false) {
                        enter(curr->m_floorNum, curr->m_passenger);
                    }
                    curr = curr->m_next;
                }
            }         
        } else {
            m_ground = groundLevel;
            m_top = m_ground;           
        }
    }
    return *this;
}
void Elevator::dump(){
    if (m_top != nullptr){
        Floor *temp = m_top;
        cout << "Top Floor " ;
        while(temp->m_previous != nullptr){
            cout << temp->m_floorNum << " (" << temp->m_passenger << ")" << endl;
            temp = temp->m_previous;
        }
        cout << "Ground Floor " << temp->m_floorNum << " (" << temp->m_passenger << ")" << endl;
    }
}