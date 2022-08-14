// Author: Sriram Vema
// Date: 3/8/2022
// Section:5
// File: mytest.cpp
// Description: Tester file that tests different cases for elevator class
#include "elevator.h"

class Tester {
    public:
    bool insertAtHeadNormalCase(); // Adding a floor at the head
    bool insertAtHeadErrorCase(); // Number is not 1 less than current head
    bool insertAtHeadRepeatCase(); // Trying to add a floor that already exists as the head
    bool insertAtTailNormalCase(); // Adding a floor at the tail
    bool insertAtTailErrorCase(); // Number is not 1 greater than current tail
    bool insertAtTailRepeatCase(); // Trying to add a floor that already exists as the tail
    bool removeFloorNormalCase(); // Remove a floor normally
    bool removeFloorErrorCase(); // Remove an out of range floor
    bool removeFloorError1Case(); // Remove a floor twice
    bool insertFloorNormalCase(); // Insert floors normally
    bool insertFloorErrorCase(); // Insert an out of range floor
    bool checkFloorNormalCase(); // Check if an existing exists
    bool checkFloorErrorCase(); // Check if an out of range floor (negative) exists
    bool checkFloorEdgeCase(); // Check if a floor exists after it has been removed
    bool moveNormalCase(); // Move a passenger normally
    bool moveErrorCase(); // Move a passenger to an out of range destination
    bool copyConstructorNormalCase(); // Copy a filled elevator class
    bool copyConstructorEdgeCase(); // Copy an empty elevator class
    bool assignmentNormalCase(); // Copy a filled elevator class
    bool assignmentEdgeCase(); // Copy an elevator class with different number of floors
    bool enterNormalCase(); // checks if enter is working properly
    bool enterErrorCase(); // checks if it throws an out of range exception
    bool exitNormalCase(); // checks if exit is working properly
    bool exitErrorCase(); // checks if it throws an out of range exception
};

