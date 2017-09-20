#include "Payroll.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double fit_rate = (.15);
const double ss_rate = (.062);
const double medicare_rate = (.0145);
const double ot_multiplier = (1.5);
const double salary_bi_weekly = (26);
const double standard_hours = (40);

double get_reg_hours(double total_hours)
{
	double hours = total_hours;

	if (total_hours > standard_hours)
		hours = standard_hours;
	else if (total_hours < 0)
		hours = 0;
	
	return hours;
}

double get_ot_hours(double total_hours)
{
	double hours = 0;

	if (total_hours > standard_hours)
		hours = total_hours - standard_hours;

	return hours;
}

double get_gross_pay(double reg_hours, double ot_hours, double hourly_rate)
{
	double gross_pay = 0;

	gross_pay = reg_hours * hourly_rate;
	gross_pay += ot_hours * hourly_rate * ot_multiplier;

	return gross_pay;
}

double get_gross_pay(double salary)
{
	return salary / (salary_bi_weekly);
}

void show_check_hourly(double gross_pay, double reg_hours, double ot_hours)
{
	cout << "\n" << showpoint << fixed << setprecision(2);
	cout << right << setw(16) << "Regular hours: " << setw(8) << reg_hours << endl;
	cout << right << setw(16) << "Overtime hours: " << setw(8) << ot_hours << endl;
	cout << right << setw(16) << "Gross pay: " << setw(8) << gross_pay << endl;
	cout << right << setw(16) << "FIT: " << setw(8) << (gross_pay * fit_rate) << endl;
	cout << right << setw(16) << "FICA SSN: " << setw(8) << (gross_pay * ss_rate) << endl;
	cout << right << setw(16) << "FICA Med: " << setw(8) << (gross_pay * medicare_rate) << endl;
	cout << right << setw(16) << "Net Pay: " << setw(8) << (gross_pay) - (gross_pay * fit_rate) - (gross_pay * ss_rate) -
		(gross_pay * medicare_rate) << endl;
	cout << endl;

}

void show_check_salary(double gross_pay)
{
	cout << "\n" << showpoint << fixed << setprecision(2);
	cout << right << setw(16) << "Gross pay: " << setw(8) << gross_pay << endl;
	cout << right << setw(16) << "FIT: " << setw(8) << (gross_pay * fit_rate) << endl;
	cout << right << setw(16) << "FICA SSN: " << setw(8) << (gross_pay * ss_rate) << endl;
	cout << right << setw(16) << "FICA Med: " << setw(8) << (gross_pay * medicare_rate) << endl;
	cout << right << setw(16) << "Net Pay: " << setw(8) << (gross_pay)-(gross_pay * fit_rate) - (gross_pay * ss_rate) -
		(gross_pay * medicare_rate) << endl;
	cout << endl;
}

