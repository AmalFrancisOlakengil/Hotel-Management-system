#include <iostream>
#include <Windows.h>
#include "SDL.h"
#pragma comment(lib, "winmm.lib")
using namespace std;



class customer;

void cust_staff();
void JukeBox();
void renderImage();
string CH = "NOT DONE", FD = "NOT DONE", RS = "NOT DONE", WO = "NOT DONE", JBO = "NOT DONE";



class bookingdetails {
private:
    int norooms;
    int nodays;
    string food;
    bool pay;
    int totalamt;

public:
    bookingdetails() {}
    bookingdetails(int nr, int nd, string f, bool p, int t) {
        norooms = nr;
        nodays = nd;
        food = f;
        pay = p;
        totalamt = t;
    }
};

bookingdetails bookdetail[100];

class booking {
private:
    int numroom;
    int numdays;
    string incfood;
    string paychoise;
    bool pay;
    int tot = 0;
    string cnb;

public:
    booking() {}

    void book() {
        int j = 0;
        cout << "No of rooms?\n";
        cin >> numroom;
        cout << "No of days?\n";
        cin >> numdays;
        cout << "Include food? (yes/no):\n";
        cin >> incfood;
        if (incfood == "yes") {
            incfood = "include";
            tot = (100 * numroom) * (numdays)+500;
        }
        else {
            incfood = "not include";
            tot = (100 * numroom) * (numdays);
        }
        cout << "Confirm booking? (yes/no):\n";
        cin >> cnb;
        if (cnb == "yes") {
            cout << "Total Amount =" << tot << endl;

            cout << "Proceed to pay? (yes/no):\n";
            cin >> paychoise;
            if (paychoise == "yes") {
                pay = true;
                bookdetail[j] = bookingdetails(numroom, numdays, incfood, pay, tot);
                j++;
                cout << "Booking successfully completed, thank you!\n"; // Added line
                PlaySound(L"109662__grunz__success.wav", NULL, SND_FILENAME | SND_ASYNC);
            }
            else {
                pay = false;
            }

        }
        else {
            int choise;
            cout << "For booking, Press '1'\nFor logout, Press '2' \n";
            cin >> choise;
            if (choise == 1) {
                book();
            }
            else {

            }
        }
    }
};

class accdetails {
private:
    string user;
    string password;

public:
    accdetails() {}
    accdetails(string u, string p) {
        user = u;
        password = p;
    }

    bool checkDetails(string u, string p) {
        if (user == u && password == p) {
            return true;
        }
        else {
            return false;
        }
    }
};

accdetails details[10]; // Array of accdetails

class account : public booking {
private:
    int i = 0;
    string userid;
    string pass;

public:
    int check = 0;
    account() {}

    void signup() {
        cout << "Enter username: \n";
        cin >> userid;
        cout << "Enter password: \n";
        cin >> pass;
        details[i] = accdetails(userid, pass); // Create and store accdetails object
        i++;
    }

    void login() {
        bool res = false;
        cout << "Enter username: \n";
        cin >> userid;
        cout << "Enter password: \n";
        cin >> pass;
        for (int j = 0; j < i; j++) {
            res = details[j].checkDetails(userid, pass);
            if (res == true) {
                cout << "^^^Login Success!^^^\n";
                PlaySound(L"109662__grunz__success.wav", NULL, SND_FILENAME | SND_ASYNC);
                book();
                break;
            }
        }
        if (res == false) {
            cout << "XXXInvalid PasswordXXX\n";
            PlaySound(L"572936__bloodpixelhero__error.wav", NULL, SND_FILENAME | SND_ASYNC);

        }
    }
};

class customer : public account {
public:
    customer() {
        custlogin();
    }

    void custlogin() {
        while (true) {
            cout << "For Sign up, Press '1'\nFor login, Press '2' \nFor Exit, Press '3' \nFor Juke Box, Press '4'\nFor Resort Beach Image, Press '5'\n";
            int menu_choice = 0;
            cin >> menu_choice;
            if (menu_choice == 1) {
                signup();
            }
            else if (menu_choice == 2) {
                login();
            }
            else if (menu_choice == 3) {
                cust_staff();
            }
            else if (menu_choice == 4) {
                JukeBox();
            }
            else if (menu_choice == 5) {
                renderImage();
            }
            else {
                cout << "Invalid Choice\n";
            }
        }
    }
};