int main() {
    Tester myTest;
    cout << "Testing insertAtHead function:" << endl;
    if (myTest.insertAtHeadNormalCase()) {
        cout << "\tNormal case of insertAtHead passed!" << endl;
    } else {
        cout << "\tNormal case of insertAtHead failed!" << endl;
    }

    if (myTest.insertAtHeadErrorCase()) {
        cout << "\tError case (number is not 1 less than current head) of insertAtHead passed!" << endl;
    } else {
        cout << "\tError case (number is not 1 less than current head) of insertAtHead failed!" << endl;
    }
    if (myTest.insertAtHeadRepeatCase()) {
        cout << "\tRepeat case (trying to add a floor at head when it already exists at head) of insertAtHead passed!" << endl;
    } else {
        cout << "\tRepeat case (trying to add a floor at head when it already exists at head) of insertAtHead failed!" << endl;
    }
    cout << endl;
    cout << "Testing insertAtTail function:" << endl;
    if (myTest.insertAtTailNormalCase()) {
        cout << "\tNormal case of insertAtTail passed!" << endl;
    } else {
        cout << "\tNormal case of insertAtTail failed!" << endl;
    }

    if (myTest.insertAtTailErrorCase()) {
        cout << "\tError case (number is not 1 greater than current tail) of insertAtTail passed!" << endl;
    } else {
        cout << "\tError case (number is not 1 greater than current tail) of insertAtTail failed!" << endl;
    }

    if (myTest.insertAtTailRepeatCase()) {
        cout << "\tRepeat case (trying to add a floor at tail when it already exists at tail) of insertAtTail passed!" << endl;
    } else {
        cout << "\tRepeat case (trying to add a floor at tail when it already exists at tail) of insertAtTail failed!" << endl;
    }
    cout << endl;
    cout << "Testing removeFloor function:" << endl;
    if (myTest.removeFloorNormalCase()) {
        cout << "\tNormal case of removeFloor passed!" << endl;
    } else {
        cout << "\tNormal case of removeFloor failed!" << endl;
    }

    if (myTest.removeFloorErrorCase()) {
        cout << "\tError case (out of range index) of removeFloor passed!" << endl;
    } else {
        cout << "\tError case (out of range index) of removeFloor failed!" << endl;
    }

    if (myTest.removeFloorError1Case()) {
        cout << "\tError case (remove a floor twice) of removeFloor passed!" << endl;
    } else {
        cout << "\tError case (remove a floor twice) of removeFloor failed!" << endl;
    }
    cout << endl;
    cout << "Testing move function:" << endl;
    if (myTest.moveNormalCase()) {
        cout << "\tNormal case of move passed!" << endl;
    } else {
        cout << "\tNormal case of move failed!" << endl;
    }

    if (myTest.moveErrorCase()) {
        cout << "\tError case (Move a passenger to an out of range destination) of move passed!" << endl;
    } else {
        cout << "\tError case (Move a passenger to an out of range destination) of move failed!" << endl;
    }
    cout << endl;
    cout << "Testing insertFloor function:" << endl;
    if (myTest.insertFloorNormalCase()) {
        cout << "\tNormal case of insertFloor passed!" << endl;
    } else {
        cout << "\tNormal case of insertFloor failed!" << endl;
    }
    if (myTest.insertFloorErrorCase()) {
        cout << "\tError case (out of range index) of insertFloor passed!" << endl;
    } else {
        cout << "\tError case (out of range index) of insertFloor failed!" << endl;
    }
    cout << endl;
    cout << "Testing checkFloor function:" << endl;
    if (myTest.checkFloorNormalCase()) {
        cout << "\tNormal case of checkFloor passed!" << endl;
    } else {
        cout << "\tNormal case of checkFloor failed!" << endl;
    }
    if (myTest.checkFloorEdgeCase()) {
        cout << "\tEdge case (floor does not exist) of checkFloor passed!" << endl;
    } else {
        cout << "\tEdge case (floor does not exist) of checkFloor failed!" << endl;
    }
    if (myTest.checkFloorErrorCase()) {
        cout << "\tError case (out of range) of checkFloor passed!" << endl;
    } else {
        cout << "\tError case (out of range) of checkFloor failed!" << endl;
    }
    cout << endl;
    cout << "Testing enter function:" << endl;
    if (myTest.enterNormalCase()) {
        cout << "\tNormal case of enter passed!" << endl;
    } else {
        cout << "\tNormal case of enter failed!" << endl;
    }
    if (myTest.enterErrorCase()) {
        cout << "\tError case (out of range) of enter passed!" << endl;
    } else {
        cout << "\tError case (out of range) of enter failed!" << endl;
    }
    cout << endl;
    cout << "Testing exit function:" << endl;
    if (myTest.exitNormalCase()) {
        cout << "\tNormal case of exit passed!" << endl;
    } else {
        cout << "\tNormal case of exit failed!" << endl;
    }
    if (myTest.exitErrorCase()) {
        cout << "\tError case (out of range) of exit passed!" << endl;
    } else {
        cout << "\tError case (out of range) of exit failed!" << endl;
    }
    cout << endl;
    cout << "Testing copy constructor:" << endl;
    if (myTest.copyConstructorNormalCase()) {
        cout << "\tNormal case of copy constructor passed!" << endl;
    } else {
        cout << "\tNormal case of copy constructor failed!" << endl;
    }

    if (myTest.copyConstructorEdgeCase()) {
        cout << "\tEdge case of copy constructor (empty elevator class copied) passed!" << endl;
    } else {
        cout << "\tEdge case of copy constructor (empty elevator class copied) failed!" << endl;
    }
    cout << endl;
    cout << "Testing assignment operator:" << endl;
    if (myTest.assignmentNormalCase()) {
        cout << "\tNormal case of assignment operator passed!" << endl;
    } else {
        cout << "\tNormal case of assignment operator failed!" << endl;
    }

    if (myTest.assignmentEdgeCase()) {
        cout << "\tEdge case of assignment operator (different number of starting floors in each elevator) passed!" << endl;
    } else {
        cout << "\tEdge case of assignment operator (different number of starting floors in each elevator) failed!" << endl;
    }
    return 0;
}

bool Tester::insertAtHeadNormalCase() {
    Elevator anElev;
    bool insert;
    for (int i = 300; i >= 1; i --){
        insert = anElev.insertAtHead(i);
        if (insert == false) { // returns false if insertathead fails to insert a node
            return false;
        }
    }
    return true;
}

bool Tester::insertAtHeadErrorCase() {
    Elevator anElev;
    for (int i = 10; i >= 1; i --){
         anElev.insertAtHead(i);
    }
    if (anElev.insertAtHead(-1) == false) { // returns true if insert at head doesnt add a floor that is not one less than the current floor
        return true;
    }
    return false;
}

