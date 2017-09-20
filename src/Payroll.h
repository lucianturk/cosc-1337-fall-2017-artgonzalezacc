#ifndef _PAYROLL_H
#define _PAYROLL_H

double get_reg_hours(double total_hours);
double get_ot_hours(double total_hours);
double get_gross_pay(double reg_hours, double ot_hours, double hourly_rate);
double get_gross_pay(double salary);
void show_check_hourly(double gross_pay, double reg_hours, double ot_hours);
void show_check_salary(double gross_pay);

#endif