class login {
public:
    void login_employee() {
        int role = 0;
        int ID = 0;
        cout << "Choose a role:\n" << "Chef -> Press '1'\n";
        cout << "Front Desk -> Press '2'\n";
        cout << "Room service -> Press '3'\n";
        cout << "Weather Operator -> Press '4'\n";
        cout << "Juke Box Operator -> Press '5'\n";
        cin >> role;
        switch (role) {
        case 1: cout << "Enter Password:\n";
            cin >> ID;
            break;
        case 2: cout << "Enter Password:\n";
            cin >> ID;
            break;
        case 3: cout << "Enter Password:\n";
            cin >> ID;
            break;
        case 4: cout << "Enter Password:\n";
            cin >> ID;
            break;
        case 5: cout << "Enter Password:\n";
            cin >> ID;
            break;
        default:
            cout << "Invalid Role\n";
        }
        int completion = 2;
        while (completion == 2) {
            switch (ID) {
            case 101: cout << "TASK:\n1.Prepare Breakfast\n2.Prepare Lunch\n3.Prepare Dinner\n";

                break;
            case 102: cout << "TASK:\n1.Deal with new customers\n2.Help with Complaints\n3.Deal with Reservations\n";

                break;
            case 103: cout << "TASK:\n1.Clean empty rooms\n2.Deep clean vacated rooms\n3.Deliver food Orders\n";

                break;
            case 104: cout << "TASK:\n1.Check Weather accuracy\n2.Satellite maintainance\n3.Weather info Maintanance\n";

                break;
            case 105: cout << "TASK:\n1.Update Music List\n2.Speaker Maintainance\n3.Device Repair\n";

                break;
            default:
                cout << "Invalid Password\n";
            }
            cout << "Task Completed?\n yes -> press '1'\n no -> press '2':\n";
            cin >> completion;
        }
        switch (ID) {
        case 101: CH = "Done";

            break;
        case 102: FD = "DONE";

            break;
        case 103: RS = "DONE";

            break;
        case 104: WO = "DONE";

            break;
        case 105: JBO = "DONE";

            break;
        default:
            cout << "Invalid Password\n";
        }

        cust_staff();
    }

    void login_manager() {
        int Pass_man = 0;
        cout << "Enter Password\n";
        cin >> Pass_man;
        if (Pass_man == 100) {
            int s_l = 1;
            while (s_l == 1) {
                int terminate = 0;
                cout << "STATUS:\n";
                cout << "The Chef has " + CH + " his work\n";
                cout << "The Front Desk has " + FD + " his work\n";
                cout << "The Room Service has " + RS + " his work\n";
                cout << "The Weather Operator has " + WO + " his work\n";
                cout << "The Juke Box Operator has " + JBO + " his work\n";
                cout << "DO YOU WANT TO TERMINATE THE PROGRAM?\nYes -> Press '1'\nNo -> Press '2'\n";
                cin >> terminate;
                if (terminate == 1) {
                    exit(0);
                }
                else {
                    cout << "Go to Status/login?\nStatus -> Press '1'\nlogin -> Press '2'\n";
                    cin >> s_l;
                    if (s_l == 2) {
                        cust_staff();
                    }
                }
            }
        }
    }
};

class employee : public login {
public:
    employee() {
        int condition = 2;
        while (condition == 2) {
            login_employee();
            cout << "Exit -> Press '1'\nNext Employee -> Press '2'\n";
            cin >> condition;
        }
    }
};

class manager : public login {
public:
    manager() {
        login_manager();
    }
};

void cust_staff() {
    int class_type;
    cout << "############################################\n            RESORT MANAGEMENT\n############################################" << endl;
    cout << "CUSTOMER OR STAFF?\nPress '1' for Customer\nPress '2' for Staff\n";
    cin >> class_type;
    if (class_type == 1) {
        customer c1;
    }
    else {
        int choice;
        cout << "EMPLOYEE OR MANAGER?\nPress '1' for Employee\nPress '2' for Manager\n";
        cin >> choice;
        if (choice == 1) {
            employee e1;
        }
        else {
            manager m1;
        }
    }
}
void JukeBox() {
    int choice = 0;
    cout << "Please select a Music:\n";
    cout << "Marana Mass -> Press '1'\n";
    cout << "Hukum -> Press '2'\n";
    cout << "Moye Moye -> Press '3'\n";
    cout << "Stop Music -> Press '4'\n";
    cin >> choice;
    switch (choice) {
    case 1:   PlaySound(L"Marana-Mass-MassTamilan.org.wav", NULL, SND_FILENAME | SND_ASYNC);
        break;
    case 2: PlaySound(L"Hukum_128-(PagalWorld).wav", NULL, SND_FILENAME | SND_ASYNC);
        break;
    case 3: PlaySound(L"Moye-Moye(PaglaSongs).wav", NULL, SND_FILENAME | SND_ASYNC);
        break;
    case 4:   PlaySound(nullptr, NULL, 0);
        break;
    default:
        cout << "Invalid option\n";
    }
    int choice2 = 0;
    cout << "Another Music -> Press '1'\ncustomer Menu -> Press '2'\n";
    cin >> choice2;
    if (choice2 == 2) {
        customer c2;
    }
    else {
        JukeBox();
    }
}
void renderImage() {
    int time = 1;
    cout << "Enter Image Display time (seconds): ";
    cin >> time;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* imageSurface = SDL_LoadBMP("C:\\Users\\franc\\source\\repos\\1stSDLWindow\\x64\\Debug\\480_360_sample.bmp");
    if (!imageSurface) {
        cout << "Failed to load image: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    SDL_Rect dstRect = { 0, 0, 600, 600 };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(time * 1000);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    customer c3;
}

int main(int argc, char* argv[]) {
    cust_staff();
    return 0;
}