bool Tester::insertAtHeadRepeatCase() {
    Elevator anElev;
    for (int i = 10; i >= 1; i --){
        anElev.insertAtHead(i);
    }
    if (anElev.insertAtHead(1)) { // checks to see if insert at head adds the same floor twice
        return false;
    }
    return true;
}

bool Tester::insertAtTailNormalCase() {
    Elevator anElev;
    bool insert;
    for (int i = 1; i <= 300; i ++){
        insert = anElev.insertAtTail(i);
        if (insert == false) {
            return false;
        } // Returns false if insert at tail fails to insert a floor
    }
    return true;
}

bool Tester::insertAtTailErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    if (anElev.insertAtTail(12)) { // returns false if insert at tail adds a floor that it shouldn't (floor is not 1 greater than current floor)
        return false;
    }
    return true;
}

bool Tester::insertAtTailRepeatCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    if (anElev.insertAtTail(10)) { // checks to see if insert at tail adds the same number twice
        return false;
    }
    return true;
}

bool Tester::removeFloorNormalCase() {
    Elevator anElev;
    bool removal;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    for (int i = 1; i <= 10; i ++) {
        removal = anElev.removeFloor(i); // Makes sure removeFloor can remove every floor without issue
        if (removal == false) {
            anElev.clear();
            return false;
        }
    }
    if (anElev.m_ground == nullptr) { // returns true if every floor is removed properly
        anElev.clear();
        return true;
    } else {
        anElev.clear();
        return false;
    }
    return true;
}

bool Tester::removeFloorErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    try{
        anElev.removeFloor(0);  // checks if remove throws an exception if the floor is out of range
    } catch(out_of_range) {
        cout <<"\tFLOOR IS OUT OF RANGE" << endl;
        return true;
    }
    return false;
}

bool Tester::removeFloorError1Case() {
    Elevator anElev;
    bool removal;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    removal = anElev.removeFloor(4); // checks to see if remove deletes the same node twice
    removal = anElev.removeFloor(4);
    if (removal == true) {
        return false;
    }
    return true;
}

bool Tester::insertFloorNormalCase() {
    Elevator anElev;
    for (int i = 11; i >= 1; i --) {
        anElev.insertAtHead(i);
    }
    anElev.removeFloor(3);  // Fill the linked list
    anElev.removeFloor(9);
    anElev.removeFloor(5);
    anElev.insertFloor(3);
    anElev.insertFloor(9);
    anElev.insertFloor(5);
    Floor* curr = anElev.m_ground;
    while (curr->m_next != nullptr) {
        curr = curr->m_next;  // Iterates through the linked list to make sure every floor is in order and not repeated
        if (curr->m_floorNum <= curr->m_previous->m_floorNum) {
            return false;
        }
    }

    return true;
}

bool Tester::insertFloorErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){ // Checks to see if insert throws an out of range exception if the floor is out of range
        anElev.insertAtTail(i);
    }
    try{
        anElev.insertFloor(11);
    } catch(out_of_range) {
        cout <<"\tFLOOR IS OUT OF RANGE" << endl;
        return true;
    }
    return false;
}

bool Tester::checkFloorNormalCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){ // Checks if check floor is working properly with a normal case (floor exists)
        anElev.insertAtTail(i);
    }
    return anElev.checkFloor(5);
}

bool Tester::checkFloorErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    try{
        anElev.checkFloor(0); // Checks to see if an exception is thrown when the floor is out of range
    } catch(out_of_range) {
        cout <<"\tFLOOR IS OUT OF RANGE" << endl;
        return true;
    }
    return false;
}

bool Tester::checkFloorEdgeCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){ // CHecks if checkfloor works properly if the floor does not exist
        anElev.insertAtTail(i);
    }
    anElev.removeFloor(5);
    if (anElev.checkFloor(5)) {
        return false;
    }
    return true;
}

bool Tester::moveNormalCase() {
    Elevator anElev;
    for (int i = 1; i <= 100; i ++){
        anElev.insertAtTail(i);
    }
    anElev.enter(3, "Jake"); // checks if move works properly for a normal case
    return anElev.move(3, 76);
}

bool Tester::moveErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 100; i ++){
        anElev.insertAtTail(i);
    }
    anElev.enter(3, "Jake");
    try{
        anElev.move(3, 101); // Checks if an exception is thrown with an out of range floor
    } catch(out_of_range) {
        cout <<"\tFLOOR IS OUT OF RANGE" << endl;
        return true;
    }
    return false;
}

