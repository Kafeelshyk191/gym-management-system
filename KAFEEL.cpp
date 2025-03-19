#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
struct Member {
    int id;
    string name;
    int age;
    string membershipType;
    string membershipStartDate;
    string membershipEndDate;
};
void displayMenu() {
    cout << "\n--- Gym Management System ---\n";
    cout << "1. Add New Member\n";
    cout << "2. Display All Members\n";
    cout << "3. Renew Membership\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}
string getCurrentDate() {
    time_t t = time(0);
    struct tm * now = localtime(&t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    return string(buffer);
}
class GymManagementSystem {
private:
    vector<Member> members;
    int nextId;

public:
    GymManagementSystem() : nextId(1) {}
    void addMember() {
        Member newMember;
        newMember.id = nextId++;
        
        cout << "Enter member name: ";
        cin.ignore();
        getline(cin, newMember.name);
        
        cout << "Enter member age: ";
        cin >> newMember.age;

        cout << "Enter membership type (e.g., Basic, Premium, VIP): ";
        cin.ignore(); 
        getline(cin, newMember.membershipType);

        newMember.membershipStartDate = getCurrentDate();
        newMember.membershipEndDate = getCurrentDate();

        members.push_back(newMember);

        cout << "Member added successfully!\n";
    }
    void displayAllMembers() {
        if (members.empty()) {
            cout << "No members to display.\n";
            return;
        }

        cout << "\n--- Member List ---\n";
        for (const auto& member : members) {
            cout << "ID: " << member.id << "\n";
            cout << "Name: " << member.name << "\n";
            cout << "Age: " << member.age << "\n";
            cout << "Membership Type: " << member.membershipType << "\n";
            cout << "Membership Start Date: " << member.membershipStartDate << "\n";
            cout << "Membership End Date: " << member.membershipEndDate << "\n";
            cout << "----------------------------\n";
        }
    }
    void renewMembership() {
        int memberId;
        cout << "Enter member ID to renew membership: ";
        cin >> memberId;

        bool found = false;
        for (auto& member : members) {
            if (member.id == memberId) {
                member.membershipEndDate = getCurrentDate();
                cout << "Membership renewed successfully for member " << member.name << "!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Member with ID " << memberId << " not found.\n";
        }
    }
};

int main() {
    GymManagementSystem gym;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                gym.addMember();
                break;
            case 2:
                gym.displayAllMembers();
                break;
            case 3:
                gym.renewMembership();
                break;
            case 4:
                cout << "Exiting Gym Management System...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
