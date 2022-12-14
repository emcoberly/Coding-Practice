#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// NOTE: ACCESSORY J MAY HAVE CHANGED OVER TIME

vector<string> DEPARTMENT_LIST = {"CLOTHING",
                                  // "CLOTHING P/G",
                                  // "CLOTHING K/B",
                                  // "CLOTHING O/Y",
                                  "SHOES", "PURSES", "CRAFTS", "LIBRARY",
                                  "KITCHENWARE", "LINEN", "KNICK",
                                  // "KNICK KNACKS",
                                  "TOYS", "FURNITURE", "MISC.", "GIFT",
                                  // "GIFT CARD",
                                  "HOLIDAY", "ACCESSORY",
                                  // "ACCESSORY J",
                                  "SHOP", "ELECTRONICS"};

class Summary {
public:
  int month = 0;
  int day = 0;
  int year = 0;
  int hour = 0;
  int minute = 0;
  string department = "";
  int items_sold = 0;
  float money = 0.0;
};

bool inDeptList(string dept);
void summaryDateTime(Summary &summary, int month, int day, int year, int hour,
                     int minute);
void printSummary(vector<Summary> totals);
void exportFormatted(vector<Summary> summary, string file_name);

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cerr << "Please add a file name as an argument." << endl;
    exit(1);
  }

  Summary sales_summary;
  int input_type;
  int input_hour, input_minute;
  int sales_month, sales_day, sales_year;
  string department = "";
  string dept_category = "";
  int items_sold;
  int dept_dollars, dept_cents;
  vector<Summary> final_results(0);
  bool dept_flag = false;
  bool clothing_flag = false;

  ifstream fin;
  fin.open(argv[1]);
  string line;

  char char_junk;
  long int int_junk;
  string str_junk;

  if (!fin.is_open()) {
    cerr << "ERROR: Could not open \"" << argv[1] << "\"." << endl;
    exit(1);
  } else {
    while (getline(fin, line)) {
      stringstream parse_line(line);
      parse_line >> input_type;
      // Get date/time info from line type '3' and apply it to all departments
      // from line type '4'
      if (input_type == 3) {
        // Discard everything except relevant date and time numbers
        parse_line >> char_junk >> int_junk >> char_junk >> char_junk;
        parse_line >> input_hour >> char_junk >> input_minute;
        parse_line >> sales_month >> char_junk >> sales_day >> char_junk >>
            sales_year >> char_junk;
      } else if (input_type == 4) {
        // Discard more useless characters
        parse_line >> char_junk >> int_junk >> char_junk >> char_junk;
        if (dept_flag) {
          dept_flag = false;
          parse_line >> char_junk >> dept_dollars >> char_junk >> dept_cents >>
              str_junk;
          sales_summary.money = dept_dollars + dept_cents * 0.01;
          final_results.push_back(sales_summary);
          // Summary for each dept. is complete once dollar amount has been
          // added, so object is pushed to vector and reset
          sales_summary = {};
        } else {
          parse_line >> department;
          // Limits line type '4' input to only be about departments, examines
          // only relevant input
          if (inDeptList(department)) {
            // Check for specific multi-string dept. names
            if (department == "KNICK" || department == "GIFT" ||
                department == "ACCESSORY" || department == "CLOTHING") {
              // Make sure just "CLOTHING" isn't fed its items sold
              for (int i = 0; i < final_results.size(); i++) {
                if (final_results.at(i).department == "CLOTHING") {
                  clothing_flag = true;
                }
              }
              // If "CLOTHING" has been filled, feed in the categories of
              // remaining "CLOTHING" categories Also functions as a scanner for
              // multi-string depts.
              //   separated by whitespace, replaces with '_' for easy read-in
              if (clothing_flag) {
                parse_line >> dept_category;
                department += "_" + dept_category;
              }
            }
            parse_line >> items_sold >> char_junk;
            sales_summary.department = department;
            sales_summary.items_sold = items_sold;

            // void function inputs sales date and time into current summary
            // object
            summaryDateTime(sales_summary, sales_month, sales_day, sales_year,
                            input_hour, input_minute);

            // Set a flag that differentiates between a line with a dept. and a
            // line with its respective dollar amount
            dept_flag = true;
          }
        }
      }
    }
  }
  fin.close();

	// Generate new file name, account for 0's
  string file_name = "";
  if (sales_month < 10) {
    file_name += "0";
  }
  file_name += to_string(sales_month) + "-";
  if (sales_day < 10) {
    file_name += "0";
  }
  file_name += to_string(sales_day) + "-" + to_string(sales_year) + ".txt";

	// Export info and print it to console in similar format
  exportFormatted(final_results, file_name);
  printSummary(final_results);

  return 0;
}