bool Tester::copyConstructorNormalCase() {
    Elevator anElev;
    for (int i = 1; i <= 100; i ++){ // Fills the linked list
        anElev.insertAtTail(i);
    }
    Elevator copiedElev(anElev); //Copies the elevator class
    if (anElev.m_ground != copiedElev.m_ground && anElev.m_top != copiedElev.m_top) { //makes sure all the memory addresses are different
        Floor* curr = anElev.m_ground;
        Floor* copiedCurr = copiedElev.m_ground;
        while (curr != nullptr && copiedCurr != nullptr) {  //Iterates through both linked lists tomake sure all the data is the same
            if (curr->m_floorNum != copiedCurr->m_floorNum) {
                return false;
            }
            curr = curr->m_next;
            copiedCurr = copiedCurr->m_next;
        }
        return true;
    } else {
        return false;
    }
}

bool Tester::copyConstructorEdgeCase() {
    Elevator anElev;
    Elevator copiedElev(anElev); // Copies the empty class
    if (anElev.m_ground == nullptr && copiedElev.m_ground == nullptr) { // makes sure both objects remain empty after the copy
        return true;
    }
    return false;
}

bool Tester::assignmentNormalCase() {
    Elevator anElev;
    Elevator copiedElev;
    for (int i = 1; i <= 100; i ++){
        anElev.insertAtTail(i);
    }
    copiedElev = anElev;
    if (anElev.m_ground != copiedElev.m_ground && anElev.m_top != copiedElev.m_top) { //makes sure memory addresses are different
        Floor* curr = anElev.m_ground;
        Floor* copiedCurr = copiedElev.m_ground;
        while (curr != nullptr && copiedCurr != nullptr) { // Iterates through both lists to make sure data is the same
            if (curr->m_floorNum != copiedCurr->m_floorNum) {
                return false;
            }
            curr = curr->m_next;
            copiedCurr = copiedCurr->m_next;
        }
        return true;
    } else {
        return false;
    }
}

bool Tester::assignmentEdgeCase() {
    Elevator anElev;
    Elevator copiedElev;
    for (int i = 1; i <= 2; i ++){ //Fills both objects with different number of nodes
        anElev.insertAtTail(i);
    }
    copiedElev.insertAtHead(1);
    copiedElev = anElev; // copies the object
    if (anElev.m_ground != copiedElev.m_ground && anElev.m_top != copiedElev.m_top) { //makes sure the memory addresses are different
        Floor* curr = anElev.m_ground;
        Floor* copiedCurr = copiedElev.m_ground;
        while (curr != nullptr && copiedCurr != nullptr) { // Iterates through each list to see if the data is the same
            if (curr->m_floorNum != copiedCurr->m_floorNum) {
                return false;
            }
            curr = curr->m_next;
            copiedCurr = copiedCurr->m_next;
        }
        return true;
    } else {
        return false;
    }
}

bool Tester::enterNormalCase() {
    Elevator anElev;
    string name = "Sally";
    for (int i = 1; i <= 100; i ++){
        anElev.insertAtTail(i);
    }  
    return anElev.enter(3, name); //Checks if name is properly entered 
}

bool Tester::enterErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    } 
    try{
        anElev.enter(11, "Molly"); // check if an exception is thrown when floor is out of range
    } catch(out_of_range) {
        cout <<"\tFLOOR IS OUT OF RANGE" << endl;
        return true;
    }
    return false;
}


bool Tester::exitNormalCase() {
    Elevator anElev;
    for (int i = 1; i <= 100; i ++){
        anElev.insertAtTail(i);
    }
    anElev.enter(11, "Molly");
    if (anElev.exit(11, "Molly") == "Molly") { // checks if the passenger properly exists the elevator
        return true;
    }
    return false;
}

bool Tester::exitErrorCase() {
    Elevator anElev;
    for (int i = 1; i <= 10; i ++){
        anElev.insertAtTail(i);
    }
    try{
        anElev.exit(11, "Molly"); // Checks if an out of range exception is thrown when floor is out of range
    } catch(out_of_range) {
        cout <<"\tFLOOR IS OUT OF RANGE" << endl;
        return true;
    } 
    return false;
}
