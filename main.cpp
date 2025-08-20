//Betsabe Covarrubias
//hw0
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "ArgumentManager.h"

using namespace std;
int i = 0, j = 0, vectlength = 0;
vector<string> temp8;

void setvectlength(int length) {vectlength = length;}

void setcardvect(vector<string> tvect) {
  for (int i = 0; i < vectlength; i++) {
    temp8.push_back(tvect[i]);
  }
}

int rowletterdec(int spot){
  if (spot == 74) {
    return 10;
  }
  else if (spot == 81) {
    return 11;
  }
  else if (spot == 75) {
    return 12;
  }
  return 0;
}

int columndecider(int posi){
  if (posi == 83) {
    return 0;
  }
  else if(posi == 72) {
    return 1;
  }
  else if(posi == 67) {
    return 2;
  }
  else if (posi == 68) {
    return 3;
  }
  return 0;
}

void outarray(int arr[][4]) {
  for(int i = 0; i < vectlength; i++) {
    string temp3 = temp8[i];
    int row = 0;
    int column = 0;
    if (temp3.size() == 2) {
      if (isalpha(temp3[0])) {
        int rowlast = temp3[0] - 0;
        row = rowletterdec(rowlast);
        int colltemp = temp3[1] - 0;
        column = columndecider(colltemp);
        arr[row][column] = 1;
      }
      else {
        int notchar = temp3[0] - '0';
        row = notchar - 1;
        int colltemp = temp3[1] - 0;
        column = columndecider(colltemp);
        arr[row][column] = 1;
      }
    }
    else if (temp3.size() == 3) {
      row = 9;
      int colltemp = temp3[2] - 0;
      column = columndecider(colltemp);
      arr[row][column] = 1;
    }
  }
}

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);

  ifstream inputfile(am.get("input"));
  ofstream outputfile(am.get("output"));

  //ifstream inputfile("input1.txt");
  string line;
  getline(inputfile,line);
  vector<string> temp;
  

  int stringnum = 0;
  int size = line.size();
  for (i = 0; i < size; i++) {
    if (isalnum(line[i])) {
      stringnum += 1;
      if (i == line.size()-1) {
        string temp2 = line.substr(i - (stringnum-1),stringnum);
        temp.push_back(temp2);
      }
    }
    else if (!isalnum(line[i])) {
      string temp2 = line.substr(i - stringnum, stringnum);
      temp.push_back(temp2);
      stringnum  = 0;
      line.erase(i, 2);
      size = line.size();
      i -= 1;
    }
  }

  int outarr[13][4] = {0};

  setvectlength(temp.size());
  setcardvect(temp);
  outarray(outarr);

  for (i = 0; i < 13; i++) {
    for (j = 0; j < 4; j++) {
      outputfile << outarr[i][j] << " ";
    }
    outputfile << endl;
  }
  

  inputfile.close();
  outputfile.close();

  return 0;
}