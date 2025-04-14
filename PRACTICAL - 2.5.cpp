#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    float loanAmount;
    float interestRate;
    int loanTerm;
    float emi;

public:
    Loan() {
        loanID = 0;
        applicantName = "N/A";
        loanAmount = 0.0;
        interestRate = 0.0;
        loanTerm = 0;
        emi = 0.0;
    }

    Loan(int id, string name, float amount, float rate, int term) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        interestRate = rate;
        loanTerm = term;
        emi = 0.0;
    }

    void calculateEMI() {
        float R = (interestRate / 100) / 12;
        int T = loanTerm;
        if (R == 0) {
            emi = loanAmount / T;
        } else {
            emi = (loanAmount * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
        }
    }

    void displayLoanDetails() {
        cout << "Loan ID : " << loanID << endl;
        cout << "Applicant Name : " << applicantName << endl;
        cout << "Loan Amount : " << loanAmount << endl;
        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Loan Term : " << loanTerm << " months" << endl;
        cout << "Monthly EMI : " << emi << endl;
    }
};

int main() {
    int id;
    string name;
    float amount, rate;
    int term;

    cout << "Enter Loan ID : ";
    cin >> id;
    cin.ignore();
    cout << "Enter Applicant Name : ";
    getline(cin, name);
    cout << "Enter Loan Amount : ";
    cin >> amount;
    cout << "Enter Annual Interest Rate (in %) : ";
    cin >> rate;
    cout << "Enter Loan Term (in months) : ";
    cin >> term;
    cout << endl ;

    Loan loan(id, name, amount, rate, term);

    loan.calculateEMI();

    loan.displayLoanDetails();

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
