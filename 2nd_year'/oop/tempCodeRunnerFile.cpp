#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

int count = 0, j = 0, m = 0;
class item {
public:
    string itemname;
    float price;
    int stock;

    ~item() {
        stock = 0;
    }
    friend void add(item a[], int h);
    friend void display(item b[], int j);
};

class person {
public:
    string name;
public:
    void getname() {
        cout << "\n\t\t\t\t\t\tEnter your name: ";
        cin >> name;
    }
};

class admin : public person {
    string pin, cpin;
public:
    admin() {
        cout << "\n\t\t\t\t\t\tEnter your name: ";
        cin >> name;
    set:
        cout << "\n\t\t\t\t\t\tSet your pin: ";
        cin >> pin;
        cout << "\n\t\t\t\t\t\tConfirm your pin: ";
        cin >> cpin;

        if (pin == cpin) {
            cout << "\n\t\t\t\t\t\tAccount created successfully.\n";
            ofstream fp;
            fp.open("admin.txt", ios::app);  // Open in append mode
            fp << "Admin Account Created - Name: " << name << "\n";
            fp.close();
        } else {
            cout << "\n\t\t\t\t\t\tInvalid pin!!!\n";
            goto set;
        }
    }
    friend void update(item x[], int j, int y);
    friend void adminupdate(item x[], int j, int y);
};

// In the main function, you should keep track of the admin's name for logging the login event:
void logAdminLogin(const string& adminName) {
    ofstream log("admin.txt", ios::app);
    log << "Admin Logged in - Name: " << adminName << "\n";  // Log the admin login
    log.close();
}

class customer : public person {
    string mail, ph;
    float bill = 0;
public:
    void getdetails() {
        cout << "\n\t\t\t\t\t\tEnter your phone number: ";
        cin >> ph;
        cout << "\n\t\t\t\t\t\tEnter your mail-id: ";
        cin >> mail;
    }

    void buy(item o[]) {
        int t, q, m = 0, opt;
        cart n[99];
    retry:
        cout << "\n\t\t\t\t\t\tSelect the item: ";
        cin >> t;
        cout << "\n\t\t\t\t\t\t" << o[t - 1].itemname << " " << "Price per unit:" << o[t - 1].price << " " << "Stock : " << o[t - 1].stock << endl;
        cout << "\n\t\t\t\t\t\tEnter the quantity: ";
        cin >> q;

        if (q > o[t - 1].stock) {
            cout << "\n\t\t\t\t\t\tInsufficient Stock !!!\n";
            goto retry;
        }

        bill += q * o[t - 1].price;
        n[m].updatecart(o[t - 1].itemname, q, o[t - 1].price);
        update(o, t - 1, q);
    g:
        cout << "\n\t\t\t\t\t\tPress 0 to continue Shopping\n\t\t\t\t\t\tPress 1 to Checkout\n";
        cin >> opt;
        if (opt == 0) {
            m++;
            goto retry;
        } else if (opt == 1) {
            displaybill(n, m, bill);
        } else {
            cout << "\n\t\t\t\t\t\tInvalid choice !!!\n";
            goto g;
        }
    }
};

class cart {
public:
    string iname;
    int quant;
    float rate, sum = 0;

    friend void displaybill(cart d[], int m, float bill);
    void updatecart(string a, int q, float p) {
        iname = a;
        quant = q;
        rate = p;
        sum = q * p;
    }
};

void update(item x[], int j, int y) {
    x[j].stock = x[j].stock - y;
}

void adminupdate(item x[], int j, int y) {
    x[j].stock = y;
}

void add(item a[], int h) {
    cout << "\n\t\t\t\t\t\tEnter the item name: ";
    cin >> a[h].itemname;
    cout << "\n\t\t\t\t\t\tEnter item price per unit: ";
    cin >> a[h].price;
    cout << "\n\t\t\t\t\t\tEnter the stock availability: ";
    cin >> a[h].stock;
    cout << "\n\t\t\t\t\t\t" << a[h].itemname << " is added successfully.\n";
}