bool inDeptList(string dept) {
  for (int i = 0; i < DEPARTMENT_LIST.size(); i++) {
    if (dept == DEPARTMENT_LIST.at(i)) {
      return true;
    }
  }
  return false;
}

void summaryDateTime(Summary &summary, int month, int day, int year, int hour,
                     int minute) {
  summary.month = month;
  summary.day = day;
  summary.year = year;
  summary.hour = hour;
  summary.minute = minute;
}

void printSummary(vector<Summary> totals) {
  float total_sales = 0.0;
  int total_items = 0;
  bool format_tab = false;
  bool format_month = false;
  bool format_day = false;
  cout << " Department\t"
       << "Items Sold\t"
       << "Money earned\t"
       << "Date\t" << endl;
  cout << "—————————————————————————————————————————————————————————————"
       << endl;
  for (int i = 0; i < totals.size(); i++) {
    format_tab = totals.at(i).department.size() < 7;
    format_month = totals.at(i).month < 10;
    format_day = totals.at(i).day < 10;
    total_sales += totals.at(i).money;
    total_items += totals.at(i).items_sold;
    cout << " " << totals.at(i).department << "\t";
    if (format_tab) {
      cout << "\t";
    }
    cout << totals.at(i).items_sold << "\t\t$" << fixed << setprecision(2)
         << totals.at(i).money << "\t\t";
    if (format_month) {
      cout << "0";
    }
    cout << totals.at(i).month << "/";
    if (format_day) {
      cout << "0";
    }
    cout << totals.at(i).day << "/" << totals.at(i).year << endl;
  }
  cout << endl
       << " Totals:\t" << total_items << "\t\t$" << fixed << setprecision(2)
       << total_sales << endl;
}

void exportFormatted(vector<Summary> summary, string file_name) {
  // Output 0's where necessary;
  bool lt10;

  // Also export totals for money and items sold
  float total_sales = 0.0;
  int total_items = 0;

  ofstream fout;
  fout.open(file_name);
  Summary currSummary;
  if (!fout.is_open()) {
    cerr << "ERROR: Could not export into " << file_name << "." << endl;
  } else {
    fout << "DEPARTMENT,ITEMS_SOLD,DOLLAR_AMOUNT,DATE,TIME" << endl;
    for (int i = 0; i < summary.size(); i++) {
      currSummary = summary.at(i);
      fout << currSummary.department << "," << currSummary.items_sold << ","
           << fixed << setprecision(2) << currSummary.money << ",";

      // Get running totals info
      total_sales += currSummary.money;
      total_items += currSummary.items_sold;

      // Check for two-digit values less than 10 and display them with 0's
      lt10 = currSummary.month < 10;
      if (lt10) {
        fout << "0";
      }
      fout << currSummary.month << "/";
      lt10 = currSummary.day < 10;
      if (lt10) {
        fout << "0";
      }
      fout << currSummary.day << "/" << currSummary.year << ",";
      lt10 = currSummary.hour < 10;
      if (lt10) {
        fout << "0";
      }
      fout << currSummary.hour << ":";
      lt10 = currSummary.minute < 10;
      if (lt10) {
        fout << "0";
      }
      fout << currSummary.minute << endl;
    }
    fout << "TOTAL"
         << "," << total_items << "," << total_sales << endl;
  }
  fout.close();
}