void display(item b[], int j) {
    int i;
    for (i = 0; i < j; i++) {
        cout << "\n\t\t\t\t\t\t" << b[i].itemname << " " << "Stock :" << b[i].stock << " " << "Price per unit:" << b[i].price;
        cout << "\t";
        if (i > 0) {
            if (i % 2 == 0) cout << endl;
        }
    }
}

void displaybill(cart d[], int m, float bill) {
    int i;
    cout << left << setw(10) << "NAME" << left << setw(5) << "QUANTITY" << left << setw(8) << "Price/unit" << left << setw(5) << "AMOUNT" << endl;
    for (i = 0; i <= m; i++) {
        cout << left << setw(10) << d[i].iname << left << setw(5) << d[i].quant << left << setw(8) << d[i].rate << left << setw(5) << d[i].sum << endl;
    }
    cout << left << setw(50) << "TOTAL" << ":" << setw(10) << bill << endl;
    for (i = 0; i < 80; i++) cout << "-";
    cout << endl;
    cout << left << setw(50) << "GRAND TOTAL" << ":" << setw(10) << (0.18 * bill) + bill << endl;
    for (i = 0; i < 80; i++) cout << "-";
}

void chatbot() {
    // The chatbot implementation goes here
}

int main() {
    item t[999];
    customer c[9999];
    int choice, opt, sel, k = 0, u;
    string pin, checkpin;
    admin a;  // Declare the admin object here so its 'name' is accessible later.
    system("Color F1");
    cout << "\n\t";
    for (int r = 0; r < 190; r++) cout << "*";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tMediZone\n\n\t";
    for (int r = 0; r < 190; r++) cout << "*";
    cout << "\n\n";
    chatbot();

    while (1) {
    here:
        cout << "\n\t\t\t\t\t\t 1.Admin\t\t 2.Customer\t\t 3.Chatbot\t\t 4.Exit\n";
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (count == 0) {
                cout << "\n\t\t\t\t\t\tAdmin SignUp\n";
                count++;
            } else {
                cout << "\n\t\t\t\t\t\tAdmin Login:\n";
            jump:
                cout << "\n\t\t\t\t\t\tEnter your pin: ";
                cin >> pin;
                ifstream fp;
                fp.open("admin.txt");

                while (!fp.eof()) {
                    fp >> checkpin;
                }

                if (pin == checkpin) {
                    cout << "\n\t\t\t\t\t\tLogged in Successfully\n";
                    logAdminLogin(a.name); // Log admin login here
                    while (1) {
                        cout << "\n\t\t\t\t\t\t 1.Add\t\t 2.Display Stock\t\t 3.Update\t\t 4.Delete\t\t 5.Log-out\n";
                        cout << "\n\t\t\t\t\t\tEnter your choice: ";
                        cin >> opt;
                        switch (opt) {
                        case 1:
                            add(t, j);
                            j++;
                            break;
                        case 2:
                            display(t, j);
                            break;
                        case 3:
                            cout << "\n\t\t\t\t\t\tSelect the item: ";
                            cin >> sel;
                            cout << "\n\t\t\t\t\t\tEnter the available stock: ";
                            cin >> u;
                            adminupdate(t, sel - 1, u);
                            break;
                        case 4:
                            cout << "\n\t\t\t\t\t\tSelect item number to delete: ";
                            cin >> sel;
                            t[sel - 1].~item();
                            break;
                        case 5:
                            cout << "\n\t\t\t\t\t\tLogged out successfully.\n";
                            goto exit_loop;
                        default:
                            cout << "\n\t\t\t\t\t\tInvalid choice.\n";
                            break;
                        }
                    }
                    exit_loop: ;
                } else {
                    cout << "\n\t\t\t\t\t\tIncorrect PIN.\n";
                    goto jump;
                }
            }
            break;

        case 2:
            c[k].getname();
            c[k].getdetails();
            c[k].buy(t);
            k++;
            break;

        case 3:
            chatbot();
            break;

        case 4:
            cout << "\n\t\t\t\t\t\tThank you for using the system!";
            return 0;

        default:
            cout << "\n\t\t\t\t\t\tInvalid choice.\n";
        }
    }

    return 0;
}
